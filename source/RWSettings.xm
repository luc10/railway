#include <Railway/RWSettings.h>
#include <Railway/RWConfig.h>

RWSettings::RWSettings()
{
	this->settings = RWReadPList( SETTINGS_PLIST_PATH );	
	
	this->enabled			= [[this->settings objectForKey:@"RWEnabled"] boolValue];
	this->show_library	= [[this->settings objectForKey:@"RWITunesLibrary"] boolValue];
	this->show_recordings	= [[this->settings objectForKey:@"RWRecordings"] boolValue];
	this->show_downloads	= [[this->settings objectForKey:@"RWDownloads"] boolValue];
	this->registered		= [[this->settings objectForKey:@"RWRegistered"] boolValue];
	
	this->license			= NULL;
	this->license_length	= 0;

#if ( !RAILWAY_DEBUG )
	this->get_license();
	this->decrypt_license();
#endif

}

void
RWSettings::get_license()
{
	NSString		*enc;
	
	if ( this->registered )
	{
		this->license 		= ( unsigned char * )[[this->settings objectForKey:@"RWLicense"] bytes];
		this->license_length	= [[this->settings objectForKey:@"RWLicense"] length];
	}
	else
	{
		if ( ( enc = [[RWNotificationClient sharedCenter] requestLicenseData] ) != nil )
		{
			RWBase64Decode( NULL, 
						  &this->license_length, 
						  ( unsigned char * )[enc UTF8String], 
						  [enc length] );
			
			if ( this->license_length > 0 )
			{
				this->license = new unsigned char[this->license_length];
				RWBase64Decode( this->license, 
							  &this->license_length, 
							  ( unsigned char * )[enc UTF8String], 
							  [enc length] );
			}
		}
	}
}

BOOL
RWSettings::get_key()
{
	md2_ctx		md2;
	const char	*udid;
	
	if ( ( udid = RWGetDeviceIdentifier() ) != NULL )
	{
		RWMD2Starts( &md2 );
		RWMD2Update( &md2, 
				   ( unsigned char * )&RWMarkStart, 
				   ( unsigned int )&RWMarkEnd - ( unsigned int )&RWMarkStart );
		RWMD2Update( &md2, 
				    ( const unsigned char * )udid, 
					strlen( udid ) );
		RWMD2Finish( &md2, this->license_key );
		RWMD2Free( &md2 );
		
		return ( true );
	}
	
	return ( false );
}

void
RWSettings::decrypt_license()
{
	blowfish_ctx		blowfish;
	NSArray			*content;
	
	if ( this->license != NULL && this->license_length > 0 )
	{
		if ( this->get_key() )
		{
			RWBlowfishSetKey( &blowfish, this->license_key );
			RWBlowfishDecryptBuffer( &blowfish,
								  this->license_length,
								  this->license,
								  this->license );
			RWBlowfishFree( &blowfish );
			
			if ( this->license != NULL )
			{
				content = [[NSString stringWithUTF8String:( const char * )this->license]
						componentsSeparatedByCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
				
				if ( content != nil )
				{
					this->ptp_virtual_camera = [[content objectAtIndex:0] UTF8String];
					this->fill_storage_cache = [[content objectAtIndex:1] UTF8String];
					this->ptp_responder	  = [[content objectAtIndex:2] UTF8String];
					this->handle_request	  = [[content objectAtIndex:3] UTF8String];
					this->handle_data	      = [[content objectAtIndex:4] UTF8String];
					this->ptp_transport	  = [[content objectAtIndex:5] UTF8String];
					this->handle_bulk_data	  = [[content objectAtIndex:6] UTF8String];
					this->delete_object	  = [[content objectAtIndex:7] UTF8String];
				}
			}
			
		}
	}
}

RWSettings::~RWSettings()
{
	this->license 			= NULL;
	this->ptp_virtual_camera 	= NULL;
	this->fill_storage_cache 	= NULL;
	this->ptp_responder	  	= NULL;
	this->handle_request	  	= NULL;
	this->handle_data	      	= NULL;
	this->ptp_transport	  	= NULL;
	this->handle_bulk_data	  	= NULL;
	this->delete_object		= NULL;
	
	[this->settings release];
}