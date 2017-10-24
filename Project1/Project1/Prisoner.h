#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Prisoner {
public:
	Prisoner();
	~Prisoner();
	int LASTOUTCOME();
	int ALLOUTCOMES_W();
	int ALLOUTCOMES_X();
	int ALLOUTCOMES_Y();
	int ALLOUTCOMES_Z();
	int ITERATIONS();
	int MYSCORE();
	void increaseIterations();
	void setCode(string code, int i);
	int powOfN(int n, int p);
	bool makeDecision();
	void result(bool result1, bool result2);
	int parseLine(int l);
	int to_int(string num);
private:
	int w, x, y, z, score, iterations;
	vector< vector< string> > code;
	int last_outcome; // a 0 means this is the first iteration, -1->W, -2->X, -3->Y, -4->Z
};