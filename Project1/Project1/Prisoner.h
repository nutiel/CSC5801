#pragma once

#include <iostream>

using namespace std;

class Prisoner {
public:
	Prisoner();
	~Prisoner();
	char LASTOUTCOME();
	int ALLOUTCOMES_W();
	int ALLOUTCOMES_X();
	int ALLOUTCOMES_Y();
	int ALLOUTCOMES_Z();
	int MYSCORE();
	void setCode(string code, int i);
	bool makeDecision(int iterations);
	void result(bool result1, bool result2);
private:
	int w, x, y, z, score;
	string code[lines];
	char last_outcome; // a ' ' means this is the first iteration
};