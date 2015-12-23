#ifndef __RAILWAY_FOLDER_H__
#define __RAILWAY_FOLDER_H__

#include <Railway/RWContainer.h>
#include <Railway/RWFile.h>
#include <Railway/Utils/RWString.h>
#include <Railway/Runtime/RWClasses.h>

#define		FOLDER_MEDIA_PATH		"/private/var/mobile/Media"

class RWFolder: public RWContainer
{
	public:
	
		const char	*name;
		
		RWFolder();
		RWFolder( Container * );
		RWFolder( const char * );
		RWFolder( PTPObjectInfoDataset *, RWContainer * );
		
		void			add( RWFile * );
		void			add( RWFolder * );
		
		Folder *		get();
		virtual void	scan();
				
};

#endif