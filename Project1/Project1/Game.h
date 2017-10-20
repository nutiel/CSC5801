#pragma once

#include <iostream>
#include "Prisoner.h"

using namespace std;

class Game {
public:
	Game();
	~Game();
	void setStrategy(string string1, string string2);
	string getStrategy1();
	string getStrategy2();
	double getScore1();
	double getScore2();
	void calculateAverage(Prisoner* p1, Prisoner* p2, int iterations);
private:
	string strategy1;
	string strategy2;

	double str1_average;
	double str2_average;
};