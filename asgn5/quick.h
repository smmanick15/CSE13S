// quick.h - Contains the function declarations for the Quick Sort function

#ifndef __QUICK_H__
#define __QUICK_H__

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//
// Function definition to execute Quick Sort
// This function also prints the output
//

void Execute_Quick(int arraysize, int randseed, int elementsprint);

//
// Function definition for Quick_Sort logic
// Pseudocode provided by the Lab 5 Document
//

void Quick_Sort(int32_t *array, int left, int right);

//
// Function definition for the Partition function referenced by Quick_Sort()
// Pseudocode provided by the Lab 5 Document
//

int Partition(int32_t *array, int left, int right);

#endif
