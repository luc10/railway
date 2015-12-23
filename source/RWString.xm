#include <Railway/Utils/RWString.h>

const char *
RWGeneratePath( const char *first, ... )
{
	char				*path;
	va_list			components;
	const char		*component;
	size_t			length;
	
	va_start( components, first );
	
	length = strlen( first ) + 1;
	while ( ( component = va_arg( components, const char * ) ) != NULL )
		length += strlen( component ) + 1;
	
	va_end( components );
	
	path = new char[length + 1];
	memset( path, 0, length + 1 );
	
	va_start( components, first );
	
	if ( first != NULL && strlen( first ) )
		strcpy( path, RWEscapePath( first ) );
	else
		return ( NULL );
	
	while ( ( component = va_arg( components, const char * ) ) != NULL )
		strcat( path, RWEscapePath( component ) );
	
	va_end( components );

	return ( path );
}

const char *
RWGenerateFilename( const char *sep, ... )
{
	char			*filename;
	va_list		components;
	const char	*component;
	size_t		length, 
				sep_length;
	
	va_start( components, sep );
	
	length 		= 0;
	sep_length	= strlen( sep );
	
	while ( ( component = va_arg( components, const char * ) ) != NULL )
		length += strlen( component ) + sep_length;
		
	va_end( components );
	
	filename = new char[length + 1];
	memset( filename, 0, length + 1 );
	
	va_start( components, sep );
	
	if ( ( component = va_arg( components, const char * ) ) != NULL )
	{
		if ( strlen( component ) )
			strcpy( filename, RWTrimString( component ) );
	}
	
	while ( ( component = va_arg( components, const char * ) ) != NULL )
	{ 
		if ( strlen( component ) )
		{ 	
			strcat( filename, sep ); 
			strcat( filename, RWTrimString( component ) );	
		}
	}
	
	va_end( components );
	
	filename[length] = 0;
	return ( filename );
}

const char *
RWEscapePath( const char *input )
{
	char		*p;
	size_t	length;
	
	length = strlen( input );
	p = new char[length + 2];
	memset( p, 0, ( length + 2 ) );
	
	p[0] = PATH_SEPARATOR_CHAR;
	strcat( 	p, 
			RWTrimStringByChar( input, PATH_SEPARATOR_CHAR ) );
	
	return ( p );
}

const char *
RWTrimStringByChar( const char *input, const char trimc )
{
	char		*p, *b;
	size_t	length;
	
	p = strdup( input );
	b = p;
	
	if ( b != NULL && ( length = strlen( input ) ) )
	{
		for ( p = b; *p && ( *p == trimc ); ++p );
		
		if ( b != p )
		{ 	length = strlen( p );
			memmove( b, p, length + 1 ); }
		
		while ( --length >= 0 )
		{
			if ( ( b[length] != trimc ) )
				break;
		}
		
		b[++length] = 0;
	}
	
	return ( b );
}

const char *
RWLowerCaseString( const char *input )
{
	char		*p, *b;
	
	p = strdup( input );
	b = p;
	
	while ( *p != 0 )
	{ *p = tolower( *p ); p++; }
	
	return ( b );
}

const char *
RWGetExtension( const char *input )
{
	return ( strstr( input, EXTENSIONS_DOT ) );
}

const char *
RWSetExtension( const char *input, const char *extension )
{
	size_t	length;
	char		*str;
	
	if ( extension != NULL && input != NULL )
	{
		if ( strlen( input ) && strlen( extension ) )
		{
			length 	= strlen( input ) 
					+ strlen( extension );
			
			str = new char[length + 1];
			strcpy( str, input );
			strcat( str, extension );
			
			str[length] = 0;
			
			return ( str );
		}
	}
	
	return ( input );
}