Systems Programming
Assignment 0: Merge Sort
Alan Sempruch, Sarah Khasawneh


Input:
	The Merger is designed to take in a csv file with 28 distinct categories in which the output file can by sorted by.  Each of these 28 categories is either a string of characters, a long, or a float.

Use:
	
	./sorter <value type> <column>

    <value type> - specifies what value type to sort on. The supported value types are:
			-c : column
	<column> - specifies which column to sort the file by. Supported column names are:
			color
			string
			num_critic_for_reviews
			duration
			director_facebook_likes
			actor_3_facebook_likes
			actor_2_name
			actor_1_facebook_likes
			gross
			genres
			actor_1_name
			movie_title
			num_voted_users
			cast_total_facebook_likes
			actor_3_name
			facenumber_in_poster
			plot_keywords
			movie_imdb_link
			num_user_for_reviews
			language
			country
			content_rating
			budget
			title_year
			actor_2_facebook_likes
			imdb_score
			aspect_ratio
			movie_facebook_likes
	
	Pipe the input file through STDIN as such
		cat file.csv | ./sorter -c movie_title

Output:
	The output is in the format of a csv file that lists the resulting array in acending order based of the keyword given upon running the program. The first line of the file contains the 28 distinct categories. In order to save the output to a file, proceed the command with " > output_file_name.csv"

Design:
	The csv file is read from stdin and written into a temporary file, named .temp, for easier use. The file is removed on program exit.
	After the csv file has been stored in the temp file, a line count is performed to determine the how much size must be malloced for the array. The file pointer is then rewound to the
	start of the temp file and the file contents are passed line by line into our personalized tokenizer. The tokenizer removes starting and trailing whitespaces.
	As it tokenizes, it passes the string/int/float into their respected functions and an address of where the variable is strorred is returned after being saved into the struct array.
	After the file has been insterted into the array in the order given within the file, and all error checks have been passed, mergesort is then called on the array along 
	with the starting index, end index and keyword retrieved from argv[1]. The mergesort aspect is done recursivley, breaking apart the array until it is left with individual 
	elements to merge back. After it has reached individual elements, merge is then recursively called, which merges the array back into ascending order. 

sorter.h:

	Our h-file consists of all function headers used within the program, as well as the struct that was used to store all the data. 
	char **getString(): Takes in info array (array of structs containing the data read from stdin), the entry number, and the requested element. Returns the address of where the specfic string category is saved within the specific struct and array.
	long **getInt(): Takes in the same params as getString and returns the address of where the int is storred from the specific element.
	float **getFloat(): same as the above but with floats.

	void insert(): Inserts the the line read from the file and tokenizes it, then inserts the data into the our array of structs.
	void merge(): Takes in the array, left index, middle index, right index, and key to sort by. This does all the sorter and merging for the program
	int getKey(): takes in the key and return the position in which it is found within the struct.
	void mergesort(): takes in array, left index, right index, and key. Recursively breaks the array into individual elements. 
	void print(): takes in the array, and the number of entries, then prints the final data from the array of structs  in order. 

Assumptions:
	CSV file used as input has exactly 28 categories, which are labeled exactly the same way (as in the test file we were given).
	
Difficulties:
	One major problem we ran into other than segmentation faults was our algorithm was duplicating certain elements and overwriting others. This lead to an incorrect output. 
	After extensive debugging we found out it was always the last element in the array that was being duplicated and printing twice. To resolve this, we did not pass the duplicated element into our sorting function. 
	We also found it a challange to avoid writing individual blocks of code for each variable name in the struct. To resolve this, we created 3 functions that handle longs, strings, and floats respectively. Each function takes in the column number and row number, and returns a pointer to the requested variable. Thanks to this, we only had to write three blocks of code, instead of 28.
	Another difficulty was trying to visualize the recusion and writing it out while using smaller test cases in order to map out the process. 
