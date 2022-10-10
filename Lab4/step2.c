// Name: Frankie Fazlollahi
// Date: 1/26/2022
// Title: Lab4 – task 2
// Description: Simple multi-threaded program that creates 20 threads and displays their info to user
// Same program as step 1 but removed the 2nd for loop.

/**************************************************************
* threadHello.c - simple multi-threaded program.            *
*   compile with: >gcc -lp threadHello.c -o threadHello       *
*
**************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 20

void *go(void *);
pthread_t threads[NTHREADS];
int main() {
        static int i;
        for (i = 0; i < NTHREADS; i++)
                pthread_create(&threads[i], NULL, go, &i);
        printf("Main thread done.\n");
}
void *go(void *arg) {
        printf("Hello from thread %d with thread ID %d \n", *(int *)arg,
        (int)pthread_self());
        return (NULL);
}
