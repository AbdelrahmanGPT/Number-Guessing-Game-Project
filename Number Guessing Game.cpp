#include<iostream>
#include<cstdlib>

using namespace std;

short RandomNumber(short From, short To)
{
	short RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;
}

short ValidateNumberInRange(short From, short To)
{
	short Number;
	do
	{
		cout << "GUESS A NUMBER BETWEEN " << From << " & " << To << "\n";
		cin >> Number;

	} while (Number < From || Number > To);

	return Number;
}

void IsYourAnswerRight(short RealAnswer, short UserAnswer)
{
	if (RealAnswer == UserAnswer)
	{
		cout << "EXCELLENT , YOU GOT IT! :)\n";
		cout << "THE NUMBER IS " << RealAnswer << " :)\n";
	}

	else if (RealAnswer > UserAnswer)
	{
		cout << "THE REAL NUMBER IS GREATER THAN " << UserAnswer << "\n";
	}

	else
	{
		cout << "THE REAL NUMBER IS SMALLER THAN " << UserAnswer << "\n";
	}
}

bool DoYouWantToPlayAgain()
{
	string Choice;
	do
	{
		cout << "DO YOU WANT TO PLAY AGAIN[Y/N]\n";
		cin >> Choice;
	} while (Choice != "Y" && Choice != "y" && Choice != "N" && Choice != "n");

	if (Choice == "Y" || Choice == "y")
	{
		system("cls");
		return 1;
	}

	else
	{
		cout << "GOOD BYE :)\n";
		return 0;
	}
}

void NumberGuessingGame()
{
	do
	{
		cout << "WELCOME TO NUMBER GUESSING GAME\n";
		short RealRandomNumber = RandomNumber(1, 100);
		short UserGuessedNumber;

		do
		{
			cout << "-------------------------------------\n";

			UserGuessedNumber = ValidateNumberInRange(1, 100);

			IsYourAnswerRight(RealRandomNumber, UserGuessedNumber);
			
			

		} while (UserGuessedNumber != RealRandomNumber);

		cout << "-------------------------------------\n";

	} while (DoYouWantToPlayAgain());
}

int main()
{
	srand((unsigned)time(NULL));

	NumberGuessingGame();

	return 0;
}