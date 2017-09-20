# SystemsProgramming-Project1

Outline:
1. Error Checking
    - Check appropriate amout of commandline inputs
    - Check if database file has contents
    - Check if requested category exists in database
    
2. Read data into array of structs
    - Read first row of database and place into global struct variable
    - Read each row, place into individual struct, place in unsorted array
    - Inner loop writes data to struct and is managed by counter with the value of the amount of categories
    - Save sorting keyword into variable
    - Pass sorting keyword and pointer to array into mergesort.c function
    
3. Mergesort made up of 2 functions
    - Mergesort(char* data, int num1, int num2)
        - Recursively breaks up the array by halves
        - Once split up, call on Merge()
    - Merge(char* data, int p, int q, int r)
        - Puts array back together in sorted order based on keyword
        
4. Exit
    - Write sorted array into .csv file