/**
CSC5801
Gang.h
Purpose: Represents a gang of 5 prisoners and handles the
variables of 200 iterations

@author Michael Yiangou (B7064124)
@version
*/

#pragma once

#include <iostream>
#include "Leader.h"

using namespace std;

class Prisoner;

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
	double MYSCORE();
	void increaseIterations();
	//takes care of the variable updates for the game to continue
	void result(Gang* g);
	//chooses a prisoner at random and sets him as a spy
	bool addSpy(int percent);
	//resets the spy variable
	void resetSpy();
	//uses the strategies given to the prisoners to make a decision
	void makeDecision();
	bool getHasSpy();
	int getSpy();
	int getSilenceNo();
	int getBetrayNo();
	Prisoner* getPrisoner(int i);
	Leader* getLeader();
	void chooseBetray();
	void chooseSilence();
	void setFoundSpy();
	bool getFoundSpy();
	int getTotalSpies();
	int getSpiesFound();
private:
	int silence_no, betray_no;
	int spies_found, total_spies;
	int w, x, y, z, a, b, c, iterations;
	double score;
	bool found_spy;
	bool has_spy;
	int spy; //1..5 depending on who the spy is
	int last_outcome; // -1 -> W, -2 -> X, -3 -> Y, -4 -> Z, -5 -> A, -6 -> B, -7 -> C 
	Leader *p1;
	Prisoner *p2, *p3, *p4, *p5;
};