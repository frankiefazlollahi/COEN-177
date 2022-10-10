// Name: Frankie Fazlollahi
// Date: 1/12/2022
// Title: Lab1 – task 5 
// Description: Creation of 7 processes (including initial parent) in a complete binary tree
//       Parent
//        / \
//      1     2
//     / \   / \
//    3   4 5   6
// Seven total processes

#include <stdio.h>	// printf, stderr
#include <stdlib.h>     // exit()
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    	// Create the different process IDs
    	pid_t child_1, child_2;
    	pid_t child_3, child_4;
    	pid_t child_5, child_6;
	
    	// Create child_1
    	child_1 = fork();
    	// If id = 0 (child)
    	if (child_1 == 0) 
	{
        	// Create a child from child (left-left)
        	child_3 = fork();
        	// If id = 0 (child-child)
        	if (child_3 == 0) 
		{
        		printf("I am child_3 %d PID (left-left)\n\n", getpid());
            		exit(0);
        	}
        	else	
	 	{
            		// Create a second child from child (left-right)
            		child_4 = fork();
            		// If id = 0 (child-child)
            		if (child_4 == 0) 
			{
                		printf("I am child_4 %d PID (left-right)\n\n", getpid());
                		exit(0);
            		}   
            		// Otherwise it is the original child_1
            		else
			{
                		printf("I am child_1 %d PID (left)\n\n", getpid());
                		exit(0);
            		}
        	}
    	}
    	// Creating second child
    	else 
	{
        	// Same code as above but with right side of tree
        	child_2 = fork();
        	// Creating child-child (right-left)
        	if (child_2 == 0) 
		{
            		child_5 = fork();
			if (child_5 == 0) 
	    		{
                		printf("I am child_5 %d PID (right-left)\n\n", getpid());
                		exit(0);
            		}
            		// Creating child-child (right-right)
            		else 
			{
                		child_6 = fork();
                		if (child_6 == 0) 
				{
                    			printf("I am child_6 %d PID (right-right)\n\n", getpid());
                    			exit(0);
                		}
                		// Else (id = 1), then original child_2
                		else 
				{
                    			printf("I am child_2 %d PID (right)\n\n", getpid());
                    			exit(0);
                		}
            		}
        	}
        	// Last else statement is for the original parent
        	else
		{
            		printf("I am Parent %d PID\n\n", getpid()); //parent
 		}
    	}
    	return 0;
}
