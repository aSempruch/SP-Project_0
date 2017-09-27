#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "sorter.h"

int entry;
char stream[1024];
movie** info;

void allocate(int rows){
	int r;
	info = malloc(rows * sizeof(movie*));
	for(r = 0; r < rows; r++){
		info[r] = (movie*)malloc(sizeof(movie));
	}
}

void deallocate(int rows){
	int r;
	for(r = 0; r < rows; r++){
		free(&info[r]->color);
		free(&info[r]->director_name);
		free(&info[r]->actor_2_name);
		free(&info[r]->genres);
		free(&info[r]->actor_1_name);
		free(&info[r]->movie_title);
		free(&info[r]->actor_3_name);
		free(&info[r]->plot_keywords);
		free(&info[r]->movie_imdb_link);
		free(&info[r]->language);
		free(&info[r]->country);
		free(&info[r]->content_rating);
		free(info[r]);
	}
	free(info);
}

//Returns a char pointer to the requested element in the struct
char* getString(int element){
	switch(element){
		case 1:
			return info[entry]->color;
		case 2:
			return info[entry]->director_name;
		case 7:
			return info[entry]->actor_2_name;
		case 10:
			return info[entry]->genres;
		case 11:
			return info[entry]->actor_1_name;
		case 12:
			return info[entry]->movie_title;
		case 15:
			return info[entry]->actor_3_name;
		case 17:
			return info[entry]->plot_keywords;
		case 18:
			return info[entry]->movie_imdb_link;
		case 20:
			return info[entry]->language;
		case 21:
			return info[entry]->country;
		case 22:
			return info[entry]->content_rating;
	}
	return NULL;
}

int* getInt(int element){
	switch(element){
		case 3:
			return &info[entry]->num_critic_reviews;
		case 4:
			return &info[entry]->duration;
		case 5:
			return &info[entry]->director_facebook_likes;
		case 6:
			return &info[entry]->actor_3_facebook_likes;
		case 8:
			return &info[entry]->actor_1_facebook_likes;
		case 9:
			return &info[entry]->gross;
		case 13:
			return &info[entry]->num_voted_users;
		case 14:
			return &info[entry]->cast_total_facebook_likes;
		case 16:
			return &info[entry]->facenumber_in_poster;
		case 19:
			return &info[entry]->num_user_for_reviews;
		case 23:
			return &info[entry]->budget;
		case 24:
			return &info[entry]->title_year;
		case 25:
			return &info[entry]->actor_2_facebook_likes;
		case 28:
			return &info[entry]->movie_facebook_likes;
	}
	return NULL;
}

float* getFloat(int element){
	switch(element){
		case 26:
			return &info[entry]->imdb_score;
		case 27:
			return &info[entry]->aspect_ratio;
	}
	return NULL;
}




void insert(char* line){
	int k, element = 0;
	//tokenize elements and insert them into "info" structure
	for(k = 0; k < strlen(line); k++)
	{
		element++;
		//String type handling
		if(element==1||element==2||element==7||element==10||element==11||element==12||element==15||element==17||element==18||element==20||element==21||element==22){
			char* val = getString(element);
			
			//Dynamically allocate string size
			val = (char *)malloc(sizeof(char));
			
			int position = 0;
			while(line[k] != ','){
				val = (char *)realloc(val,position+2);
				strncpy(&val[position], &line[k], 1);
				position++;
				k++;
			}
			val[position+1] = '\0';
			printf("String: %s\n", val);
		}


		//Int type handling
		if(element==3||element==4||element==5||element==6||element==8||element==9||element==13||element==14||element==16||element==19||element==23||element==24||element==25||element==28){
			int* val = getInt(element);
			char* temp = malloc(sizeof(char)*128);
			int position = 0;
			while(line[k] != ',' && line[k] != '\n'){
				strncpy(&temp[position],&line[k], 1);
				position++;
				k++;
			}
			*val = atoi(temp);
			//printf("About to free temp\n");
			free(temp);
		}


		//Float type handling
		if(element==26||element==27){
			float* val = getFloat(element);
			char* temp = malloc(sizeof(char)*128);
			int position = 0;
			while(line[k] != ','){
				temp[position] = line[k];
				position++;
				k++;
			}
			*val = atof(temp);
			free(temp);
		}
	}
}	







int main(int argc, char* argv[])
{
	
	if(argc != 3)
	{
		printf("ERROR00: Invalid number of inputs.\n");
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
	entry = 0;
	   
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
	int k = 0;
	while(!feof(fp))
	{
		
		fgets(stream,sizeof(stream),fp);
		//printf("Stream --> %s\n", stream);
		if(k != 0)
			insert(stream);
		else
			k = 1;		
	}

	deallocate(numOfEntries);

	printf("NumOfEntries: %d   NumOfColumns: %d\n", numOfEntries, numOfColumns);
	fclose(fp);
	return 0;
}
