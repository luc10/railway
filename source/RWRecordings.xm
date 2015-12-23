#include <Railway/RWRecordings.h>

RWRecordings::RWRecordings()
	:RWFolder( RECORDINGS_FOLDER )
{
	this->labels 	= RWReadPList( RWGeneratePath( this->path, 
											RECORDINGS_CUSTOM_LABELS, 
											NULL ) );
}

const char *
RWRecordings::get_custom_label( const char *filename )
{
	NSString		*label;
	
	if ( ( label = [this->labels objectForKey:[NSString stringWithUTF8String:filename]] ) != nil )
		return ( RWGenerateFilename( RECORDINGS_LABEL_SEPARATOR,
							      [label UTF8String],
								  filename,
								  NULL ) );
	else
		return ( filename );
}

void
RWRecordings::scan()
{
	sqlite3		*recordings;
	sqlite3_stmt	*items;
	RWFile		*file;
	
	if ( sqlite3_open( RWGeneratePath( this->path, RECORDINGS_DATABASE, NULL ), 
					 &recordings ) != SQLITE_OK ) return;

	if ( sqlite3_prepare_v2( recordings, 
						  RECORDINGS_QUERY_ITEMS, 
						  -1, 
						  &items, 
						  NULL ) == SQLITE_OK )
	{
		while ( sqlite3_step( items ) == SQLITE_ROW )
		{
			file = new RWFile( ( const char * )sqlite3_column_text( items, 0 ) );
			
			this->add( file );
			file->set_name( this->get_custom_label( file->name ) );
		}
		
		sqlite3_finalize( items );
	}
	
	sqlite3_close( recordings );
}

void
RWRecordings::import( RWFile *file )
{
	NSLog(@"file->name: %s", file->name);
	NSLog(@"file->path: %s", file->path);
}

















