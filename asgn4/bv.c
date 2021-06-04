#include "bv.h"
#include <stdio.h>
#include <stdlib.h>

// This function creates a new bit vector with bit_len length
BitVector *bv_create(uint32_t bit_len) {
  BitVector *v = (BitVector *)malloc(sizeof(BitVector));

  // Check if the malloc succeeded, if not return NULL
  if (!v) {
    return NULL;
  }

  // Assign bit_len to the Bit Vector length
  v->length = bit_len;

  // Malloc enough bytes in the bit vector for the specified bit length
  v->vector = (uint8_t *)malloc(((bit_len / 8) + 1) * sizeof(uint8_t));

  // Check if the malloc succeeded
  if (!v->vector) {
    return 0;
  }

  // Return created Bit Vector
  return v;
}

// Deletes the heap memory allocated for the specified Bit Vector
void bv_delete(BitVector *v) {
  free(v->vector); // Frees memory allocated for *vector
  free(v);         // Frees memory allocated for Bit Vector *v
}

// Returns Bit Vector length variable
uint32_t bv_get_len(BitVector *v) { return v->length; }

// Sets the bit at the specified index i (changes its value to 1)
void bv_set_bit(BitVector *v, uint32_t i) {
  v->vector[i / 8] |= 0x1 << (i % 8);
}

// Clears the bit at the specified index i (changes its value to 0)
void bv_clr_bit(BitVector *v, uint32_t i) {
  v->vector[i / 8] &= ~(0x1 << (i % 8));
}

// Returns the value at the bit of the specified index i
uint8_t bv_get_bit(BitVector *v, uint32_t i) {
  return v->vector[i / 8] >> (i % 8) & 0x1;
}

// Sets all the bits of specified Bit Vector
void bv_set_all_bits(BitVector *v) {
  for (uint32_t i = 0; i <= v->length; i++) {
    bv_set_bit(v, i);
  }
}
