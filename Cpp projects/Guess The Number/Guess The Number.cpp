#include <iostream>
#include<ctime> 
#include<cstdlib>
#include<windows.h>
using namespace std;
int getvalidInput(string message)
{
	int num;
	while(true)
	{
		cout << message;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			cout << "ERROR ! Please , Enter A Vaild Number \n";
		}
		else
		{
			return num;
		}
	}
}
int main()
{
	char playAgain;
	int Score = 0;
	do
	{
		srand(time(0));
		int Start, End;
		system("cls");
		do
		{
			Start = getvalidInput("Enter The Starting Number\n");
			End = getvalidInput("Enter The Ending Number\n");
			if(Start >= End )
			{
				cout << "ERROR ! The Starting Number Must Be Less Than The Ending Number\n";
			}
		} while (Start >= End);
		system("cls");
		int Level, chance, numofChance;
		cout << "   Enter Number To Guess Between " << Start << " & " << End << " You Will Have Limited Attempts Based On The Level " << endl;
		cout << "--------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t ----- SELECT DIFFICULTY LEVEL ----- \n";
		cout << "--------------------------------------------------------------------------------------------\n";
		cout << "1.Easy Level (10 Attempts)\n";
		cout << "2.Medium Level (7 Attempts)\n";
		cout << "3.Difficult Level (5 Attempts)\n";
		cout << "4.Custom Number Of Attempts \n";
		cout << "0.Exist\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		do
		{
			Level = getvalidInput("Enter Difficulty Level\n");
			if (Level < 0 || Level > 4)
			{
				cout << "ERROR ! Please , Enter Number Between 0 & 4 \n";
			}
		} while (Level < 0 || Level > 4);
		switch (Level)
		{
		case 1:
			chance = 10;
			break;
		case 2:
			chance = 7;
			break;
		case 3:
			chance = 5;
			break;
		case 4:
			do
			{
				numofChance = getvalidInput("Enter The Number Of Attempts\n");
				if (numofChance <= 0)
				{
					cout << "ERROR ! The Number Of Attempts Must Be Greater Than Zero\n";
				}
			} while (numofChance <= 0);
			chance = numofChance;
			break;
		case 0:
			cout << "Thanks For Playinng\n";
			return 0;
		}
		int secretNumber = rand() % (End - Start + 1) + Start;
		int chosenNumber, Attempts = 0;
		bool guessed = false;
		while (Attempts < chance)
		{
			cout << "==========================================================\n";
			do
			{
				chosenNumber = getvalidInput("Enter Your Guess\n");
				if (chosenNumber < Start || chosenNumber > End)
				{
					cout << "ERROR ! Please , Enter Number Between " << Start << " & " << End << endl;
				}
			} while (chosenNumber < Start || chosenNumber > End);
			Attempts++;
			if (chosenNumber == secretNumber)
			{
				if (Attempts == 1)
				{
					Score += 100;
				}
				else if (Attempts > 1 && Attempts <= chance / 3)
				{
					Score += 50;
				}
				else
				{
					Score += 20;
				}
				system("Color F0");
				cout << "\033[32m*** Congratulations ***\033[0m\n";
				cout << "You Found The Secret Number " << secretNumber << " In " << Attempts << " Attempts \n";
				Sleep(2000);
				system("Color 0F");
				guessed = true;
				break;
			}
			else if (chosenNumber < secretNumber)
			{
				cout << "Isn't Secret Number \n";
				cout << "The Secret Number Is Greater Than Your Guess \n";
				cout <<  (chance - Attempts) <<" Choice Left " << endl;
			}
			else
			{
				cout << "Isn't Secret Number \n";
				cout << "The Secret Number Is Smaller Than Your Guess\n";
				cout << (chance - Attempts) << " Choice Left " << endl;
			}
			if (Attempts == chance / 2  )
			{
				cout << "==========================================================\n";
				char hint;
				cout << "Would You Like To Know If The Number Is Even OR Odd ? (Y / N ) \n";
				cout << "Enter Your Choice \n";
				cin >> hint;
				if (hint == 'Y' || hint == 'y')
				{
					cout << "The Secret Number Is " << ((secretNumber % 2 == 0) ? "Even" : "ODD") << endl;
				}
			}
		}
		if (!guessed)
		{
			cout << "==========================================================\n";
			Score -= 10;
			system("Color 80");
			cout << "\033[31m## GAME OVER ## \033[0m\n";
			cout<<"You Have Used All "<< Attempts << " Attempts The Secret Number Was " << secretNumber << endl;
			Sleep(2000);
			system("Color 0F");
		}
		cout << "----------------------------------------------------------\n";
		cout << "Do You Want To Play Again ? (Y/N)\n";
		cin >> playAgain;
	}while (playAgain == 'y' || playAgain == 'Y');
	if(playAgain != 'Y' && playAgain != 'y')
	{
		cout << "Final Score " << Score << endl;
		cout << "\t\t\t Thanks For Playinng \n";
	}
	return 0;
}

