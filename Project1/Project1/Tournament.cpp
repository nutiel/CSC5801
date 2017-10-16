#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"

Tournament::Tournament() :
	iterations(0),
	num_Strategies(0) {

}

Tournament::~Tournament() {

}

void Tournament::setNumofFiles(int n) {
	num_Strategies = n;
}

void Tournament::runTournament() {
	Prisoner p1, p2;
}