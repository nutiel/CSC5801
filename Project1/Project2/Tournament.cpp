#include "CW2.h"
#include "Expression.h"
#include "Game.h"
#include "Gang.h"
#include "IfNode.h"
#include "Leader.h"
#include "Prisoner.h"
#include "Thread.h"
#include "Tournament.h"

Game* matchups;
ofstream ifile2;

Tournament::Tournament() :
	num_Strategies(0) {

}

Tournament::~Tournament() {

}

void Tournament::setNumofFiles(int n) {
	num_Strategies = n;
}

void Tournament::runSimulation(int i, int j, Game* g) {

	Gang* g1 = new Gang();
	Gang* g2 = new Gang();

	/*
	 *  Unanimus
	 * w->both gangs silent, z->both gangs betrayed
	 * x->we were silent, y->we betrayed,
	 *
	 *  Mixed responce
	 * a->in the gang with most betrays, b->in the gang with the least betrays,
	 * c->mixed response with equal votes
	 *
	 */
	int g1_decision, g2_decision;

	readFiles(i, j, g1, g2);

	for (int k = 0; k < 200; k++) {

		g1->increaseIterations();
		g2->increaseIterations();

		/*
		*
		*Needs to be fixed <---------------
		*/

		g2_decision = g2->makeDecision();
		g1_decision = g1->makeDecision();

		g1->result(g2_decision);
		g2->result(g1_decision);

	}

	ifile2 << "Detailed Game Results" << endl;

	printCurrentResults(g1, g2, *g);
	g->calculateAverage(g1, g2, g1->ITERATIONS());

	delete g1;
	delete g2;
}

void Tournament::printCurrentResults(Gang* p1, Gang* p2, Game g) {

	/*
	*
	*Needs to be fixed <---------------
	*/

	cout << "\n" << g.getStrategy1() << " vs " << g.getStrategy2() << endl << endl;
	ifile2 << "\nResults for match between " << g.getStrategy1() << " and " << g.getStrategy2() << endl << endl;
	ifile2 << "p1 w = " << p1->ALLOUTCOMES_W() << ", x = " << p1->ALLOUTCOMES_X() << ", y = " << p1->ALLOUTCOMES_Y() << ", z = " << p1->ALLOUTCOMES_Z();
	ifile2 << ", score = " << p1->MYSCORE() << endl;
	ifile2 << "p2 w = " << p2->ALLOUTCOMES_W() << ", x = " << p2->ALLOUTCOMES_X() << ", y = " << p2->ALLOUTCOMES_Y() << ", z = " << p2->ALLOUTCOMES_Z();
	ifile2 << ", score = " << p2->MYSCORE() << endl;
	if (p1->MYSCORE() > p2->MYSCORE()) {
		ifile2 << "Player 2 won" << endl;
	}
	else if (p1->MYSCORE() < p2->MYSCORE()) {
		ifile2 << "Player 1 won" << endl;
	}
	else {
		ifile2 << "Draw" << endl;
	}
}

void Tournament::readFiles(int i, int j, Gang* p1, Gang* p2) {


	string st1 = matchups[j + i * num_Strategies].getStrategy1();
	string st2 = matchups[j + i * num_Strategies].getStrategy2();
	string line;
	int l = 0;

	/*
	*
	* Needs to be fixed <---------------
	* Add set code for all the prisoners or let the gang class take care of it
	*/

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

	string name;

	name = "Results.txt";

	if (remove(("./files/" + name).c_str()) != 0) {
		cout << "File couldn't be removed\n";
	}
	ifile2.open("./files/" + name);

	for (int i = 0; i < num_Strategies*num_Strategies; i++) {
		arr[i] = -1;
	}

	for (int i = 0; i < num_Strategies; i++) {
		for (int j = 0; j < num_Strategies; j++) {
			name1 = "";
			name2 = "";
			name1 = name1 + std::to_string(i + 1);
			name1.append(".txt");
			name2 = name2 + std::to_string(j + 1);
			name2.append(".txt");
			matchups[j + i*num_Strategies].setStrategy(name1, name2);
			runSimulation(i, j, &matchups[j + i*num_Strategies]);
			saveStats(matchups[j + i*num_Strategies], i, j);
		}
	}

	printStats();

	ifile2.close();
	delete[] arr;
	delete[] matchups;
}

void Tournament::printStats() {

	string *avname = new string[num_Strategies];
	double *avnum = new double[num_Strategies];
	double avg = 0;

	ifile2 << "\nStrategy Average Scores\n\n";

	ifile2 << fixed << setprecision(2) << setfill('0');

	for (int i = 0; i < num_Strategies; i++) {

		avname[i] = std::to_string(i + 1);
		ifile2 << std::setfill('0') << std::setw(2) << i + 1;

		for (int j = 0; j < num_Strategies; j++) {
			avg += arr[i*num_Strategies + j];
			ifile2 << " | " << arr[i*num_Strategies + j];
		}
		avg = avg / num_Strategies;
		avnum[i] = avg;
		avg = 0;
		ifile2 << endl;
	}

	sortAverageArr(avname, avnum);

	ifile2 << endl << "Strategy Rankings" << endl << endl;

	//Cumulative average for each strategy
	for (int i = 0; i < num_Strategies; i++) {
		ifile2 << std::setfill('0') << std::setw(2) << avname[i] << ".txt -> " << avnum[i] << endl;
	}
	ifile2 << endl;

	delete[] avname;
	delete[] avnum;
}

void Tournament::sortAverageArr(string *avname, double *avnum) {
	string tname;
	double tav;
	bool done = false;

	while (!done) {
		done = true;
		for (int i = 0; i < num_Strategies - 1; i++) {
			if (avnum[i] > avnum[i + 1]) {
				tname = avname[i];
				tav = avnum[i];
				avname[i] = avname[i + 1];
				avnum[i] = avnum[i + 1];
				avname[i + 1] = tname;
				avnum[i + 1] = tav;
				done = false;
			}
		}
	}
}

void Tournament::saveStats(Game g, int str1, int str2) {

	double temp;
	double score1 = g.getScore1(), score2 = g.getScore2();

	//for first strategy
	for (int i = 0; i < num_Strategies; i++) {
		if (arr[str1*num_Strategies + i] < score1) {
			temp = arr[str1*num_Strategies + i];
			arr[str1*num_Strategies + i] = score1;
			score1 = temp;
		}
	}

	//for second strategy
	for (int i = 0; i < num_Strategies; i++) {
		if (arr[str2*num_Strategies + i] < score2) {
			temp = arr[str2*num_Strategies + i];
			arr[str2*num_Strategies + i] = score2;
			score2 = temp;
		}
	}

}