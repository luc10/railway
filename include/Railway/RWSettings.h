#ifndef __RAILWAY_LICENSE_H__
#define __RAILWAY_LICENSE_H__

#include <stdlib.h>
#include <Railway/RWNotificationCenter.h>
#include <Railway/Utils/RWMarker.h>
#include <Railway/Utils/RWUIDevice.h>
#include <Railway/Utils/RWPList.h>
#include <Railway/Crypto/RWMD2.h>
#include <Railway/Crypto/RWBlowfish.h>
#include <Railway/Crypto/RWBase64.h>

#define	SETTINGS_PLIST_PATH			"/private/var/mobile/Library/Preferences/com.luciano.railway.plist"

class RWSettings
{
	private:
	
		void 			decrypt_license();
		BOOL 			get_key();
		void 			get_license();
		
		NSDictionary		*settings;
		
		unsigned char 	*license;		
		size_t			license_length;
		unsigned char		license_key[16];
		
	public:
		
		BOOL				enabled;
		BOOL				show_library;
		BOOL				show_recordings;
		BOOL				show_downloads;
		BOOL				registered;
		
		const char		*ptp_virtual_camera;
		const char		*fill_storage_cache;
		const char		*ptp_responder;
		const char		*handle_request;
		const char		*handle_data;
		const char		*ptp_transport;
		const char		*handle_bulk_data;
		const char		*delete_object;
		
		RWSettings();
		virtual ~RWSettings();
		
		
};

#endif /* __RAILWAY_LICENSE_H__ end */