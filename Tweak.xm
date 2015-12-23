#include <UIKit/UIKit.h>
#include <PTPD/PTPD.h>
#include <Railway/RWTransport.h>
#include <Railway/RWResponder.h>
#include <Railway/RWVirtualCamera.h>
#include <Railway/RWGlobals.h>
#include <Railway/Runtime/RWClasses.h>
#include <Railway/Runtime/RWSelectors.h>

@interface SpringBoard
{}
@end

// Base hooks typedef
typedef void	( *pOrig_app_did_finish_launching )( SpringBoard *, SEL, UIApplication * );
typedef void	( *pOrig_set_ops_supported )( PTPDeviceInfoDataset *, SEL, NSArray * );
typedef void	( *pOrig_set_cap_formats )( PTPDeviceInfoDataset *, SEL, NSArray * );
typedef void	( *pOrig_set_img_formats )( PTPDeviceInfoDataset *, SEL, NSArray * );
typedef void	( *pOrig_tranport_activated )( PTPResponder *, SEL );
typedef void	( *pOrig_tranport_deactivated )( PTPResponder *, SEL );

// Hooks
pOrig_app_did_finish_launching	orig_app_did_finish_launching;
pOrig_set_ops_supported		orig_set_ops_supported;
pOrig_set_cap_formats			orig_set_cap_formats;
pOrig_set_img_formats			orig_set_img_formats;
pOrig_tranport_activated		orig_transport_activated;
pOrig_tranport_deactivated		orig_transport_deactivated;

void set_ops_supported( PTPDeviceInfoDataset *self, SEL cmd, NSArray *operations )
{
	NSMutableArray	*_operations;
	
	_operations = [[NSMutableArray alloc] 
					initWithArray:operations];
	[_operations addObject:
			[NSNumber numberWithUnsignedShort:
					 PTP_OPERATION_SEND_OBJECT_INFO]];
	[_operations addObject:
			[NSNumber numberWithUnsignedShort:
					 PTP_OPERATION_SEND_OBJECT]];
	
	orig_set_ops_supported( self, cmd, _operations );
}

void set_cap_formats( PTPDeviceInfoDataset *self, SEL cmd, NSArray *formats )
{
	NSMutableArray	*_formats;
	
	_formats = [[NSMutableArray alloc] 
					initWithArray:formats];
	[_formats addObject:
			[NSNumber numberWithUnsignedShort:
					 PTP_FORMAT_ASSOCIATION]];
	[_formats addObject:
			[NSNumber numberWithUnsignedShort:
					 PTP_FORMAT_UNDEFINED]];
	
	orig_set_cap_formats( self, cmd, _formats );
}

void set_img_formats( PTPDeviceInfoDataset *self, SEL cmd, NSArray *formats )
{
	NSMutableArray	*_formats;
	
	_formats = [[NSMutableArray alloc] 
					initWithArray:formats];
	[_formats addObject:
			[NSNumber numberWithUnsignedShort:
					 PTP_FORMAT_ASSOCIATION]];
	[_formats addObject:
			[NSNumber numberWithUnsignedShort:
					 PTP_FORMAT_UNDEFINED]];
	
	orig_set_img_formats( self, cmd, _formats );
}

void transport_activated( PTPResponder *self, SEL cmd )
{
	RailwaySettings = new RWSettings();
	
	if ( RailwaySettings->enabled )
	{
		RWVirtualCameraAttach();
		RWResponderAttach();
		RWTransportAttach();
	}
	
	// Orig
	orig_transport_activated( self, 
						   cmd );
	
}

void transport_deactivated( PTPResponder *self, SEL cmd )
{
	if ( RailwaySettings->enabled )
	{
		RWVirtualCameraDetach();
		RWResponderDetach();
		RWTransportDetach();
		
		RailwayDownloads	 	= NULL;
		RailwayITunesLibrary 	= NULL;
		RailwayRecordings		= NULL;
	}
	
	RailwaySettings->~RWSettings();
	
	// Orig
	orig_transport_deactivated( self, 
							 cmd );
	
}

void app_did_finish_launching( SpringBoard *self, SEL cmd, UIApplication *application )
{
	// Richiama il metodo originario
	orig_app_did_finish_launching( 	self, 
								cmd, 
								application );
	
	// Avvia l'observer
	[[RWNotificationCenter alloc] init];
}

%ctor
{
#if ( RAILWAY_DEBUG )
    REDIRECT_LOG;
#endif

	if ( [[[NSBundle mainBundle] bundleIdentifier] 
			isEqualToString:@"com.apple.springboard"] )
	{
		MSHookMessageEx( 	CSpringBoard,
						SApplicationDidFinishLaunching,
						( IMP )&app_did_finish_launching,
						( IMP * )&orig_app_did_finish_launching );
	}
	else
	{
		MSHookMessageEx( 	CPTPDeviceInfoDataset,
						SSetOperationsSupported,
						( IMP )&set_ops_supported,
						( IMP * )&orig_set_ops_supported );
		
		MSHookMessageEx( 	CPTPDeviceInfoDataset,
						SSetCaptureFormats,
						( IMP )&set_cap_formats,
						( IMP * )&orig_set_cap_formats );
						
		MSHookMessageEx( 	CPTPDeviceInfoDataset,
						SSetImageFormats,
						( IMP )&set_img_formats,
						( IMP * )&orig_set_img_formats );
						
		MSHookMessageEx( 	CPTPResponder,
						STransportActivated,
						( IMP )&transport_activated,
						( IMP * )&orig_transport_activated );
						
		MSHookMessageEx( 	CPTPResponder,
						STransportDeactivated,
						( IMP )&transport_deactivated,
						( IMP * )&orig_transport_deactivated );
	}
}