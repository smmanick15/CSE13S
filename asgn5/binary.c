#include "binary.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void Binary_Sort(int arraysize, int randseed, int elementsprint) {

  // set random seed
  srand(randseed);

  // initialize array pointer
  int32_t *binary_array;

  // calloc memory on the heap to store array random numbers
  binary_array = (int32_t *)calloc(arraysize, sizeof(uint32_t));

  // check if calloc succeeded, if memory was allocated
  if (!binary_array) {
    return;
  }

  // bit mask bit 31 and 32
  for (int i = 0; i < arraysize; i++) {
    binary_array[i] = rand();
    binary_array[i] &= ~(1 << 31);
    binary_array[i] &= ~(1 << 30);
  }

  int compares = 0; // comparison counter variable
  int moves = 0; // moves counter variable
  int jtemp = 0; // temporary swap variable
  int jsub = 0; // second temporary swap variable

  // PSEUDOCODE GIVEN BY LAB DOCUMENT
  for (int i = 1; i < arraysize; i++) {
    int value = binary_array[i];
    int left = 0;
    int right = i;

    while (left < right) {
      int mid = left + ((right - left) / 2);

      if (value >= binary_array[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
      compares += 1; // increment compares counter
    }

    for (int j = i; j > left; j = j - 1) {
      jsub = binary_array[j - 1];
      jtemp = binary_array[j];
      binary_array[j] = jsub;
      binary_array[j - 1] = jtemp;
      moves += 3; // increment moves counter
    }
  }

  // Method to print the output for bubble sort
  printf("Binary Insertion Sort\n");
  printf("%d elements, %d moves, %d compares\n", arraysize, moves, compares);
  for (int i = 0; i < elementsprint;) {
    printf("%13d\t", binary_array[i]);
    i++;
    if (i % 7 == 0 && i != 0) {
      printf("\n");
    }
  }

  printf("\n");
  free(binary_array); // free heap memory allocated for binary_array

  return;
}
