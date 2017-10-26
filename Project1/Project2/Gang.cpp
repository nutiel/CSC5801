/**
CSC5801
Gang.cpp
Purpose: Represents a gang of 5 prisoners and handles the 
variables of 200 iterations

@author Michael Yiangou (B7064124)
@version
*/

#include "CW2.h"
#include "Expression.h"
#include "Game.h"
#include "Gang.h"
#include "IfNode.h"
#include "Thread.h"
#include "Tournament.h"
#include "Prisoner.h"

Gang::Gang() :
	w(0), x(0), y(0), z(0),
	score(0),
	iterations(0),
	last_outcome(' '),
	has_spy(false),
	found_spy(false),
	spies_found(0), total_spies(0),
	silence_no(0),
	betray_no(0) {

	p1 = new Leader(this);
	p2 = new Prisoner(this);
	p3 = new Prisoner(this);
	p4 = new Prisoner(this);
	p5 = new Prisoner(this);
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

double Gang::MYSCORE() {
	return score;
}

void Gang::increaseIterations() {
	iterations++;
}

void Gang::makeDecision() {

	Prisoner* p;

	/*->run the make decision code for the prisoners with threads
	* ->save the number of votes for silence and betray
	**/
	for (int i = 0; i < 5; i++) {
		p = getPrisoner(i);
		if (i+1 != spy) {
			//starts the decision making process of the prisoner
			p->start();
		}
	}

	for (int i = 0; i < 5; i++) {
		p = getPrisoner(i);
		if (i + 1 != spy) {
			//ends the decision making process of the prisoner
			p->join();
		}
	}

	//the spy is left in the end to make a decision
	if (has_spy) {
		p = getPrisoner(spy);

		p->start();
		p->join();
	}
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
		if (found_spy) {
			if (g->getFoundSpy()) {
				score += 6;
			}
			else {
				score += 2;
			}
		}
		else {
			score += 2;
		}
		this->last_outcome = -1;
	}
	else if (this->silence_no == 5 && g->getBetrayNo() == 5) {
		x++;
		if (found_spy) {
			if (g->getFoundSpy()) {
				score += 6;
			}
			else {
				score += 2;
			}
		}
		else {
			score += 5;
		}
		this->last_outcome = -2;
	}
	else if (this->betray_no == 5 && g->getSilenceNo() == 5) {
		y++;
		if (found_spy) {
			if (g->getFoundSpy()) {
				score += 6;
			}
			else {
				score += 2;
			}
		}
		else {
			score += 0;
		}
		this->last_outcome = -3;
	}
	else if(this->betray_no == 5 && g->getBetrayNo() == 5) {
		z++;
		if (found_spy) {
			if (g->getFoundSpy()) {
				score += 6;
			}
			else {
				score += 2;
			}
		}
		else {
			score += 4;
		}
		this->last_outcome = -4;
	}
	else if (this->betray_no > g->getBetrayNo()) {
		a++;
		if (found_spy) {
			if (g->getFoundSpy()) {
				score += 6;
			}
			else {
				score += 2;
			}
		}
		else {
			score += 2.5;
		}
		this->last_outcome = -5;
	}
	else if (this->betray_no < g->getBetrayNo()) {
		b++;
		if (found_spy) {
			if (g->getFoundSpy()) {
				score += 6;
			}
			else {
				score += 2;
			}
		}
		else {
			score += 3;
		}
		this->last_outcome = -6;
	}
	else if (this->betray_no == g->getBetrayNo()) {
		c++;
		if (found_spy) {
			if (g->getFoundSpy()) {
				score += 6;
			}
			else {
				score += 2;
			}
		}
		else {
			score += 2;
		}
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
	total_spies++;

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

void Gang::resetSpy() {
	if (has_spy) {
		has_spy = false;
		this->getPrisoner(spy)->setSpy();
	}
	found_spy = false;
	silence_no = 0;
	betray_no = 0;
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
	return nullptr;
}

Leader* Gang::getLeader() {
	return p1;
}

void Gang::chooseBetray() {
	betray_no++;
}

void Gang::chooseSilence() {
	silence_no++;
}

int Gang::getSpy() {
	return spy;
}

void Gang::setFoundSpy() {
	found_spy = true;
	spies_found++;
}

bool Gang::getFoundSpy() {
	return found_spy;
}

int Gang::getTotalSpies() {
	return total_spies;
}

int Gang::getSpiesFound() {
	return spies_found;
}