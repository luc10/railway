#import <Foundation/NSObject.h>
#import <PTPD/PTPDeviceInfoDataset.h>

@interface PTPVirtualCamera : NSObject 
{
	NSString* 				_name;
	NSString* 				_userAssignedName;
	NSString* 				_path;
	PTPDeviceInfoDataset* 	_deviceInfoDataset;
	NSMutableDictionary* 	_storages;
	int 					_lastError;
	unsigned char 			_eventData[24];
	id 						_delegate;
	CFNotificationCenterRef _notificationCenter;
	BOOL 					_notificationObserversInstalled;
	NSString* 				_productType;
	NSMutableArray* 		_objectDescriptionDataset;
	BOOL 					_largeFileEnumeration;
}
-(id)objectPropListForHandle:(unsigned long)handle withObjectFormatCode:(unsigned long)objectFormatCode andPropertyCode:(unsigned long)code andPropertyGroup:(unsigned long)group andDepth:(unsigned long)depth responseCode:(unsigned short*)code6;
-(id)objectPropDescForObjectPropertyCode:(unsigned short)objectPropertyCode responseCode:(unsigned short*)code;
-(id)objectPropValueForHandle:(unsigned long)handle withObjectPropertyCode:(unsigned short)objectPropertyCode responseCode:(unsigned short*)code;
-(id)objectPropertiesSupportedForObjectFormatCode:(unsigned short)objectFormatCode responseCode:(unsigned short*)code;
-(void)libraryDidBecomeUnavailable;
-(void)handleLibraryDidBecomeUnavailable:(id)handleLibrary;
-(void)libraryDidBecomeAvailable;
-(void)addedPhotoKeys:(id)keys deletedPhotoKeys:(id)keys2 changedPhotoKeys:(id)keys3 changePendingPhotoKeys:(id)keys4;
-(void)processDeletedFiles:(id)files;
-(void)processAddedFiles:(id)files;
-(void)generatePTPEventsForDeletedObjectHandles:(id)deletedObjectHandles;
-(void)generatePTPEventsForAddedObjectHandles:(id)addedObjectHandles;
-(void)deleteObjectWithObjectHandle:(unsigned long)objectHandle responseCode:(unsigned short*)code;
-(id)thumbDataForObjectHandle:(unsigned long)objectHandle responseCode:(unsigned short*)code;
-(id)objectMetadataForObjectHandle:(unsigned long)objectHandle responseCode:(unsigned short*)code;
-(id)objectPathForObjectHandle:(unsigned long)objectHandle responseCode:(unsigned short*)code size:(unsigned*)size;
-(id)objectDataForObjectHandle:(unsigned long)objectHandle responseCode:(unsigned short*)code;
-(id)getObjectInfo64Bit:(unsigned long)bit responseCode:(unsigned short*)code;
-(id)objectInfoDatasetForObjectHandle:(unsigned long)objectHandle;
-(id)storageInfoDatasetForStorageID:(unsigned long)storageID;
-(id)devicePropValueForProperty:(unsigned short)property;
-(id)devicePropDescDatasetForProperty:(unsigned short)property;
-(id)deviceInfoDataset;
-(unsigned long)numAllObjects;
-(unsigned long)numDownloadableObjects;
-(id)objectFilesystemManifest:(unsigned long)manifest forObjectFormatCode:(unsigned short)objectFormatCode inAssociation:(unsigned long)association responseCode:(unsigned short*)code;
-(id)objectInfoForObjectsInStorage64:(unsigned long)storage64 forObjectFormatCode:(unsigned short)objectFormatCode inAssociation:(unsigned long)association responseCode:(unsigned short*)code;
-(id)objectInfoForObjectsInStorage:(unsigned long)storage forObjectFormatCode:(unsigned short)objectFormatCode inAssociation:(unsigned long)association responseCode:(unsigned short*)code;
-(id)objectHandlesInStorage:(unsigned long)storage forObjectFormatCode:(unsigned short)objectFormatCode inAssociation:(unsigned long)association responseCode:(unsigned short*)code;
-(BOOL)largeFileEnumeration;
-(void)setLargeFileEnumeration:(BOOL)enumeration;
-(id)allStorageIDs;
-(id)objectForObjectHandle:(id)objectHandle;
-(void)flushStorageCache;
-(void)fillStorageCache;
-(void)removeStorage:(id)storage;
-(void)addStorage:(id)storage;
-(void)updateUserAssignedName;
-(void)setTrustedHostAttached:(BOOL)attached;
-(BOOL)trustedHostAttached;
-(BOOL)deviceLocked;
-(void)updateDeviceLockStatus;
-(void)checkIfConnectedToPairedHost;
-(void)handleDeviceLockStatusChanged;
-(unsigned long)dummyPTPDevice;
-(id)userAssignedName;
-(id)name;
-(id)path;
-(void)setDelegate:(id)delegate;
-(void)dealloc;
-(id)initWithName:(id)name andPath:(id)path;
@end

