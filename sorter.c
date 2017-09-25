#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *stream[1028];

int main(int argc, char* argv[])
{
	
	if(argc != 3)
	{
		printf("ERROR00: Invalid number of inputs");
		return 0;
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
	   
	 /*		STEP 2.1
	  *Count number of entries and columns
	  */
	int numOfEntries = 0, numOfColumns = 0;
	int buff;
	while(!feof(fp))
	{
		buff = (char)fgetc(fp);
		if(numOfEntries == 0){
			if(buff == ',')
				numOfColumns++;
		}
		if(buff == '\n')
			numOfEntries++;						
	}
	

	const char* info[numOfEntries][numOfColumns];
	rewind(fp);
	int ctr, row=1, col=0;
	char *token;
	
	/*		STEP 2.2
	 *Wrtie file into array
	 
	 *Since we have 28 feilds, we can use a counter to determine which feild we are currently on
	 *That way with testcases that don't have certain feilds in them we can increment the counter to
	 *go to the next element in the array
	**/

	
	/*NOTE TO ALAN:
	 *https://www.techwalla.com/articles/how-to-read-a-csv-file-in-c
	*/
	/*while(!feof(fp))
	{
		fgets(stream,sizeof(stream),fp);
		token = strtok(stream, ",");
		
		
		
		
	}*/

	printf("NumOfEntries: %d   NumOfColumns: %d\n", numOfEntries, numOfColumns);

	fclose(fp);
	return 0;
}
