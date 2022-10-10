#include <stdio.h>

int main(int argc, char *argv[]) 
{
    	FILE *fp;
    	int BUFFSIZE = atoi(argv[2]);
    	char buffer[BUFFSIZE];
    	char* filename = argv[1];
    	FILE *outfp = fopen("output", "wb");

    	fp = fopen(filename, "r");
    	if (fp == NULL){
        	printf("Could not open file %s", filename);
        	return 1;
    	}
    	
	while (fread(buffer, BUFFSIZE, 1, fp))
        	fwrite(buffer, BUFFSIZE, 1, outfp);
    	fclose(fp);
    	fclose(outfp);
    	
	return 0;
}
