#ifndef __RAILWAY_CONTAINER_H__
#define __RAILWAY_CONTAINER_H__

#include <stdlib.h>
#include <fts.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#include <PTPD/PTPD.h>
#include <Railway/Utils/RWTime.h>
#include <Railway/Runtime/RWIVars.h>
#include <Railway/Runtime/RWClasses.h>

class RWContainer
{
	public:
		
		int64_t				size;
		uint64_t				serial;
		uint32_t				object_handle;
		time_t				capture_time;
		const char			*path;
		id					parent;
		id					object;
		
		NSMutableDictionary	*folders;
		NSMutableIndexSet		*folder_indices;
		NSMutableDictionary	*files;
		NSMutableIndexSet		*file_indices;
			
		RWContainer();
		RWContainer( Container * );
		
		void		set_path( const char * );
};

#endif /* __RAILWAY_CONTAINER_H__ end */