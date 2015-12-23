#include <Railway/RWResponder.h>
#include <Railway/RWFile.h>
#include <Railway/RWFolder.h>
#include <Railway/RWTransport.h>
#include <Railway/RWGlobals.h>
#include <substrate.h>

static uint16_t				operation_code;
static uint32_t				transaction_id;
static uint32_t				parameter1;
static uint32_t				parameter2;
static uint32_t				parameter3;
static uint32_t				parameter4;
static uint32_t				parameter5;

// Incoming objects
RWFile						*file;
RWFolder						*folder;
RWFolder						*parent;

// Hooks
static pOrig_handle_request	orig_handle_request;
static pOrig_handle_data		orig_handle_data;
static pOrig_delete_object		orig_delete_object;

void 
send_object_info( PTPResponder *self, PTPDataPacket *packet )
{
	PTPObjectInfoDataset			*dataset;
	PTPOperationResponsePacket		*response;
	
	dataset	= [[CPTPObjectInfoDataset alloc] 
				initWithData:[packet data]];
	
	// Ottiene la cartella di destinazione
	if 	( parameter2 == RailwayStorage->object_handle )
		  parent = RailwayStorage;
	else		
		  parent = new RWFolder( [ivar_virtual_camera( self ) objectForObjectHandle:
									[NSNumber numberWithUnsignedLong:parameter2]] );
	
	if ( [dataset objectFormat] == PTP_FORMAT_ASSOCIATION ) 
	{
		folder = new RWFolder( dataset, parent );
		parent->add( folder );
		parameter3 = folder->object_handle;
	}
	else
	{
		file = new RWFile( dataset, parent );
		parent->add( file );		
		parameter3 = file->object_handle;			
	}
	
	[self reportObjectAdded:[NSNumber numberWithUnsignedLong:parameter3]];
	
	response = [[CPTPOperationResponsePacket alloc]
				initWithResponseCode:PTP_RESPONSE_OK
				transactionID:transaction_id
				parameter1:parameter1
				parameter2:parameter2
				parameter3:parameter3];
	
	[ivar_transport( self ) sendResponse:response];
	[response release];

}

void 
send_object( PTPResponder *self, PTPDataPacket *packet )
{
	NSData						*data;
	PTPOperationResponsePacket		*response;
	int							written;
	
	data 	= [packet data];
	written 	= file->write( [data bytes], 
						  [data length] );
	if ( written < 0 )
	{
		receive_length = 0;
		file->close();
		
		response = [[CPTPOperationResponsePacket alloc]
					initWithResponseCode:PTP_RESPONSE_ACCESS_DENIED
					transactionID:transaction_id];
		[ivar_transport( self ) sendResponse:response];
		[response release];
	}
	
	receive_length -= written;
	
	[data release];
	
	if ( !receive_length )
	{	
		// Genera la risposta, la invia e chiude il file
		file->close();
		
		// Verifica in quale cartella è stato inviato il file
		if ( RailwayRecordings != NULL )
			if ( parameter2 == RailwayRecordings->object_handle )
			{
				// Importa nei memo vocali
				NSLog(@"Importing into recordings");
			}
		
		response = [[CPTPOperationResponsePacket alloc]
					initWithResponseCode:PTP_RESPONSE_OK
					transactionID:transaction_id];
		[ivar_transport( self ) sendResponse:response];
		[response release];
	
	}
	
}

/*void move_object( PTPResponder *self )
{
	
}*/

void delete_object( PTPResponder *self, SEL cmd, PTPOperationRequestPacket *request )
{
	RWFolder					*object;
	RWFolder					*parent;
	PTPOperationResponsePacket	*response;
	
	if ( [[ivar_virtual_camera( self ) objectForObjectHandle:
					[NSNumber numberWithUnsignedLong:parameter1]] isKindOfClass:CFolder] )
	{
		object = new RWFolder( [ivar_virtual_camera( self ) objectForObjectHandle:
								[NSNumber numberWithUnsignedLong:parameter1]] );
		
		if ( [[NSFileManager defaultManager] 
					removeItemAtPath:[NSString stringWithUTF8String:object->path]
					error:nil] )
		{
			parent = new RWFolder( object->parent );
		
			[parent->folders 			removeObjectForKey:[NSNumber numberWithUnsignedLong:object->object_handle]];
			[parent->folder_indices	removeIndex:object->object_handle];
			
			response = [[CPTPOperationResponsePacket alloc]
						initWithResponseCode:PTP_RESPONSE_OK
						transactionID:transaction_id];
		}
		else
		{
			response = [[CPTPOperationResponsePacket alloc]
						initWithResponseCode:PTP_RESPONSE_ACCESS_DENIED
						transactionID:transaction_id];
		}
		
		[ivar_transport( self ) sendResponse:response];
			[response release];
	}
	else
	{
		orig_delete_object( self, cmd, request );
	}
}

