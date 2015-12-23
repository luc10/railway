#import <Foundation/NSObject.h>

@interface ObjectProperty : NSObject
{
	unsigned short 	_propertyCode;
	unsigned short 	_dataType;
	unsigned char 	_writableSet;
	char* 			_dataValue;
	unsigned long 	_groupCode;
	unsigned char 	_formFlag;
	BOOL 			_useString;
	NSString* 		_stringValue;
	NSMutableData* 	_dataObject;
}
+(id)objectPropertyWithPropertyCode:(unsigned long)propertyCode andDataType:(unsigned short)type;
-(void)dealloc;
-(void)setFormFlag:(unsigned char)flag;
-(unsigned char)formFlag;
-(unsigned short)dataType;
-(unsigned short)propertyCode;
-(void)objectPropertyListElement:(id)element withObject:(id)object andHandle:(unsigned long)handle;
-(void)objectPropertyDescriptionDataset:(id)dataset;
-(void)objectValue:(id)value withObject:(id)object andHandle:(unsigned long)handle;
-(id)initWithPropertyCode:(unsigned short)propertyCode andDataType:(unsigned short)type;
@end

