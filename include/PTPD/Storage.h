#import <Foundation/NSObject.h>
#import "Container.h"
#import "PTPStorageInfoDataset.h"

@interface Storage : Container 
{
	BOOL 					_largeFileEnumeration;
	PTPStorageInfoDataset	*_storageInfoDataset;
}
-(void)dealloc;
-(void)addContent;
-(id)storageInfoDataset;
-(BOOL)largeFileEnumeration;
-(void)setLargeFileEnumeration:(BOOL)enumeration;
-(id)initWithParent:(id)parent;
@end

