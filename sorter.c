#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
	
	if(argc != 3)
	{
		printf("ERROR00: Invalid number of inputs");
		exit(1);
	}	
	
	/*		STEP 1
	 *Note: 'info' will be the array the file will be written into.
	 *Also the file pointer and opener will be innitalized here too. 
	 */
	char *file = argv[1];
	FILE *fp = fopen(file,"r");
		
	if(!(fp = fopen(argv[1],"r")))
	{
		printf("ERROR01: Invalid or empty file. Try again.\n");
		return 0;
	}
	else if(fp == NULL)
	{
		printf("ERROR02: Trouble opening file. Try again.\n");
		return 0;
	}
	   
	 /*		STEP 2
	  *Start writing the file into the array
	  */
	int numOfEntries = 0, numOfColumns = 0;
	//Counts number of entries and columns
	char buff;
	while(!feof(fp))
	{
		fscanf(fp, "%c", buff);
		if(numOfEntries == 0){
			if(buff == ',')
				numOfColumns++;
		}
		if(buff = 'C'){
			fscanf(fp, "%c", buff);
			if(buff = 'O'){
				fscanf(fp, "%c", buff);
				if(buff = 'L'){
					fscanf(fp, "%c", buff);
					if(buff = 'O'){
						fscanf(fp, "%c", buff);
	                                        if(buff = 'R'){
							numOfEntries++;
						}
					}

				}
			}
		}
	}
	const char* info[numOfEntries][numOfColumns];

return 0;
}
