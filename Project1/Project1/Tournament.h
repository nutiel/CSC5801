#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Tournament {
public:
	Tournament();
	~Tournament();
	void runTournament();
	void setNumofFiles(int n);
	void runSimulation(int i, int j);
	void readFiles(int i, int j, Prisoner* p1, Prisoner* p2);
private:
	int num_Strategies;
	static const int MAX_ITERARIONS = 200;
};