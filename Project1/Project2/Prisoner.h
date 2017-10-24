#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Prisoner {
public:
	Prisoner();
	virtual ~Prisoner();
	virtual int LASTOUTCOME();
	virtual int ALLOUTCOMES_W();
	virtual int ALLOUTCOMES_X();
	virtual int ALLOUTCOMES_Y();
	virtual int ALLOUTCOMES_Z();
	virtual int ALLOUTCOMES_A();
	virtual int ALLOUTCOMES_B();
	virtual int ALLOUTCOMES_C();
	virtual int ITERATIONS();
	virtual int MYSCORE();
	virtual void increaseIterations();
	virtual void setCode(string code, int i);
	virtual int powOfN(int n, int p);
	virtual bool makeDecision();
	virtual void result(bool result1, bool result2);
	virtual int parseLine(int l);
	virtual int to_int(string num);
	virtual void setSpy();
private:
	int w, x, y, z, a, b, c, score, iterations;
	vector< vector< string> > code;
	bool spy;
	int last_outcome; // -1 -> W, -2 -> X, -3 -> Y, -4 -> Z, -5 -> A, -6 -> B, -7 -> C 
};