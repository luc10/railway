#include <Railway/RWFolder.h>

RWFolder::RWFolder()
	:RWContainer()
{}

RWFolder::RWFolder( Container *object )
	:RWContainer( object )
{}

RWFolder::RWFolder( const char *path )
	:RWContainer()
{
	struct stat	statbuf;
	
	this->path 			= strdup( RWGeneratePath( FOLDER_MEDIA_PATH, path, NULL ) );
	
	if ( stat( this->path, &statbuf ) == 0 )
	{
		this->name 			= strdup( path );
		this->capture_time	= statbuf.st_ctime;
		this->serial			= statbuf.st_ino;
		this->size			= statbuf.st_size;
	}
}

RWFolder::RWFolder( PTPObjectInfoDataset *dataset, RWContainer *parent )
	:RWContainer()
{
	this->name = [[dataset filename] UTF8String];
	this->path = RWGeneratePath( parent->path, this->name, NULL );
	this->size = [dataset objectCompressedSize];
	
	mkdir( this->path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH );
}

void
RWFolder::add( RWFolder *folder )
{
	folder->parent = this->object;
	
	[this->folders 
		setObject:folder->get() 
		forKey:[NSNumber numberWithUnsignedLong:folder->object_handle]];
					
	[this->folder_indices 
		addIndex:folder->object_handle];
}

void
RWFolder::add( RWFile *file )
{
	file->parent = this->object;
	
	[this->files 	
		setObject:file->get()
		forKey:[NSNumber numberWithUnsignedLong:file->object_handle]];
					
	[this->file_indices 
		addIndex:file->object_handle];
}

void
RWFolder::scan()
{
	FTS					*filesystem;
	FTSENT				*child;
	const char			*path[2];
	RWFile				*file;
	RWFolder				*folder;
	
	path[0] = this->path;
	path[1] = NULL;
	
	filesystem = fts_open( ( char* const * )path, 
						 FTS_NOCHDIR | FTS_PHYSICAL | FTS_XDEV,
						 NULL );
	
	// Se riesce add ottenere il filesystem
	if ( filesystem )
	{
		// Ottiene la linked list
		fts_read( filesystem );
		child = fts_children( filesystem, NULL );
		
		while ( child )
		{
			switch ( child->fts_info )
			{
				case FTS_F:
				{
					file = new RWFile();
					
					file->name 			= child->fts_name;
					file->size 			= child->fts_statp->st_size;
					file->capture_time	= child->fts_statp->st_ctime;
					file->serial			= child->fts_statp->st_ino;
					
					this->add( file );
					
					break;
				}
				case FTS_D:
				{
					folder = new RWFolder();
					
					folder->name 			= child->fts_name;
					folder->size 			= child->fts_statp->st_size;
					folder->capture_time	= child->fts_statp->st_ctime;
					folder->serial		= child->fts_statp->st_ino;
					
					this->add( folder );
					folder->scan();
					
					break;
				}
			}
			
			child = child->fts_link;
		}
		
		fts_close( filesystem );
	}
}

Folder *
RWFolder::get()
{
	if ( this->object == NULL )
	{
		if ( this->path == NULL )
		{
			this->object 	= [[CFolder alloc]
							initWithName:[NSString stringWithUTF8String:this->name]
							serialNumber:this->serial
							captureTimeSpec:RWTimeToTimeSpec( this->capture_time )
							size:this->size
							parent:this->parent
							parentID:ivar_object_handle( this->parent )];
							
			this->path	= [ivar_path( this->object ) UTF8String ];
		}
		else
		{
			this->object 	= [[CFolder alloc] 
							initWithName:[NSString stringWithUTF8String:this->name]
							path:[NSString stringWithUTF8String:this->path]
							captureTimeSpec:RWTimeToTimeSpec( this->capture_time )
							parent:this->parent
							parentID:ivar_object_handle( this->parent )];
		}
		
		this->folders			= ivar_folders( this->object );
		this->folder_indices	= ivar_folder_indices( this->object );
		this->files			= ivar_files( this->object );
		this->file_indices	= ivar_file_indices( this->object );
		this->object_handle 	= ivar_object_handle( this->object );
	}
	
	return ( this->object );
}













