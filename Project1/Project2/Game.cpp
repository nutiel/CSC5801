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

void Game::calculateAverage(Gang* p1, Gang* p2, int iterations) {
	str1_average = (double)p1->MYSCORE() / (double)iterations;
	str2_average = (double)p2->MYSCORE() / (double)iterations;
}