#include "Leader.h"
#include "CW2.h"
#include "Prisoner.h"
#include "IfNode.h"
#include "Expression.h"

Leader::Leader() :
Prisoner() {

}

Leader::~Leader() {

}

int Leader::chooseSpy() {
	//will choose a gang member at random including himself
	choice = rand() % 5 + 1;
	return choice;
}

int Leader::changeChoice(int p) {

	int random_integer = rand () % 5 + 1;

	while (random_integer == p || random_integer == choice) {
		random_integer = rand() % 5 + 1;
	}

	choice = random_integer;
	return choice;
}