#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorter.h"

void mergesort(movie **array, int a, int b, char *word)
{
	//a(p) is left index, b(r) is right, m(q) is middle
	char *key = word;
	int l = a, r =b, m;
	if(l<r)
	{
		m = (l+r)/2;
		mergesort(array,l,m, key);
		mergesort(array,m+1, r, key);
		merge(array, l, m, r, key);
	}
}



void print(movie **info, int numOfEntries){
	int i;

//NOTE: Need to input file to args in fprintf
	for(i =0; i< numOfEntries; i++)
	{
		fprintf("%s, %s, %d, %d, %d, %d, %s, %d, %d, %s, %s, %s, %d, %d, %s, %d, %s, %s, %d, %s, %s, %s, %d, %d, %d, %3.1f, %4.2f, %d \n", 
			info[i]->color, info[i]->director_name, info[i]->num_critic_reviews,
			info[i]->duration, info[i]->director_facebook_likes,
			info[i]->actor_3_facebook_likes, info[i]->actor_2_name,
			info[i]->actor_1_facebook_likes, info[i]->gross, 
			info[i]->actor_1_name, info[i]->movie_title, 
			info[i]->num_voted_users, info[i]->cast_total_facebook_likes,
			info[i]->actor_3_name, info[i]->facenumber_in_poster,
			info[i]->plot_keywords, info[i]->movie_imdb_link,
			info[i]->num_user_for_reviews, info[i]->language,
			info[i]->country, info[i]->content_rating, info[i]->budget,
			info[i]->title_year, info[i]->actor_2_facebook_likes,
			info[i]->imdb_score, info[i]->aspect_ratio, 
			info[i]->movie_facebook_likes );
	}
}

//determines key for struct purposes
int getKey(char *key)
{
	char *var = key;
	if(strcmp(var, "Color") == 0)
		return  1;
	if(strcmp(var, "director_name") == 0)
		return 2;
	if(strcmp(var, "num_critic_reviews") == 0)
		return 3;
	if(strcmp(var, "duration") == 0)
		return 4;
	if(strcmp(var, "director_facebook_likes") == 0)
		return 5;
	if(strcmp(var, "actor_3_facebook_likes") == 0)
		return 6;
	if(strcmp(var, "actor_2_name") == 0)
		return 7;
	if(strcmp(var, "actor_1_facebook_likes") == 0)
		return 8;
	if(strcmp(var, "gross") == 0)
		return 9;
	if(strcmp(var, "genres") == 0)
		return 10;
	if(strcmp(var, "actor_1_name")== 0)
		return 11;
	if(strcmp(var, "movie_title") == 0)
		return 12;
	if(strcmp(var, "num_voted_users") == 0)
		return 13;
	if(strcmp(var, "cast_total_facebook_likes") == 0)
		return 14;
	if(strcmp(var, "actor_3_name;") == 0)
		return 15;
	if(strcmp(var, "facenumber_in_poster") == 0)
		return 16;
	if(strcmp(var, "plot_keywords") == 0)
		return 17;
	if(strcmp(var, "movie_imdb_link") == 0)
		return 18;
	if(strcmp(var, "num_user_for_reviews") == 0)
                return 19;
        if(strcmp(var, "language") == 0)
                return 20;
        if(strcmp(var, "country") == 0)
                return 21;
        if(strcmp(var, "content_rating") == 0)
                return 22;
        if(strcmp(var, "budget") == 0)
                return 23;
        if(strcmp(var, "title_year") == 0)
                return 24;
        if(strcmp(var, "actor_2_facebook_likes") == 0)
                return 25;
	if(strcmp(var, "imdb_score") == 0)
                return 26;
        if(strcmp(var, "aspect_ratio") == 0)
                return 27;
	if(strcmp(var, "movie_facebook_likes") == 0)
                return 28;



	
return 0;
}
/*
//Must put array into params
void mergeString(movie *left, movie *right, int keyEle, int lI, int mI, int rI, int size1, int size2)
{
	int key = keyEle;
	int l = lI, r = rI, m = mI, m1 = size1, m2 = size2;
	switch(key)
	{
		case 1://color 
		case 2://direcor_name 
		case 7://actor_2_name
		case 10://genres
		case 11://actor_1_name
		case 12://movie_title
		case 15://actor_3_name
		case 17://plot_keywords
		case 18://movie_imdb_link
		case 20://language
		case 21://country
		case 22: //content_rating
			
	}
	
	

}


//Must put array into params
void mergeInt(movie *left, movie *right, int keyEle, int lI, int mI, int rI, int size1, int size2)
{
	int key = keyEle;
	int l = lI, r = rI, m = mI, m1 = size1, m2 = size2;
	switch(key)
	{
		case 3://num_critic_reviews
		case 4://duration
		case 5://director_facebook_likes
		case 6://actor_3_facebook_likes
		case 8://actor_1_facebook_likes
		case 9://gross
		case 13://num_voted_users
		case 14://cast_total_facebook_likes
                case 16://facenumber_in_poster
                case 19://num_user_for_reviews
                case 23://budget
                case 24://title_year
                case 25://actor_2_facebook_likes
                case 28://movie_facebook_likes
	}
}



void mergeFloat(movie *array, movie *left, movie *right, int keyEle, int lI, int mI, int rI, int size1, int size2)
{
	int key = keyEle;
	int l = lI, r = rI, m = mI, m1 = size1, m2 = size2;
	switch(key)
	{
		case 26://imdb_score
			while(l<m1 && r<m2)
			{
				if(left[l].imdb_score <= right[l].imdb_score)
				{
					array[m] = left[l];
					l++;	
				}else
				{
					array[m] = right[r];
					r++;
				}
				m++;
			}	

			while(l<m1)
			{
				array[m] = left[l];
				l++;
				m++;
			}
			while(r<m2)
			{
				array[m] = right[r];
				r++;
				m++;
			}
		case 27://aspect_ratio
	}

}

*/


