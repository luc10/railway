#import <Foundation/NSObject.h>

@interface EXIFScanner : NSObject {
	NSMutableDictionary* 	_metaData;
	int 					_fd;
	char* 					_buffer;
	unsigned 				_bufferLenMapped;
	unsigned 				_bufferLen;
	char* 					_ptr;
	int 					_IFD;
	char* 					_tiffData;
	unsigned 				_tiffLength;
	bool 					_bigEndian;
	unsigned 				_offsetCorrection;
}
-(id)initWithFilename:(id)filename maxSize:(long long)size;
-(void)setupTiff:(char*)tiff length:(unsigned long)length;
-(unsigned short)s2n_16:(unsigned long)a16;
-(unsigned long)s2n_32:(unsigned long)a32;
-(unsigned long long)s2n_64:(unsigned long)a64;
-(unsigned long)next_IFD:(unsigned long)ifd overran:(BOOL*)overran;
-(id)copyIFDArray;
-(void)dump_IFD:(unsigned long)ifd;
-(void)scanExif;
-(void)scanTiff;
-(void)scanSOF:(unsigned short)sof;
-(BOOL)handleJPEGMarker;
-(void)scanForMarkers;
-(void)scan;
-(id)copyMetaData;
-(void)dealloc;
@end

