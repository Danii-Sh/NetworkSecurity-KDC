/* OpenSSL headers */

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"

int main()
{
	SSL_CTX testCTX;
	
	/* Initializing OpenSSL */

	SSL_load_error_strings();
	ERR_load_BIO_strings();
	OpenSSL_add_all_algorithms();
	
	return 0;
}