void merge(movie **array, int p, int q, int r, char *word)
{
	int i,j,k;
	char *keyWord = word;
	int m1 = q-p+1, m2 = r-q;
	
	movie **left = (movie**)  malloc(sizeof(movie)*m1);
	movie **right = (movie**) malloc(sizeof(movie)*m2);

	int key = getKey(keyWord);

	for(i=0; i<m1; i++)
	
		left[i] = array[p+i];
	
	for(j=0; j<m2;j++)
		right[j] = array[q+j+1];

	i=0, j=0,k=p;



	//mergeString
	if(key == 1 || key == 2 || key == 7 || key == 10 || key == 11
	   || key == 12 || key == 15 || key == 17 || key == 18 || key == 20 || 
		 key == 21 || key == 22)
	{
		//mergeString(left, right, key, i,j,k, m1,m2);
		char *temp1 = malloc(50*sizeof(char));
		char *temp2 = malloc(50*sizeof(char));
		
		while(i<m1 && j<m2)
		{
			temp1 = (char*) getString(i);
			temp2 = (char*) getString(j);
			if(strcmp(temp1, temp2) < 0 || strcmp(temp1,temp2) == 0)
			{
				array[k] = left[i];
				i++;
			}
			else
			{
				array[k] = right[j];
				j++;
			}
			k++;
		}  	
		
		while(i<m1)
		{
			array[k] = left[i];
			i++;
			k++;
		}	
		while(j<m2)
		{
			array[k] = right[j];
			j++;
			k++;
		}
			
		free(temp1);
		free(temp2);
	}
	//mergeInt
	else if(key == 3 || key == 4 || key == 5 || key == 6 || key == 8 
		|| key == 9 || key == 13 || key == 14 || key == 16 || key == 19 ||
		      key == 23 || key == 24 || key == 25 || key == 28 )
	{
		//mergeString(left,right,key,i,j,k,m1,m2);
		int temp1;// = malloc(20*sizeof(char));
                int temp2;// = malloc(20*sizeof(char));
                while(i<m1 && j<m2)
                {
                        temp1 = *getInt(i);
                        temp2 = *getInt(j);
                        if(temp1 <= temp2)
                        {
                                array[k] = left[i];
                                i++;
                        }
                        else
                        {
                                array[k] = right[j];
                                j++;
                        }
                        k++;
                }       

                while(i<m1)
                {
                        array[k] = left[i];
                        i++;
                        k++;
                }
                while(j<m2)
                {
                        array[k] = right[j];
                        j++;
                        k++;
                }
                 
             //   free(temp1);
             //   free(temp2);

	}
	//mergeFloat		
	else if(key == 26 || key == 27)
	{
		//mergeFloat(array,left,right,key,i,j,k,m1,m2);
		float *temp1 = malloc(20*sizeof(char));
                float *temp2 = malloc(20*sizeof(char));
                while(i<m1 && j<m2)
                {
                        temp1 = getFloat(i);
                        temp2 = getFloat(j);
                        if(temp1 <= temp2)
                        {
                                array[k] = left[i];
                                i++;
                        }
                        else
                        {
                                array[k] = right[j];
                                j++;
                        }
                        k++;
                }

                while(i<m1)
                {
                        array[k] = left[i];
                        i++;
                        k++;
                }
                while(j<m2)
                {
                        array[k] = right[j];
                        j++;
                        k++;
                }

                free(temp1);
                free(temp2);

	}
	

free(left);
free(right);
}
