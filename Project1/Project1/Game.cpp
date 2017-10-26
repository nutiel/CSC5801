/**
CSC5801
Game.cpp
Purpose: Is responsible for a single game of 200 iterations
between 2 prisoners

@author Michael Yiangou (B7064124)
@version
*/

#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"
#include "Expression.h"

Game::Game() :
strategy1(""),
strategy2("") {

}

Game::~Game() {

}

void Game::setStrategy(string string1, string string2) {
	strategy1 = string1;
	strategy2 = string2;
}

string Game::getStrategy1() {
	return strategy1;
}

string Game::getStrategy2() {
	return strategy2;
}

double Game::getScore1() {
	return str1_average;
}

double Game::getScore2() {
	return str2_average;
}

void Game::calculateAverage(Prisoner* p1, Prisoner* p2, int iterations) {
	str1_average = (double)p1->MYSCORE() / (double)iterations;
	str2_average = (double)p2->MYSCORE() / (double)iterations;
}