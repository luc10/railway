#ifndef __RAILWAY_RECORDINGS_H__
#define __RAILWAY_RECORDINGS_H__

#include <Railway/RWFolder.h>
#include <Railway/Utils/RWString.h>
#include <Railway/Utils/RWPList.h>
#include <sqlite3.h>
#include <sys/syslimits.h>

#define		RECORDINGS_FOLDER					"Recordings"
#define		RECORDINGS_DATABASE				"Recordings.db"
#define		RECORDINGS_CUSTOM_LABELS			"CustomLabels.plist"

#define		RECORDINGS_QUERY_ITEMS				"SELECT	ZPATH				\
											 FROM	ZRECORDING			\
											 WHERE	ZPATH IS NOT NULL"

#define		RECORDINGS_INSERT_ITEM				"INSERT INTO	ZRECORDING( ZPATH,		\
																   ZDATE,		\
																   ZDURATION)		\
											 VALUES		( '?', ?, ? )	"
											 
#define		RECORDINGS_LABEL_SEPARATOR			" - "
				 
class RWRecordings: public RWFolder
{
	private:
		NSMutableDictionary	*labels;
		const char *	get_custom_label( const char * );
		
	public:
		
		RWRecordings();
		
		void 		scan();
		void			import( RWFile * );
		
};

#endif /* __RAILWAY_RECORDINGS_H__ end */