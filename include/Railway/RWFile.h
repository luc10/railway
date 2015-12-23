#ifndef __RAILWAY_FILE_H__
#define __RAILWAY_FILE_H__

#include <stdlib.h>
#include <fts.h>
#include <time.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <PTPD/PTPD.h>
#include <Railway/RWConfig.h>
#include <Railway/RWContainer.h>
#include <Railway/Utils/RWTime.h>
#include <Railway/Utils/RWString.h>

#include <Railway/Runtime/RWIVars.h>
#include <Railway/Runtime/RWClasses.h>

class RWFile
{		
	
	public:
				
		const char			*name;
		const char			*path;
		time_t				capture_time;
		time_t				modification_time;
		int64_t				size;
		uint64_t				serial;
		uint32_t				image_pix_size;
		uint32_t				thumb_compressed_size;
		uint32_t				object_handle;
		NSObject				*photo_key;
		Container			*parent;
		File					*object;
		PTPObjectInfoDataset	*dataset;
		int					descriptor;
		short				file_format;
		
		RWFile();
		RWFile( File * );
		RWFile( const char * );
		RWFile( PTPObjectInfoDataset *, RWContainer * );
		
		File *		get();
		void			set_name( const char * );
		
		int32_t		write( const void *, size_t );
		void			close();
};

#endif /* __RAILWAY_FILE_H__ end */