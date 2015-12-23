#ifndef __RAILWAY_STRING_H__
#define __RAILWAY_STRING_H__

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

const char *	RWGeneratePath( const char *, ... );
const char *	RWLowerCaseString( const char * );
const char *	RWGetExtension( const char * );
const char *	RWSetExtension( const char *, const char * );
const char *	RWGenerateFilename( const char *, ... );
const char *	RWTrimStringByChar( const char *, const char );
const char *	RWEscapePath( const char * );

#define		SPACE_CHAR				0x20
#define		PATH_SEPARATOR_CHAR		0x2f
#define		EXTENSIONS_DOT			"."

#define		RWTrimString( input )					\
			RWTrimStringByChar( input, SPACE_CHAR )


#endif /* __RAILWAY_STRING_H__ end */