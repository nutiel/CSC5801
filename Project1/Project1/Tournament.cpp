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

void Tournament::runSimulation(int i, int j, Game g) {

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

	}

	printCurrentResults(p1, p2, g);
	g.calculateAverage(p1, p2, p1->ITERATIONS());

	delete p1;
	delete p2;
}

void Tournament::printCurrentResults(Prisoner* p1, Prisoner* p2, Game g) {

	cout << "\nResults for match between " << g.getStrategy1() << " and " << g.getStrategy2() << endl << endl;
	cout << "p1 w = " << p1->ALLOUTCOMES_W() << ", x = " << p1->ALLOUTCOMES_X() << ", y = " << p1->ALLOUTCOMES_Y() << ", z = " << p1->ALLOUTCOMES_Z();
	cout << ", score = " << p1->MYSCORE() << endl;
	cout << "p2 w = " << p2->ALLOUTCOMES_W() << ", x = " << p2->ALLOUTCOMES_X() << ", y = " << p2->ALLOUTCOMES_Y() << ", z = " << p2->ALLOUTCOMES_Z();
	cout << ", score = " << p2->MYSCORE() << endl;

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
	arr = new double[num_Strategies*num_Strategies];
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
			runSimulation(i, j, matchups[j + i*num_Strategies]);
			saveStats(matchups[j + i*num_Strategies], i, j);
		}
	}

	printStats();

	delete[] arr;
	delete[] matchups;
}

void Tournament::printStats() {

	cout << "Strategy Average Scores\n\n";
	for (int i = 0; i < num_Strategies; i++) {
		cout << i + 1;
		for (int j = 0; j < num_Strategies; j++) {
			cout << " | " << arr[i*num_Strategies + j];
		}
		cout << endl;
	}
}

void Tournament::saveStats(Game g, int str1, int str2) {

	double temp;
	double score1 = g.getScore1(), score2 = g.getScore2();

	//for first strategy
	for (int i = 0; i < num_Strategies; i++) {
		if (arr[str1*num_Strategies + i] > score1) {
			temp = arr[str1*num_Strategies + i];
			arr[str1*num_Strategies + i] = score1;
			score1 = temp;
		}
	}

	//for second strategy
	for (int i = 0; i < num_Strategies; i++) {
		if (arr[str2*num_Strategies + i] > score2) {
			temp = arr[str2*num_Strategies + i];
			arr[str2*num_Strategies + i] = score2;
			score2 = temp;
		}
	}

}