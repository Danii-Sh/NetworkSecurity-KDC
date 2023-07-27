/* 
 * echoclient.c - A simple connection-based client
 * usage: echoclient <host> <port>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 


#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/err.h>


int Crypt(int arc, char *argv[]);
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *aad,
            int aad_len, unsigned char *tag, unsigned char *key, unsigned char *iv,
            unsigned char *plaintext);
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *aad,
            int aad_len, unsigned char *key, unsigned char *iv,
            unsigned char *ciphertext, unsigned char *tag);
void handleErrors(void);
char tempplaintext[100];
char tempkey[32];

#define BUFSIZE 1024
char buf[BUFSIZE];

/* 
 * error - wrapper for perror
 */
void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;


    /* check command line arguments */
    if (argc != 3) {
       fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
       exit(0);
    }
    hostname = argv[1];
    portno = atoi(argv[2]);

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
	  (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    /* connect: create a connection with the server */
    if (connect(sockfd, &serveraddr, sizeof(serveraddr)) < 0) 
      error("ERROR connecting");

    /* read: print the server's reply */
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("server reply: %s", buf);

	bzero(buf, BUFSIZE);
	fgets(buf, BUFSIZE, stdin);
	/* send the UserName line to the server */
	n = write(sockfd, buf, strlen(buf));
	if (n < 0) 
	  error("ERROR writing to socket");

char buff=buf[n-2];
if(buff=='0')
{


		/////********/////
		FILE *outfile1;

		char mystring[100];
		int x=0;
		while(x!=100)
		{mystring[x]=NULL;
		x++;}

		outfile1 = fopen("myAcc.txt","r");
		int b=0;
		while(b!=50)
		{mystring[b]=fgetc (outfile1);
		b++;} 
		fclose(outfile1);
	
		x=0;
		while(mystring[x]!=10)
		{x++;}
		x++;
		while(mystring[x]!=10)
		{x++;}
		x++;

		int k=0;
		while(k!=20)
		{tempkey[k]=mystring[k+x-1];
		k++;}
		k=0;
		while(k!=12)
		{tempkey[k+20]=mystring[k];
		k++;}



    /* read: print the server's reply */
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("server reply: %s\n", buf);
		FILE *outfile2;		
		outfile2 = fopen("plain.txt","w");
		fputs (buf,outfile2);
		fclose(outfile2);
	Crypt(NULL,NULL);

    close(sockfd);
}



if(buff=='1'||buff=='2'||buff=='3')
{
    /* read: print the server's reply */
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("server reply: %s", buf);

    /* get message line from the user */
    printf("Send T(tgs), y/n? ");
    bzero(buf, BUFSIZE);
    fgets(buf, BUFSIZE, stdin);
    /* send the UserName line to the server */
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) 
      error("ERROR writing to socket");

	if(buf[0]=='y')
	{
	/////SEND TGS

    /* read: print the server's reply */
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("server reply: %s", buf);
	}

    close(sockfd);
}



    return 0;
}











/////////**********************//////////////////////////
/////////**********************////////////////////
/////////**********************//////////////////////////









int Crypt(int arc, char *argv[])
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();     

    /* Set up the key and iv. Do I need to say to not hard code these in a real application? :-) */

    /* A 256 bit key */
    static unsigned char key[] = "01234567890123456789012345678901";
   int j=0;
   while(j!=32)
    {
    key[j]=tempkey[j];
    j++;
    }

    /* A 128 bit IV */
    static unsigned char iv[] = "0123456789012345";

    /* Message to be encrypted */
    unsigned char plaintext[100]; //= "The quick brown fox jumps over the lazy dog";

    bzero(plaintext, 100);    

    j=0;
    while(buf[j]!=NULL)
    {
    plaintext[j]=buf[j];
    j++;    
    }

    /* Some additional data to be authenticated */
    static unsigned char aad[] = "Some AAD data";

    /* Buffer for ciphertext. Ensure the buffer is long enough for the
     * ciphertext which may be longer than the plaintext, dependant on the
     * algorithm and mode
     */
    unsigned char ciphertext[128];

    /* Buffer for the decrypted text */
    unsigned char decryptedtext[128];

    /* Buffer for the tag */
    unsigned char tag[16];

    int decryptedtext_len = 0, ciphertext_len = 0;

    /* Encrypt the plaintext */
