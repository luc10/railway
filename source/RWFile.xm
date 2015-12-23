#include <Railway/RWFile.h>

RWFile::RWFile()
{
	this->name				= NULL;
	this->path				= NULL;
	this->size				= 0;
	this->serial				= 0;
	this->object_handle		= 0;
	this->descriptor			= 0;
	this->capture_time		= time( NULL );
	this->modification_time	= time( NULL );
	this->object				= NULL;
	this->parent				= NULL;
	this->dataset				= NULL;
	this->photo_key			= NULL;
}

RWFile::RWFile( const char *path )
{
	struct stat	statbuf;
	
	if ( stat( path, &statbuf ) == 0 )
	{
		this->name				= strdup( ( const char * )basename( ( char * )path ) );
		this->path				= strdup( ( const char * )dirname( ( char * )path ) );
		this->capture_time		= statbuf.st_ctime;
		this->modification_time	= statbuf.st_mtime;
		this->size				= statbuf.st_size;
		this->serial				= statbuf.st_ino;
		this->object_handle		= 0;
		this->descriptor			= 0;
		this->object				= NULL;
		this->parent				= NULL;
		this->dataset				= NULL;
		this->photo_key			= NULL;
	}
}

RWFile::RWFile( File *object )
{
	this->name				= [ivar_basename( object ) UTF8String];
	this->path 				= [ivar_path( object ) UTF8String];
	this->size				= ivar_size( object );
	this->capture_time		= time( NULL );
	this->modification_time	= time( NULL );
	this->serial				= ivar_serial_number( object );
	this->dataset				= ivar_object_info_dataset( object );
	this->photo_key			= ivar_photo_key( object );
	this->parent				= ivar_parent( object );
	this->object_handle		= ivar_object_handle( object );
	this->object				= object;
	this->descriptor			= 0;
}

RWFile::RWFile( PTPObjectInfoDataset *dataset, RWContainer *parent )
{	
	this->name				= [[dataset filename] UTF8String];
	this->path				= strdup( parent->path );
	this->size				= [dataset objectCompressedSize];
	this->capture_time		= time( NULL );
	this->modification_time	= time( NULL );
	this->object_handle		= 0;
	this->photo_key			= NULL;
	this->parent				= NULL;
	this->object				= NULL;
	this->descriptor			= open( 	RWGeneratePath( this->path, this->name, NULL ), 
									O_RDWR | O_CREAT | O_TRUNC, 
									S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH );
}

int32_t
RWFile::write( const void *buffer, size_t length )
{
	if ( this->descriptor > 0 )
		return ( ::write( this->descriptor, buffer, length ) );
	else
		return ( -1 );
}

void
RWFile::close()
{
	if ( this->descriptor > 0 )
	{
		::close( this->descriptor );
		this->descriptor = 0;
	}
}

void
RWFile::set_name( const char *name )
{
	this->name = strdup( name );
	
	if ( this->object )
	{
		ivar_basename( this->object ) = [[NSString stringWithUTF8String:name] retain];
		[this->dataset setFilename:[ivar_basename( this->object ) copy]];
	}
}

File *
RWFile::get()
{
	if ( this->object == NULL )
	{
		if ( this->path == NULL )
		{
			this->object = [[CFile alloc]
							initWithName:[[NSString stringWithUTF8String:this->name] retain]
							serialNumber:this->serial
							captureTimeSpec:RWTimeToTimeSpec( this->capture_time )
							size:this->size
							andParent:this->parent];
		}
		else
		{
			this->object = 
				[[CFile alloc]
					initWithDictionary:
						[[NSDictionary alloc] 
						initWithObjectsAndKeys:
						[NSString stringWithUTF8String:this->name],							@"kPTPFilename",
						[NSString stringWithUTF8String:this->path], 							@"kPTPFullDirectoryPath",
						[NSNumber numberWithLongLong:size], 								@"kPTPObjectCompressedSize",
						[NSString stringWithUTF8String:RWTimeToString( capture_time )], 		@"kPTPCaptureDate",
						[NSString stringWithUTF8String:RWTimeToString( modification_time)], 	@"kPTPModificationDate",
						[NSNumber numberWithUnsignedLong:image_pix_size], 					@"kPTPImagePixSize",
						[NSNumber numberWithUnsignedLong:thumb_compressed_size],				@"kPTPThumbCompressedSize",
						this->photo_key, 													@"kPTPPhotoKey",
						nil]
					andParent:
						this->parent];
		}
		
		this->object_handle	= ivar_object_handle( this->object );
		this->dataset			= ivar_object_info_dataset( this->object );
	}
	
	return ( this->object );
}

