#ifndef __RAILWAY_STORAGE_H__
#define __RAILWAY_STORAGE_H__

#include <PTPD/PTPD.h>
#include <sys/types.h>
#include <liblockdown.h>
#include <Railway/RWFile.h>
#include <Railway/RWFolder.h>
#include <Railway/Runtime/RWIVars.h>

class RWStorage: public RWFolder
{
	public:
		RWStorage( Storage * );
		
		//void		update_mem_indicator();
};

#endif /* __RAILWAY_STORAGE_H__ end */