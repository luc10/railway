#include <Railway/RWTransport.h>
#include <Railway/RWConfig.h>
#include <Railway/RWGlobals.h>

static uint16_t				operation_code;
static uint32_t				transaction_id;
static BOOL					header_buffer_found;
static unsigned char			*raw_packet;

// Exports
uint32_t						receive_length;

// Hooks
static pOrig_handle_bulk_data		orig_handle_bulk_data;

BOOL
handle_bulk_data( PTPDeviceUSBTransport *self, SEL cmd, uint32_t data, int result )
{
	PTPDataPacket					*packet;
	PTPOperationRequestPacket		*request;
	PTPOperationResponsePacket		*response;
	ReadBuffer					*read_buffer;
	
	packet  	= nil;
	request 	= nil;
	response = nil;
	
	if ( ( read_buffer = ( ReadBuffer* )ivar_read_buffer( self ) ) )
	{
		if ( !receive_length || receive_length == 0 )
		{
			if ( header_buffer_found )
			{
				memcpy( ( raw_packet + HEADER_LENGTH ),
						 read_buffer,
						 data );
						 
				packet = [[CPTPDataPacket alloc] 			
							initWithUSBBuffer:( unsigned char * )raw_packet];
				
				[ivar_delegate( self ) handleData:packet];
				[packet release];
				
				header_buffer_found = false;
				return ( true );
			}
			else
			{
				switch ( read_buffer->packet_type )
				{
					case PACKET_TYPE_ACK:
					{
						request = [[CPTPOperationRequestPacket alloc]
									initWithUSBBuffer:( unsigned char * )read_buffer];
						[ivar_delegate( self ) handleRequest:request];
						[request release];
						
						return true;
					}
					case PACKET_TYPE_DATA:
					{	
						if ( read_buffer->operation_code == PTP_OPERATION_SEND_OBJECT )
						{
							// Salva le dimensioni del file che si sta per ricevere e passa
							// al responder solo i dati raw del file stesso tolto l'header
							receive_length 	= read_buffer->length - HEADER_LENGTH;
							operation_code	= read_buffer->operation_code;
							transaction_id	= read_buffer->transaction_id;
							
							packet = [[CPTPDataPacket alloc]
									initWithOperationCode:operation_code
									transactionID:transaction_id
									andData:[[NSData alloc] initWithBytes:( unsigned char * )read_buffer->data
														 length:( data - HEADER_LENGTH )]];
							[ivar_delegate( self ) handleData:packet];
							[packet release];
							
						}
						else
						{
							if ( !header_buffer_found )
							{
								if ( read_buffer->length != data && data == HEADER_LENGTH )
								{
									header_buffer_found 	= true;
									raw_packet			= new unsigned char[read_buffer->length];
									
									// Copia l'header e attende il prossimo pacchetto per
									// concatenare i dati e inviarli
									memcpy( raw_packet, read_buffer, HEADER_LENGTH );
								}
								else
								{
									packet = [[CPTPDataPacket alloc] 			
												initWithUSBBuffer:( unsigned char * )read_buffer];
								}
							}
							
							if ( packet != nil )
							{
								[ivar_delegate( self ) handleData:packet];
								[packet release];
							}
						}
						
						return true;
					}
					case PACKET_TYPE_RESPONSE:
					{	
						response = [[CPTPOperationResponsePacket alloc]
									initWithUSBBuffer:( unsigned char * )read_buffer];
						[ivar_delegate( self ) handleResponse:response];
						[response release];
						
						return true;
					}	
				}
			}
		}
		else
		{
			// Header trovato in precedenza, bisogna procedere finchè i dati non vengono
			// inviati tutti
			packet = [[CPTPDataPacket alloc]
						initWithOperationCode:operation_code
						transactionID:transaction_id
						andData:[[NSData alloc] initWithBytes:( unsigned char * )read_buffer
											 length:data]];
			[ivar_delegate( self ) handleData:packet];
			[packet release];
			
			return true;
		}
	}
	
	return true;
		
}

void 
RWTransportAttach()
{	
#if ( RAILWAY_DEBUG )
	MSHookMessageEx( CPTPDeviceUSBTransport,
				   @selector(handleBulkData:result:),
				   ( IMP )&handle_bulk_data,
				   ( IMP * )&orig_handle_bulk_data);
#else
	MSHookMessageEx( objc_getClass( RailwaySettings->ptp_transport ),
				   sel_registerName( RailwaySettings->handle_bulk_data ),
				   ( IMP )&handle_bulk_data,
				   ( IMP * )&orig_handle_bulk_data);
#endif
}

void 
RWTransportDetach()
{
#if ( RAILWAY_DEBUG )
	MSHookMessageEx( CPTPDeviceUSBTransport,
				   @selector(handleBulkData:result:),
				   ( IMP )orig_handle_bulk_data,
				   NULL);
#else
	MSHookMessageEx( objc_getClass( RailwaySettings->ptp_transport ),
				   sel_registerName( RailwaySettings->handle_bulk_data ),
				   ( IMP )orig_handle_bulk_data,
				   NULL);
#endif
}
