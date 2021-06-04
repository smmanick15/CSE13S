#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "stack.c"

// Function prototypes:
void Recur(int disks, char init_peg, char temp_peg, char final_peg); 
void StackFunction(int disks, char a, char c, char b);

// Global variable to count the number of moves, used by Recur() and
// StackFunction()
int nummoves = 0;

int main(int argc, char **argv) {

  int a = 0; // Getopt variable
  int disks = 5; // Default number of disks, changed if user enters "-n"
  char *validentries = "srn:"; // Valid getopt entries
  bool recursivefunc = false; //Boolean variable for Recursive Function
  bool stackfunc = false; // Boolean variable for Stack Function

  // If the user only compiles the code (enters "./tower", print options)
  if (argc == 1) {
    printf("Enter -s or -r to play Stack or Recursive Tower of Hanoi Game\n");
    printf("Enter -n followed by the number of disks you wish to start ");
    printf("with\n");
  }

  // Parse through getopt arguments
  if (argc > 1) {
    while ((a = getopt(argc, argv, validentries)) != -1) {

      // Change stack function boolean to true if user enters "-s"
      if (a == 's') {
        stackfunc = true;
      }

      // Change recursive function boolean to true if user enters "-r"
      else if (a == 'r') {
        recursivefunc = true;
      }

      // Change disks number if user enters "-n"
      else if (a == 'n') {
        disks = atoi(optarg);
      }

    }
  }

  // If stackfunction boolean is true, call stack function
  if (stackfunc == true) {
    //Printing Header:
    printf("================================\n");
    printf("----------   STACKS   ----------\n");
    printf("================================\n");
    
    StackFunction(disks, 'a', 'c', 'b');
  }

  // If recursive function boolean is true, call recursive function
  if (recursivefunc == true) {
    printf("================================\n");
    printf("--------   RECURSION   ---------\n");
    printf("================================\n");

    // Reset nummoves counter (in case stack function was called earlier)
    nummoves = 0; 
    Recur(disks, 'A', 'C', 'B'); 
    printf("\nNumber of moves: %d\n", nummoves); // Print # of moves
  }
  return 0;
}

void Recur(int disks, char init_peg, char temp_peg, char final_peg) {

  // Base Case
  if (disks == 1){
    printf("Move disk %d from peg %c to peg %c\n", disks, init_peg, final_peg);
    nummoves += 1; // Increment move counter after final move
  }

  else{
    Recur(disks-1, init_peg, final_peg, temp_peg);
    printf("Move disk %d from peg %c to peg %c\n", disks, init_peg, final_peg);
    nummoves += 1; // Increment move counter after 1 move
    Recur(disks-1, temp_peg, init_peg, final_peg);
  }

}