void 
handle_data( PTPResponder *self, SEL cmd, PTPDataPacket *packet )
{
	switch ( operation_code )
	{
		case PTP_OPERATION_SEND_OBJECT_INFO:
			send_object_info( self, packet ); break;
		case PTP_OPERATION_SEND_OBJECT:
			send_object( self, packet ); break;
	}
}

NSNumber * 
handle_request( PTPResponder *self, SEL cmd, PTPOperationRequestPacket *request )
{
	transaction_id	= [request transactionID];
	operation_code	= [request operationCode];
	parameter1		= [request parameter1];
	parameter2		= [request parameter2];
	parameter3		= [request parameter3];
	parameter4		= [request parameter4];
	parameter5		= [request parameter5];
	
	switch ( operation_code )
	{
		case PTP_OPERATION_SEND_OBJECT:
		case PTP_OPERATION_SEND_OBJECT_INFO:
			
			// Attende ulteriori dati
			break;
		
		/*case PTP_OPERATION_MOVE_OBJECT:
			
			move_object( self );
			break;*/
		
		default:
			
			return ( orig_handle_request( self, cmd, request ) );
	}
	
	return ( [NSNumber numberWithBool:false] );
}

void 
RWResponderAttach()
{
#if ( RAILWAY_DEBUG )
	MSHookMessageEx( CPTPResponder,
				   @selector(handleRequest:),
				   ( IMP )&handle_request,
				   ( IMP * )&orig_handle_request );
				   
	MSHookMessageEx( CPTPResponder,
				   @selector(handleData:),
				   ( IMP )&handle_data,
				   ( IMP * )&orig_handle_data );
	
	MSHookMessageEx( CPTPResponder,
				   @selector(deleteObject:),
				   ( IMP )&delete_object,
				   ( IMP * )&orig_delete_object );
#else
	MSHookMessageEx( objc_getClass( RailwaySettings->ptp_responder ),
				   sel_registerName( RailwaySettings->handle_request ),
				   ( IMP )&handle_request,
				   ( IMP * )&orig_handle_request );
				   
	MSHookMessageEx( objc_getClass( RailwaySettings->ptp_responder ),
				   sel_registerName( RailwaySettings->handle_data ),
				   ( IMP )&handle_data,
				   ( IMP * )&orig_handle_data );
				   
	MSHookMessageEx( objc_getClass( RailwaySettings->ptp_responder ),
				   sel_registerName( RailwaySettings->delete_object ),
				   ( IMP )&delete_object,
				   ( IMP * )&orig_delete_object );
#endif
}

void 
RWResponderDetach()
{
#if ( RAILWAY_DEBUG )
	MSHookMessageEx( CPTPResponder,
				   @selector(handleRequest:),
				   ( IMP )orig_handle_request,
				   NULL );
	
	MSHookMessageEx( CPTPResponder,
				   @selector(handleData:),
				   ( IMP )orig_handle_data,
				   NULL );
	
	MSHookMessageEx( CPTPResponder,
				   @selector(deleteObject:),
				   ( IMP )orig_delete_object,
				   NULL );
#else
	MSHookMessageEx( objc_getClass( RailwaySettings->ptp_responder ),
				   sel_registerName( RailwaySettings->handle_request ),
				   ( IMP )orig_handle_request,
				   NULL );
	
	MSHookMessageEx( objc_getClass( RailwaySettings->ptp_responder ),
				   sel_registerName( RailwaySettings->handle_data ),
				   ( IMP )orig_handle_data,
				   NULL );
				   
	MSHookMessageEx( objc_getClass( RailwaySettings->ptp_responder ),
				   sel_registerName( RailwaySettings->delete_object ),
				   ( IMP )orig_delete_object,
				   NULL );
	
#endif
}