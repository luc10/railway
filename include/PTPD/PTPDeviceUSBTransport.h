#import <Foundation/NSObject.h>
#import <IOKit/IOKitLib.h>

#import <CoreFoundation/CFRunLoop.h>
#import <CoreFoundation/CFPlugIn.h>
#import <CoreFoundation/CFPlugInCOM.h>

typedef struct IOUSBDeviceInterfaceInterface* 	IOUSBDeviceInterfaceInterfaceRef;
typedef struct IOCFPlugInInterfaceStruct* 		IOCFPlugInInterfaceStructRef;
typedef struct __IOUSBDeviceData* 				IOUSBDeviceDataRef;
typedef struct IONotificationPort* 				IONotificationPortRef;
typedef struct __CFRunLoopTimer* 				CFRunLoopTimerRef;
typedef struct __CFRunLoopSource* 				CFRunLoopSourceRef;

typedef struct {
	unsigned char 	_field1;
	unsigned char 	_field2;
	unsigned short 	_field3;
	unsigned short 	_field4;
	unsigned short 	_field5;
} XXStruct_NUaWfC;

@interface PTPDeviceUSBTransport : NSObject 
{
	unsigned long 						_locationID;
	unsigned short 						_vendorID;
	unsigned short 						_productID;
	NSString* 							_usbSerialNumberString;
	IOUSBDeviceInterfaceInterfaceRef* 	_interfaceInterfaceRef;
	unsigned 							_notification;
	IOCFPlugInInterfaceStructRef* 		_ioCFPlugInInterface;
	void* 								_bulkPipeIn;
	void* 								_bulkPipeOut;
	void* 								_interruptPipeIn;
	IOUSBDeviceDataRef 					_readDataRef;
	IOUSBDeviceDataRef 					_writeDataRef;
	IOUSBDeviceDataRef 					_eventDataRef;
	unsigned 							_notificationDevice;
	IONotificationPortRef 				_notificationPort;
	NSMutableArray* 					_eventArray;
	CFRunLoopTimerRef 					_activationTimer;
	unsigned long 						_readBufferSize;
	unsigned long 						_writeBufferSize;
	unsigned long 						_eventDataBufferSize;
	char* 								_readBuffer;
	char* 								_writeBuffer;
	char* 								_eventDataBuffer;
	NSMutableData* 						_cdData;
	NSMutableData* 						_eventData;
	int 								_maxPacketSizeBulkIn;
	int 								_maxPacketSizeBulkOut;
	int 								_maxPacketSizeInterruptIn;
	CFRunLoopSourceRef 					_CFRunLoopSource;
	BOOL 								_delegateNeedsData;
	BOOL 								_connected;
	unsigned long 						_transactionID;
	opaque_pthread_t* 					_timerThread;
	BOOL 								_callbackThreadIsReady;
	BOOL 								_sendEvents;
	unsigned long 						_numberOfSendEventsTimedOut;
}
-(void*)timerThreadEntryPoint;
-(void)cleanupTimerThread;
-(void)cleanupCallbackThread;
-(int)handleDeviceRequest:(XXStruct_NUaWfC*)request data:(IOUSBDeviceDataRef*)data dataSize:(unsigned*)size status:(int*)status;
-(int)setupDeviceInterface;
-(void)deviceAdded:(unsigned)added;
-(void)handleInterruptData:(unsigned long)data;
-(BOOL)handleBulkData:(unsigned long)data result:(int)result;
-(void)dumpData:(void*)data length:(int)length comment:(id)comment;
-(int)readInterruptData;
-(int)readBulkData;
-(BOOL)sendNextEvent;
-(void)abortInterruptWrite:(id)write;
-(void)checkInterruptWriteCompletion:(id)completion;
-(void)handleWriteInterruptDataCompletion:(id)completion;
-(BOOL)writeInterruptData:(id)data;
-(BOOL)writeBulkData:(id)data;
-(void)abortPendingIO;
-(unsigned short)deviceStatus;
-(void)cancelTransaction:(id)transaction;
-(BOOL)sendEvent:(id)event;
-(BOOL)sendResponse:(id)response;
-(void)sendData:(id)data;
-(void)sendDataPacketsSplit:(id)split;
-(void)sendDataPackets:(id)packets;
-(BOOL)sendRequest:(id)request needsData:(BOOL)data;
-(BOOL)sendCancel:(id)cancel;
-(id)description;
-(void)setActivationTimeout:(int)timeout;
-(void)activationTimeoutOccurred;
-(void)deactivate;
-(void)activate:(BOOL)activate;
-(void)setConnected:(BOOL)connected;
-(BOOL)connected;
-(void)stop;
-(BOOL)startResponder;
-(id)usbSerialNumberString;
-(unsigned short)productID;
-(unsigned short)vendorID;
-(unsigned long)locationID;
-(void)dealloc;
-(id)initWithDelegate:(id)delegate;
@end

