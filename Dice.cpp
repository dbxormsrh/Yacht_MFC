#include "pch.h"
#include "Dice.h"

#include"input_nameDlg.h"

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

Dice::Dice() {

}

int* Dice::RollDice() {
	for (int i = 0; i < 5; i++) {
		dice[i] = rand() % 6 + 1;
	}
	return dice;
}

void Dice::reRoll(int a) {
	if (a < 6 && a>0)
		dice[a - 1] = rand() % 6 + 1;
}


int* Dice::TakeDice() {
	return dice;
}

