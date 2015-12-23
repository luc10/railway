#ifndef __RAILWAY_PLIST_H__
#define __RAILWAY_PLIST_H__

#import <Foundation/Foundation.h>

NSMutableDictionary *	RWReadPList( const char * );
BOOL					RWWritePList( NSMutableDictionary *, const char * );

#endif /* __RAILWAY_PLIST_H__ end */