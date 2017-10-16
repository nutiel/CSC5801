#pragma once

#include <iostream>

using namespace std;

class Tournament {
public:
	Tournament();
	~Tournament();
	void runTournament();
	void setNumofFiles(int n);
private:
	int iterations, num_Strategies;
	static const int MAX_ITERARIONS = 200;
};