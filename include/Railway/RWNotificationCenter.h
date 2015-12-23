#ifndef __RAILWAY_NOTIFICATIONCENTER_H__
#define __RAILWAY_NOTIFICATIONCENTER_H__

#include <Railway/Utils/RWUIDevice.h>
#import  <AppSupport/CPDistributedMessagingCenter.h>

#include <fts.h>
#include <sys/stat.h>
#include <sys/types.h>

// Nome del centro dei messaggi
#define		NOTIFICATION_CENTER_NAME				@"com.luciano.railway.center"
#define		REMOTE_LICENSE_HOST					@"http://162.208.11.97"

@interface RWNotificationCenter: NSObject
{
	CPDistributedMessagingCenter *center;
}

-( RWNotificationCenter * )init;
-( NSDictionary * )requestLicenseData:( NSString * )name withInfo:( NSDictionary * )info;
-( void )setAsLicensed:( NSString * )license;

@end

@interface RWNotificationClient: NSObject
{
	CPDistributedMessagingCenter *center;
}

-( RWNotificationClient * )init;
+( RWNotificationClient * )sharedCenter;
-( NSString * )requestLicenseData;

@end

#endif /* __RAILWAY_NOTIFICATIONCENTER_H__ end */