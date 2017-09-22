#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	
	if(argc != 3)
	{
		printf("ERROR00: Invalid number of inputs");
		exit(1);
	}	
	
	/*
	 *Note: 'info' will be the array the file will be written into.
	 *Also the file pointer and opener will be innitalized here too. 
	 */
	char *file = argv[1];
	FILE *fp = fopen(file,"r");
	const char* info[5001][29];
	
	if(!(fp = fopen(fp))
	{
		printf("ERROR01: Invalid or empty file. Try again.\n");
		return 0;
	}
	else if(fp == NULL)
	{
		printf("ERROR02: Trouble opening file. Try again.\n");
		return 0;
	}
		
	return 0;
}
