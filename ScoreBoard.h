#pragma once
#ifndef ScoreBoard_h
#define ScoreBoard_h
#include <string>
#include "Rules.h"
#include "abc.h"
#include "dice.h"

class ScoreBoard {
	CString pn;
	int* dice;
public:
	ScoreBoard();
	abc* ab = new abc[12];							//abc객체는 점수판에 점수를 넣은 기록을 확인하는 객체
	int board[12];									//점수판
	int score;
	Dice D;
	bool getx(int a) { return ab[a - 1].getx(); }
	bool inputScore(int a, int score);				//점수판에 주사위값을 입력
	void PlayTurn();
	CString return_name();								//플레이어의 이름을 리턴함
	void get_name();
	int return_score() { return score; }
	bool subtotal();
	int total();
	int re_subtotal();
};

#endif // !ScoreBoard_h