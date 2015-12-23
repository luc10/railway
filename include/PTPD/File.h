#import <Foundation/NSObject.h>
#import "PTPObjectInfoDataset.h"

@interface File : NSObject 
{
	unsigned long 			_storageID;
	unsigned long 			_objectHandle;
	NSString* 				_path;
	unsigned long long 		_serialNumber;
	timespec 				_captureTimeSpec;
	long long 				_size;
	id 						_parent;
	PTPObjectInfoDataset* 	_objectInfoDataset;
	NSString* 				_baseName;
	NSObject* 				_plPhotoKey;
	NSString* 				_thumbFileExtension;
}
-(void)dealloc;
-(id)metadata;
-(BOOL)getThmFilePath:(id*)path andFileSize:(long long*)size;
-(id)objectInfoDataset;
-(id)initWithDictionary:(id)dictionary andParent:(id)parent;
-(id)initWithName:(id)name serialNumber:(unsigned long long)number captureTimeSpec:(timespec*)spec size:(long long)size andParent:(id)parent;
@end

