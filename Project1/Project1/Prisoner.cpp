#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"

Prisoner::Prisoner() :
	w(0), x(0),	y(0), z(0),
	score(0), 
	last_outcome(' '), 
	iterations(0) {

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