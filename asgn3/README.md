Name: Smrithi Manickam  
  
  
#### ASSIGNMENT 3 README: Tower of Brahma   

  
##### FILES:  
  
**tower.c**: This file contains the code for the recursive and stack implementations of the Tower of Hanoi/Tower of Brahma game.   
   
   
**stack.h**: This file contains the stack function prototypes.   
   
   
**stack.c**: This file contins the stack function implementations that are protoyped in stack.h.   
   
   
**Makefile**: This file is used to compile the tower.c file. Type "make" or "make all" to compile the code. Then type ./tower to display    
the options you can enter. The options are "-s" to run the stack implementation of the game, "-r" to run the recursive implementation of   
the game, and "-n" followed by a number of disks you wish to play the game with. The number of disks entry is optional, and if no number   
is entered, then the game will run with a default number of 5 disks. You can enter "-s" or "-r" or both, and the program will run whichever   
entries you entered.   
   
Type "make clean" to remove all the files that are compiler generated.   
   
One memory leak was documented by "make infer". This memory leak appears to be insignificant and is documented with an explanation in the   
WRITEUP.pdf.   
   
The tower.c file is also clang formatted.   
   
   
**DESIGN.pdf**: This file contains the pseudocode for tower.c, and stack.c. More specifically, it contains an explanation of the iterative   
algorithm and the recursive algorithm, as well as pseudocode and an explanation of the pseudocode for the recursive and stack   
implementations of the game.   
   
   
**WRITEUP.pdf**: This file contains an explanation of the results, and an analysis of the time and space complexities of the recursive    
solution versus the stack implementation. It also contains an explanation of the valgrind results and make infer results.   
   
   
**README.md**   
   
   
##### SUMMARY OF GAME:   
   
This assignment implements C programming code to play the Tower of Hanoi game in two ways: both recursively and using stacks. The user   
enters the number of disks they wish to play with, if no number is entered then the default number of disks is 5. In the game, there are   
three pegs, Peg A, Peg B, and Peg C. All the disks start off on Peg A, with the largest disk being at the bottom, and the smallest disk   
at the top. The goal of the game is to move all the disks from Peg A to Peg B while only moving one disk at a time. The moves also only   
permit a smaller disk being placed on top of a larger disk. For example, disk 4 cannot be placed on top of Disk 2. After all the moves have   
been made, the program is supposed to print the number of moves it took to complete the game. This number should also be the minimum number   
of moves for the given number of disks. This value is calculated using the formula ((2^n) - 1) with n = disks.   
   
   
##### RESOURCES AND EXTRA HELP:   
   
To complete this assignment, I went to two different lab sections. The first one was Oly's lab which I attended at 2 pm on Monday October   
26th. The second lab I attended was Lokesh's lab at 4 pm on Friday October 30th.   
   
To understand the iterative algorithm, I also watched a brief youtube video that explained the iterative pattern. This video provided no   
code, and all the coding was done by me. I simply referred to this video to gain a better understanding of the iterative algorithm. I have   
included my own explanation and understanding of the algorithm in my DESIGN.pdf where I also cited this video. The link to this video is   
provided below:    
https://www.youtube.com/watch?v=cZDydAdFrqg   


