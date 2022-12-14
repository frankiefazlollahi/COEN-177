// Name: Frankie Fazlollahi
// Date: 1/19/2022
// Title: Lab3 - Part 5
// Description: Read from command arguments and send it through a buffer from upstream to downstream in pipe
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

// main
int main(int argc,char *argv[]){
   	int  fds[2];
   	char buff[60];
   	char buffer[60];
   	int count;
   	int i;
   	pipe(fds);
   
   	if (fork()==0){
       		printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       		close(fds[0]);
       
       		// For each string from commandline arguments
       		for(i=1;i<argc;i++){
           		// concatenate strings into buffer
           		strcat(buffer, argv[i]);
       		}
       		// Write the whole buffer to fds[1] in one go instead of iterated
       		write(fds[1],buffer,strlen(buffer));
       		exit(0);
   	}
   	else if(fork()==0){
       		printf("\nReader on the downstream end of the pipe \n");
       		close(fds[1]);
       
       		// Read from buffer into fds[0]
       		read(fds[0], buffer, 60);
       		printf("\n");

       		// Write to the screen from buffer
       		write(1,buffer,60);
       		printf("\n");

       		exit(0);
    	}
   	else{     
      		close(fds[0]);
      		close(fds[1]);
      		wait(0);
      		wait(0);
   	}
	return 0;
}
