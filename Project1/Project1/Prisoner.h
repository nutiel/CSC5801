#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

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
	//string code[lines];
	char last_outcome; // a ' ' means this is the first iteration
};