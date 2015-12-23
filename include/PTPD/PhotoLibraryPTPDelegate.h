#import <Foundation/NSObject.h>

@protocol PhotoLibraryPTPDelegate
-(void)addedPhotoKeys:(id)keys deletedPhotoKeys:(id)keys2 changedPhotoKeys:(id)keys3 changePendingPhotoKeys:(id)keys4;
@optional
-(void)libraryDidBecomeUnavailable;
-(void)libraryDidBecomeAvailable;
@end

