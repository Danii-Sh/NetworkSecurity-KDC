/* 
 * echoclient.c - A simple connection-based client
 * usage: echoclient <host> <port>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>    ///baraye pointerha + size_t + read(socket, poninter, chand byte),write
#include <sys/types.h>  /// baraye type va pointerha
#include <sys/socket.h>   /// recieve ,send,accept,connect, listen
#include <netinet/in.h>
#include <netdb.h> 

#define BUFSIZE 1024

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
    char buf[BUFSIZE];
    char mystring[]="User Not Found\n";
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
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    /* connect: create a connection with the server */
    if (connect(sockfd, &serveraddr, sizeof(serveraddr)) < 0) 
      error("ERROR connecting");

    /* get message line from the user */
    printf("Task Input: 1 for add, 2 for change , 3 for delete ");
    bzero(buf, BUFSIZE);
    fgets(buf, BUFSIZE, stdin);
    /* send the message line to the server */
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) 
      error("ERROR writing to socket");



	if(buf[0]=='1')
	{
	/* read: print the server's reply */
	bzero(buf, BUFSIZE);
	n = read(sockfd, buf, BUFSIZE);
	if (n < 0) 
	  error("ERROR reading from socket");
	printf("server reply was %d bytes: %s", n, buf);   
	bzero(buf, BUFSIZE);
	fgets(buf, BUFSIZE, stdin);
	/* send the UserName line to the server */
	n = write(sockfd, buf, strlen(buf));
	if (n < 0) 
	  error("ERROR writing to socket");
    	/* read: print the server's reply */
    	bzero(buf, BUFSIZE);
    	n = read(sockfd, buf, BUFSIZE);
    	if (n < 0) 
    	  error("ERROR reading from socket");
	printf("server reply was %d bytes: %s", n, buf);
	bzero(buf, BUFSIZE);
	fgets(buf, BUFSIZE, stdin);
    	/* send the Pass line to the server */
    	n = write(sockfd, buf, strlen(buf));
    	if (n < 0) 
    	  error("ERROR writing to socket");
    	/* read: print the server's reply */
    	bzero(buf, BUFSIZE);
    	n = read(sockfd, buf, BUFSIZE);
    	if (n < 0) 
    	  error("ERROR reading from socket");
    	printf("server reply was %d bytes: %s", n, buf);
    	close(sockfd);
	}




	if(buf[0]=='2')
	{
	/* read: print the server's reply */
	bzero(buf, BUFSIZE);
	n = read(sockfd, buf, BUFSIZE);
	if (n < 0) 
	  error("ERROR reading from socket");
	printf("server reply was %d bytes: %s", n, buf);  
	bzero(buf, BUFSIZE);
	fgets(buf, BUFSIZE, stdin);
	/* send the UserName line to the server */
	n = write(sockfd, buf, strlen(buf));
	if (n < 0) 
	  error("ERROR writing to socket");
    	/* read: print the server's reply */
    	bzero(buf, BUFSIZE);
    	n = read(sockfd, buf, BUFSIZE);
    	if (n < 0) 
    	  error("ERROR reading from socket");
	printf("server reply was %d bytes: %s", n, buf);
	bzero(buf, BUFSIZE);
	fgets(buf, BUFSIZE, stdin);
    	/* send the Pass line to the server */
    	n = write(sockfd, buf, strlen(buf));
    	if (n < 0) 
    	  error("ERROR writing to socket");
    	/* read: print the server's reply */
    	bzero(buf, BUFSIZE);
    	n = read(sockfd, buf, BUFSIZE);
    	if (n < 0) 
    	  error("ERROR reading from socket");
    	printf("server reply was %d bytes: %s", n, buf);
	bzero(buf, BUFSIZE);
	fgets(buf, BUFSIZE, stdin);
    	/* send the New Pass line to the server */
    	n = write(sockfd, buf, strlen(buf));
    	if (n < 0) 
    	  error("ERROR writing to socket");
    	/* read: print the server's reply */
    	bzero(buf, BUFSIZE);
    	n = read(sockfd, buf, BUFSIZE);
    	if (n < 0) 
    	  error("ERROR reading from socket");
    	printf("server reply was %d bytes: %s", n, buf);
    	close(sockfd);
	}



	if(buf[0]=='3')
	{
	/* read: print the server's reply */
	bzero(buf, BUFSIZE);
	n = read(sockfd, buf, BUFSIZE);
	if (n < 0) 
	  error("ERROR reading from socket");
	printf("server reply was %d bytes: %s", n, buf);   
	bzero(buf, BUFSIZE);
	fgets(buf, BUFSIZE, stdin);
	/* send the UserName line to the server */
	n = write(sockfd, buf, strlen(buf));
	if (n < 0) 
	  error("ERROR writing to socket");
    	/* read: print the server's reply */
    	bzero(buf, BUFSIZE);
    	n = read(sockfd, buf, BUFSIZE);
    	if (n < 0) 
    	  error("ERROR reading from socket");
	printf("server reply was %d bytes: %s", n, buf);
	
	if(strcmp(buf,mystring)==0)
	{goto x;}

	bzero(buf, BUFSIZE);
	fgets(buf, BUFSIZE, stdin);
    	/* send the Pass line to the server */
    	n = write(sockfd, buf, strlen(buf));
    	if (n < 0) 
    	  error("ERROR writing to socket");
    	/* read: print the server's reply */
    	bzero(buf, BUFSIZE);
    	n = read(sockfd, buf, BUFSIZE);
    	if (n < 0) 
    	  error("ERROR reading from socket");
    	printf("server reply was %d bytes: %s", n, buf);
x:    	close(sockfd);
	}

    return 0;
}
