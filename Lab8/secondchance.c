// Name: Frankie Fazlollahi
// Date: 2/23/2022 
// Title: Lab 8
// Description: Second Chance Page Replacement

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct{     
        int pageno;
        int second_chance;
}ref_page;

int main(int argc, char *argv[]) {
    	int cacheSize = atoi(argv[1]);
    	ref_page cache[cacheSize]; 
    	char charCache[100];
    	int totalFaults = 0; 
    	int totalRequests = 0;
    	int counter = 0;
    	int i, j, k, page_num;
    	int found;
    	
	for(i = 0; i < cacheSize; i++) 
	{                               					// Initialize array with -1 and second_chance = 0
        	cache[i].pageno = -1;
        	cache[i].second_chance = 0;
    	}

    	while(fgets(charCache, 100, stdin)) 
	{
        	page_num = atoi(charCache);
        	totalRequests++;
        	for(i = 0; i < cacheSize; i++) 
		{                           					// Loop through array
            		if(cache[i].pageno == page_num) 
			{                   					// If we find the number in array
                		cache[i].second_chance = 1;                     // Set that second_chance to 1
                		found = 0;                                      // And we found the number
                		break;
            		}
            		if(i == cacheSize-1)                                   	// If we didn't find and array full
                		found = 1;                                      // Set found bit to 1
        	}
        	if(found) 
		{                                             			// If we didn't find
            		printf("Page %d caused a fault\n", page_num);
            		totalFaults++;
            		for(k = counter; k < cacheSize; k++) 
			{                 					// Loop through array
                		if(cache[k].second_chance == 1) 
				{               				// Check if second chance bit is 1
                    			cache[k].second_chance = 0;            	// Set that second chance back to 0
                    			counter++;                  
                    			if(counter == cacheSize) 
					{                     			// If we hit end of array
                        			counter = 0;                    // Reset counter to 0
                        			k = 0;                         	// And set our iterator to 0
                    			}
                		}
                		else 
				{                                          	// Else, not second chance bit is 1
                    			cache[k].pageno = page_num;             // Just insert number as usual
                    			cache[k].second_chance = 0;
                    			counter = (counter+1) % cacheSize;
                    			break;
                		}
            		}
        	}
    	}
    
	double hitrate = (totalRequests - totalFaults) / (double)totalRequests;
    	printf("%d Total Page Faults with %d Total Page Requests\n", totalFaults, totalRequests);
    	printf("Second Chance Hit rate = %f\n", hitrate);
    	
	return 0;
}
