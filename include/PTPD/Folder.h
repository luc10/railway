#import <Foundation/NSObject.h>
#import "Container.h"
#import "PTPObjectInfoDataset.h"

@interface Folder : Container 
{
	PTPObjectInfoDataset* _objectInfoDataset;
}
-(void)dealloc;
-(void)addContent;
-(id)objectInfoDataset;
-(id)initWithName:(id)name path:(id)path captureTimeSpec:(timespec*)spec parent:(id)parent parentID:(unsigned long)anId;
-(id)initWithName:(id)name serialNumber:(unsigned long long)number captureTimeSpec:(timespec*)spec size:(long long)size parent:(id)parent parentID:(unsigned long)anId;
@end

