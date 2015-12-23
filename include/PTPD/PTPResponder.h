#import <Foundation/NSObject.h>
#import "PTPTransport.h"
#import "PTPEventPacket.h"
#import "PTPVirtualCamera.h"
#import "PTPOperationRequestPacket.h"
#import "PTPOperationResponsePacket.h"

@interface PTPResponder : NSObject 
{
	PTPTransport* 				_transport;
	PTPVirtualCamera* 			_virtualCamera;
	PTPOperationRequestPacket* 	_operationRequest;
	PTPOperationResponsePacket* _response;
	PTPEventPacket* 			_event;
	NSMutableArray* 			_pendingSendDataPackets;
	unsigned long				_lastTransactionID;
	unsigned long 				_canceledTransactionID;
	unsigned long 				_sessionID;
	NSString* 					_guid;
	NSString* 					_name;
	NSString* 					_path;
	id 							_delegate;
	BOOL						_keepRunningRunLoop;
	void* 						_cpPowerAssertion;
	BOOL 						_allowKeepAwake;
	double 						_powerAssertionReleaseDelay;
	BOOL 						_usingMTP;
}
-(void)setUsingMTP:(id)mtp;
-(id)usingMTP;
-(void)releasePowerAssertion;
-(void)holdPowerAssertion;
-(void)sendRestartSessionEvent;
-(void)sendDeviceUnlockedEvent;
-(void)transportDeactivated;
-(void)transportActivated;
-(void)stopRunLoop;
-(void)runRunLoop;
-(void)stop;
-(BOOL)start;
-(void)registerForAccept;
-(void)registerForTerminate;
-(void)reportUserAssignedNameChange;
-(void)reportObjectDeleted:(id)deleted;
-(void)reportObjectAdded:(id)added;
-(void)sentData:(id)data responseCode:(id)code;
-(void)sendEvent:(id)event;
-(void)handleDeviceRemoval;
-(void)handleCancel:(id)cancel;
-(void)handleData:(id)data;
-(void)handleStartData:(id)data;
-(void)handleResponse:(id)response;
-(id)handleRequest:(id)request;
-(void)getObjectPropDesc:(id)desc;
-(void)getObjectPropList:(id)list;
-(void)getObjectPropValue:(id)value;
-(void)getObjectPropsSupported:(id)supported;
-(void)handleUnsupportedRequest:(id)request;
-(void)allowKeepAwake:(id)awake;
-(void)getDevicePropValue:(id)value;
-(void)getDevicePropDesc:(id)desc;
-(void)deleteObject:(id)object;
-(void)getObjectMetadata:(id)metadata;
-(void)getPartialObject64:(id)a64;
-(void)getPartialObject:(id)object;
-(void)getObject:(id)object;
-(void)getThumb:(id)thumb;
-(void)getObjectInfo:(id)info;
-(void)getUserAssignedDeviceName:(id)name;
-(void)getObjectInfoForAllObjects64:(id)allObjects64;
-(void)getObjectInfo64Bit:(id)bit;
-(void)getObjectInfoForAllObjects:(id)allObjects;
-(void)getObjectFilesystemManifest:(id)manifest;
-(void)getObjectHandles:(id)handles;
-(void)getNumDownloadableObjects:(id)objects;
-(void)getNumObjects:(id)objects;
-(void)getStorageInfo:(id)info;
-(void)getStorageIDs:(id)ids;
-(void)closeSession:(id)session;
-(void)openSession:(id)session;
-(void)getDeviceInfo:(id)info;
-(id)path;
-(id)name;
-(void)setDelegate:(id)delegate;
-(void)dealloc;
-(void)acceptNewSocket:(id)socket;
-(id)initWithName:(id)name path:(id)path guid:(id)guid andTransportType:(unsigned short)type withAcceptedSocket:(int)acceptedSocket;
-(id)initWithName:(id)name path:(id)path andTransportType:(unsigned short)type;
-(id)init;
@end

