#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <netdb.h>


#define BUF_SIZE 1000


char *host_name = "127.0.0.1"; /* local host */
int port = 8000;
int NUM_CLIENT = 5;


int main(int argc, char *argv[]) 
{
	int num;
	srand(time(NULL));
	struct sockaddr_in serv_addr;
 	struct hostent* server;	
	int answer;
	
	if (argc < 1) { 
		exit(-1);
	}
	
		
	
	if ( ( server = gethostbyname(host_name) ) == 0 ) 
	{
		perror("Error resolving local host\n");
		exit(1);
	}

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = ((struct in_addr *)(server->h_addr))->s_addr;
	serv_addr.sin_port = htons(port);

	for(int i=0; i<NUM_CLIENT; ++i) {

		int pid = fork();
		if(pid == 0) {
			srand(time(NULL) + getpid());
			int num = rand() % 100;
			int sockfd = socket( PF_INET, SOCK_STREAM, 0 );
		if ( sockfd == -1 ) 
			{
			perror("Error opening socket\n");
			exit(1);
		}    

		if ( connect(sockfd, (void*)&serv_addr, sizeof(serv_addr) ) == -1 ) 
		{
			perror("Error connecting to socket\n");
			exit(1);
		}


		printf("Send the number %d\n", num);

		/* This sends the string plus the string terminator '\0' */
		if ( send(sockfd, &num, sizeof(num), 0) == -1 ) 
		{
			perror("Error on send\n");
			exit(1);
		}

		printf("waiting response \n");
	
		if ( recv(sockfd, &answer, sizeof(answer), 0) == -1 ) 
		{
			perror("Error in receiving response from server\n");
			exit(1);
		}

		printf("response: %d\n", answer);
		close(sockfd);
		exit(0);			
		}


	}

	for(int i=0; i<NUM_CLIENT; ++i) {
		wait(NULL);
	}

	return 0;
	 
	
	
}



