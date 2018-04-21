#include "stdafx.h"
#include <iostream>
#include<ctime>
#include<string>
#include<chrono>
#include<algorithm>
#include <array>
#include<random>

#include<Windows.h>
#include "Header.h"

void Digit::ResetField()
{	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			PlayerField[i][j] = '-';
			DugField[i][j] = '-';
			
		}
		for (int i = 0; i < 16; i++)
		{
			ComputerField[i] = '-';
		}

	}
	
}
void Digit::InputPlayerTreasure(int i)
{
		std::cout << "Place tresure chest " << i << std::endl;
		std::cin >> PlayerTresureX >> PlayerTresureY;
		PlayerField[PlayerTresureX-1][PlayerTresureY-1] = '#';
	
}

void Digit::DisplayPlayerField () const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << " " << PlayerField[i][j];
		}
		std::cout << std::endl;
	}

	
}

void Digit::CreatePlayerField()
{	
	for (int i = 1; i <= 4; i++)
	{
		system("cls");
		switch (i)
		{
		case 1:std::cout << "Enter Location of first Treasure chest\n"; break;
		case 2:std::cout << "Enter Location of second Treasure chest\n"; break;
		case 3:std::cout << "Enter Location of third Treasure chest\n"; break;
		case 4:std::cout << "Enter Location of fourth Treasure chest\n"; break;
		default:
			break;
		}
		InputPlayerTreasure(i);
		DisplayPlayerField();
		if (i != 4)
		{
			Sleep(1500);
		}
	}

}

void Digit::CreateComputerField()
{
	for (int i = 0; i < 4; i++)
	{
		srand(time(0));
		int p = rand()%16;
		if (ComputerField[p] == '#')
		{
			i--;
		}
		else
		{
			ComputerField[p] = '#';
		}
	}
}

void Digit::DisplayComputerField() const
{
	for (int i = 0; i < 16; i++)
	{
		std::cout << " " << ComputerField[i];
		if ((i + 1) % 4 == 0)
		{
			std::cout << std::endl;
		}
	}
}

void Digit::AskPlayerToDig()
{	
		Dig:
		std::cout << "Your turn\n Select coordinates where you wish to dig\n";
		int x, y;
		std::cin >> x >> y;
		int Location = 4 * (x - 1) + (y - 1);
		if ((ComputerField[Location] != 'O')&&(ComputerField[Location] != 'X'))
		{
			PlayerDigLocation = Location;
			
		}
		else
		{
			std::cout << " How many times do you want to dig there mate !!\n";
			goto Dig;
		}
}

void Digit::PrintResultOfPlayerDig()
{
	if (ComputerField[PlayerDigLocation] == '#')
	{
		std::cout << " Woohoo! you uncovered a treasure chest\n";
		PlayerHits++;
		ComputerField[PlayerDigLocation] = 'X';
		DugField[PlayerDigLocation/4][PlayerDigLocation%4] = 'X';
		std::cout << " Remaining Treasures = " << 4 - (PlayerHits) << std::endl;
		if (PlayerHits == 4)
		{
			PlayerWins = true;
			GameOver = true;
		}
	}
	else
	{
		std::cout << " No luck here....Nothing found \n";
		ComputerField[PlayerDigLocation] = 'O';
		DugField[PlayerDigLocation / 4][PlayerDigLocation % 4] = 'O';
	}

}

void Digit::ComputerDig(int i)
{		
	int AttackX;
	int AttackY;
	
	
		AttackX = ComputerDigArray[i] / 4;
		AttackY = ComputerDigArray[i] % 4;
		Sleep(2000);
		
		if (PlayerField[AttackX][AttackY] == '#')
		{
			std::cout << " Watch out Computer just found one of your treasure chest!!\n";
			ComputerHits++;
			std::cout << "Treasure Remaining = " << (4 - ComputerHits) << std::endl;
			if (ComputerHits == 4)
			{
				ComputerWins = true;
				GameOver = true;
			}
		
		}

		else
		{
			std::cout << "Computer Missed \n";
		}
	/*srand(time(0));
	std::cout << " Computer's turn to dig \n";
		Sleep(1000);
		CpuDig:
		int P = rand();
		int AttackX = P/4;
		int AttackY = P % 4;
		std::cout << AttackX << AttackY;
		if (PlayerField[AttackX][AttackY] == 'O')
		{
			goto CpuDig;
		}
		else
		{
			if (PlayerField[AttackX][AttackY] == '#')
			{
				PlayerField[AttackX][AttackY] = 'O';
				std::cout << " Watch out Computer just found one of your treasure chest!!\n";
				ComputerHits++;
				std::cout << "Treasure Remaining = " << (4 - ComputerHits) << std::endl;
				if (ComputerHits == 4)
				{
					ComputerWins = true;
					GameOver = true;
				}
			}
			else
			{
				std::cout << "Computer Missed \n";
			}
		}*/

}

void Digit::PrintSummary() const
{
	if (GameOver&&ComputerWins)
	{
		std::cout << " You Lost..Better Luck Next Time\n";
	}
	if (GameOver&&PlayerWins)
	{
		std::cout << " Congratulations you won..\n";
	}
}

bool Digit::GetGameOverFlag()
{
	return GameOver;
}

void Digit::RandomiseComputerDigArray()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(ComputerDigArray.begin(), ComputerDigArray.end(), std::default_random_engine(seed));
}

void Digit::DisplayDugField()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << DugField[i][j];
		}
		std::cout << std::endl;
	}
}

bool Digit::AskToPlayAgain()
{
	std::cout << "Do you wish to play again (y/n) \n";
	std::string Choice;
	std::cin >> Choice;
	if ((Choice[0] == 'y') || (Choice[0] == 'Y'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

