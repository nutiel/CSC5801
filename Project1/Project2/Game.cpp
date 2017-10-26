#include "CW2.h"
#include "Expression.h"
#include "Game.h"
#include "Gang.h"
#include "IfNode.h"
#include "Leader.h"
#include "Prisoner.h"
#include "Thread.h"
#include "Tournament.h"

Game::Game() :
	strategy1(""),
	strategy2("") {

}

Game::~Game() {

}

void Game::setStrategy(string string1, string string2, int k) {
	switch (k) {
	case 0:
		strategy1 = string1;
		strategy6 = string2;
		break;
	case 1:
		strategy2 = string1;
		strategy7 = string2;
		break;
	case 2:
		strategy3 = string1;
		strategy8 = string2;
		break;
	case 3:
		strategy4 = string1;
		strategy9 = string2;
		break;
	case 4:
		strategy5 = string1;
		strategy10 = string2;
		break;
	}
}

string Game::getStrategy(int i) {

	switch (i) {
	case 0:
		return strategy1;
		break;
	case 1:
		return strategy2;
		break;
	case 2:
		return strategy3;
		break;
	case 3:
		return strategy4;
		break;
	case 4:
		return strategy5;
		break;
	case 5:
		return strategy6;
		break;
	case 6:
		return strategy7;
		break;
	case 7:
		return strategy8;
		break;
	case 8:
		return strategy9;
		break;
	case 9:
		return strategy10;
		break;
	default:
		string strategies;

		strategies = strategies + strategy1 + ", ";
		strategies = strategies + strategy2 + ", ";
		strategies = strategies + strategy3 + ", ";
		strategies = strategies + strategy4 + ", ";
		strategies = strategies + strategy5 + ", ";
		strategies = strategies + strategy6 + ", ";
		strategies = strategies + strategy7 + ", ";
		strategies = strategies + strategy8 + ", ";
		strategies = strategies + strategy9 + ", ";
		strategies = strategies + strategy10;

		return strategies;
		break;
	}
}


double Game::getScore1() {
	return str1_average;
}

double Game::getScore2() {
	return str2_average;
}

void Game::calculateAverage(Gang* g1, Gang* g2, int iterations) {
	str1_average = (double)g1->MYSCORE() / (double)iterations;
	str2_average = (double)g2->MYSCORE() / (double)iterations;
}