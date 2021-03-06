/**
CSC5801
CW2.cpp
Purpose: Contains main function and handles strategy
creation and UI

@author Michael Yiangou (B7064124)
@version
*/


#include "CW2.h"
#include "Expression.h"
#include "Game.h"
#include "Gang.h"
#include "IfNode.h"
#include "Leader.h"
#include "Prisoner.h"
#include "Thread.h"
#include "Tournament.h"

using namespace std;

ofstream ifile;
string* statement[lines];

void writeLastLine(int n) {
	int random_integer;
	random_integer = rand() % 5 + 1; // generates random int nums from 1 to 5
	statement[n]->append(std::to_string(n + 1)) + " ";

	switch (random_integer) {
	case 1:
	case 2:
		*statement[n] += " BETRAY";
		break;
	case 3:
	case 4:
		*statement[n] += " SILENCE";
		break;
	case 5:
		*statement[n] += " RANDOM";
		break;
	}

	*statement[n] += "\n";
}

void writeStrategy(int n) {

	int random_integer;
	random_integer = rand() % 13 + 1; // generates random int nums from 1 to 13
	statement[n]->append(std::to_string(n + 1)) + " ";

	switch (random_integer) {
	case 1:
	case 2:
		*statement[n] += " BETRAY";
		break;
	case 3:
	case 4:
		*statement[n] += " SILENCE";
		break;
	case 5:
	case 6:
		*statement[n] += " RANDOM";
		break;
	default:
		addIfStatement(n);
		break;
	}

	*statement[n] += "\n";
}

void writeFirstLine(int n) {

	int random_integer;
	random_integer = rand() % 20 + 1; // generates random int nums from 1 to 20
	statement[n]->append(std::to_string(n + 1)) + " ";

	switch (random_integer) {
	case 1:
		*statement[n] += " BETRAY";
		break;
	case 7:
		*statement[n] += " SILENCE";
		break;
	case 14:
		*statement[n] += " RANDOM";
		break;
	default:
		addIfStatement(n);
		break;
	}
	*statement[n] += "\n";
}

void addIfStatement(int n) {

	int random_integer;
	bool flag = true;
	random_integer = rand() % 10 + 1; // generates random int nums from 1 to 10

	statement[n]->append(" IF ");

	switch (random_integer) {
	case 1:
		statement[n]->append("LASTOUTCOME ");
		flag = true;
		break;
	case 2:
		statement[n]->append("ALLOUTCOMES_X ");
		flag = false;
		break;
	case 3:
		statement[n]->append("ALLOUTCOMES_Y ");
		flag = false;
		break;
	case 4:
		statement[n]->append("ALLOUTCOMES_W ");
		flag = false;
		break;
	case 5:
		statement[n]->append("ALLOUTCOMES_Z ");
		flag = false;
		break;
	case 6:
		statement[n]->append("MYSCORE ");
		flag = false;
		break;
	case 7:
		statement[n]->append("ITERATIONS ");
		flag = false;
		break;
	case 8:
		statement[n]->append("ALLOUTCOMES_A ");
		flag = true;
		break;
	case 9:
		statement[n]->append("ALLOUTCOMES_B ");
		flag = true;
		break;
	case 10:
		statement[n]->append("ALLOUTCOMES_B ");
		flag = true;
		break;
	}

	if (flag) {
		statement[n]->append("= ");
	}
	else {
		random_integer = rand() % 3 + 1; // generates random int nums from 1 to 3

		switch (random_integer) {
		case 1:
			statement[n]->append("< ");
			break;
		case 2:
			statement[n]->append("> ");
			break;
		case 3:
			statement[n]->append("= ");
			break;
		}
	}

	if (flag) {
		random_integer = rand() % 4 + 1; // generates random int nums from 1 to 4

		switch (random_integer) {
		case 1:
			statement[n]->append("LASTOUTCOME ");
			break;
		case 2:
			statement[n]->append("A ");
			break;
		case 3:
			statement[n]->append("B ");
			break;
		case 4:
			statement[n]->append("C ");
			break;
		}
	}
	else {
		random_integer = rand() % 7 + 1; // generates random int nums from 1 to 10

		switch (random_integer) {
		case 1:
			statement[n]->append("ALLOUTCOMES_X ");
			break;
		case 2:
			statement[n]->append("ALLOUTCOMES_Y ");
			break;
		case 3:
			statement[n]->append("ALLOUTCOMES_W ");
			break;
		case 4:
			statement[n]->append("ALLOUTCOMES_Z ");
			break;
		case 5:
			statement[n]->append("MYSCORE ");
			break;
		case 6:
			statement[n]->append("ITERATIONS ");
			break;
		case 7:
			statement[n]->append("ALLOUTCOMES_A ");
			break;
		case 8:
			statement[n]->append("ALLOUTCOMES_B ");
			break;
		case 9:
			statement[n]->append("ALLOUTCOMES_C ");
			break;
		default:
			random_integer = rand() % (n + 1) + 1; // generates random int nums from 1 to number of iterations
			statement[n]->append(std::to_string(n)).append(" ");
			break;
		}
	}

	statement[n]->append("GOTO ");

	goToStatement(n);
}

