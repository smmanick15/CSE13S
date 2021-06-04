#include "bubble.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void Bubble_Sort(int arraysize, int randseed, int elementsprint) {

  // set random seed
  srand(randseed);

  // initialize array pointer
  uint32_t *bubble_array;

  // calloc memory on the heap to store array random numbers
  bubble_array = (uint32_t *)calloc(arraysize, sizeof(uint32_t));

  // check if calloc succeeded, if memory was allocated
  if (!bubble_array) {
    return;
  }

  // store random values in bubble_array and bit mask bits 31 and 32
  for (int i = 0; i < arraysize; i++) {
    bubble_array[i] = rand();
    bubble_array[i] &= ~(1 << 31);
    bubble_array[i] &= ~(1 << 30);
  }

  int compares = 0; // comparison counter variable
  int moves = 0; // moves counter variable
  int jtemp = 0; // temporary swap variable
  int jsub = 0; // second temporary swap variable
  int j = 0; // array index

  // PSEUDOCODE GIVEN BY LAB DOCUMENT
  for (int i = 0; i < arraysize; i++) {
    j = arraysize - 1;
    while (j > i) {
      if (bubble_array[j] < bubble_array[j - 1]) {
        jtemp = bubble_array[j];
        jsub = bubble_array[j - 1];
        bubble_array[j] = jsub;
        bubble_array[j - 1] = jtemp;
        moves += 3; // increment moves counter by 3
      } // swap is considered 3 moves
      compares += 1; // increment comparison counter by 1
      j -= 1;
    }
  }

  // Method to print the output for bubble sort
  printf("Bubble Sort\n");
  printf("%d elements, %d moves, %d compares\n", arraysize, moves, compares);
  for (int i = 0; i < elementsprint;) {
    printf("%13d\t", bubble_array[i]);
    i++;
    if (i % 7 == 0 && i != 0) {
      printf("\n");
    }
  }

  printf("\n");

  free(bubble_array); // frees heap memory

  return;
}
