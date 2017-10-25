#pragma once

#include <iostream>
#include "Leader.h"
#include "Prisoner.h"

using namespace std;

class Gang {
public:
	Gang();
	~Gang();
	int LASTOUTCOME();
	int ALLOUTCOMES_W();
	int ALLOUTCOMES_X();
	int ALLOUTCOMES_Y();
	int ALLOUTCOMES_Z();
	int ALLOUTCOMES_A();
	int ALLOUTCOMES_B();
	int ALLOUTCOMES_C();
	int ITERATIONS();
	int MYSCORE();
	void increaseIterations();
	void result(char result);
	bool addSpy(int percent);
private:
	int w, x, y, z, a, b, c, iterations;
	double score;
	int last_outcome; // -1 -> W, -2 -> X, -3 -> Y, -4 -> Z, -5 -> A, -6 -> B, -7 -> C 
	Leader *p1;
	Prisoner *p2, *p3, *p4, *p5;
};