#include <stdio.h>

int main(int argc, char *argv[]) 
{
    	FILE *fp;
    	int BUFFSIZE = atoi(argv[2]);
    	char buffer[BUFFSIZE];
    	char* filename = argv[1];
    	fp = fopen(filename, "r");
    	if (fp == NULL){
        	printf("Could not open file %s", filename);
        	return 1;
    	}

    	while (fgets(buffer, BUFFSIZE, fp) != NULL)
        	printf("%s", buffer);
    	fclose(fp);
    	
	return 0;
}
