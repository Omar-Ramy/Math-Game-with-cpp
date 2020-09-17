#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

int correctAnswers = 0;

bool isLevelFinished = false;

bool isNextLevel;

void Level(int levelNumber, int between, char sign)
{
	srand(time(NULL));
	int numberOne = rand() % between;
	int numberTwo = rand() % between;

	cout << "Level " << levelNumber << endl;

	int result;

	if (sign == '+')
	{
		result = numberOne + numberTwo;
	}
	else if (sign == '-')
	{
		result = numberOne - numberTwo;
	}

	cout << numberOne << ' ' << sign << ' ' << numberTwo << " = ";
	cin >> result;


	if (result)
	{
		correctAnswers += 1;
		cout << "\n" << "Good Job!" << endl;
		cout << "Your Score is now " << correctAnswers << "!" << endl;
		isLevelFinished = true;
	}
	else if (correctAnswers == 0 && !result)
	{
		cout << "\n" << "Wrong answer!" << endl;
		cout << "Your score is now " << correctAnswers << "!" << endl;
		isLevelFinished = true;
	}
	else if (correctAnswers > 0 && !result)
	{
		correctAnswers -= 1;
		cout << "\n" << "Wrong answer!" << endl;
		cout << "Your score is now " << correctAnswers << "!" << endl;
		isLevelFinished = true;
	}

}

int main()
{
	//------------------Level One-------------------//
	Level(1, 6, '+');

	// Level Two
	if (isLevelFinished)
	{
		cout << "\n";
		Level(2, 11, '+');
	}

	// Level Three
	if (isLevelFinished)
	{
		cout << "\n";
		Level(3, 6, '-');
	}
}