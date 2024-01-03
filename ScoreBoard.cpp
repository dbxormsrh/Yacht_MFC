#include "pch.h"
#include "ScoreBoard.h"
#include "input_nameDlg.h"

#include<iostream>
#include<string>
using namespace std;


//점수판기본 설정 및 플레이어 입력
ScoreBoard::ScoreBoard() {
	for (int i = 0; i < 12; i++) {
		board[i] = 0;
	}
	score = 0;
	
}
int ScoreBoard::re_subtotal() {
	int st = 0;
	for (int i = 0; i < 6; i++)
		st += board[i];
	return st;
}

bool ScoreBoard::subtotal() {
	int st = 0;
	for (int i = 0; i < 6; i++)
		st += board[i];
	if (st >= 63)
		return true;
	return false;
}

int ScoreBoard::total() {
	int st = 0, t = 0;

	for (int i = 0; i < 6; i++)
		st += board[i];
	for (int i = 0; i < 12; i++)
		t += board[i];
	if (st >= 63)
		t += 35;
	return t;
}

//점수판에 점수를 입력하고, 점수가 입력되있으면 다시 선택하라고 안내.
bool ScoreBoard::inputScore(int a, int score) {
	if (!ab[a - 1].getx()) {
		board[a - 1] = score;
		ab[a - 1].changeabc();
	}
	else {
		AfxMessageBox(_T("이미 점수가 입력되어 있습니다! 다른 곳에 점수를 입력하세요!"));
		return false;
	}
	return 0;
}


//플레이어 이름 리턴
CString ScoreBoard::return_name() {
	return pn;
}


void ScoreBoard::PlayTurn() {
	//cout << pn << "님의 차례입니다! 주사위를 굴려주세요!" << endl; //--> guide 스태틱 텍스트에서 안내

	dice = D.TakeDice();   // view에서 주사위 이미지 5개를 띄우고, 주사위 관련 이벤트는 dice 클래스에서 조작.
	int l;
	while (true) {
		//cout << endl << "어느 항목에 점수를 입력하시겠습니까?" << endl; // --> 이런 것도 guide 스태틱 텍스트에서 안내 안내관련 문구들은 guide 스태틱 텍스트에서 관리
		cin >> l; // -->입력은 스태틱 텍스트를 선택하는 것으로 관리 --> 스테틱 텍스트 이벤트 처리기 필요함.
		if (l <= 12 && l >= 1) {
			if (rules::judge(l, dice, ab, score)) {
				inputScore(l, score);
				break;
			}
			//else
				//cout << "해당항목에는 점수가 들어갈 수 없습니다. 다시 선택해주세요." << endl; // 스테틱 텍스트
		}
		else if (l == 13)
			break;
		//else
			//cout << "*************************************\n   1~13사이의 숫자를 입력해주세요!\n*************************************" << endl;  // 스테틱 텍스트
	}
}

void ScoreBoard::get_name() {
	input_nameDlg in;
	in.DoModal();
	pn = in.return_name();
	delete in;
}