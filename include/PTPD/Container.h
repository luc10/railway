#import <Foundation/NSObject.h>

@interface Container : NSObject
{
	NSString* 				_path;
	unsigned long long 		_serialNumber;
	timespec 				_captureTimeSpec;
	long long 				_size;
	id 						_parent;
	NSMutableDictionary* 	_files;
	NSMutableIndexSet* 		_fileIndices;
	NSMutableDictionary* 	_folders;
	NSMutableIndexSet* 		_folderIndices;
	unsigned long 			_storageID;
	unsigned long 			_objectHandle;
}
-(void)dealloc;
-(void)appendObjectInfo64:(id)a64 forObjectFormatCode:(unsigned short)objectFormatCode inAssociation:(unsigned long)association;
-(void)appendObjectInfo:(id)info forObjectFormatCode:(unsigned short)objectFormatCode inAssociation:(unsigned long)association;
-(unsigned long)appendObjectFilesystemInfo:(id)info forObjectFormatCode:(unsigned short)objectFormatCode inAssociation:(unsigned long)association;
-(id)folderObjectHandleMatchingName:(id)name serialNumber:(unsigned long long)number captureTimeSpec:(timespec*)spec andSize:(long long)size;
-(id)fileObjectHandleMatchingName:(id)name serialNumber:(unsigned long long)number captureTimeSpec:(timespec*)spec andSize:(long long)size;
-(id)foldeMatchingName:(id)name;
-(id)fileMatchingName:(id)name;
-(void)deleteFolder:(id)folder;
-(void)deleteFile:(id)file;
-(void)addContent;
-(id)objectForObjectHandle:(id)objectHandle;
-(id)objectHandlesForFiles;
-(id)objectHandlesForFolders;
-(BOOL)largeFileEnumeration;
-(id)objectHandlesForObjectFormatCode:(unsigned short)objectFormatCode inAssociation:(unsigned long)association;
-(id)initWithObjectHandle:(unsigned long)objectHandle path:(id)path andParent:(id)parent;
@end