void StackFunction(int disks, char a, char c, char b) {
  nummoves = 0; //Initialize nummoves = 0 in case used by Recursive Function

  Stack *pega = stack_create(disks, a); //Create Stack PEG A
  Stack *pegb = stack_create(disks, b); //Create Stack PEG B
  Stack *pegc = stack_create(disks, c); //Create Stack PEG C

  //Initialize Disks in PEG A from largest to smallest
  for (int i = disks; i > 0; i--) {
    stack_push(pega, i);
  }

  //IF DISKS = ODD
  if (disks % 2 == 1) {
    while (1) {

      //MOVE 1:
      if (stack_empty(pega) == false) {   // If PEG A = not empty
        if (stack_empty(pegb) == false) { // If PEG B = not empty
          if (stack_peek(pega) > stack_peek(pegb)) { // If Top A > Top B
            pega->top += 1;
            pegb->top += 1;
            stack_push(pega, stack_pop(pegb));  // Move Top from B to A
            printf("Move disk %d from peg B to peg A\n", stack_peek(pega));
            pega->top += 1;
          } else {                              // If Top B > Top A
            pega->top += 1;
            pegb->top += 1;
            stack_push(pegb, stack_pop(pega));  // Move Top from A to B
            printf("Move disk %d from peg A to peg B\n", stack_peek(pegb));
            pegb->top += 1;
          }
        } else {  // If PEG A = not empty and PEG B = empty
          stack_push(pegb, stack_pop(pega));     // Move Top from A to B
          printf("Move disk %d from peg A to peg B\n", stack_peek(pegb));
          pegb->top += 1;
        }
      } else {                            // If PEG A = empty
        if (stack_empty(pegb) == false) { // If PEG B = not empty
          stack_push(pega, stack_pop(pegb));    // Move Top from B to A
          printf("Move disk %d from peg B to peg A", stack_peek(pega));
          pega->top += 1;
        }
      }

      nummoves += 1;                      // Increment moves counter
      if (stack_empty(pega) == true) {    // Check if Peg A empty
        if (stack_empty(pegc) == true) {  // Check if Peg C empty
          break;                          // ^ if true: break while loop
        }                                 // and end the game
      }
      

      //MOVE 2:
      if (stack_empty(pega) == false) {         // If Peg A = not empty
        if (stack_empty(pegc) == false) {       // If Peg C = not empty
          if (stack_peek(pega) > stack_peek(pegc)) {  // If Top A > Top C
            pega->top += 1;
            pegc->top += 1;
            stack_push(pega, stack_pop(pegc));  // Move Top from C to A
            printf("Move disk %d from peg C to peg A\n", stack_peek(pega));
            pega->top += 1;
          } else {                                    // If Top C > Top A
            pega->top += 1;
            pegc->top += 1;
            stack_push(pegc, stack_pop(pega));  // Move Top from A to C
            printf("Move disk %d from peg A to peg C\n", stack_peek(pegc));
            pegc->top += 1;
          }
        } else {  // If Peg A = not empty and Peg C = empty   
          stack_push(pegc, stack_pop(pega));    // Move Top from A to C
          printf("Move disk %d from peg A to peg C\n", stack_peek(pegc));
          pegc->top += 1;
        }
      } else {                              // If Peg A = empty
        if (stack_empty(pegc) == false) {   // If Peg C = not empty
          stack_push(pega, stack_pop(pegc));    // Move Top from C to A
          printf("Move disk %d from peg C to peg A\n", stack_peek(pega));
          pega->top += 1;
        }
      }

      nummoves += 1;                      // Increment moves counter
      if (stack_empty(pega) == true) {    // Check if Peg A empty
        if (stack_empty(pegc) == true) {  // Check if Peg C empty
          break;                          // ^ if true: break while loop
        }                                 // and end the game
      }
      
      //MOVE 3:

      if (stack_empty(pegb) == false) {         // If Peg B = not empty
        if (stack_empty(pegc) == false) {       // If Peg C = not empty
          if (stack_peek(pegb) > stack_peek(pegc)) {  // If Top B > Top C
            pegb->top += 1;
            pegc->top += 1;
            stack_push(pegb, stack_pop(pegc));  // Move Top from C to B
            printf("Move disk %d from peg C to peg B\n", stack_peek(pegb));
            pegb->top += 1;
          } else {                              // If Top C > Top B
            pegb->top += 1;
            pegc->top += 1;
            stack_push(pegc, stack_pop(pegb));  // Move Top from B to C
            printf("Move disk %d from peg B to peg C\n", stack_peek(pegc));
            pegc->top += 1;
          }
        } else {  // If Peg B = not empty and Peg C = empty
          stack_push(pegc, stack_pop(pegb));    // Move Top from B to C
          printf("Move disk %d from peg B to peg C\n", stack_peek(pegc));
          pegc->top += 1;
        }
      } else {                              // If Peg B = empty
        if (stack_empty(pegc) == false) {   // If Peg C = not empty
          stack_push(pegb, stack_pop(pegc));    // Move Top from C to B
          printf("Move disk %d from peg C to peg B", stack_peek(pegb));
          pegb->top += 1;
        }
      }
      
      nummoves += 1;                      // Increment moves counter
      if (stack_empty(pega) == true) {    // Check if Peg A empty
        if (stack_empty(pegc) == true) {  // Check if Peg C empty
          break;                          // ^ if true: break while loop
        }                                 // and end the game
      }

    }

    printf("\nNumber of moves: %d\n", nummoves);
  } else {
    while (1) {
      //MOVE 1:
      if (stack_empty(pega) == false) {         // If Peg A = not empty
        if (stack_empty(pegc) == false) {       // If Peg C = not empty
          if (stack_peek(pega) > stack_peek(pegc)) {  // If Top A > Top C
            pega->top += 1;
            pegc->top += 1;
            stack_push(pega, stack_pop(pegc));  // Move Top from C to A
            printf("Move disk %d from peg C to peg A\n", stack_peek(pega));
            pega->top += 1;
          } else {                                    // If Top C > Top A
            pega->top += 1;
            pegc->top += 1;
            stack_push(pegc, stack_pop(pega));  // Move Top from A to C
            printf("Move disk %d from peg A to peg C\n", stack_peek(pegc));
            pegc->top += 1;
          }
        } else {  // If Peg A = not empty and Peg C = empty   
          stack_push(pegc, stack_pop(pega));    // Move Top from A to C
          printf("Move disk %d from peg A to peg C\n", stack_peek(pegc));
          pegc->top += 1;
        }
      } else {                              // If Peg A = empty
        if (stack_empty(pegc) == false) {   // If Peg C = not empty
          stack_push(pega, stack_pop(pegc));    // Move Top from C to A
          printf("Move disk %d from peg C to peg A\n", stack_peek(pega));
          pega->top += 1;
        }
      }

      nummoves += 1;                      // Increment moves counter
      if (stack_empty(pega) == true) {    // Check if Peg A empty
        if (stack_empty(pegc) == true) {  // Check if Peg C empty
          break;                          // ^ if true: break while loop
        }                                 // and end the game
      }

      //MOVE 2:
      if (stack_empty(pega) == false) {   // If PEG A = not empty
        if (stack_empty(pegb) == false) { // If PEG B = not empty
          if (stack_peek(pega) > stack_peek(pegb)) { // If Top A > Top B
            pega->top += 1;
            pegb->top += 1;
            stack_push(pega, stack_pop(pegb));  // Move Top from B to A
            printf("Move disk %d from peg B to peg A\n", stack_peek(pega));
            pega->top += 1;
          } else {                              // If Top B > Top A
            pega->top += 1;
            pegb->top += 1;
            stack_push(pegb, stack_pop(pega));  // Move Top from A to B
            printf("Move disk %d from peg A to peg B\n", stack_peek(pegb));
            pegb->top += 1;
          }
        } else {  // If PEG A = not empty and PEG B = empty
          stack_push(pegb, stack_pop(pega));     // Move Top from A to B
          printf("Move disk %d from peg A to peg B\n", stack_peek(pegb));
          pegb->top += 1;
        }
      } else {                            // If PEG A = empty
        if (stack_empty(pegb) == false) { // If PEG B = not empty
          stack_push(pega, stack_pop(pegb));    // Move Top from B to A
          printf("Move disk %d from peg B to peg A", stack_peek(pega));
          pega->top += 1;
        }
      }
      

      nummoves += 1;                      // Increment moves counter
      if (stack_empty(pega) == true) {    // Check if Peg A empty
        if (stack_empty(pegc) == true) {  // Check if Peg C empty
          break;                          // ^ if true: break while loop
        }                                 // and end the game
      }

      //MOVE 3:

      if (stack_empty(pegb) == false) {         // If Peg B = not empty
        if (stack_empty(pegc) == false) {       // If Peg C = not empty
          if (stack_peek(pegb) > stack_peek(pegc)) {  // If Top B > Top C
            pegb->top += 1;
            pegc->top += 1;
            stack_push(pegb, stack_pop(pegc));  // Move Top from C to B
            printf("Move disk %d from peg C to peg B\n", stack_peek(pegb));
            pegb->top += 1;
          } else {                              // If Top C > Top B
            pegb->top += 1;
            pegc->top += 1;
            stack_push(pegc, stack_pop(pegb));  // Move Top from B to C
            printf("Move disk %d from peg B to peg C\n", stack_peek(pegc));
            pegc->top += 1;
          }
        } else {  // If Peg B = not empty and Peg C = empty
          stack_push(pegc, stack_pop(pegb));    // Move Top from B to C
          printf("Move disk %d from peg B to peg C\n", stack_peek(pegc));
          pegc->top += 1;
        }
      } else {                              // If Peg B = empty
        if (stack_empty(pegc) == false) {   // If Peg C = not empty
          stack_push(pegb, stack_pop(pegc));    // Move Top from C to B
          printf("Move disk %d from peg C to peg B", stack_peek(pegb));
          pegb->top += 1;
        }
      }
      
      nummoves += 1;                      // Increment moves counter
      if (stack_empty(pega) == true) {    // Check if Peg A empty
        if (stack_empty(pegc) == true) {  // Check if Peg C empty
          break;                          // ^ if true: break while loop
        }                                 // and end the game
      }
      
    }

    printf("\nNumber of moves: %d\n\n", nummoves);
    
  }

  //FREE DYNAMICALLY ALLOCATED MEMORY
  stack_delete(pega);
  stack_delete(pegb);
  stack_delete(pegc);

}
