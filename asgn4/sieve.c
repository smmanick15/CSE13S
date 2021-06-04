#include "sieve.h"
#include "bv.c"
#include "bv.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// This code is the Sieve of Erastothenes
// It was provided by the Assignment 4 Lab Document
// No changes have been made to the code from the Document

void sieve(BitVector *v) {
  bv_set_all_bits(v);
  bv_clr_bit(v, 0);
  bv_clr_bit(v, 1);
  bv_set_bit(v, 2);
  for (uint32_t i = 2; i < sqrtl(bv_get_len(v)); i += 1) {
    // Prime means bit is set
    if (bv_get_bit(v, i)) {
      for (uint32_t k = 0; (k + i) * i <= bv_get_len(v); k += 1) {
        bv_clr_bit(v, (k + i) * i);
      }
    }
  }
  return;
}
