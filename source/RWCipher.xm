#include <Railway/Crypto/RWCipher.h>

const char *
RWCrypt( const unsigned char *input, size_t length, uint32_t key )
{
	uint32_t		i;
	uint32_t		n;
	char			*output;
	
	output = ( char * )malloc( length );
	
	for ( i = 0; i < length; i += 4)
	{
		GET_UINT32_BE( n, input, i );
		n ^= key;
		PUT_UINT32_BE( n, output, i );
	}
	
	return ( output );
}