void goToStatement(int n) {

	bool flag1 = false, flag2 = true;

	for (int i = n + 1; i < lines; i++) {
		if (!checkIf(i)) {
			flag1 = true;
		}
		if (flag1) {
			//random_integer = rand() % (n + 1) + 1; // for arbitary number
			statement[n]->append(std::to_string(i + 2));
			flag2 = false;
			break;
		}
	}
	if (flag1 && flag2) {
		statement[n]->append(std::to_string(n));
	}
}

bool checkIf(int n) {

	for (int i = 0; i < (int)statement[n]->size(); i++) {
		if (statement[n]->at(i) == 'I') {
			if (statement[n]->at(i + 1) == 'F') {
				return true;
			}
		}
	}
	return false;
}

void createFile(int n) throw (invalid_argument) {

	string name;

	name = name + std::to_string(n);
	name.append(".txt");

	if (remove(("./files/" + name).c_str()) == 0) {
		//cout << "File couldn't be removed\n";
	}

	ifile.open("./files/" + name);

	if (ifile.fail()) {
		throw invalid_argument("File couldn't be opened (" + name + ".txt)");
	}

	for (int i = lines - 1; i >= 0; i--) {
		statement[i] = new string;
		if (i == 0) {
			writeFirstLine(i);
		}
		else if (i == lines - 1 || i == lines - 2) {
			writeLastLine(i);
		}
		else {
			writeStrategy(i);
		}
	}

	for (int i = 0; i < lines; i++) {
		ifile << *statement[i];
		delete statement[i];
	}
	ifile.close();
}

void showMenu() {
	cout << endl << "***********************************************************" << endl;
	cout << "\t\tMain Menu" << endl;
	cout << "Press the appropriate number to select action." << endl;
	cout << "1. To Generate a new set of strategies in the \"files\" file(must exist)" << endl;
	cout << "2. To run tournament with strategies in the \"files\" file(must exist)" << endl;
	cout << "3. For Detailed Results of each game" << endl;
	cout << "4. For average score of Each strategy" << endl;
	cout << "5. For Strategy Rankings" << endl;
	cout << "0. To Exit" << endl;
	cout << endl << "> ";
}

void showDetailedRes() {

	string line;
	bool flag = true;

	ifstream ofile("./files/Results.txt");
	if (ofile.is_open()) {
		while (getline(ofile, line)) {
			if (line == "Strategy Average Scores") {
				flag = false;
			}
			if (flag) {
				cout << line << endl;
			}
		}
		ofile.close();
	}
	else {
		cout << "Unable to open Results file\n";
		exit(1);
	}
}

void showStrAvg() {
	string line;
	bool flag = false;

	ifstream ofile("./files/Results.txt");
	if (ofile.is_open()) {
		while (getline(ofile, line)) {
			if (line == "Strategy Average Scores") {
				flag = true;
			}
			if (line == "Strategy Rankings") {
				flag = false;
			}
			if (flag) {
				cout << line << endl;
			}
		}
		ofile.close();
	}
	else {
		cout << "Unable to open Results file\n";
		exit(1);
	}
}

void showStrRanks() {
	string line;
	bool flag = false;

	ifstream ofile("./files/Results.txt");
	if (ofile.is_open()) {
		while (getline(ofile, line)) {
			if (line == "Strategy Rankings") {
				flag = true;
			}
			if (flag) {
				cout << line << endl;
			}
		}
		ofile.close();
	}
	else {
		cout << "Unable to open Results file\n";
		exit(1);
	}
}

int main() {

	int x, choice = -1;
	Tournament* tour;

	while (choice != 0) {

		showMenu();
		cin >> choice;

		switch (choice) {
		case 0:
			break;
		case 1:
			cout << "Give number of strategies: ";
			cin >> x;

			cout << endl << "Creating Strategies ... ";
			for (int i = 1; i <= x; i++) {
				try {
					createFile(i);
				}
				catch (const invalid_argument& iae) {
					cout << "Invalid argument: " << iae.what() << endl;
					exit(1);
				}
			}
			cout << "\nDone!" << endl;
			break;
		case 2:
			tour = new Tournament();

			tour->setNumofFiles(10);
			cout << endl << "Running Tournament ... ";
			tour->runTournament();
			cout << "Done!" << endl;

			cout << "Releasing Memory ... ";
			delete tour;
			cout << "Done!" << endl;
			break;
		case 3:
			showDetailedRes();
			break;
		case 4:
			showStrAvg();
			break;
		case 5:
			showStrRanks();
			break;
		default:
			cout << "Invalid input." << endl << "Try again." << endl;
			break;
		}

	}

	return 0;
}