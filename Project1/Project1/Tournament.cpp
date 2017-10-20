#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"
#include "Expression.h"

Game* matchups;

Tournament::Tournament() :
	num_Strategies(0) {

}

Tournament::~Tournament() {

}

void Tournament::setNumofFiles(int n) {
	num_Strategies = n;
}

void Tournament::runSimulation(int i, int j) {

	Prisoner* p1 = new Prisoner();
	Prisoner* p2 = new Prisoner();

	//true = silence, false = betray
	bool p1_decision, p2_decision;

	readFiles(i, j, p1, p2);
	for (int k = 0; k < 200; k++) {

		p1->increaseIterations();
		p2->increaseIterations();

		p1_decision = p1->makeDecision();
		p2_decision = p2->makeDecision();

		p1->result(p1_decision, p2_decision);
		p2->result(p2_decision, p1_decision);

		/*Gather info for statistics*/
	}
	
	delete p1;
	delete p2;
}

void Tournament::readFiles(int i, int j, Prisoner* p1, Prisoner* p2) {

	
	string st1 = matchups[j + i * num_Strategies].getStrategy1();
	string st2 = matchups[j + i * num_Strategies].getStrategy2();
	string line;
	int l = 0;


	//prisoner1 strategy
	ifstream ofile("./files/" + st1);
	if (ofile.is_open()) {
		while (getline(ofile, line))
		{
			p1->setCode(line, l);
			l++;
		}
		ofile.close();
	}
	else {
		cout << "Unable to open file for prisoner1\n";
		exit(1);
	}

	l = 0;

	//prisoner2 strategy
	ifstream ofile2("./files/" + st2);
	if (ofile2.is_open()) {
		while (getline(ofile2, line))
		{
			p2->setCode(line, l);
			l++;
		}
		ofile2.close();
	}
	else {
		cout << "Unable to open file for prisoner2\n";
		exit(1);
	}
}

void Tournament::runTournament() {

	matchups = new Game[num_Strategies*num_Strategies];
	string name1, name2;

	for (int i = 0; i < num_Strategies; i++) {
		for (int j = 0; j < num_Strategies; j++) {
			name1 = "";
			name2 = "";
			name1 = name1 + std::to_string(i+1);
			name1.append(".txt");
			name2 = name2 + std::to_string(j+1);
			name2.append(".txt");
			matchups[j + i*num_Strategies].setStrategy(name1, name2);
			runSimulation(i, j);
		}
	}

	delete matchups;
}