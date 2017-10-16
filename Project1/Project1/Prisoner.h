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
private:
	int w, x, y, z, score, iterations;
	char last_outcome;
};