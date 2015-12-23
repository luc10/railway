#ifndef __RAILWAY_MD2_H__
#define __RAILWAY_MD2_H__

typedef struct
{
    unsigned char 	cksum[16];
    unsigned char 	state[48];
    unsigned char 	buffer[16];
    size_t 			left;
} md2_ctx;

void RWMD2Starts( md2_ctx * );
void RWMD2Update( md2_ctx *, const unsigned char *, size_t );
void RWMD2Finish( md2_ctx *, unsigned char * );
void RWMD2Free( md2_ctx * );

#endif /* __RAILWAY_MD2_H__ end */