Name: Smrithi Manickam  
  
  
#### ASSIGNMENT 5 README: Sorting   

    
##### FILES:  
**ALL C FILES HAVE BEEN CLANG FORMATTED**   
    
    
**sorting.c**: This file contains the code to process the getopt entries from the user, and calls the appropriate   
sorting functions as inputted by the user.   
   
   
**bubble.h**: This file is the header file for bubble.c, it contains the bubble sort function prototype.   
   
**bubble.c**: This file contains the bubble sort function implementation. This file is where memory is allocated   
in the heap and freed at the end of the function.   
   
   
**shell.h**: This file is the header file for shell.c, it contains the shell sort function prototype.   
   
**shell.c**: This file contains the shell sort function implementation. This file is where memory is allocated in   
the heap and freed at the end of the function. This is also where the output of the sorted array is printed.   
   
   
**quick.h**: This file is the header file for quick.c, it contains the quick sort function prototypes.   
   
**quick.c**: This file contains the quick sort function implementation. This file is where memory is allocated in   
the heap and freed at the end of the function. This is also where the output of the sorted array is printed.   
    
    
**binary.h**: This file is the header file for binary.c, it contains the binary insertion sort function prototypes.   
   
**binary.c**: This file contains the binary insertion sort function implementation. This file is where memroy is   
allocated in the heap and freed at the end of the function. This is also where the output of the sorted array is   
printed.   
   
   
**DESIGN.pdf**: This file contains the pseudocode for all of the mentioned function files, and also contains the    
answers to the prelab questions.   
   
   
**WRITEUP.pdf**: This file contains a discussion of the time complexities of each sorting algorithm, as well as   
a discussion of what I have learned through implementing each function, and discusses the results of running Make   
Infer and Valgrind on my program.    
   
   
**README.md**    
    
   
**MAKEFILE**: This file is used to compile the sorting.c file. Type "make" or "make all" to compile the code. Then   
type "./sorting" followed by a set of program arguments that indicate which sorting algorithms you would like to run   
as well as the random seed you would like to run with, the array size, and the number of elements you want to print.   
The program argument options are:   
- A which will print the results from all the sorting algorithms   
- b which will print the results from Bubble Sort   
- s which will print the results from Shell Sort   
- q which will print the results from Quick Sort   
- i which will print the results from Binary Insertion Sort   
- p followed by a number n, which will print the first n elements of the sorted array. If this program argument   
isn't included, the program will print 100 elements by default    
- r followed by a number s, which will set the random seed to s. If this program argument isn't included, the   
program will run with a default random seed of 8222022    
- n followed by a number c, which will set the array size to c. If this program argument isn't included, the program   
will run with a default array size of 100   
   
Type "make clean" to remove all the files that are compiler generated, including the "sorting" executable.      
Type "make infer" to display the results of "make infer".   
Type "make valgrind" to run valgrind on the program.   
    
    
    
    
##### MAKE INFER AND VALGRIND RESULTS:   
   
When running make infer, it returned 1 memory leak that was flagged in my shell.c stating that memory calloc()d for   
my gap array (n_array in my code), is not reachable after the line where I check if the calloc() had succeeded. This   
appears to be a false positive memory leak, as I do correctly free my memory for that array at the end of the function.   
I am also certain that there are no actual memory leaks as I free() the calloc()d memory in the heap for each array   
at the end of each function. This is also why valgrind returns no memory leaks possible because all the allocated memory   
is freed in the end.   
    

























