// # Name: Frankie Fazlollahi
// # Date: 2/2/2022
// # Title: Lab1 – task 3 
// # Description: producer-consumer problem using semaphores

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

sem_t empty;
sem_t full;
sem_t mutex;

int in = 0;
int out = 0;
int buffer[5];

void *producer(void *arg){
    	int item, i;
    	for(i = 0; i < 5; i++) {
      		item = rand() % 10;
      		sem_wait(&empty);
      		sem_wait(&mutex);
      		buffer[in] = item;
      		printf("Producer %d: Insert Item %d at %d\n", (int)arg,buffer[in],in);
      		in = (in+1)%5;
      		sem_post(&mutex);
      		sem_post(&full);
    	}
}

void *consumer(void *arg){
    	int i;
    	for(i = 0; i < 5; i++) {
      		sem_wait(&full);
      		sem_wait(&mutex);
      		int item = buffer[out];
      		printf("Consumer %d: Remove Item %d from %d\n",(int)arg,item, out);
      		out = (out+1)%5;
      		sem_post(&mutex);
      		sem_post(&empty);
    	}
}

int main(){
    	pthread_t producers[5],consumers[5];
    	sem_init(&mutex, 0, 1);
    	sem_init(&empty,0,5);
    	sem_init(&full,0,0);

    	int i;
    	for(i = 0; i < 5; i++) {
      		pthread_create(&producers[i], NULL, (void *)producer, (void *)i + 1);
    	}
    	for(i = 0; i < 5; i++) {
      		pthread_create(&consumers[i], NULL, (void *)consumer, (void *)i + 1);
    	}

    	for(i = 0; i < 5; i++) {
      		pthread_join(producers[i], NULL);
    	}
    	for(i = 0; i < 5; i++) {
      		pthread_join(consumers[i], NULL);
    	}

    	sem_destroy(&mutex);
    	sem_destroy(&empty);
    	sem_destroy(&full);

   	return 0;

}
