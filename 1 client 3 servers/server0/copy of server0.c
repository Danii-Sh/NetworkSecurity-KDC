/* 
 * echoserver.c - A simple connection-based echo server 
 * usage: echoserver <port>
 */
#include <openssl/sha.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define BUFF_SIZE 1024


FILE *outfile2;
 //unsigned char *SHA1(const unsigned char *d, unsigned long n,unsigned char *md);

 int SHA1_Init(SHA_CTX *c);
// char SHA1_Update(SHA_CTX *c, const void *data,unsigned long len);
 int SHA1_Final(unsigned char *md, SHA_CTX *c);
// The data to be hashed
//char data[] ;
//size_t length = strlen(data);

unsigned char hash[SHA_DIGEST_LENGTH];
//char output[];




/*
 * error - wrapper for perror
 */
void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv) {
  int listenfd; /* listening socket */
  int connfd; /* connection socket */
  int portno; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct hostent *hostp; /* client host info */
  char buf[BUFF_SIZE]; /* message buffer */
  char temp_buf[20];
  time_t rawtime ;
  struct tm *info;
  time(&rawtime);
  info = localtime(&rawtime);	
  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */
  int n; /* message byte size */

  /* check command line args */
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);

  /* socket: create a socket */
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) 
    error("ERROR opening socket");

  /* setsockopt: Handy debugging trick that lets 
   * us rerun the server immediately after we kill it; 
   * otherwise we have to wait about 20 secs. 
   * Eliminates "ERROR on binding: Address already in use" error. 
   */
  optval = 1;
  setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, 
	     (const void *)&optval , sizeof(int));

  /* build the server's internet address */
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET; /* we are using the Internet */
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); /* accept reqs to any IP addr */
  serveraddr.sin_port = htons((unsigned short)portno); /* port to listen on */

  /* bind: associate the listening socket with a port */
  if (bind(listenfd, (struct sockaddr *) &serveraddr, 
	   sizeof(serveraddr)) < 0) 
    error("ERROR on binding");

  /* listen: make it a listening socket ready to accept connection requests */
  if (listen(listenfd, 5) < 0) /* allow 5 requests to queue up */ 
    error("ERROR on listen");

  /* main loop: wait for a connection request, echo input line, 
     then close connection. */
  clientlen = sizeof(clientaddr);
  while (1) {

    /* accept: wait for a connection request */
    connfd = accept(listenfd, (struct sockaddr *) &clientaddr, &clientlen);
    if (connfd < 0) 
      error("ERROR on accept");
    
    /* gethostbyaddr: determine who is connected */
    hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
			  sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      error("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      error("ERROR on inet_ntoa\n");
    printf("server established connection with %s (%s)\n", hostp->h_name, hostaddrp);
    



    /* 
     * read: read input string from the client
     */
    bzero(buf, BUFF_SIZE);
    n = read(connfd, buf, BUFF_SIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("server received %d bytes,Task Selected is %s", n, buf);


   if(buf[0]=='1')
   {
    n = write(connfd, "Insert User Name\n", 17);
    
    bzero(temp_buf, 20);
    bzero(buf, BUFF_SIZE);
    n = read(connfd, buf, BUFF_SIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("server received %d bytes: %s", n, buf);	

	int x=0;
	int y=0;
	while(x!=n-1)
	{temp_buf[x]=buf[x];
	x++;}
	temp_buf[x]=10;
	


    n = write(connfd, "Insert Pass\n", 12);
    bzero(buf, BUFF_SIZE);
    n = read(connfd, buf, BUFF_SIZE);
    if (n < 0) 
      error("ERROR reading from socket");

    printf("server received %d bytes: %s", n, buf);

	y=x+1;
	x=0;
	while(x!=n-1)
	{temp_buf[y]=buf[x];
	x++;
	y++;}
	temp_buf[y]=10;

	
size_t length = strlen(buf);
buf[length]=NULL;
buf[length-1]=NULL;
SHA1(buf, length-1, hash);
// hash now contains the 20-byte SHA-1 hash

	x=y+1;
	y=0;
	while(y!=20)
	{temp_buf[x]=hash[y];
	x++;
	y++;}

FILE *outfile1;
FILE *outfile2;
FILE *outfile3;
FILE *outfile4;

char mystring[100];
x=0;
while(x!=100)
{mystring[x]=NULL;
x++;}

outfile1 = fopen("user1.txt","r");
fgets (mystring , 100 , outfile1); 
fclose(outfile1);


if(mystring[0]==NULL)
	{
	outfile1 = fopen("user1.txt","w");
	fputs (temp_buf,outfile1);
	fclose(outfile1);
	n = write(connfd, "User Addition OK\n", 17);
	}

if(mystring[0]!=NULL)
	{
	x=0;
	while(x!=100)
	{mystring[x]=NULL;
	x++;}

	outfile2 = fopen("user2.txt","r");
	fgets (mystring , 100 , outfile2); 
	fclose(outfile2);

	if(mystring[0]==NULL)
		{
		outfile2 = fopen("user2.txt","w");
		fputs (temp_buf,outfile2);
		fclose(outfile2);
		n = write(connfd, "User Addition OK\n", 17);
		}
	if(mystring[0]!=NULL)
		{
		n = write(connfd,"User Addition Failed,User Buffers Are Full\n",43);		
		}
}

}


//  FILE * pFile;
//  pFile = tmpfile ();



   if(buf[0]=='2')
   {
	n = write(connfd, "B\n", 17);
   }
   if(buf[0]=='3')
   {
    n = write(connfd, "Insert User Name\n", 17);
    
    bzero(temp_buf, 20);
    bzero(buf, BUFF_SIZE);
    n = read(connfd, buf, BUFF_SIZE);
    if (n < 0) 
      error("ERROR reading from socket");
    printf("server received %d bytes: %s", n, buf);	


FILE *outfile1;
FILE *outfile2;
FILE *outfile3;

char mystring[100];
int x=0;
while(x!=100)
{mystring[x]=NULL;
x++;}

outfile1 = fopen("user1.txt","r");
int b=0;
while(b!=30)
{mystring[b]=fgetc (outfile1);
b++;} 
fclose(outfile1);
	
	int match=0;
	x=0;
	int y=1;
	while(x!=n-1)
	{if(mystring[x]!=buf[x])
	{y=0;}
	x++;}
	int counter = n;



	if(y==1)
	{
				    n = write(connfd, "Insert Pass\n", 12);
				    bzero(buf, BUFF_SIZE);
				    n = read(connfd, buf, BUFF_SIZE);
				    if (n < 0) 
			            error("ERROR reading from socket");
 				    printf("server received %d bytes: %s", n, buf);
		//ROUTINE Password 
				    x=0;
				    y=1;
				    while(x!=n-1)
			            {if(mystring[counter+x]!=buf[x])
			            {y=0;}
			            x++;}
				    if(y==1)
				    {match=1;}	
	}

			if(match==0)
		{
			x=0;
			while(x!=100)
			{mystring[x]=NULL;
			x++;}
			outfile2 = fopen("user2.txt","r");
			b=0;

			while(b!=30)
			{mystring[b]=fgetc (outfile2);
			b++;}
			fclose(outfile2);
			x=0;
			y=1;
			while(x!=n-1)
			{if(mystring[x]!=buf[x])
			{y=0;}
			x++;}
			if(y==1)
			{
			    n = write(connfd, "Insert Pass\n", 12);
			    bzero(buf, BUFF_SIZE);
			    n = read(connfd, buf, BUFF_SIZE);
			    if (n < 0) 
		            error("ERROR reading from socket");
 			    printf("server received %d bytes: %s", n, buf);
		//ROUTINE Password 
//printf("buf: %s\n", buf);
//printf("out2: %d\n", strlen(outfile2));
			    x=0;
			    y=1;
			    while(x!=n-1)
		            {if(mystring[counter+x]!=buf[x])
		            {y=0;}
		            x++;}
			    if(y==1)
			    {match=2;}

			}
		}

if(match==0)
{    n = write(connfd, "User Not Found\n", 15); }	

if(match!=0)
{


if(match==1)
{outfile1 = fopen("user1.txt","w");
fclose(outfile1);
n = write(connfd, "Deletion OK\n", 12);}
if(match==2)
{outfile2 = fopen("user2.txt","w");
fclose(outfile2);
n = write(connfd, "Deletion OK\n", 12);}



}

   }


    close(connfd);
  }
}
