Name: Smrithi Manickam  
CRUZ ID: smmanick  
  
  
#### ASSIGNMENT 1 README  
  
  
##### FILES:  
  
**lrc.c**: This file contains the code for the game.  
  
  
**Makefile**: This file is used to compile the lrc.c file.  
Type "make" or "make all" to compile the code. Then type  
random seed and the number of players in the game. The number  
of players must be between 2 and 10. Otherwise the game will  
return an invalid result.  
  
Type "make clean" to remove all the files that are compiler  
generated.  
  
**DESIGN.pdf**: This file contains the pseudocode for the  
assignment.  

**README.md**  

  
##### SUMMARY OF GAME:  
  
This assignment implements C programming code to play a game  
with a max of 10 players and a minimum of 2 players. The user  
must enter a valid number of players (between 2 and 10) to play  
the game. The user must also enter a random seed number that  
initializes the dice rolls.  
  
The game itself allows each player to start off with $3. If a  
player has $3 or more, at the beginning of the turn, then the  
player can roll the dice 3 times. If a player has $2, then they  
can roll 2 times, and if they have $1, they can roll once.  
  
The dice has six sides, 1 for 'LEFT', 1 for 'RIGHT', 1 for 'CENTER'  
and 3 for 'PASS'. If a player rolls 'LEFT', then they have to  
give $1 to the player on their left. If a player rolls 'RIGHT',  
then they have to give $1 to the player on their right. If a  
player rolls 'CENTER', they put $1 in the center pot. If a player  
rolls 'PASS', then they do nothing.  
  
If a player has $0, they are still not completely out of the game.  
They can still be passed $1 from the players on the right or their  
left. The last remaining player with money (while all the other  
players have $0 in their bank) wins the game and the money in the pot.  
  

