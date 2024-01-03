#include "pch.h"
#include "ScoreBoard.h"
#include "input_nameDlg.h"

#include<iostream>
#include<string>
using namespace std;


//�����Ǳ⺻ ���� �� �÷��̾� �Է�
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

//�����ǿ� ������ �Է��ϰ�, ������ �Էµ������� �ٽ� �����϶�� �ȳ�.
bool ScoreBoard::inputScore(int a, int score) {
	if (!ab[a - 1].getx()) {
		board[a - 1] = score;
		ab[a - 1].changeabc();
	}
	else {
		AfxMessageBox(_T("�̹� ������ �ԷµǾ� �ֽ��ϴ�! �ٸ� ���� ������ �Է��ϼ���!"));
		return false;
	}
	return 0;
}


//�÷��̾� �̸� ����
CString ScoreBoard::return_name() {
	return pn;
}


void ScoreBoard::PlayTurn() {
	//cout << pn << "���� �����Դϴ�! �ֻ����� �����ּ���!" << endl; //--> guide ����ƽ �ؽ�Ʈ���� �ȳ�

	dice = D.TakeDice();   // view���� �ֻ��� �̹��� 5���� ����, �ֻ��� ���� �̺�Ʈ�� dice Ŭ�������� ����.
	int l;
	while (true) {
		//cout << endl << "��� �׸� ������ �Է��Ͻðڽ��ϱ�?" << endl; // --> �̷� �͵� guide ����ƽ �ؽ�Ʈ���� �ȳ� �ȳ����� �������� guide ����ƽ �ؽ�Ʈ���� ����
		cin >> l; // -->�Է��� ����ƽ �ؽ�Ʈ�� �����ϴ� ������ ���� --> ����ƽ �ؽ�Ʈ �̺�Ʈ ó���� �ʿ���.
		if (l <= 12 && l >= 1) {
			if (rules::judge(l, dice, ab, score)) {
				inputScore(l, score);
				break;
			}
			//else
				//cout << "�ش��׸񿡴� ������ �� �� �����ϴ�. �ٽ� �������ּ���." << endl; // ����ƽ �ؽ�Ʈ
		}
		else if (l == 13)
			break;
		//else
			//cout << "*************************************\n   1~13������ ���ڸ� �Է����ּ���!\n*************************************" << endl;  // ����ƽ �ؽ�Ʈ
	}
}

void ScoreBoard::get_name() {
	input_nameDlg in;
	in.DoModal();
	pn = in.return_name();
	delete in;
}