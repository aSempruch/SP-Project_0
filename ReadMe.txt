Systems Programming
Assignment 0: Merge Sort
Sarah Khasawneh && Alan Sempruch


Input:
	The Merger is designed to take in a csv file with 28 distinct categories in which the output file can by sorted by.  Each of these 28 is either a string of characters, an integer number, or a float.  
	
Output:
	The output is a new csv file that lists the resulting array in acending order based of the keyword given upon running the program. The first line of the file always prints the 28 distinct categories. 		

Design:
	The csv file is read from stdin and written into a text file for easier use. 
	After the csv file has been written, the file pointer is rewinded to the start of the written file and is then passed line by line into our personalized tokenizer. 
	As it tokenizes, it passes the string/int/float into their respected functions and an address of where the variable is strorred is returned after being saved into the struct array.
	After the file has been insterted into the array in the order given within the file, and all error checks have been passed, mergesort is then called on the array along 
	with the starting index, end index and keyword retrieved from argv[1]. The mergesort aspect is done recursivley, breaking apart the array until it is left with individual 
	elements to merge back. After it has reached individual elements, merge is then called to which it merges the array back into ascending order. 

sorter.h:

	Our h-file is consisted of all function headers used within the program, as well as the struct that was used to store all the data. 
	char **getString(): Takes in info array, the entery number, and element. Returns the address of where the specfic string category is saved within the specific struct and array.
	long **getInt(): Takes in the same params as getString and returns the address of where the int is storred from the specific element.
	float **getFloat(): same as the above but with floats.

	void intert(): Inserts the the line taken from the file and tokenizes it.
	void merge(): Takes in the array, left index, middle index, right index, and key to sort by. This does all the sorter and merging for the program
	int getKey(): takes in the key and return the position in which it is found within the struct.
	void mergesort(): takes in array, left index, right index, and key. Recursively breaks the array into individual elements. 
	void print(): takes in the arary, and numbr of entries, and prints the results in order. 

Assumptions:
	
Difficulties:
	One major problem we ran into other than segmentation faults was our algorithm was duplicating certain elements and overwriting others. This lead to an incorrect output. 
	After extensive debugging we found out it was always the last element in the array that was being duplicated and printing twice. 
	Another difficulty was trying to visualize the recusion and writing it out while using smaller test cases in order to map out the process. 
