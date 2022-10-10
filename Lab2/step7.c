// Name: Frankie Fazlollahi
// Date: 1/12/2022
// Title: Lab 2 - step 7
// Description: Child process runs ls command and parent process waits until child process finishes before it terminates

#define _BSD_SOURCE  		// Needed to avoid usleep function warning
#include <stdio.h>              // printf, stderr
#include <sys/types.h>          // pid_t
#include <unistd.h>             // fork
#include <stdlib.h>            	// atoi
#include <errno.h>              // errno
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Initialize variables
    pid_t pid;
    int i, n = atoi(argv[1]);  	// n microseconds to input from keyboard for delay
    
    printf("\n Before forking.\n");
    
    // Set pid to fork(). Child process now starts after this line with parent properties
    pid = fork();
    
    // If the fork failed, fork() returns -1
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    
    // Child process runs different code with execlp
    else if (pid == 0) {
        execlp("/bin/ls", "ls", NULL); 	// Make child run `ls` command
    }

    // Parent process waits for child and then exits
    else {
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }
    return 0;
}
