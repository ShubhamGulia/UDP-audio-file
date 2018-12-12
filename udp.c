#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<time.h>

int delay;
int buffersize = 1500; //Hard-coded buffer size


int main(int argc, char **argv){
	if ( argc != 4 ) {
		printf("This command requires the following arguments: filename, ip address, transmission delay\n");
		return -1;
	}
	if ((delay = atoi(argv[3])) == 0 ) {
			printf("Please enter an integer argument for the transmission delay.\n");
			return -1;
	}
	else {
		
		int dest_socket;
		struct sockaddr_in dest_address;
		dest_address.sin_family = AF_INET;
		dest_address.sin_port=htons(4444);
		inet_pton(AF_INET,argv[2],&(dest_address.sin_addr.s_addr));
			//no longer a hard-coded ip!
		dest_socket=socket(AF_INET,SOCK_DGRAM,0);

		unsigned char buffer[buffersize];
		
		struct timespec timer;
		long ms = 1000000 * delay;
		timer.tv_nsec = ms;
		
		FILE  *f = NULL;
		int n = 0;
		f = fopen(argv[1], "rb");
		if (f != NULL) {
			while ((n = fread(buffer, 1, buffersize, f)) > 0) {
				sendto(dest_socket, buffer, n, 0, (struct sockaddr *) &dest_address, sizeof(dest_address));
				nanosleep(&timer,NULL);
			}
		}
	}
	return 0;
}
