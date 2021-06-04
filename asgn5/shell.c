#include "shell.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void Shell_Sort(int arraysize, int randseed, int elementsprint) {

  // initialize array pointers
  uint32_t *shell_array; // pointer for shell array
  int *n_array; // pointer for gap array

  // calloc space in heap for shell array
  shell_array = (uint32_t *)calloc(arraysize, sizeof(uint32_t));

  // check if calloc succeeded, if memory was allocated
  if (!shell_array) {
    return;
  }

  // set random seed
  srand(randseed);

  // store random values in shell_array and bit mask bits 31 and 32
  for (int i = 0; i < arraysize; i++) {
    shell_array[i] = rand();
    shell_array[i] &= ~(1 << 31);
    shell_array[i] &= ~(1 << 30);
  }

  // initialize variables for gap calculations
  int n = arraysize;
  int n_count = 0; // variable to count how many gaps in n_array

  // loop to count the number of gaps in the gap sequence
  while (n > 1) {
    if (n <= 2) {
      n = 1;
    } else {
      n = (5 * n) / 11;
    }
    n_count += 1;
  }

  // calloc space in heap for gap sizes
  n_array = (int *)calloc(n_count, sizeof(int));

  // check if calloc succeeded, if memory was allocated
  if (!n_array) {
    return;
  }

  // reset counter variables
  n = arraysize;
  int i = 0;

  // add values to gap array
  while (n > 1) {
    if (n <= 2) {
      n = 1;
      n_array[i] = n;
    } else {
      n = (5 * n) / 11;
      n_array[i] = n;
    }
    i++;
  }

  int compares = 0; // comparison counter variable
  int moves = 0; // moves counter variable
  int jtemp = 0; // temporary swap variable
  int jsub = 0; // second temporary swap variable
  int stepvar = 0; // step variable

  // PSEUDOCODE GIVEN BY LAB DOCUMENT
  for (int step = 0; step < n_count; step++) {
    stepvar = n_array[step];
    for (int i = stepvar; i < arraysize; i++) {
      for (int j = i; j > stepvar - 1; j -= stepvar) {
        if (shell_array[j] < shell_array[j - stepvar]) {
          jtemp = shell_array[j];
          jsub = shell_array[j - stepvar];
          shell_array[j] = jsub;
          shell_array[j - stepvar] = jtemp;
          moves += 3; // increment moves by 3
        } // one swap is considered 3 moves
        jtemp = 0; // reset swap variables
        jsub = 0;
        compares += 1; // increment counter by 1
      }
    }
  }

  // Method to print the output for shell sort
  printf("Shell Sort\n");
  printf("%d elements, %d moves, %d compares\n", arraysize, moves, compares);
  for (int i = 0; i < elementsprint;) {
    printf("%13d\t", shell_array[i]);
    i++;
    if (i % 7 == 0 && i != 0) {
      printf("\n");
    }
  }

  printf("\n");

  free(n_array); // free heap memory allocated for gap array
  free(shell_array); // free heap memory allocated for shell array

  return;
}
