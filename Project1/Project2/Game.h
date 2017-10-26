#pragma once

#include <iostream>
#include "Prisoner.h"
#include "Gang.h"

using namespace std;

class Game {
public:
	Game();
	~Game();
	void setStrategy(string string1, string string2, int k);
	string getStrategy(int i);
	double getScore1();
	double getScore2();
	void calculateAverage(Gang* g1, Gang* g2, int iterations);
private:
	string strategy1; //The first strategy competing in the game
	string strategy2; //The second strategy competing in the game
	string strategy3;
	string strategy4;
	string strategy5;
	string strategy6;
	string strategy7;
	string strategy8;
	string strategy9;
	string strategy10;

	double str1_average; //The average score of strategy 1 after 200 iterations
	double str2_average; //The average score of strategy 2 after 200 iterations
};
