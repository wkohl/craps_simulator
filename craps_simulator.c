// Fig. 5.14: fig05_14.c
 // Simulating the game of craps.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

int rollDice(void); // function prototype

int main(void) {
	float win = 0;
	float loss = 0;
	unsigned int simulations;
	float house;

	// randomize random number generator using current time
	srand(time(NULL));

	printf("Simulation Number: ");
	scanf_s("%i", &simulations);

	for (int i = 0; i < simulations; i++) {
		int myPoint; // player must make this point to win
		enum Status gameStatus; // can contain CONTINUE, WON, or LOST
		int sum = rollDice(); // first roll of the dice

		// determine game status based on sum of dice
		switch (sum) {

			// win on first roll
		case 7: // 7 is a winner
		case 11: // 11 is a winner
			gameStatus = WON;
			break;

			// lose on first roll
		case 2: // 2 is a loser
		case 3: // 3 is a loser
		case 12: // 12 is a loser
			gameStatus = LOST;
			break;

			// remember point
		default:
			gameStatus = CONTINUE; // player should keep rolling
			myPoint = sum; // remember the point
			// printf("Point is %d\n", myPoint);
			break; // optional
		}
		// while game not complete
		while (CONTINUE == gameStatus) { // player should keep rolling
			sum = rollDice(); // roll dice again

		  // determin game status
			if (sum == myPoint) { // win by making point
				gameStatus = WON;
			}
			else {
				if (7 == sum) { // lose by rolling 7
					gameStatus = LOST;
				}
			}
		}

		// display won or lost message
		if (WON == gameStatus) { // did player win?
			// puts("Player wins");
			win++;
		}
		else { // player lost
			// puts("Player loses");
			loss++;
		}

		house = (1 - (win / loss)) * 100;
		printf("Run: %i, House Win Percentage: % 1.2f%%\n", i, house);
	}
	house = (1 - (win / loss)) * 100;
	printf("Player: %1.0f\nHouse: %1.0f\nHouse Win Percentage: %1.2f%%\n\n", win, loss, house);

	main();
}

// roll dice, calculate sum and display results

int rollDice(void)
{
	int die1 = 1 + (rand() % 6); // pick random die1 value
	int die2 = 1 + (rand() % 6); // pick random die2 value

	// display results of this roll
	// printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
	return die1 + die2; // return sum of dice
}
