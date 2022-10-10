// Name: Frankie Fazlollahi
// Date: 1/26/2022
// Title: Lab 4 - step 3
// Description: calculate matrix multiplication using threads

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define SIZE 1024

void* matrixMultiply(void *arg);


// Create threads for each row
pthread_t threads[SIZE];

// Initialize matrix to be SIZE x SIZE
double matrixA[SIZE][SIZE], matrixB[SIZE][SIZE], matrixC[SIZE][SIZE];

int main() {
	static int i;
    
    	// Used to initialize seed using CPU time
    	srand(time(NULL));
	int j;
	int k;
    	for(j = 0; j < SIZE; j++) {
        	for(k = 0; k < SIZE; k++) {
            		// Loop through each value in 2d array, and assign it a random value
            		matrixA[j][k] = rand() % 10;
            		// Print to console afterwards
            		printf(" %.2f ", matrixA[j][k]);
        	}
        	printf("\n");
    	}
    	printf("\n");
    
    	// Same code as above but for matrixB
    	for(j = 0; j < SIZE; j++) {
        	for(k = 0; k < SIZE; k++) {
            		matrixB[j][k] = rand() % 10;
            		printf(" %.2f ", matrixB[j][k]);
        	}
        	printf("\n");
    	}

    	printf("\n");
    	// Create threads for each row
    	for(j = 0; j < SIZE; j++)
        	pthread_create(&threads[j], NULL, matrixMultiply, (void *)(size_t)j);
    
    	// Wait for each thread to finish and close before continuing the program
    	for(j = 0; j < SIZE; j++)
        	pthread_join(threads[j], NULL);
    
    	// After matrixC contains the result of multiplying matrices A and B, print each value
    	for(j = 0; j < SIZE; j++) {
        	for(k = 0; k < SIZE; k++) {
            		printf(" %.2f ", matrixC[j][k]);
        	}
        	printf("\n");
    	}
}

void* matrixMultiply(void *arg) {
        int j;
        int k;
        for(j = 0; j < SIZE; j++){
                for(k = 0; k < SIZE; k++){
                        // Loop through matrixC
                        // using (int)(size_t) because arg is passed as (size_t) but needs to be integer for indexing purposes
                        matrixC[(int)(size_t)arg][j] += matrixA[(int)(size_t)arg][k] * matrixB[k][j];
		}
	}
}	
