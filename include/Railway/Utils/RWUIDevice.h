#ifndef __RAILWAY_UIDEVICE_H__
#define __RAILWAY_UIDEVICE_H__

#include <stdlib.h>
#include <dlfcn.h>
#include <sys/types.h>

#define 		SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define 		SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define 		SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define 		SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define 		SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define 		SYSTEM_VERSION_4		@"4.0"
#define 		SYSTEM_VERSION_5		@"5.0"
#define 		SYSTEM_VERSION_6		@"6.0"
#define 		SYSTEM_VERSION_7		@"7.0"

#define		LIB_MOBILE_GESTALT	"/usr/lib/libMobileGestalt.dylib"
#define		MG_COPY_ANSWER		"MGCopyAnswer"
#define		UNIQUE_DEVICE_ID		"UniqueDeviceID"
#define		CORE_FOUNDATION_IOS7	800

const char *	RWGetDeviceIdentifier();

#endif /* __RAILWAY_IOSVERSION_H__ end */