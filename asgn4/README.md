Name: Smrithi Manickam  
  
  
#### ASSIGNMENT 4 README: Bit Vectors and Primes    
    
    
##### FILES:  
**ALL C FILES HAVE BEEN CLANG FORMATTED**   
    
   
**sequence.c**: This file contains the code to output mersenne, lucas, and fibonacci primes, as well as the code to   
print the palindromic primes in Base 2, Base 9, Base 10, and Base 23.
   
   
**bv.h**: This file contains the bit vector function prototypes.   
   
   
**bv.c**: This file contains the bit vector function implementations.   
   
   
**sieve.h**: This file contains the sieve function prototype.    
   
   
**sieve.c**: This file contains the sieve function implementation.   
   
   
**Makefile**: This file is used to compile the sequence.c file. Type "make" or "make all" to compile the code. Then   
type ./sequence to display the options you can enter. The options are "-s" to print the primes and whether they are   
Mersenne primes, Lucas primes, Fibonacci primes, or none, "-p" to print the palindromic primes in Base 2, 9, 10, and   
23, and "-n" followed by a maximum number that is included in the number of primes you want to test (between 2 and   
the maximum number). The default maximum number is 1000, so if no "-n" option is entered, the program will   
automatically test primes between 2 and 1000. If no number is entered after the "-n" option, then the program will   
print an error message.   
   
Type "make clean" to remove all the files that are compiler generated.   
   
    
**DESIGN.pdf**: This file contains the pseudocode for sequence.c and bv.c, and also contains the answers to the   
prelab questions.   
   
   
**README.md**   
   
   
   
##### MAKE INFER AND VALGRIND RESULTS:   
   
When running make infer, it returned 1 memory leak that was flagged in my bv.c saying that memory malloc()d by my   
bv_create() function is not reachable after the function ends despite me returning the BitVector V. However, in my   
implementation of these functions, when creating each BitVector, I do free the heap memory allocated for the   
BitVector and BitVector items using bv_delete(). This is also why valgrind returns no memory leaks possible because    
all the allocated memory is freed in the end. 

























