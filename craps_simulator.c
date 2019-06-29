// Simulating the game of craps.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };
struct variables_ {
	int simulations;
	float win;
	float loss;
	float house;
};

int rollDice(void);									// function prototype
struct variables_ return_variables(int sim_num);	// function prototype

int main(void) {
	// Variables
	unsigned int simulations;

	struct variables_ c1;

	// Prompt
	printf("Simulation Number: ");
	c1 = return_variables(scanf_s("%i", &simulations));

	//// Set Seed
	//srand(time(NULL));

	//// Print Results
	//printf("Player: %1.0f\nHouse: %1.0f\nHouse Win Percentage: %1.2f%%\n\n", c1.win, c1.loss, c1.house);

	//// Pause Exit
	//system("pause");
}

int rollDice(void)
{
	int die1 = 1 + (rand() % 6); // pick random die1 value
	int die2 = 1 + (rand() % 6); // pick random die2 value

	// display results of this roll
	// printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
	return die1 + die2; // return sum of dice
}

struct variables_ return_variables(int sim_num) {

	struct variables_ score;
	score.simulations = sim_num;

	for (int i = 0; i < score.simulations; i++) {
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
			score.win++;
		}
		else { // player lost
			// puts("Player loses");
			score.loss++;
		}
	}

	return score;
}
