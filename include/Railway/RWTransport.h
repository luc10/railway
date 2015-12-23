#ifndef __RAILWAY_TRANSPORT_H__
#define __RAILWAY_TRANSPORT_H__

#include <stdlib.h>
#include <PTPD/PTPD.h>
#include <sys/types.h>
#include <Railway/Runtime/RWIVars.h>
#include <Railway/Runtime/RWClasses.h>
#include <substrate.h>

typedef struct __attribute__ ((__packed__)) {
	uint32_t			length;
	uint16_t			packet_type;
	uint16_t			operation_code;
	uint32_t			transaction_id;	
	unsigned char		data[];
} ReadBuffer;

#define		PACKET_TYPE_ACK			1
#define		PACKET_TYPE_DATA			2
#define		PACKET_TYPE_RESPONSE		3

#define		HEADER_LENGTH				12

typedef		BOOL		( *pOrig_handle_bulk_data ) ( PTPDeviceUSBTransport *, SEL, uint32_t, int );

void 	RWTransportAttach();
void 	RWTransportDetach();

extern	uint32_t		receive_length;

#endif /* __RAILWAY_TRANSPORT_H__ end */
