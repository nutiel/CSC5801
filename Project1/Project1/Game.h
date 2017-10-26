/**
CSC5801
Game.h
Purpose: Is responsible for a single game of 200 iterations
between 2 prisoners

@author Michael Yiangou (B7064124)
@version
*/

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
	string strategy1; //The first strategy competing in the game
	string strategy2; //The second strategy competing in the game

	double str1_average; //The average score of strategy 1 after 200 iterations
	double str2_average; //The average score of strategy 2 after 200 iterations
};