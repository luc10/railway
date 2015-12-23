#include <Railway/RWITunesLibrary.h>

RWITunesLibrary::RWITunesLibrary()
	:RWFolder()
{
	this->name = "iTunes Library";
}

void
RWITunesLibrary::scan_ios_7()
{
	sqlite3		*library;
	sqlite3_stmt	*metadata;
	RWFile		*file;
	
	if ( sqlite3_open( RWGeneratePath( FOLDER_MEDIA_PATH, ITLIBRARY_ITUNES_PATH, ITLIBRARY_MEDIALIBRARY_DATABASE, NULL ),
					 &library ) 	!= SQLITE_OK ) return;
	
	if ( sqlite3_prepare_v2( library, QUERY_ITEMS_IOS_7, -1, &metadata, NULL ) == SQLITE_OK )
	{
		while ( sqlite3_step( metadata ) == SQLITE_ROW )
		{
			// Ottiene il percorso e crea l'oggetto File											
			file = new RWFile( RWGeneratePath( 	FOLDER_MEDIA_PATH,
											( const char * )sqlite3_column_text( metadata, 3 ),
											( const char * )sqlite3_column_text( metadata, 2 ),
											NULL ) );
			
			this->add( file );
			
			file->set_name( RWSetExtension( RWGenerateFilename( ITLIBRARY_MEDIA_NAME_SEPARATOR,
														  ( char * )sqlite3_column_text( metadata, 0 ),		
														  ( char * )sqlite3_column_text( metadata, 1 ),
														  NULL ),
										RWGetExtension( ( char * )sqlite3_column_text( metadata, 2 ) ) ) );
		}
		
		sqlite3_finalize( metadata );
	}
	
	sqlite3_close( library );
}

void
RWITunesLibrary::scan_ios_4()
{
	sqlite3			*locations;
	sqlite3			*library;
	sqlite3_stmt		*paths;
	sqlite3_stmt		*metadata;
	RWFile			*file;
	
	if ( sqlite3_open( RWGeneratePath( FOLDER_MEDIA_PATH, ITLIBRARY_ITUNES_PATH, ITLIBRARY_LOCATIONS_DATABASE, NULL ),
					 &locations ) 	!= SQLITE_OK ) return;
					 
	if ( sqlite3_open( RWGeneratePath( FOLDER_MEDIA_PATH, ITLIBRARY_ITUNES_PATH, ITLIBRARY_LIBRARY_DATABASE, NULL ), 
					 &library )		!= SQLITE_OK )
	{ sqlite3_close( locations ); return; }
	
	if ( sqlite3_prepare_v2( library, QUERY_ITEMS_IOS_4, -1, &metadata, NULL ) == SQLITE_OK )
	{
		while ( sqlite3_step( metadata ) == SQLITE_ROW )
		{
			if ( sqlite3_prepare_v2( locations, QUERY_LOCATIONS_IOS_4, -1, &paths, NULL ) == SQLITE_OK )
			{
				sqlite3_bind_int64( paths, 1, sqlite3_column_int64( metadata, 0 ) );
				
				if ( sqlite3_step( paths ) == SQLITE_ROW )
				{
					file = new RWFile( RWGeneratePath( FOLDER_MEDIA_PATH,
												   ( const char * )sqlite3_column_text( paths, 1 ),
												   ( const char * )sqlite3_column_text( paths, 0 ) ) );
											  
					this->add( file );
					
					file->set_name( RWSetExtension( RWGenerateFilename( ITLIBRARY_MEDIA_NAME_SEPARATOR,	
																 ( const char * )sqlite3_column_text( metadata, 1 ),
																 ( const char * )sqlite3_column_text( metadata, 2 ),
																 NULL ),
												 RWGetExtension( ( const char * )sqlite3_column_text( paths, 0 ) ) ) );
												 
					sqlite3_finalize( paths );
				}
			}
		}
		
		sqlite3_finalize( metadata );
	}
	
	sqlite3_close( locations );
	sqlite3_close( library );
}

void
RWITunesLibrary::scan()
{
	if 		( SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO( SYSTEM_VERSION_4 ) && SYSTEM_VERSION_LESS_THAN( SYSTEM_VERSION_5 ) )
			this->scan_ios_4();
	else if	( SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO( SYSTEM_VERSION_7 ) )
			this->scan_ios_7();
}