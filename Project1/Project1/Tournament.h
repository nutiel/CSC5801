#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Game.h"

using namespace std;

class Tournament {
public:
	Tournament();
	~Tournament();
	void runTournament();
	void setNumofFiles(int n);
	void runSimulation(int i, int j, Game g);
	void readFiles(int i, int j, Prisoner* p1, Prisoner* p2);
	void printCurrentResults(Prisoner* p1, Prisoner* p2, Game g);
private:
	int num_Strategies;
	static const int MAX_ITERARIONS = 200;
};