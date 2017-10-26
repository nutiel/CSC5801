#include "Gang.h"

Gang::Gang() :
	w(0), x(0), y(0), z(0),
	score(0),
	iterations(0),
	last_outcome(' '),
	has_spy(false),
	silence_no(0),
	betray_no(0) {

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

int Gang::makeDecision() {

	/*->run the make decision code for the prisoners with threads
	* ->save the number of votes for silence and betray
	**/

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
void Gang::result(Gang* g) {
	if (this->silence_no == 5 && g->getSilenceNo() == 5) {
		w++;
		score += 2;
		this->last_outcome = -1;
	}
	else if (this->silence_no == 5 && g->getBetrayNo() == 5) {
		x++;
		score += 5;
		this->last_outcome = -2;
	}
	else if (this->betray_no == 5 && g->getSilenceNo() == 5) {
		y++;
		score += 0;
		this->last_outcome = -3;
	}
	else if(this->betray_no == 5 && g->getBetrayNo() == 5) {
		z++;
		score += 4;
		this->last_outcome = -4;
	}
	else if (this->betray_no > g->getBetrayNo()) {
		a++;
		score += 2.5;
		this->last_outcome = -5;
	}
	else if (this->betray_no < g->getBetrayNo()) {
		b++;
		score += 3;
		this->last_outcome = -6;
	}
	else if (this->betray_no == g->getBetrayNo()) {
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

	has_spy = true;

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

	spy = random_integer;

	return true;
}

bool Gang::getHasSpy() {
	return has_spy;
}

int Gang::getSilenceNo() {
	return silence_no;
}

int Gang::getBetrayNo() {
	return betray_no;
}

Prisoner* Gang::getPrisoner(int i) {
	switch (i%5) {
	case 0:
		return p1;
		break;
	case 1:
		return p2;
		break;
	case 2:
		return p3;
		break;
	case 3:
		return p4;
		break;
	case 4:
		return p5;
		break;
	}
}