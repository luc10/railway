#include <Railway/Utils/RWUIDevice.h>

const char *
RWGetDeviceIdentifier()
{
	void			*gestalt;
	NSString		*udid;
	
	CFStringRef  ( *MGCopyAnswer )( CFStringRef );
	
	if ( kCFCoreFoundationVersionNumber < CORE_FOUNDATION_IOS7 )
	{
		udid = [[UIDevice currentDevice] uniqueIdentifier];
	}
	else
	{
		gestalt 		= dlopen( LIB_MOBILE_GESTALT, RTLD_LAZY );
		
		if ( gestalt )
		{
			MGCopyAnswer 	= reinterpret_cast<CFStringRef ( * )( CFStringRef )>
						( dlsym( gestalt, MG_COPY_ANSWER ) );
						
			udid 		= ( NSString * )MGCopyAnswer( CFSTR( UNIQUE_DEVICE_ID ) );
			
			dlclose( gestalt );
		}
		else
		{
			udid = NULL;
		}
	}
	
	return ( [udid UTF8String] );
}