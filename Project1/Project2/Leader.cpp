/**
CSC5801
Leader.cpp
Purpose: An extension of the prisoner class, has the responsibility of 
spotting the spy

@author Michael Yiangou (B7064124)
@version
*/

#include "CW2.h"
#include "Expression.h"
#include "Game.h"
#include "IfNode.h"
#include "Leader.h"
#include "Thread.h"
#include "Tournament.h"
#include "Gang.h"

Leader::Leader(Gang* gname) :
Prisoner(gname) {

}

Leader::~Leader() {

}

int Leader::chooseSpy() {
	//will choose a gang member at random including himself
	choice1 = rand() % 5 + 1;
	return choice1;
}

int Leader::changeChoice(int p) {

	int random_integer = rand () % 5 + 1;

	while (random_integer == p || random_integer == choice1) {
		random_integer = rand() % 5 + 1;
	}

	choice2 = random_integer;
	return choice2;
}