#pragma once
#include<array>
class Digit
{     
public:
	void ResetField();
	void InputPlayerTreasure(int);
	void DisplayPlayerField() const;
	void CreatePlayerField();
	void CreateComputerField();
	void DisplayComputerField()const;
	void AskPlayerToDig();
	void PrintResultOfPlayerDig();
	void ComputerDig(int);
	void PrintSummary()const;
	bool GetGameOverFlag();
	void RandomiseComputerDigArray();
	void DisplayDugField();
	bool AskToPlayAgain();
	
	


private:
	char PlayerField[4][4];
	char DugField[4][4];
	char ComputerField[16];
	int PlayerTresureX;
	int PlayerTresureY;
	int ComputerTreasureX;
	int ComputerTreasureY;
	int ComputerTresure[8];
	int PlayerHits = 0;
	int ComputerHits = 0;
	bool ComputerWins = false;
	bool PlayerWins = false;
	bool GameOver = false;
	int PlayerDigLocation;
	std::array<int, 16> ComputerDigArray{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	
};