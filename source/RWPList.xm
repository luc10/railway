#include <Railway/Utils/RWPList.h>

NSMutableDictionary *
RWReadPList( const char *path )
{
	if ( access( path, F_OK ) != -1 )
	{
		return ( [NSPropertyListSerialization 
					propertyListWithData:
						[NSData dataWithContentsOfFile:[NSString stringWithUTF8String:path]]
					options:
						NSPropertyListMutableContainersAndLeaves 
					format:nil
					error:nil] );
	}
	else
	{
		return ( [[NSMutableDictionary alloc] init] );
	}
}

BOOL
RWWritePList( NSMutableDictionary *plist, const char *path )
{
	return ( [[NSPropertyListSerialization 
					dataWithPropertyList:plist
					format:NSPropertyListBinaryFormat_v1_0
					options:0
					error:nil] 
				writeToFile:[NSString stringWithUTF8String:path]
				atomically:YES] );
}