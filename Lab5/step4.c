// # Name: Frankie Fazlollahi
// # Date: 2/2/2022
// # Title: Lab1 – task 4
// # Description: producer-consumer problem using condition variables

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

pthread_cond_t cv;
pthread_mutex_t mutex;

int in = 0;
int out = 0;
int count = 0;
int buffer[5];

void *producer(void *arg)
{
    	int item, i;
    	for(i = 0; i < 5; i++) {
      		item = rand() % 10;
      		pthread_mutex_lock(&mutex);
      		if(count == 5) {
        		pthread_cond_wait(&cv, &mutex);
       		}
      		buffer[in] = item;
      		printf("Producer %d: Insert Item %d at %d\n", (int)arg,buffer[in],in);
      		in = (in+1)%5;
      		count++;
      		pthread_cond_signal(&cv);
      		pthread_mutex_unlock(&mutex);
    	}
}

void *consumer(void *arg)
{
    	int i;
    	for(i = 0; i < 5; i++) {
      		pthread_mutex_lock(&mutex);
      		if(count == 0) {
         		pthread_cond_wait(&cv, &mutex);
        	}
      		int item = buffer[out];
      		printf("Consumer %d: Remove Item %d from %d\n",(int)arg,item, out);
      		out = (out+1)%5;
      		count--;
      		pthread_cond_signal(&cv);
      		pthread_mutex_unlock(&mutex);
    	}
}

int main()
{
    	pthread_t producers[5],consumers[5];
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
    	pthread_cond_destroy(&cv);
    	pthread_mutex_destroy(&mutex);

    	return 0;
}
