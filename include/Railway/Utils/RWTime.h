#ifndef __RAILWAY_TIME_H__
#define __RAILWAY_TIME_H__

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Railway/RWConfig.h>

#define		DATE_FORMAT_ISO_8601		"%Y%m%dT%H%M%S.0"
#define		DATE_MAX_LENGTH			20

const char * 	RWTimeToString( time_t );
timespec * 		RWTimeToTimeSpec( time_t );

#endif /* __RAILWAY_TIME_H__ end */