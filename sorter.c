#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "sorter.h"

int index = 0;
char stream[1028];
movie** info;

void allocate(int rows){
	int r;
	info = malloc(rows * sizeof(movie*));
	for(r = 0; r < rows; r++){
		info[r] = (movie*)malloc(sizeof(movie));
	}
}

void insert(char* line){
	int k, element = 0;
	//tokenize elements and insert them into "info" structure
	for(k = 0; k < strlen(line); k++){
		element++;
		//String type
		if(element == 1 || element == 2 || element == 7 || element == 10 || element == 11 || element == 12 || element == 15 || element == 17 || element == 18 || element == 20 || element == 21 || element == 22){
			info[index]->color = (char*)malloc(128*sizeof(char));
			int position = 0;
			while(line[k] != ','){
				info[index]->color[position] = line[k];
				position++;
				k++;
			}
			k++;
		}
	}
}	

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
	int numOfEntries = 0, numOfColumns = 1;
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

	rewind(fp);



	/*		STEP 2.2
	 *Write file into array
	 
	 *Since we have 28 feilds, we can use a counter to determine which feild we are currently on
	 *That way with testcases that don't have certain feilds in them we can increment the counter to
	 *go to the next element in the array
	**/
	allocate(numOfEntries);
	while(!feof(fp))
	{
		fgets(stream,sizeof(stream),fp);
		insert(stream);
	}

	printf("NumOfEntries: %d   NumOfColumns: %d\n", numOfEntries, numOfColumns);

	fclose(fp);
	return 0;
}
