#include <stdio.h>
#include <pthread.h>

char file_in[20];
int BUFFSIZE, NTHREADS;
 
void *go(void *arg) 
{
    	char file_out[20];
    	char buffer[BUFFSIZE];
	sprintf(file_out, "output%d.txt", (int)arg);
   	FILE *in = fopen(file_in, "r");
    	FILE *out = fopen(file_out, "w");
    	while(fread(buffer, sizeof(char), 1, in) != 0)
        	fwrite(buffer, sizeof(char), 1, out);
    	fclose(in);
    	fclose(out);
}

int main (int argc, char *argv[])
{
    	strcpy(file_in, argv[1]);
    	BUFFSIZE = atoi(argv[2]);
    	NTHREADS = atoi(argv[3]);
    	pthread_t threads[NTHREADS];
    	int i;
    	for(i = 0; i < NTHREADS; i++)
        	pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    	for(i = 0; i < NTHREADS; i++)
        	pthread_join(threads[i],NULL);
    	
	return 0;
}
