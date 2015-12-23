#include <Railway/RWContainer.h>

RWContainer::RWContainer()
{
	this->path			= NULL;
	this->capture_time	= time( NULL );
	this->serial			= 0;
	this->size			= 0;
	this->object_handle	= 0xffffffff;
	this->files			= NULL;
	this->folders			= NULL;
	this->file_indices	= NULL;
	this->folder_indices	= NULL;
	this->object			= NULL;
	this->parent			= NULL;
}

RWContainer::RWContainer( Container *object )
{
	this->path			= [ivar_path( object ) UTF8String];
	this->capture_time	= time( NULL );
	this->serial			= ivar_serial_number( object );
	this->size			= ivar_size( object );
	this->object_handle	= ivar_object_handle( object );
	this->files			= ivar_files( object );
	this->folders			= ivar_folders( object );
	this->file_indices	= ivar_file_indices( object );
	this->folder_indices	= ivar_folder_indices( object );
	this->object			= object;
	this->parent			= ivar_parent( object );
}

void
RWContainer::set_path( const char *path )
{
	this->path			= strdup( path );
	
	// Crea la cartella
	mkdir( this->path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH );
	
	if ( this->object != NULL )
		ivar_path( this->object ) = [[NSString stringWithUTF8String:path] retain];
}
