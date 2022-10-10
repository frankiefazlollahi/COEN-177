// # Name: Frankie Fazlollahi
// # Date: 1/12/2022
// # Title: Lab 2 - step 6
// # Description: Use two threads (instead of two processes) to replicate step 1

#define _BSD_SOURCE			// usleep warning
#include <stdio.h>             		// printf, stderr
#include <sys/types.h>         		// pid_t
#include <unistd.h>            		// fork
#include <stdlib.h>            		// atoi
#include <errno.h>             		// errno
#include <pthread.h>           		// pthread functions

struct qs
{
	int num;
	int n;
};

void* func1(void *arg) {
	struct qs *q=(struct qs*)arg;
	int num = q->num;
	int n = q->n;
	int i;
	for(i = 0; i < num; i++) {
		printf("\t \t \t Thread 1 %d \n", i);
		usleep(n);
	}
}

void* func2(void *arg) {
	struct qs *q=(struct qs*)arg;
	int num=q->num;
	int n=q->n;
	int i;
	for(i = 0; i < num; i++) {
 		printf("\t \t \t Thread 2 %d \n", i);
		usleep(n);
	}
}

int main(int argc, char *argv[]) {
	pid_t pid;
	int i, n = atoi(argv[1]);    // n microseconds to input from keyboard for delay
	printf("\n Before forking. \n");
	pid = fork();
	if (pid == -1){
		fprintf(stderr, "Can't fork, error %d\n", errno);
	}
	pthread_t thread1, thread2;
	struct qs q1, q2;
	q1.num = 100;
	q1.n = n;
	q2.num = 100;
	q2.n = n;
	pthread_create(&thread1, NULL, func1, &q1);
	pthread_create(&thread2, NULL, func2, &q2);
	pthread_join(thread1, NULL); // Wait for thread1 to execute
	pthread_join(thread2, NULL); // Wait for thread2 to execute

	return 0;
}
