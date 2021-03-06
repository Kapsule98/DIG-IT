// Digit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<ctime>
#include<Windows.h>
#include "header.h"
Digit GameInstance;
void PlayGame();
int main()
{	
	do
	{
		PlayGame();
	} while (GameInstance.AskToPlayAgain());
	return 0;
}

void PlayGame()
{
	GameInstance.ResetField();;
	GameInstance.CreatePlayerField();
	std::cout << "Creating Computer Field\n";
	GameInstance.CreateComputerField();
	GameInstance.RandomiseComputerDigArray();
	Sleep(4000);
	std::cout << "Computer Field Created \n -----Lets Begin the Game-----\n";
	while (!GameInstance.GetGameOverFlag())
	{
		static int i = 0;
		GameInstance.AskPlayerToDig();
		Sleep(2000);
		GameInstance.PrintResultOfPlayerDig();
		GameInstance.DisplayDugField();
		GameInstance.ComputerDig(i);
			Sleep(2000);
		i++;
		system("cls");
	}
	GameInstance.PrintSummary();


}