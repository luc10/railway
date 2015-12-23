#import <Preferences/Preferences.h>
#include <Railway/Utils/RWUIDevice.h>
#include <Railway/RWSettings.h>
#include <Railway/RWNotificationCenter.h>

@interface RailwayListController: PSListController 
{
}
-( void )purchaseLicense;

@end

@implementation RailwayListController

-( id )specifiers 
{
	NSMutableDictionary	*settings;
	NSNumber				*registered;
	NSString				*status;
	NSString				*status_footer;
	NSNumber				*enabled;

	if( _specifiers == nil ) 
	{
		_specifiers = [[self loadSpecifiersFromPlistName:@"Railway" target:self] retain];
	}
	
	// Carica le impostazioni
	settings 		= RWReadPList( SETTINGS_PLIST_PATH );
	status			= @"Purchase";
	status_footer		= @"After purchasing a license please respring and keep alive internet connection while plugging in the device.";
	enabled			= [NSNumber numberWithBool:YES];
	
	if ( ( registered = [settings objectForKey:@"RWRegistered"] ) != nil )
	{
		if ( [registered boolValue] == true )
		{
			status 		= @"Registered";
			status_footer	= @"";
			enabled		= [NSNumber numberWithBool:NO];
		}
	}
	
	for ( PSSpecifier *specifier in _specifiers )
	{
		if ( [[specifier name] isEqualToString:@"Status"] )
			[[specifier properties] 
					setObject:status_footer
					forKey:@"footerText"];
		
		if ( [[specifier name] isEqualToString:@"Purchase"] )
		{
			specifier.name = status;
			[[specifier properties] 
					setObject:status
					forKey:@"label"];
			[[specifier properties] 
					setObject:enabled
					forKey:@"enabled"];
		}			
				
	}
	
	return _specifiers;
}

-( void )purchaseLicense
{
	NSString		*url;
	
	url = [NSString stringWithFormat:@"%@/purchase.php?udid=%s&version=1.1.0", 
					REMOTE_LICENSE_HOST,
					RWGetDeviceIdentifier()];
					
	[[UIApplication sharedApplication] 
		openURL:[NSURL URLWithString:url]];
}

@end

// vim:ft=objc
