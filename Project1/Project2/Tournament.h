/**
CSC5801
Tournament.h
Purpose: Handles the matchups between the two gangs

@author Michael Yiangou (B7064124)
@version
*/

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
	//The start of the tournament
	void runTournament();
	void setNumofFiles(int n);
	//Runs the 200 iterations for a game
	void runSimulation(int i, int j, Game* g, int spy_percent);
	//Reads the 2 strategy files
	void readFiles(int i, int j, Gang* p1, Gang* p2);
	//Saves the results of the game for both prisoners in a file
	void printCurrentResults(Gang* p1, Gang* p2, Game g);
	//Saves and sorts the average scores for each strategy in an array
	void saveStats(Game g, int str1, int str2);
	//Prints the array with the average scores
	void printStats();
	//Sorts the contents of the average array
	void sortAverageArr(string *average, double *avnum);
	//Calls the set prisoner code function for each prisoner
	void setPrisonerCode(int i, string str, Gang* g);
private:
	int num_Strategies;
	static const int MAX_ITERARIONS = 200;
	double* arr; //For saving and sorting the average score for each strategy
};