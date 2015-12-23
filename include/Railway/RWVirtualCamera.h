#ifndef __RAILWAY_VIRTUAL_CAMERA_H__
#define __RAILWAY_VIRTUAL_CAMERA_H__

#include <PTPD/PTPD.h>
#include <Railway/RWGlobals.h>

typedef	void		 ( *pOrig_fill_storage_cache )( PTPVirtualCamera *, SEL );

void RWVirtualCameraAttach();
void RWVirtualCameraDetach();

#endif /* __RAILWAY_VIRTUAL_CAMERA_H__ end */