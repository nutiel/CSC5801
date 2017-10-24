#include "Gang.h"

Gang::Gang() {
	p1 = new Leader();
	p2 = new Prisoner();
	p3 = new Prisoner();
	p4 = new Prisoner();
	p5 = new Prisoner();
}

Gang::~Gang(){
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
}

bool Gang::addSpy(int percent) {
	int random_integer;
	random_integer = rand() % 100 + 1;

	if (random_integer > percent) {
		return false;
	}

	random_integer = rand() % 5 + 1;

	switch (random_integer) {
	case 1:
		p1->setSpy();
		break;
	case 2:
		p2->setSpy();
		break;
	case 3:
		p3->setSpy();
		break;
	case 4:
		p4->setSpy();
		break;
	case 5:
		p5->setSpy();
		break;
	}

	return true;
}