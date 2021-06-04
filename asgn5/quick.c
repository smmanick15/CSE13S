#include "quick.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int moves = 0; // moves counter global variable
int compares = 0; // comparison counter global variable

// Function Declarations
void Quick_Sort(int32_t *array, int left, int right);
int Partition(int32_t *array, int left, int right);
void Execute_Quick(int arraysize, int randseed, int elementsprint) {

  int32_t *quick_array; // initialize array pointer for quick_array

  // calloc space in the heap for quick_array
  quick_array = (int32_t *)calloc(arraysize, sizeof(uint32_t));

  // check if calloc succeeded, if memory was allocated
  if (!quick_array) {
    return;
  }

  // set random seed = randseed
  srand(randseed);

  // store random values in quick_array and bit mask bits 31 and 32
  for (int i = 0; i < arraysize; i++) {
    quick_array[i] = rand();
    quick_array[i] &= ~(1 << 31);
    quick_array[i] &= ~(1 << 30);
  }

  // initialize left and right variables for quick sort algorithm
  int left = 0;
  int right = arraysize - 1;

  // call quick sort function
  Quick_Sort(quick_array, left, right);

  // Format Output for Quick Sort
  printf("Quick Sort\n");
  printf("%d elements, %d moves, %d compares\n", arraysize, moves, compares);
  for (int i = 0; i < elementsprint;) {
    printf("%13d\t", quick_array[i]);
    i++;
    if (i % 7 == 0 && i != 0) {
      printf("\n");
    }
  }

  printf("\n");

  free(quick_array); // free heap memory allocated for quick_array
}

//
// PSEUDOCODE GIVEN BY LAB DOCUMENT
//
void Quick_Sort(int32_t *array, int left, int right) {
  if (left < right) {
    int index = Partition(array, left, right);
    Quick_Sort(array, left, index - 1);
    Quick_Sort(array, index + 1, right);
  }
  return;
}

//
// PSEUDOCODE GIVEN BY LAB DOCUMENT
//
int Partition(int32_t *array, int left, int right) {
  int pivot = array[left];
  int lo = left + 1;
  int hi = right;

  while (1) {
    while ((lo <= hi) && (array[hi] >= pivot)) {
      compares += 1; // increment compares counter
      hi -= 1;
    }

    if (lo <= hi) {
      if (array[hi] < pivot) {
        compares += 1;
      }
    }
    

    while ((lo <= hi) && (array[lo] <= pivot)) {
      compares += 1; // increment compares counter
      lo += 1;
    }

    if (lo <= hi) {
      if (array[lo] > pivot) {
        compares += 1; 
      }
    }

    if (lo <= hi) {
      int movelo = array[lo];
      int movehi = array[hi];
      array[hi] = movelo;
      array[lo] = movehi;
      moves += 3; // increment moves counter (each swap = 3 moves)
    } else {
      break;
    }
  }

  int outer_left = array[left];
  int outer_hi = array[hi];
  array[hi] = outer_left;
  array[left] = outer_hi;
  moves += 3; // increment moves counter (each swap = 3 moves)
  return hi;
}
