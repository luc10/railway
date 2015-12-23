#include <Railway/RWVirtualCamera.h>
#include <Railway/RWConfig.h>
#include <substrate.h>

static pOrig_fill_storage_cache		orig_fill_storage_cache;

void fill_storage_cache( PTPVirtualCamera *self, SEL cmd )
{
	orig_fill_storage_cache( self, cmd );
	
	RailwayStorage = new RWStorage( [ivar_storages( self ) objectForKey:
								[[self allStorageIDs] objectAtIndex:0]] );
	
	if ( RailwaySettings->show_downloads )
	{
		RailwayDownloads = new RWDownloads();
		RailwayStorage->add( RailwayDownloads );
		RailwayDownloads->scan();
	}
	
	if ( RailwaySettings->show_library )
	{
		RailwayITunesLibrary = new RWITunesLibrary();
		RailwayStorage->add( RailwayITunesLibrary );
		RailwayITunesLibrary->scan();
	}
	
	if ( RailwaySettings->show_recordings )
	{
		RailwayRecordings = new RWRecordings();
		RailwayStorage->add( RailwayRecordings );
		RailwayRecordings->scan();
	}
	
	RailwayStorage->set_path( RWGeneratePath( FOLDER_MEDIA_PATH, 
										 "Railway", 
										 NULL ) );
	RailwayStorage->scan();
	
}

void
RWVirtualCameraAttach()
{
#if ( RAILWAY_DEBUG )
	MSHookMessageEx( 	CPTPVirtualCamera,
					@selector(fillStorageCache),
					( IMP )&fill_storage_cache,
					( IMP * )&orig_fill_storage_cache );
#else
	MSHookMessageEx( 	objc_getClass( RailwaySettings->ptp_virtual_camera ),
					sel_registerName( RailwaySettings->fill_storage_cache ),
					( IMP )&fill_storage_cache,
					( IMP * )&orig_fill_storage_cache );
#endif
}

void
RWVirtualCameraDetach()
{
#if ( RAILWAY_DEBUG )
	MSHookMessageEx( 	CPTPVirtualCamera,
					@selector(fillStorageCache),
					( IMP )orig_fill_storage_cache,
					( IMP * )NULL );
#else
	MSHookMessageEx( 	objc_getClass( RailwaySettings->ptp_virtual_camera ),
					sel_registerName( RailwaySettings->fill_storage_cache ),
					( IMP )orig_fill_storage_cache,
					NULL );
#endif
}
