#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorter.h"

void mergesort(movie array[][28], int a, int b)
{
//a(p) is left index, b(r) is right, m(q) is middle
	int l = a, r =b, m;

	if(l<r)
	{
		m = (l+r)/2;
		mergesort(array,l,m);
		mergesort(array,m+1, r);
		merge(array, l, m, r);
	}
}

//This function loops into columns of the array to search for 
//the index of the key word given to sort by
int getKey(char *word, movie array[][28])
{
	int c = atoi(word), i, w;
	for(i=0; i<28;i++)
	{
		w = atoi(array[0][i]);
		if( w == c)
		{
			return i;
		}
	}	
return 0;
}
void merge(movie array[][28], int p, int q, int r, char *word)
{
	int i,j,k;
	char *key = word;
	int m1 = q-p+1, m2 = r-q;
	
	movie *left = (movie*)  malloc(sizeof(movie)*m1);
	movie *right = (movie*) malloc(sizeof(movie)*m2);

	for(i=0; i<m1; i++)
	{
		memcpy(&array[p+i], &left[i], sizeof((array[p+i])));
	}
	for(j=0; j<m2;j++)
	{
		memcpy(&array[q+j+1], &right[j], sizeof((array[q+j+1])));
	}

	i=0, j=0,k=p;

	while(i<m1 && j<m2)
	{
		//Compare Code added here
		

	}

free(left);
free(right);
}
