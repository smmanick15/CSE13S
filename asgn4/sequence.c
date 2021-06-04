#include "sieve.c"
#include "sieve.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include "bv.h"
// #include "bv.c"

void sieveFUNC(int max_val);             // Function Prototype
void palindrome(uint32_t num, int base); // Function Prototype

int main(int argc, char **argv) {

  int a = 0;                        // Get opt variable
  int max_val = 1000;               // Default max value
  char *valid_entries = "spn:";     // Valid get opt entries
  bool sieve_function = false;      // Sieve Boolean
  bool palindrome_function = false; // Palindrome Boolean

  // Display getopt() options:
  if (argc == 1) {
    printf("Enter -s to display the Lucas, Mersenne, and Fibonacci primes\n");
    printf("Enter -p to display the palindrome primes in base 2, 9, 10, ");
    printf("and 23\n");
    printf("Enter -n followed by the largest value you wish to consider as ");
    printf("a prime.\n");
    printf("For example: entering 100 will output the primes from 0 ");
    printf("to 100.\n");
  }

  // Parse through getopt() arguments:
  if (argc > 1) {
    while ((a = getopt(argc, argv, valid_entries)) != -1) {
      // Change sieve function boolean variable to true if user enters '-s'
      if (a == 's') {
        sieve_function = true;
      }

      // Change palindrome function boolean variable to true if user enters '-p'
      else if (a == 'p') {
        palindrome_function = true;
      }

      // Change max_val value to user entered number if user enters '-n'
      else if (a == 'n') {
        max_val = atoi(optarg);
      }
    }
  }

  // If boolean variable for prime sieve function is true, call the function
  if (sieve_function == true) {
    sieveFUNC(max_val);
  }

  if (palindrome_function == true) {
    // Create bit vector for palindrome primes
    BitVector *pal_primes = bv_create(max_val);
    // Use sieve to set prime bits in bit vector
    sieve(pal_primes);

    // BASE 2
    printf("Base  2\n");
    printf("---- --\n");
    for (int i = 0; i <= max_val; i++) {
      if (bv_get_bit(pal_primes, i) == 1) {
        palindrome(i, 2);
      }
    }

    printf("\n");

    // BASE 9
    printf("Base  9\n");
    printf("---- --\n");
    for (int i = 0; i <= max_val; i++) {
      if (bv_get_bit(pal_primes, i) == 1) {
        palindrome(i, 9);
      }
    }

    printf("\n");

    // BASE 10
    printf("Base 10\n");
    printf("---- --\n");
    for (int i = 0; i <= max_val; i++) {
      if (bv_get_bit(pal_primes, i) == 1) {
        palindrome(i, 10);
      }
    }

    printf("\n");

    // BASE 23
    printf("Base 23\n");
    printf("---- --\n");
    for (int i = 0; i <= max_val; i++) {
      if (bv_get_bit(pal_primes, i) == 1) {
        palindrome(i, 23);
      }
    }

    printf("\n");
    bv_delete(pal_primes);
  }
  return 0;
}

void sieveFUNC(int max_val) {
  BitVector *primeBV = bv_create(max_val);

  // Calculate all prime numbers between 1 and max value
  sieve(primeBV);

  // Mersenne number calculations
  BitVector *mersenneBV = bv_create(max_val);

  for (int i = 0; i <= max_val; i++) {
    bv_clr_bit(mersenneBV, i);
  }

  int prime = 0;

  // Set bits for mersenne numbers
  for (int start = 2; prime < max_val; start++) {
    prime = (1 << start) - 1;
    bv_set_bit(mersenneBV, prime);
    if (((1 << (start + 1)) - 1) > max_val) {
      break;
    }
  }

  // Lucas Number calculations
  BitVector *lucasBV = bv_create(max_val);

  for (int i = 0; i <= max_val; i++) {
    bv_clr_bit(lucasBV, i);
  }

  int lucas_num = 0;
  int nsub1 = 2;
  int nsub2 = 1;
  bv_set_bit(lucasBV, 2);
  bv_set_bit(lucasBV, 1);

  // Set bits for lucas numbers
  while (1) {
    lucas_num = nsub1 + nsub2;
    bv_set_bit(lucasBV, lucas_num);

    nsub1 = nsub2;
    nsub2 = lucas_num;

    if (nsub1 + nsub2 > max_val) {
      break;
    }
  }

  // Fibonacci Number calculations
  BitVector *fibBV = bv_create(max_val);

  for (int i = 0; i <= max_val; i++) {
    bv_clr_bit(fibBV, i);
  }

  int fib_num = 0;
  int fsub1 = 0;
  int fsub2 = 1;

  // Set bits for Fibonacci numbers
  while (1) {
    fib_num = fsub1 + fsub2;
    bv_set_bit(fibBV, fib_num);

    fsub1 = fsub2;
    fsub2 = fib_num;

    if (fsub1 + fsub2 > max_val) {
      break;
    }
  }

  // OUTPUT PRINTING

  for (int i = 0; i <= max_val; i++) {
    if (bv_get_bit(primeBV, i) == 1) {
      printf("%d: prime", i);
      if (bv_get_bit(mersenneBV, i) == 1) {
        printf(", mersenne");
      }
      if (bv_get_bit(lucasBV, i) == 1) {
        printf(", lucas");
      }
      if (bv_get_bit(fibBV, i) == 1) {
        printf(", fibonacci");
      }
      printf("\n");
    }
  }

  bv_delete(primeBV);    // Delete bit vector for Prime Numbers
  bv_delete(mersenneBV); // Delete bit vector for Mersenne Numbers
  bv_delete(lucasBV);    // Delete bit vector for Lucas Numbers
  bv_delete(fibBV);      // Delete bit vector for Fibonacci Numbers
}

void palindrome(uint32_t num, int base) {
  uint32_t tempn = num;  // Variable to preserve num value in loop
  uint32_t finaln = num; // Variable to preserve num value in loop
  char *conversion = "0123456789abcdefghijklm"; // Characters used in conversion
  int size = 0; // Variable to calculate length of characters
                // in the converted base number

  while (num > 0) { // While loop to calculate the size variable
    num /= base;
    size += 1;
  }

  // Array to hold the converted base number
  char pal_array[50] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
                        '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
                        '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
                        '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
                        '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'};

  int i = 0; // Loop counter variable

  while (tempn > 0) { // While loop to add the converted number to pal_array
    pal_array[i] = conversion[tempn % base];
    tempn /= base;
    i += 1;
  }

  i = 0; // Reinitialize i as a length holder

  while (pal_array[i] != '-') { // While loop to calculate the end of the
    i += 1;                     // converted characters in pal_array
  }

  int start = 0;    // Variable to index the beginning of array
  int end = i - 1;  // Variable to index the end of pal_array
  int pal_bool = 0; // Variable to track validity of palindrome

  if (end == 0) { // If end of pal_array = 0 (meaning length
    pal_bool = 1; // of converted number = 1; number is
  }               // automatically considered a palindrome

  int endcondition = end; // variable to preserve end value to end loop

  // While loop to determine whether converted number is a palindrome
  while (start != endcondition) {
    if (pal_array[start] == pal_array[end]) {
      start = start + 1;
      end = end - 1;
      pal_bool = 1;
      continue;
    } else {
      pal_bool = 0;
      break;
    }
  }

  // If pal_bool == 1 (if number = palindrome):
  i = 0;
  if (pal_bool == 1) {
    printf("%d = ", finaln);
    while (pal_array[i] != '-') { // While loop to print output
      printf("%c", pal_array[i]);
      i += 1;
    }
    printf("\n");
  } else {
    return;
  }

  return;
}
