// Name: Frankie Fazlollahi
// Date: 1/19/2022
// Title: Lab3 - part 7
// Description: Creating 10 threads and seeing how they run concurrently (fixing error from part 6)

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main() {
    	int i;
    	for (i = 0; i < NTHREADS; i++)  
        	// cast to void * to pass the actual object i and use size_t for i to make sure 
		// that we create the object locally and it doesn't use the i from within our main(),
        	pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
                                                                        
    	for (i = 0; i < NTHREADS; i++) {
		printf("Thread %d returned\n", i);
        	pthread_join(threads[i],NULL);
    	}
    	printf("Main thread done.\n");
    	return 0;
}

void *go(void *arg) {
	// Update line to adjust for the size_t object, and cast to (int) because we use %d
	printf("Hello from thread %d with iteration %d\n",  (int)pthread_self(), (int) (size_t *)arg);
 	return 0;
}
