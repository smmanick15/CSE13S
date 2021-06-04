// SMRITHI MANICKAM
// UCSC ID: 1735660
// CRUZ ID: SMMANICK

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Function that returns the player to the left
uint32_t left(uint32_t pos, uint32_t players) {
  return ((pos + players - 1) % players);
}

// Function that returns the player to the right
uint32_t right(uint32_t pos, uint32_t players) { return ((pos + 1) % players); }

// Function that rolls a dice and returns its value
uint32_t diceroll() {

  int die_value = rand() % 6; // Take modulus by 6 to receive
                              // a range of values from 0-5

  typedef enum faciem { LEFT, RIGHT, CENTER, PASS } faces;
  faces die[] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS};

  faces resultchange;

  resultchange = die[die_value];

  return resultchange;
}

int main() {

  int randseed, numplayers;

  // User enters random seed
  printf("Random seed: ");
  scanf("%d", &randseed);

  srand(randseed);

  // User enters number of players
  printf("How many players? ");
  scanf("%d", &numplayers);

  // Check if number of players is valid (return 0)
  if (numplayers <= 1) {
    printf("Invalid number of players.\n");
    return 0;
  }

  else if (numplayers > 10) {
    printf("Invalid number of players.\n");
    return 0;
  }

  // Initial list of names
  const char *names[] = {"Happy",      "Sleepy",      "Sneezy", "Dopey",
                         "Bashful",    "Grumpy",      "Doc",    "Mirror Mirror",
                         "Snow White", "Wicked Queen"};

  // Create the official list of players
  const char *names_official[numplayers];

  int i;

  for (i = 0; i < numplayers; ++i) {
    names_official[i] = names[i];
  }

  // Create bank accounts for each player
  int names_amount[numplayers];
  int j;

  // Initializes each player to start off with $3
  for (j = 0; j < numplayers; ++j) {
    names_amount[j] = 3;
  }

  // Die faces
  enum faciem { LEFT, RIGHT, CENTER, PASS }; // faces;
  // faces die[] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS};

  int pos = 0;                       // Initial position of player:
  int centerpot = 0;                 // Initialize pot in the center
  int numactiveplayers = numplayers; // Initialize #of players in game

  // Outer loop for the game to keep playing
  while (1) {

    if (numactiveplayers == 1) {

      // Loop to calculate winner (loops through each player until it finds
      // player with bank account > 0)
      int k;
      for (k = 0; k < numplayers; ++k) {
        if (names_amount[k] > 0) {
          int winner;
          winner = k;
          printf("%s wins the $%d pot with $%d left in the bank!\n",
                 names_official[winner], centerpot, names_amount[winner]);
          break;
        }
      }

      return 0;
    }

    // Check if player has any money in the bank
    if (names_amount[pos] == 0) {
      pos = right(pos, numplayers); // Move position to the right
    }

    else {

      int temppos; // Initialize temporary position holder
      int newpos;  // Initialize new position holder
      // Initialize temporary bank amount holder
      int tempamount = names_amount[pos];

      // Print player rolling name
      printf("%s rolls...", names_official[pos]);

      // Initialize and roll Dice 1
      int dice1 = diceroll();
      if (dice1 == LEFT) {

        // Calculate left player position
        temppos = left(pos, numplayers);
        printf(" gives $1 to %s", names_official[temppos]);

        // If player to the left has $0, add 1 numactiveplayer
        if (names_amount[temppos] == 0) {
          ++numactiveplayers;
        }

        // Calculate new bank values
        names_amount[pos]--;
        ++names_amount[temppos];

        // If current player has $0, subtract 1 numactiveplayer
        if (names_amount[pos] == 0) {
          numactiveplayers--;
        }
      }

      if (dice1 == RIGHT) {
        // Calculate right player position
        temppos = right(pos, numplayers);
        printf(" gives $1 to %s", names_official[temppos]);

        // If player to the right has $0, add 1 numactiveplayer
        if (names_amount[temppos] == 0) {
          ++numactiveplayers;
        }

        // Calculate new bank values
        names_amount[pos]--;
        ++names_amount[temppos];

        // If current player has $0, subtract 1 numactiveplayer
        if (names_amount[pos] == 0) {
          numactiveplayers--;
        }
      }

      if (dice1 == CENTER) {

        // Print statement
        printf(" puts $1 in the pot");

        // Calculate new bank values
        names_amount[pos]--;
        ++centerpot;

        // If current player has $0, subtract 1 numactiveplayer
        if (names_amount[pos] == 0) {
          numactiveplayers--;
        }
      }

      if (dice1 == PASS) {

        // Print statement
        printf(" gets a pass");
      }

      if (tempamount >= 2) {

        // Initialize and roll Dice 2
        int dice2 = diceroll();

        if (dice2 == LEFT) {

          // Calculate left player position
          temppos = left(pos, numplayers);
          printf(" gives $1 to %s", names_official[temppos]);

          // If player to the left has $0, add 1 numactiveplayer
          if (names_amount[temppos] == 0) {
            ++numactiveplayers;
          }

          // Calculate new bank values
          names_amount[pos]--;
          ++names_amount[temppos];

          // If current player has $0, subtract 1 numactiveplayer
          if (names_amount[pos] == 0) {
            numactiveplayers--;
          }
        }

        if (dice2 == RIGHT) {
          // Calculate right player position
          temppos = right(pos, numplayers);
          printf(" gives $1 to %s", names_official[temppos]);

          // If player to the right has $0, add 1 numactiveplayer
          if (names_amount[temppos] == 0) {
            ++numactiveplayers;
          }

          // Calculate new bank values
          names_amount[pos]--;
          ++names_amount[temppos];

          // If current player has $0, subtract 1 numactiveplayer
          if (names_amount[pos] == 0) {
            numactiveplayers--;
          }
        }

        if (dice2 == CENTER) {

          // Print statement
          printf(" puts $1 in the pot");

          // Calculate new bank values
          names_amount[pos]--;
          ++centerpot;

          // If current player has $0, subtract 1 numactiveplayer
          if (names_amount[pos] == 0) {
            numactiveplayers--;
          }
        }

        if (dice2 == PASS) {

          // Print statement
          printf(" gets a pass");
        }
      }

      if (tempamount >= 3) {

        // Initialize and roll Dice 3
        int dice3 = diceroll();

        if (dice3 == LEFT) {

          // Calculate left player position
          temppos = left(pos, numplayers);
          printf(" gives $1 to %s", names_official[temppos]);

          // If player to the left has $0, add 1 numactiveplayer
          if (names_amount[temppos] == 0) {
            ++numactiveplayers;
          }

          // Calculate new bank values
          names_amount[pos]--;
          ++names_amount[temppos];

          // If current player has $0, subtract 1 numactiveplayer
          if (names_amount[pos] == 0) {
            numactiveplayers--;
          }
        }

        if (dice3 == RIGHT) {
          // Calculate right player position
          temppos = right(pos, numplayers);
          printf(" gives $1 to %s", names_official[temppos]);

          // If player to the right has $0, add 1 numactiveplayer
          if (names_amount[temppos] == 0) {
            ++numactiveplayers;
          }

          // Calculate new bank values
          names_amount[pos]--;
          ++names_amount[temppos];

          // If current player has $0, subtract 1 numactiveplayer
          if (names_amount[pos] == 0) {
            numactiveplayers--;
          }
        }

        if (dice3 == CENTER) {

          // Print statement
          printf(" puts $1 in the pot");

          // Calculate new bank values
          names_amount[pos]--;
          ++centerpot;

          // If current player has $0, subtract 1 numactiveplayer
          if (names_amount[pos] == 0) {
            numactiveplayers--;
          }
        }

        if (dice3 == PASS) {

          // Print statement
          printf(" gets a pass");
        }
      }

      printf("\n");

      newpos = right(pos, numplayers);
      pos = newpos;
    }
  }
}
