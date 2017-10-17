#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"

Prisoner::Prisoner() :
	w(0), x(0),	y(0), z(0),
	score(0), 
	last_outcome(' ') {

}

Prisoner::~Prisoner() {

}

char Prisoner::LASTOUTCOME() {
	return last_outcome;
}

int Prisoner::ALLOUTCOMES_W() {
	return w;
}

int Prisoner::ALLOUTCOMES_X() {
	return x;
}

int Prisoner::ALLOUTCOMES_Y() {
	return y;
}

int Prisoner::ALLOUTCOMES_Z() {
	return z;
}

int Prisoner::MYSCORE() {
	return score;
}

void Prisoner::setCode(string line, int i) {
	code[i] = line;
}

bool Prisoner::makeDecision(int iterations) {

}

/*
 * 
 * bool result1 - prisoners own decision
 * bool result2 - other prisoners decision
 * 
 * true = silence, false = betray
 * 
 */
void Prisoner::result(bool result1, bool result2) {
	if(result1 && result2) {
		w++;
		score += 2;
		this->last_outcome = 'w';
	}else if (result1 && !result2) {
		x++;
		score += 5;
		this->last_outcome = 'x';
	}else if (!result1 && result2) {
		y++;
		score += 0;
		this->last_outcome = 'y';
	}
	else {
		z++;
		score += 4;
		this->last_outcome = 'z';
	}
}