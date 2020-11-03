/*
Viatris Scott
C++ Fall 2020
Due: November 2, 2020
Lab 5: C++ Programming
Building a random number guessing game that uses do loops and switch statements.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Game();
bool Menu();
void WrongGuessMessage();
void YouWinMessage();
void NewGamePrompt();

int main()
{
	bool loop = true;
	int YouWinCount = 0;
	int YouLoseCount = 0;
	int totalGames = 1;

	do
	{
		++totalGames = 1;
		if (Game() == 1)
		{
			++YouWinCount;
			YouWinMessage();
			NewGamePrompt();
			if (Menu())
			{
				loop = true; //User starts new game
				continue;
			}
			else
			{
				loop = false; //User quits program
				continue;
			}
		}
		else if (Game() == 0)
		{
			++YouLoseCount;
			NewGamePrompt();
			if (Menu())
			{
				loop = true; //User starts new game
				continue;
			}
			else
				loop = false; //User quits game
		}
	} while (loop);

	cout << "\n\nHere are your final scores: \n";
	cout << "Wins: " << YouWinCount << endl;
	cout << "Losses: " << YouLoseCount << endl;
	cout << "Total Games: " << totalGames << endl;


	return 0;
}

int Game()
{
	int input; //User guess

	srand(unsigned int(time(NULL))); // seed random number generator
	int ranNumber = rand() % 10 + 1; // output to screen random number between 1 and 10

	cout << "The computer has generated a random number between 1 and 100.\n";
	cout << "You have twenty guesses to correctly guess what the random number is.\n";
	cout << "Enter your guess: ";
	cin >> input; //This is where the user guesses what the random number is.


	int howmanyGuesses = 1;
	do
	{
		if (input != ranNumber)
		{
			WrongGuessMessage();

			cout << "Enter your next guess: ";
			cin >> input;
			howmanyGuesses++;
		}
		else if (input == ranNumber) //input random numbers
		{
			return 1; //True
		}
	} while (howmanyGuesses < 20);

	cout << "\nYou lose!\n";
	cout << "The secret number was: " << ranNumber;

	return 0;
}

bool Menu()
{
	bool menuLoop = true;
	char selection; //User input for menu

	do
	{
		cout << "\nPlease make a selection from the menu below: \n";
		cout << "N - New Game\n";
		cout << "Q - Quit Program\n";
		cout << "Enter your selection: \n";
		cin >> selection;

		switch (selection)
		{
		case 'N':
			return true; //New game is started.
			break;

		case 'Q':
			menuLoop = false;
			break;

		default:
			cout << "Invalid input";

		}
	} while (menuLoop);

	return false; //Terminated program
}

void WrongGuessMessage()
{
	int WhatMessage; //Determines what random message to be printed

	srand(unsigned int(time(NULL))); // seed random number generator
	int ranNumber = rand() % 10 + 1; // output to screen random number between 1 and 10

	WhatMessage = ranNumber; //Sets WhatNumber to the random number generated

	switch (WhatMessage)
	{
	case 1:
	{
		cout << "\nTry again\n";
		break;
	}

	case 2:
	{
		cout << "\nNot quite\n";
		break;
	}

	case 3:
	{
		cout << "\nThat's not it\n";
		break;
	}

	case 4:
	{
		cout << "\nWrong Number\n";
		break;
	}

	case 5:
	{
		cout << "\nDon't give up!\n";
		break;
	}

	case 6:
	{
		cout << "\nGive it another shot\n";
		break;
	}

	case 7:
	{
		cout << "\nPlease try harder\n";
		break;
	}

	case 8:
	{
		cout << "\nAre you even trying?\n";
		break;
	}

	case 9:
	{
		cout << "\nGetting a warmer\n";
		break;
	}

	case 10:
	{
		cout << "\nGive it another guess.\n";
		break;
	}

	default:
		"Random number generation error";
	}
}

void YouWinMessage()
{
	int WhatMessage;

	srand(unsigned int(time(NULL))); // seed random number generator
	int ranNumber = rand() % 10 + 1; // output to screen random number between 1 and 10

	WhatMessage = ranNumber; //Sets WhatNumber to the random number generated

	switch (WhatMessage)
	{
	case 1:
	{
		cout << "\nYou win!\n";
		break;
	}

	case 2:
	{
		cout << "\nGood Job!\n";
		break;
	}

	case 3:
	{
		cout << "\nThat's it!\n";
		break;
	}

	case 4:
	{
		cout << "\nYou guessed the secret number!\n";
		break;
	}

	case 5:
	{
		cout << "\nYou succeeded in guessing the number!\n";
		break;
	}

	case 6:
	{
		cout << "\nAwesome!\n";
		break;
	}

	case 7:
	{
		cout << "\nWe're all going to Disney Land!\n";
		break;
	}

	case 8:
	{
		cout << "\nWooHoo!\n";
		break;
	}

	case 9:
	{
		cout << "\nRight on!\n";
		break;
	}

	case 10:
	{
		cout << "\nYou're the best at guessing random numbers!\n";
		break;
	}

	default:
		"Random number generation error";
	}
}

void NewGamePrompt()
{
	int WhatMessage; //Determines what random message to be printed

	srand(unsigned int(time(NULL))); // seed random number generator
	int ranNumber = rand() % 10 + 1; // output to screen random number between 1 and 100

	WhatMessage = ranNumber; //Sets WhatNumber to the random number generated

	switch (WhatMessage)
	{
	case 1:
	{
		cout << "\nPlay another game!\n";
		break;
	}

	case 2:
	{
		cout << "\nPress 'N' below to play a new game\n";
		break;
	}

	case 3:
	{
		cout << "\nPress 'Q' to quit\n";
		break;
	}

	case 4:
	{
		cout << "\nThat was fun - play again!\n";
		break;
	}

	case 5:
	{
		cout << "\nPlay again!\n";
		break;
	}

	case 6:
	{
		cout << "\nTake a chance on another round!\n";
		break;
	}

	case 7:
	{
		cout << "\nIf you play again the computer will generate a new random number\n";
		break;
	}

	case 8:
	{
		cout << "\nHow about another game?\n";
		break;
	}

	case 9:
	{
		cout << "\nOne more time, you will get it the next round!\n";
		break;
	}

	case 10:
	{
		cout << "\nAnother game?\n";
		break;
	}

	default:
		"Random number generation error";
	}
}