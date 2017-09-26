#include <stdio.h>
#include <stdlib.h>
#include "sorter.h"

void mergesort(movie array[][col], int a, int b)
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
int getKey(char *word, movie array[][col])
{
	int c = atoi(word), i;
	for(i=0; i<col;i++)
	{
		if(atoi(array[i]) == c)
		{
			return i;
		}
	}	
return NULL;
}
void merge(movie array[][col], int p, int q, int r, char *word)
{
	int i,j,k;
	char *key = word;
	int m1 = q-p+1, m2 = r-q;
	
	movie *left = malloc(sizeof(movie*m1));
	movie *right= malloc(sizeof(movie*m2));

	for(i=0; i<m1; i++)
	{
		left[i] = array[p+i];
	}
	for(j=0; j<m2;j++)
	{
		right[j] = array[q+j+1];
	}

	i=0, j=0,k=p;

	while(i<m1 && j<size2)
	{
		//Compare Code added here
		

	}
}
