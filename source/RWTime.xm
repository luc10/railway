#include <Railway/Utils/RWTime.h>

const char *
RWTimeToString( time_t time )
{
	struct tm	tm;
	char			*localtime;
	
	localtime = new char[DATE_MAX_LENGTH];
	localtime_r( &time, &tm );
	
	strftime( localtime, 
			 DATE_MAX_LENGTH, 
			 DATE_FORMAT_ISO_8601, 
			 &tm );
	
	return ( ( const char * )localtime );
}

timespec *
RWTimeToTimeSpec( time_t time )
{
	timespec	*spec;
	
	spec = new timespec;
	spec->tv_sec	= time;
	spec->tv_nsec	= 0;
	
	return ( spec );
}