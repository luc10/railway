#ifndef __RAILWAY_BLOWFISH_H__
#define __RAILWAY_BLOWFISH_H__

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)        		                 \
{                                                     	   \
    (n) = ( ( uint32_t ) (b)[(i)    ] << 24 )             \
        | ( ( uint32_t ) (b)[(i) + 1] << 16 )             \
        | ( ( uint32_t ) (b)[(i) + 2] <<  8 )             \
        | ( ( uint32_t ) (b)[(i) + 3]       );            \
}
#endif

#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)         				  \
{                                              		  \
    (b)[(i)    ] = ( unsigned char ) ( (n) >> 24 );      \
    (b)[(i) + 1] = ( unsigned char ) ( (n) >> 16 );      \
    (b)[(i) + 2] = ( unsigned char ) ( (n) >>  8 );	  \
    (b)[(i) + 3] = ( unsigned char ) ( (n)       );      \
}
#endif 

#define	BLOWFISH_BLOCK_SIZE		8
#define	BLOWFISH_ROUNDS			16

typedef struct                                                                                                      
{                                                                                                                   
	uint	P[ BLOWFISH_ROUNDS + 2 ];                                                                       
	uint	S[ 4 ][ 256 ];                                                                                  
} blowfish_ctx;

void RWBlowfishSetKey( blowfish_ctx *, const unsigned char * );
void RWBlowfishDecryptBuffer( blowfish_ctx *, size_t, unsigned char *, unsigned char * );
void RWBlowfishFree( blowfish_ctx * );

#endif /* __RAILWAY_BLOWFISH_H__ end */