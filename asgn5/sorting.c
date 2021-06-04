#include "binary.c"
#include "binary.h"
#include "bubble.c"
#include "bubble.h"
#include "quick.c"
#include "quick.h"
#include "shell.c"
#include "shell.h"
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

  int govariable = 0;
  int arraysize = 100;
  int randseed = 8222022;
  int elementsprint = 100;
  char *valid_entries = "Absqip:r:n:";
  bool all_functions = false;
  bool bubble = false;
  bool shell = false;
  bool quick = false;
  bool binary = false;

  if (argc == 1) {
    printf("Enter arguments\n");
  }

  // Parse through getopt() arguments:
  if (argc > 1) {
    while ((govariable = getopt(argc, argv, valid_entries)) != -1) {
      // Change all functions bool to true
      if (govariable == 'A') {
        all_functions = true;
      }

      else if (govariable == 'b') {
        bubble = true;
      }

      else if (govariable == 's') {
        shell = true;
      }

      else if (govariable == 'q') {
        quick = true;
      }

      else if (govariable == 'i') {
        binary = true;
      }

      else if (govariable == 'p') {
        elementsprint = atoi(optarg);
      }

      else if (govariable == 'r') {
        randseed = atoi(optarg);
      }

      else if (govariable == 'n') {
        arraysize = atoi(optarg);
      }
    }
  }

  if (all_functions == true) {
    Binary_Sort(arraysize, randseed, elementsprint);
    Execute_Quick(arraysize, randseed, elementsprint);
    Shell_Sort(arraysize, randseed, elementsprint);
    Bubble_Sort(arraysize, randseed, elementsprint);
  }

  if (bubble == true) {
    Bubble_Sort(arraysize, randseed, elementsprint);
  }

  if (shell == true) {
    Shell_Sort(arraysize, randseed, elementsprint);
  }

  if (quick == true) {
    Execute_Quick(arraysize, randseed, elementsprint);
  }

  if (binary == true) {
    Binary_Sort(arraysize, randseed, elementsprint);
  }

  return 0;
}
