//Requirements: 
//•Ask for how many rounds the game will be.
//•Start each round Player vs Computer.
//•Show the results with each round.
//•If computer wins the round ring a bell, and screen red.
//•If player won the round show green screen.
//•After all rounds show game over the print game results,
//       then ask the user if s / he want to play again ?
#include<iostream>
using namespace std;
enum enGameConditions { Paper = 1, Stone = 2, Scissor };
int ReadNumber(string msg)
{
	int Number;
	do
	{
		cout << msg;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int CopmuterChoice(int from, int to)
{
	int RandomNbr = rand() % (to - from + 1) + from;
	return RandomNbr;
}
int Rounds()
{
	int RoundNbr = ReadNumber("How many round do you want to play ?.  ");
	return RoundNbr;
}
int PlayerChoice()
{
	int PlayerChoice = ReadNumber("What is your choice ?");
	return PlayerChoice;
}
void RoundCicle(int& PlayerWin, int& ComputerWin, int& Draw)
{
	cout << "Choose  Paper=1 Stone=2 Scissor=3" << endl << endl;
	int Player = PlayerChoice();
	cout << endl;
	int Computer = CopmuterChoice(1, 3);
	if ((Player == Paper && Computer == Stone) || (Player == Stone && Computer == Scissor) || (Player == Scissor && Computer == Paper))
	{
		system("color 2F");
		cout << "Player Choice   -->" << Player << endl;
		cout << "Computer Choice -->" << Computer << endl;
		cout << "*** Player Win ***" << endl;
		PlayerWin++;


	}
	else if ((Computer == Paper && Player == Stone) || (Computer == Stone && Player == Scissor) || (Computer == Scissor && Player == Paper))
	{
		system("color 4F");
		cout << "\a";
		cout << "Player Choice   -->" << Player << endl;
		cout << "Computer Choice -->" << Computer << endl;
		cout << "*** Computer Win ***" << endl;
		ComputerWin++;
	}

	else
	{
		system("color 6F");
		cout << "Player Choice   -->" << Player << endl;
		cout << "Computer Choice -->" << Computer << endl;
		cout << "*** The outcome is a Draw ***" << endl;
		Draw++;
	}
}
void RoundPlay(int& PlayerWin, int& ComputerWin, int& Draw)
{
	int RoundNbr = Rounds();
	for (int i = 0; i < RoundNbr; i++)
	{
		cout << "-------------- Round " << i + 1 << "--------------" << endl;
		RoundCicle(PlayerWin, ComputerWin, Draw);
		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << "------------GAME OVER--------------" << endl << endl;
	cout << "Round Game is " << RoundNbr << endl;
	cout << " Player Win   [" << PlayerWin << "] Times" << endl;
	cout << " Computer Win [" << ComputerWin << "] Times" << endl;
	cout << " ******* draw [" << Draw << "] Times" << endl;
	cout << endl;
	if (PlayerWin > ComputerWin)
	{
		cout << "Final Winner is " << "Player " << endl;
	}
	else
	{
		cout << "Final Winner is " << "Computer " << endl;
	}
	cout << "------------------------------------" << endl;

}
void StartGame(int PlayerWin, int ComputerWin, int Draw)
{
	bool PlayAgain=1;
	do
	{
		RoundPlay(PlayerWin, ComputerWin, Draw);
		cout << "Do you want to play again?" << endl;
		cin >> PlayAgain;
	}while(PlayAgain);
}
int main()
{
	srand((unsigned)time(NULL));
	int PlayerWin = 0, ComputerWin = 0, Draw = 0;
	StartGame(PlayerWin, ComputerWin, Draw);
	return 0;
}