#include <openssl/sha.h>
#include <stdio.h>

FILE *outfile2;

void main()
{
 //unsigned char *SHA1(const unsigned char *d, unsigned long n,unsigned char *md);

 int SHA1_Init(SHA_CTX *c);
// char SHA1_Update(SHA_CTX *c, const void *data,unsigned long len);
 int SHA1_Final(unsigned char *md, SHA_CTX *c);
// The data to be hashed
char data[] = "Hello";
size_t length = strlen(data);

unsigned char hash[SHA_DIGEST_LENGTH];
SHA1(data, length, hash);
// hash now contains the 20-byte SHA-1 hash



outfile2 = fopen("out1.txt","w");
fputs (hash,outfile2);
fclose(outfile2);

}
