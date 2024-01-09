#include<iostream>
#include<cstdlib>
#include"ABODAstd.h"

using namespace std;

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