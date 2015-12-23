#ifndef __RAILWAY_RESPONDER_H__
#define __RAILWAY_RESPONDER_H__

#include <PTPD/PTPD.h>
#include <stdlib.h>
#include <sys/types.h>
#include <Railway/RWGlobals.h>
#include <Railway/Runtime/RWIVars.h>
#include <Railway/Runtime/RWClasses.h>

typedef	NSNumber *	( *pOrig_handle_request )( PTPResponder *, SEL, PTPOperationRequestPacket * );
typedef	void		 	( *pOrig_handle_data )( PTPResponder *, SEL, PTPDataPacket * );
typedef	void			( *pOrig_delete_object )( PTPResponder *, SEL, PTPOperationRequestPacket * );

void RWResponderAttach();
void RWResponderDetach();

#endif /* __RAILWAY_RESPONDER_H__ end */