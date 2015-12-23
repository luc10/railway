#ifndef __RAILWAY_IVARS_H__
#define __RAILWAY_IVARS_H__

#include <objc/objc.h>
#include <objc/message.h>
#include <objc/runtime.h>

#include <Railway/RWConfig.h>

#define		get_ivar( object, name )					\
			( ( unsigned char * )( void * )object +		\
				ivar_getOffset(						\
					class_getInstanceVariable(			\
						object_getClass( object ),		\
						name ) ) )			

#if ( RAILWAY_DEBUG )

#define		ivar_path( object )			*( NSString ** )get_ivar( object, "_path" )
#define		ivar_basename( object )		*( NSString ** )get_ivar( object, "_baseName" )
#define		ivar_parent( object )			*( Container ** )get_ivar( object, "_parent" )
#define		ivar_photo_key( object )		*( NSObject ** )get_ivar( object, "_plPhotoKey" )

#define		ivar_files( object )			*( NSMutableDictionary ** )get_ivar( object, "_files" )
#define		ivar_folders( object )			*( NSMutableDictionary ** )get_ivar( object, "_folders" )

#define		ivar_file_indices( object )		*( NSMutableIndexSet ** )get_ivar( object, "_fileIndices" )
#define		ivar_folder_indices( object )	*( NSMutableIndexSet ** )get_ivar( object, "_folderIndices" )

#define		ivar_object_handle( object )	*(( uint32_t * )get_ivar( object, "_objectHandle" ))

#define		ivar_storage_id( object )		 *(( uint32_t * )get_ivar( object, "_storageID" ))
#define		ivar_serial_number( object )	 *(( uint64_t * )get_ivar( object, "_serialNumber" ))
#define		ivar_capture_time_spec( object ) *(( timespec * )get_ivar( object, "_captureTimeSpec" ))
#define		ivar_size( object )			 *(( int64_t * )get_ivar( object, "_size" ))

#define		ivar_object_info_dataset( object ) 	*( PTPObjectInfoDataset ** )get_ivar( object, "_objectInfoDataset" )

#define		ivar_read_buffer( object ) 			*( unsigned char ** )get_ivar( object, "_readBuffer" )
#define		ivar_delegate( object ) 			*( PTPResponder ** )get_ivar( object, "_delegate" )
#define		ivar_transport( object ) 			*( PTPDeviceUSBTransport ** )get_ivar( object, "_transport" )
#define		ivar_virtual_camera( object ) 		*( PTPVirtualCamera ** )get_ivar( object, "_virtualCamera" )

#define		ivar_storages( object )			*( NSDictionary ** )get_ivar( object, "_storages" )

#else

#define		ivar_path( object )			*( NSString ** )get_ivar( object, RWCrypt( ( unsigned char[8] ){ 0x46, 0x3c, 0xa9, 0xf2, 0x71, 0x4c, 0xc8, 0x86 }, 8, 0x194cc886 ) )
#define		ivar_basename( object )		*( NSString ** )get_ivar( object, RWCrypt( ( unsigned char[12] ){ 0xc3, 0xd0, 0xe3, 0x18, 0xf9, 0xfc, 0xe3, 0x06, 0xf9, 0xb2, 0x82, 0x6b }, 12, 0x9cb2826b ) )
#define		ivar_parent( object )			*( Container ** )get_ivar( object, RWCrypt( ( unsigned char[8] ){ 0x57, 0x58, 0x3f, 0x0f, 0x6d, 0x46, 0x2a, 0x7d }, 8, 0x08285e7d ) )
#define		ivar_photo_key( object )		*( NSObject ** )get_ivar( object, RWCrypt( ( unsigned char[12] ){ 0x3d, 0x3f, 0x0e, 0x76, 0x0a, 0x20, 0x16, 0x49, 0x29, 0x2a, 0x1b, 0x26 }, 12, 0x624f6226 ) )

#define		ivar_files( object )			*( NSMutableDictionary ** )get_ivar( object, RWCrypt( ( unsigned char[8] ){ 0x96, 0xdb, 0x70, 0xac, 0xac, 0xce, 0x19, 0xc0 }, 8, 0xc9bd19c0 ) )
#define		ivar_folders( object )			*( NSMutableDictionary ** )get_ivar( object, RWCrypt( ( unsigned char[12] ){ 0xc2, 0xa4, 0xff, 0x29, 0xf9, 0xa7, 0xe2, 0x36, 0x9d, 0xc2, 0x90, 0x45 }, 12, 0x9dc29045 ) )

