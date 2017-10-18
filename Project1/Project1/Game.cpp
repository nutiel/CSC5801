#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"

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