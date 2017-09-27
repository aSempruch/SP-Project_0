#ifndef _SORTER_H_
#define _SORTER_H_

typedef struct movie_
{
	char *color;
	char *director_name;
	int num_critic_reviews;
	int duration;
	int director_facebook_likes;
	int actor_3_facebook_likes;
	char *actor_2_name;
	int actor_1_facebook_likes;
	int gross;
	char *genres;
	char *actor_1_name;
	char *movie_title;
	int num_voted_users;
	int cast_total_facebook_likes;
	char *actor_3_name;
	int facenumber_in_poster;
	char *plot_keywords;
	char *movie_imdb_link;
	int num_user_for_reviews;
	char *language;
	char *country;
	char *content_rating;
	int budget;
	int title_year;
	int actor_2_facebook_likes;
	float imdb_score;
	float aspect_ratio;
	int movie_facebook_likes;
}movie;

char* getString(int element);
int* getint(int element);
float* getFloat(int element);
void insert(char* line);
void mergeFloat(movie *array, movie *left, movie *right, int keyEle, int lI, int mI, int rI, int size1, int size2);
void mergeString(movie *array, movie *left, movie *right, int keyEle, int lI, int mI, int rI, int size1, int size2);
void mergeInt(movie *array, movie *left, movie *right, int keyEle, int lI, int mI, int rI, int size1, int size2);
void merge(movie *array, int p, int q, int r, char *word);
int getKey(char *word);
void mergesort(movie *array, int a, int b, char *word);

#endif