//    ciphertext_len = encrypt(plaintext, strlen(plaintext), aad, strlen(aad), key, iv, ciphertext, tag);
    ciphertext_len = strlen(plaintext);
    /* Do something useful with the ciphertext here */
//   printf("Ciphertext is:\n");
//    BIO_dump_fp(stdout, plaintext, ciphertext_len);
    printf("Tag is:\n");
    BIO_dump_fp(stdout, tag, 14);

    /* Mess with stuff */
    /* ciphertext[0] ^= 1; */
    /* tag[0] ^= 1; */

    /* Decrypt the ciphertext */
    decryptedtext_len = decrypt(plaintext, ciphertext_len, aad, strlen(aad), tag, key, iv, decryptedtext);

    if(decryptedtext_len < 0)
    {
        /* Verify error */
        printf("Decrypted text failed to verify\n");
    }
    else
    {
        /* Add a NULL terminator. We are expecting printable text */
        decryptedtext[decryptedtext_len] = '\0';

        /* Show the decrypted text */
        printf("Decrypted text is:\n");
        printf("%s\n", decryptedtext);
    }

    /* Remove error strings */
    ERR_free_strings();

    return 0;
}

void handleErrors(void)
{
    unsigned long errCode;

    printf("An error occurred\n");
    while(errCode = ERR_get_error())
    {
        char *err = ERR_error_string(errCode, NULL);
        printf("%s\n", err);
    }
    abort();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *aad,
            int aad_len, unsigned char *key, unsigned char *iv,
            unsigned char *ciphertext, unsigned char *tag)
{
    EVP_CIPHER_CTX *ctx = NULL;
    int len = 0, ciphertext_len = 0;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    /* Initialise the encryption operation. */
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL))
        handleErrors();

    /* Set IV length if default 12 bytes (96 bits) is not appropriate */
    if(1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 16, NULL))
        handleErrors();

    /* Initialise key and IV */
    if(1 != EVP_EncryptInit_ex(ctx, NULL, NULL, key, iv)) handleErrors();

    /* Provide any AAD data. This can be called zero or more times as
     * required
     */
    if(aad && aad_len > 0)
    {
        if(1 != EVP_EncryptUpdate(ctx, NULL, &len, aad, aad_len))
            handleErrors();
    }

    /* Provide the message to be encrypted, and obtain the encrypted output.
     * EVP_EncryptUpdate can be called multiple times if necessary
     */
    if(plaintext)
    {
        if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
            handleErrors();

        ciphertext_len = len;
    }

    /* Finalise the encryption. Normally ciphertext bytes may be written at
     * this stage, but this does not occur in GCM mode
     */
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    /* Get the tag */
    if(1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, 16, tag))
        handleErrors();

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *aad,
            int aad_len, unsigned char *tag, unsigned char *key, unsigned char *iv,
            unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx = NULL;
    int len = 0, plaintext_len = 0, ret;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    /* Initialise the decryption operation. */
    if(!EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL))
        handleErrors();

    /* Set IV length. Not necessary if this is 12 bytes (96 bits) */
    if(!EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 16, NULL))
        handleErrors();

    /* Initialise key and IV */
    if(!EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv)) handleErrors();

    /* Provide any AAD data. This can be called zero or more times as
     * required
     */
    if(aad && aad_len > 0)
    {
        if(!EVP_DecryptUpdate(ctx, NULL, &len, aad, aad_len))
            handleErrors();
    }

    /* Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary
     */
    if(ciphertext)
    {
        if(!EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
            handleErrors();

        plaintext_len = len;
    }

    /* Set expected tag value. Works in OpenSSL 1.0.1d and later */
    if(!EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, 16, tag))
        handleErrors();

    /* Finalise the decryption. A positive return value indicates success,
     * anything else is a failure - the plaintext is not trustworthy.
     */
    ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    if(ret > 0)
    {
        /* Success */
        plaintext_len += len;
        return plaintext_len;
    }
    else
    {
        /* Verify failed */
        return -1;
    }
}
