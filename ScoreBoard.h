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
	abc* ab = new abc[12];							//abc��ü�� �����ǿ� ������ ���� ����� Ȯ���ϴ� ��ü
	int board[12];									//������
	int score;
	Dice D;
	bool getx(int a) { return ab[a - 1].getx(); }
	bool inputScore(int a, int score);				//�����ǿ� �ֻ������� �Է�
	void PlayTurn();
	CString return_name();								//�÷��̾��� �̸��� ������
	void get_name();
	int return_score() { return score; }
	bool subtotal();
	int total();
	int re_subtotal();
};

#endif // !ScoreBoard_h