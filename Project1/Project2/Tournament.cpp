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

void Tournament::runTournament() {

	matchups = new Game[num_Strategies*num_Strategies];
	arr = new double[num_Strategies*num_Strategies];
	string name1, name2; // names of the strategy files given to prisoners
	int random;
	string name = "Results.txt"; // name of the results file

	if (remove(("./files/" + name).c_str()) != 0) {
		//cout << "File couldn't be removed\n";
	}

	try {
		ifile2.open("./files/" + name);

		if (ifile2.fail()) {
			delete[] arr;
			delete[] matchups;
			throw invalid_argument("file " + name + " couldn't be opened");
		}
	}
	catch (const invalid_argument & iae) {
		cout << " unable to read data : " << iae.what() << "\n";
		exit(1);
	}

	for (int i = 0; i < num_Strategies*num_Strategies; i++) {
		arr[i] = -1;
	}

	int spy_percent;
	cout << "\nGive the % for the propability of a spy: ";
	cin >> spy_percent;

	for (int i = 0; i < num_Strategies; i++) {
		for (int j = 0; j < num_Strategies; j++) {
			name1 = "";
			name2 = "";
			for (int k = 0; k < 5; k++) {
				random = rand() % 5 + 1;
				name1 = name1 + std::to_string(random);
				name1.append(".txt");
				random = rand() % 5 + 1;
				name2 = name2 + std::to_string(random);
				name2.append(".txt");
				matchups[j + i*num_Strategies].setStrategy(name1, name2, k);
			}
			runSimulation(i, j, &matchups[j + i*num_Strategies], spy_percent);
			saveStats(matchups[j + i*num_Strategies], i, j);
		}
	}

	printStats();

	ifile2.close();
	delete[] arr;
	delete[] matchups;
}

void Tournament::runSimulation(int i, int j, Game* g, int spy_percent) {

	Gang* g1 = new Gang();
	Gang* g2 = new Gang();
	int random_integer, leaders_choice1, leaders_choice2;
	/*
	*  Unanimus
	* -1->both gangs silent, -2->both gangs betrayed
	* -3->we were silent, -4->we betrayed,
	*
	*  Mixed responce
	* -5->in the gang with most betrays, -6->in the gang with the least betrays,
	* -7->mixed response with equal votes
	*
	*/
	int g1_decision, g2_decision;

	readFiles(i, j, g1, g2); // takes the files chosen for the game and gives them to the gang to be assigned to the prisoners

	for (int k = 0; k < 200; k++) {

		//Add Spy
		random_integer = rand() % spy_percent + 1;
		g1->addSpy(random_integer);
		g1->addSpy(random_integer);

		//Increace Iterations
		g1->increaseIterations();
		g2->increaseIterations();

		//make the decision and save the results in the class
		g2->makeDecision();
		g1->makeDecision();

		if (g1->getHasSpy()) {
			//The leader makes a choice for the spy and then gets a chance to change his choice
			leaders_choice1 = g1->getLeader()->changeChoice(g1->getLeader()->chooseSpy());
		}

		if (g2->getHasSpy()) {
			//The leader makes a choice for the spy and then gets a chance to change his choice
			leaders_choice2 = g2->getLeader()->changeChoice(g2->getLeader()->chooseSpy());
		}

		if (leaders_choice1 == g1->getSpy() && leaders_choice2 == g2->getSpy()) {
			g1->setFoundSpy();
			g2->setFoundSpy();
		}
		else if (leaders_choice1 == g1->getSpy()) {
			g1->setFoundSpy();
		}
		else {
			g2->setFoundSpy();
		}

		//Update variables
		g1->result(g2);
		g2->result(g1);

	}

	ifile2 << "Detailed Game Results" << endl;

	printCurrentResults(g1, g2, *g);
	g->calculateAverage(g1, g2, g1->ITERATIONS());

	delete g1;
	delete g2;
}

void Tournament::readFiles(int i, int j, Gang* g1, Gang* g2) {

	for (int k = 0; k < 10; k++) {
		if (k < 5) {
			setPrisonerCode(k, matchups[j + i * num_Strategies].getStrategy(k), g1);
		}
		else {
			setPrisonerCode(k, matchups[j + i * num_Strategies].getStrategy(k), g2);
		}
	}
}

void Tournament::setNumofFiles(int n) {
	num_Strategies = n;
}

void Tournament::printCurrentResults(Gang* g1, Gang* g2, Game g) {

	cout << "\n" << "Gang1 vs Gang2" << endl << endl;
	ifile2 << "\nResults for match between " << g.getStrategy(10) << " and " << g.getStrategy(10) << endl << endl;
	ifile2 << "g1 w = " << g1->ALLOUTCOMES_W() << ", x = " << g1->ALLOUTCOMES_X() << ", y = " << g1->ALLOUTCOMES_Y() << ", z = " << g1->ALLOUTCOMES_Z();
	ifile2 << ", a = " << g1->ALLOUTCOMES_A() << ", b = " << g1->ALLOUTCOMES_B() << ", c = " << g1->ALLOUTCOMES_C() << ", score = " << g1->MYSCORE() << endl;
	ifile2 << "Votes for Silence = " << g1->getSilenceNo() << "Votes for Betray = " << g1->getBetrayNo() << endl;
	ifile2 << "g2 w = " << g2->ALLOUTCOMES_W() << ", x = " << g2->ALLOUTCOMES_X() << ", y = " << g2->ALLOUTCOMES_Y() << ", z = " << g2->ALLOUTCOMES_Z();
	ifile2 << ", a = " << g2->ALLOUTCOMES_A() << ", b = " << g2->ALLOUTCOMES_B() << ", c = " << g2->ALLOUTCOMES_C() << ", score = " << g2->MYSCORE() << endl;
	ifile2 << "Votes for Silence = " << g2->getSilenceNo() << "Votes for Betray = " << g2->getBetrayNo() << endl;
	
	if (g1->getHasSpy()) {
		ifile2 << "\tGang 1 had a spy";
		if (g1->getFoundSpy()) {
			ifile2 << " and found him";
		}
		ifile2 << endl;
	}

	if (g2->getHasSpy()) {
		ifile2 << "\tGang 2 had a spy";
		if (g2->getFoundSpy()) {
			ifile2 << " and found him";
		}
		ifile2 << endl;
	}

	if (g1->MYSCORE() > g2->MYSCORE()) {
		ifile2 << "Gang 2 won" << endl;
	}
	else if (g1->MYSCORE() < g2->MYSCORE()) {
		ifile2 << "Gang 1 won" << endl;
	}
	else {
		ifile2 << "Draw" << endl;
	}
}

void Tournament::setPrisonerCode(int i, string str, Gang* g) {

	int l = 0;
	string line;

	ifstream ofile("./files/" + str);
	if (ofile.is_open()) {
		while (getline(ofile, line))
		{
			(g->getPrisoner(i))->setCode(line, l);
			l++;
		}
		ofile.close();
	}
	else {
		cout << "Unable to open file for prisoner1\n";
		exit(1);
	}
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