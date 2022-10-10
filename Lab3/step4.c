// Name: Frankie Fazlollahi
// Date: 1/19/2022
// Title: Lab3 - Part 4
// Description: Implements the shell command `cat /etc/passwd | grep root` and deal with execlp with multiple arguments

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

// main
int main(int argc,char *argv[]){
   	int  fds[2];
   	pipe(fds);
   
   	if (fork()==0){
       		dup2(fds[0], 0);
       		close(fds[1]);
       		// Include /bin/grep as the `file source`, which points to the code we want to run
       		// then call grep and root as two separate parameters
       		execlp("/bin/grep", "grep", "root", 0);
   	}
   	else if(fork()==0){
       		dup2(fds[1], 1);
       		// Include /bin/cat as file source, and `cat` and `/etc/passwd` as separate parameters
       		close(fds[0]);
       		execlp("/bin/cat", "cat", "/etc/passwd", 0);
    	}
   	else{     
      		close(fds[0]);
      		close(fds[1]);
      		wait(0);
      		wait(0);
   	}
	return 0;
}
