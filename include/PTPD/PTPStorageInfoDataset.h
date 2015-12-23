#import <Foundation/NSObject.h>

@interface PTPStorageInfoDataset : NSObject 
{
    unsigned short 		_storageType;
    unsigned short 		_filesystemType;
    unsigned short 		_accessCapability;
    unsigned long long 	_maxCapacity;
    unsigned long long 	_freeSpaceInBytes;
    unsigned long 		_freeSpaceInImages;
    NSString 			*_storageDescription;
    NSString 			*_volumeLabel;
    NSMutableData 		*_content;
    BOOL 				_dirty;
    BOOL 				_readOnlyObject;
}

- (void)setVolumeLabel:(id)arg1;
- (id)volumeLabel;
- (void)setStorageDescription:(id)arg1;
- (id)storageDescription;
- (void)setFreeSpaceInImages:(unsigned long)arg1;
- (unsigned long)freeSpaceInImages;
- (void)setFreeSpaceInBytes:(unsigned long long)arg1;
- (unsigned long long)freeSpaceInBytes;
- (void)setMaxCapacity:(unsigned long long)arg1;
- (unsigned long long)maxCapacity;
- (void)setAccessCapability:(unsigned short)arg1;
- (unsigned short)accessCapability;
- (void)setFilesystemType:(unsigned short)arg1;
- (unsigned short)filesystemType;
- (void)setStorageType:(unsigned short)arg1;
- (unsigned short)storageType;
- (id)description;
- (id)content;
- (void)updateContent;
- (void)dealloc;
- (id)initWithMutableData:(id)arg1;
- (id)initWithData:(id)arg1;
- (void)setContent:(id)arg1;
- (id)init;

@end