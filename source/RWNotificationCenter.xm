#include <Railway/RWNotificationCenter.h>
#include <Railway/RWSettings.h>
#include <Railway/Utils/RWPList.h>
#include <Railway/Crypto/RWBase64.h>

@implementation RWNotificationCenter

-( RWNotificationCenter * )init
{
	if ( ( self = [super init] ) )
	{
		center =	[[CPDistributedMessagingCenter 
				  centerNamed:NOTIFICATION_CENTER_NAME] retain];
		
		[center 	registerForMessageName:@"requestLicenseData"
				target:self
				selector:@selector(requestLicenseData:withInfo:)];
		
		[center runServerOnCurrentThread];
	}
	
	return ( self );
}

-( void )dealloc
{
	[super dealloc];
}

-( NSDictionary * )requestLicenseData:( NSString* )name 
						withInfo:( NSDictionary * )info
{
	const char 			*udid;
	NSString				*params;
	NSString				*license;
	NSData				*data;
	NSHTTPURLResponse 	*response;
	NSDictionary			*headers;
	NSMutableURLRequest	*request;
	NSString				*message;
	UIAlertView 			*alert_view;
	
	if ( ( udid = RWGetDeviceIdentifier() ) != NULL )
	{
		request 	= [NSMutableURLRequest requestWithURL:
						[NSURL URLWithString:
						[NSString stringWithFormat:@"%@/index.php", REMOTE_LICENSE_HOST]]];
		params	= [NSString stringWithFormat:@"udid=%s&version=1.1.0", udid];
		data		= [params dataUsingEncoding:NSUTF8StringEncoding];
		
		[request setHTTPMethod:@"POST"];
		
		[request addValue:@"8bit" 
				forHTTPHeaderField:@"Content-Transfer-Encoding"];
		[request addValue:@"application/x-www-form-urlencoded" 
				forHTTPHeaderField:@"Content-Type"];
		[request addValue:[NSString stringWithFormat:@"%d", [data length]] 
				forHTTPHeaderField:@"Content-Length"];
		[request setHTTPBody:data];
		
		[NSURLConnection sendSynchronousRequest:request
                       returningResponse:&response
                       error:nil];
	}
	
	if ( response != nil )
	{
		headers = [response allHeaderFields];
		
		if ( ( message = [headers objectForKey:@"X-Message"] ) != nil )
		{
			alert_view =
			[[UIAlertView alloc] initWithTitle:@"Railway" 
									message:message
								   delegate:nil 
						   cancelButtonTitle:nil 
						   otherButtonTitles:@"OK", nil];
						   
			[alert_view show];
			[alert_view release];
		}
		
		if ( ( license = [headers objectForKey:@"X-License"] ) != nil )
			[self setAsLicensed:license];
			
		return ( [[NSDictionary alloc] initWithObjectsAndKeys:
								license, @"license",
								nil] );
	}
	else
	{
		return ( nil );
	}
	
}

-( void )setAsLicensed:( NSString * )license
{
	NSMutableDictionary	*plist;
	unsigned char			*data;
	size_t				length;
	
	plist = RWReadPList( SETTINGS_PLIST_PATH );
	[plist 	setObject:[NSNumber numberWithBool:YES]
			forKey:@"RWRegistered"];
	
	RWBase64Decode( NULL,
				  &length,
				  ( const unsigned char * )[license UTF8String],
				  [license length] );
	
	data = new unsigned char[length];
	
	RWBase64Decode( data,
				  &length,
				  ( const unsigned char * )[license UTF8String],
				  [license length] );
	
	[plist 	setObject:[[NSData alloc] 
						initWithBytes:data
						length:length]
			forKey:@"RWLicense"];
	
	RWWritePList( plist, SETTINGS_PLIST_PATH );

}

@end

@implementation RWNotificationClient

+( RWNotificationClient * )sharedCenter
{
	static RWNotificationClient *shared = nil;
	if ( shared == nil )
		shared = [[self alloc] init];
	
	return shared;
}

-( RWNotificationClient * )init
{
	if ( ( self = [super init] ) )
	{
		center = [CPDistributedMessagingCenter centerNamed:NOTIFICATION_CENTER_NAME];
	}
	
	return self;
}

-( NSString * )requestLicenseData
{
	return [[center 	sendMessageAndReceiveReplyName:@"requestLicenseData"
					userInfo:nil] objectForKey:@"license"];
}

@end

