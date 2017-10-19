#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"
#include "Expression.h"

Game* matchups;

Tournament::Tournament() :
	iterations(0),
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

		iterations++;

		p1_decision = p1->makeDecision(iterations);
		p2_decision = p2->makeDecision(iterations);

		p1->result(p1_decision, p2_decision);
		p2->result(p2_decision, p1_decision);
	}
	
	delete p1;
	delete p2;
}

void Tournament::readFiles(int i, int j, Prisoner* p1, Prisoner* p2) {

	
	string st1 = matchups[j + i * num_Strategies].getStrategy1();
	string st2 = matchups[j + i * num_Strategies].getStrategy2();
	string path, line;
	char c;
	int k = 0, l = 0;

	cout << "\nEnter the path to the location of the files:\n";
	cout << "./\t  -> defines the source folder\n./\"path\"/ -> defines a path within that folder\n> ";
	while (cin.peek() != '\n') {
		cin >> c;
		path += c;
		k++;
	}

	//prisoner1 strategy
	ifstream ofile(path.append(st1));
	if (ofile.is_open()) {
		while (getline(ofile, line))
		{
			p1->setCode(line, l);
			l++;
		}
		ofile.close();
	}
	else {
		cout << "Unable to open file for prisoner1";
	}

	l = 0;

	//prisoner2 strategy
	ifstream ofile2(path.append(st2));
	if (ofile2.is_open()) {
		while (getline(ofile2, line))
		{
			p2->setCode(line, l);
			l++;
		}
		ofile2.close();
	}
	else {
		cout << "Unable to open file for prisoner2";
	}
}

void Tournament::runTournament() {

	matchups = new Game[num_Strategies*num_Strategies];
	string name1, name2;

	for (int i = 0; i < num_Strategies; i++) {
		for (int j = 0; j < num_Strategies; j++) {
			name1 = name1 + std::to_string(i);
			name1.append(".txt");
			name2 = name2 + std::to_string(j);
			name2.append(".txt");
			matchups[j + i*num_Strategies].setStrategy(name1, name2);
			runSimulation(i, j);
		}
	}

	delete matchups;
}