#define		ivar_file_indices( object )		*( NSMutableIndexSet ** )get_ivar( object, RWCrypt( ( unsigned char[16] ){ 0xe5, 0x86, 0x7c, 0xbb, 0xdf, 0xa9, 0x7b, 0xb3, 0xd3, 0x83, 0x70, 0xa4, 0xba, 0xe0, 0x15, 0xd7 }, 16, 0xbae015d7 ) )
#define		ivar_folder_indices( object )	*( NSMutableIndexSet ** )get_ivar( object, RWCrypt( ( unsigned char[16] ){ 0x3e, 0x04, 0xb2, 0x5f, 0x05, 0x07, 0xaf, 0x7a, 0x0f, 0x06, 0xb4, 0x50, 0x04, 0x11, 0xdd, 0x33 }, 16, 0x6162dd33 ) )

#define		ivar_object_handle( object )	*(( uint32_t * )get_ivar( object, RWCrypt( ( unsigned char[16] ){ 0x00, 0xa1, 0xe2, 0xe2, 0x3a, 0xad, 0xf4, 0xc0, 0x3e, 0xa0, 0xe4, 0xe4, 0x3a, 0xce, 0x80, 0x88 }, 16, 0x5fce8088 ) ))

#define		ivar_storage_id( object )		 *(( uint32_t * )get_ivar( object, RWCrypt( ( unsigned char[12] ){ 0x30, 0x53, 0x56, 0x30, 0x1d, 0x41, 0x45, 0x3a, 0x26, 0x64, 0x22, 0x5f }, 12, 0x6f20225f ) ))
#define		ivar_serial_number( object )	 *(( uint64_t * )get_ivar( object, RWCrypt( ( unsigned char[16] ){ 0x31, 0xe1, 0xeb, 0xd1, 0x07, 0xf3, 0xe2, 0xed, 0x1b, 0xff, 0xec, 0xc6, 0x1c, 0x92, 0x8e, 0xa3 }, 16, 0x6e928ea3 ) ))
#define		ivar_capture_time_spec( object ) *(( timespec * )get_ivar( object, RWCrypt( ( unsigned char[20] ){ 0xec, 0xfe, 0x28, 0xb4, 0xc7, 0xe8, 0x3b, 0xa1, 0xe7, 0xf4, 0x24, 0xa1, 0xe0, 0xed, 0x2c, 0xa7, 0xb3, 0x9d, 0x49, 0xc4 }, 20, 0xb39d49c4 ) ))
#define		ivar_size( object )			 *(( int64_t * )get_ivar( object, RWCrypt( ( unsigned char[8] ){ 0x74, 0x78, 0xe3, 0x12, 0x4e, 0x0b, 0x8a, 0x68 }, 8, 0x2b0b8a68 ) ))

#define		ivar_object_info_dataset( object ) 	*( PTPObjectInfoDataset ** )get_ivar( object, RWCrypt( ( unsigned char[20] ){ 0xe3, 0xae, 0xae, 0x14, 0xd9, 0xa2, 0xb8, 0x37, 0xd2, 0xa7, 0xa3, 0x3a, 0xdd, 0xb5, 0xad, 0x0d, 0xd9, 0xb5, 0xcc, 0x7e }, 20, 0xbcc1cc7e ) )

#define		ivar_read_buffer( object ) 			*( unsigned char ** )get_ivar( object, RWCrypt( ( unsigned char[12] ){ 0x26, 0x18, 0x6e, 0x5b, 0x1d, 0x28, 0x7e, 0x5c, 0x1f, 0x0f, 0x79, 0x3a }, 12, 0x796a0b3a ) )
#define		ivar_delegate( object ) 			*( PTPResponder ** )get_ivar( object, RWCrypt( ( unsigned char[12] ){ 0x28, 0xb4, 0x0b, 0xef, 0x12, 0xb7, 0x0f, 0xf7, 0x12, 0xd0, 0x6e, 0x83 }, 12, 0x77d06e83 ) )
#define		ivar_transport( object ) 			*( PTPDeviceUSBTransport ** )get_ivar( object, RWCrypt( ( unsigned char[12] ){ 0xd0, 0xf5, 0x76, 0x91, 0xe1, 0xf2, 0x74, 0x9f, 0xfd, 0xf5, 0x04, 0xf0 }, 12, 0x8f8104f0 ) )
#define		ivar_virtual_camera( object ) 		*( PTPVirtualCamera ** )get_ivar( object, RWCrypt( ( unsigned char[16] ){ 0x5b, 0x9d, 0x88, 0x37, 0x70, 0x9e, 0x80, 0x29, 0x47, 0x8a, 0x8c, 0x20, 0x76, 0x8a, 0xe1, 0x45 }, 16, 0x04ebe145 ) )

#define		ivar_storages( object )			*( NSDictionary ** )get_ivar( object, RWCrypt( ( unsigned char[12] ){ 0x64, 0x40, 0x42, 0x93, 0x49, 0x52, 0x51, 0x99, 0x48, 0x33, 0x36, 0xfc }, 12, 0x3b3336fc ) )

#endif

#endif /* __RAILWAY_IVARS_H__ end */