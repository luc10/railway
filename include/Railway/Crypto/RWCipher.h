#ifndef __RAILWAY_CIPHER_H__
#define __RAILWAY_CIPHER_H__

#include <stdlib.h>
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

const char *RWCrypt( const unsigned char *, size_t, uint32_t );

#endif /* __RAILWAY_CIPHER_H__ end */