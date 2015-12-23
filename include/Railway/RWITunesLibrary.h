#ifndef __RAILWAY_ITUNESLIBRARY_H__
#define __RAILWAY_ITUNESLIBRARY_H__

#include <Railway/RWFolder.h>
#include <Railway/Utils/RWString.h>
#include <Railway/Utils/RWUIDevice.h>
#include <sqlite3.h>
#include <sys/syslimits.h>

#define		ITLIBRARY_ITUNES_PATH				"iTunes_Control/iTunes"
#define		ITLIBRARY_LOCATIONS_DATABASE		"iTunes Library.itlp/Locations.itdb"
#define		ITLIBRARY_LIBRARY_DATABASE			"iTunes Library.itlp/Library.itdb"
#define		ITLIBRARY_MEDIALIBRARY_DATABASE		"MediaLibrary.sqlitedb"
#define		ITLIBRARY_MEDIA_NAME_SEPARATOR		" - "

#define		QUERY_ITEMS_IOS_4		"SELECT  	pid,			\
											title,		\
											artist		\
								 FROM   		item"
								 
#define		QUERY_LOCATIONS_IOS_4	"SELECT  	location.location,							\
											base_location.path							\
								 FROM   		location										\
								 INNER JOIN 	base_location									\
								 ON 			location.base_location_id = base_location.id		\
								 WHERE		location.item_pid = ?"
								 
#define		QUERY_ITEMS_IOS_7		"SELECT 		item_extra.title,										\
											item_artist.item_artist,								\
											item_extra.location,									\
											base_location.path									\
								 FROM   		item_extra											\
								 LEFT JOIN 	item													\
								 ON			item.item_pid = item_extra.item_pid						\
								 LEFT JOIN 	item_artist											\
								 ON  		item.item_artist_pid = item_artist.item_artist_pid		\
								 INNER JOIN 	base_location											\
								 ON  		item.base_location_id = base_location.base_location_id		\
								 AND 		item_extra.location IS NOT NULL							\
								 AND  		item_extra.location NOT LIKE ''							\
								 AND 		base_location.path IS NOT NULL							\
								 AND 		base_location.path NOT LIKE ''"

class RWITunesLibrary: public RWFolder
{
	private:
		void 	scan_ios_4();
		//void 	scan_ios_5();
		//void	scan_ios_6();
		void		scan_ios_7();
		
	public:
	
		RWITunesLibrary();
		
		void		scan();
		
		
};

#endif