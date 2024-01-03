#pragma once

class Dice
{
	int dice[5];
	int count;
	//CMainFrame* pFrame;
	//CMFCFinalView* pView;
public:
	Dice();
	int* RollDice();
	int* TakeDice();
	void reRoll(int a);
};

