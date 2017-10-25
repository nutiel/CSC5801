#include "Gang.h"

Gang::Gang() :
	w(0), x(0), y(0), z(0),
	score(0),
	iterations(0),
	last_outcome(' ') {
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

int Gang::LASTOUTCOME() {
	return last_outcome;
}

int Gang::ALLOUTCOMES_W() {
	return w;
}

int Gang::ALLOUTCOMES_X() {
	return x;
}

int Gang::ALLOUTCOMES_Y() {
	return y;
}

int Gang::ALLOUTCOMES_Z() {
	return z;
}

int Gang::ALLOUTCOMES_A() {
	return a;
}

int Gang::ALLOUTCOMES_B() {
	return b;
}

int Gang::ALLOUTCOMES_C() {
	return c;
}

int Gang::ITERATIONS() {
	return iterations;
}

int Gang::MYSCORE() {
	return score;
}

void Gang::increaseIterations() {
	iterations++;
}

/*
*
* char result1 - gangs own decision
* char result2 - other gang decision
*
* Unanimus
* w -> both gangs silent, z -> both gangs betrayed
* x -> we were silent, y -> we betrayed, 
*
* Mixed responce
* a -> in the gang with most betrays, b -> in the gang with the least betrays, 
* c -> mixed response with equal votes
*
*/
void Gang::result(char result) {
	if (result == 'w') {
		w++;
		score += 2;
		this->last_outcome = -1;
	}
	else if (result == 'x') {
		x++;
		score += 5;
		this->last_outcome = -2;
	}
	else if (result == 'y') {
		y++;
		score += 0;
		this->last_outcome = -3;
	}
	else if(result == 'z') {
		z++;
		score += 4;
		this->last_outcome = -4;
	}
	else if (result == 'a') {
		a++;
		score += 2.5;
		this->last_outcome = -5;
	}
	else if (result == 'b') {
		b++;
		score += 3;
		this->last_outcome = -6;
	}
	else if (result == 'c') {
		c++;
		score += 2;
		this->last_outcome = -7;
	}
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