#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"

using namespace std;

ofstream ifile;
string* statement[lines];

void writeLastLine(int n) {
	int random_integer;
	random_integer = rand() % 5 + 1; // generates random int nums from 1 to 4
	statement[n]->append(std::to_string(n+1)) + " ";

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
	statement[n]->append(std::to_string(n+1)) + " ";

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
	statement[n]->append(std::to_string(n+1)) + " ";

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
	random_integer = rand() % 7 + 1; // generates random int nums from 1 to 7

	statement[n]->append(" IF ");

	switch (random_integer) {
	case 1:
		statement[n]->append("LASTOUTCOME ");
		break;
	case 2:
		statement[n]->append("ALLOUTCOMES_X ");
		break;
	case 3:
		statement[n]->append("LASTOUTCOME_Y ");
		break;
	case 4:
		statement[n]->append("LASTOUTCOME_W ");
		break;
	case 5:
		statement[n]->append("LASTOUTCOME_Z ");
		break;
	case 6:
		statement[n]->append("MYSCORE ");
		break;
	case 7:
		statement[n]->append("ITERATIONS ");
		break;
	}

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

	random_integer = rand() % 8 + 1; // generates random int nums from 1 to 8

	switch (random_integer) {
	case 1:
		statement[n]->append("LASTOUTCOME ");
		break;
	case 2:
		statement[n]->append("ALLOUTCOMES_X ");
		break;
	case 3:
		statement[n]->append("LASTOUTCOME_Y ");
		break;
	case 4:
		statement[n]->append("LASTOUTCOME_W ");
		break;
	case 5:
		statement[n]->append("LASTOUTCOME_Z ");
		break;
	case 6:
		statement[n]->append("MYSCORE ");
		break;
	case 7:
		statement[n]->append("ITERATIONS ");
		break;
	default:
		random_integer = rand() % n + 1; // generates random int nums from 1 to number of iterations
		statement[n]->append(std::to_string(n)).append(" ");
		break;
	}

	statement[n]->append("GOTO ");

	goToStatement(n);
}

void goToStatement(int n) {

	bool flag1 = false, flag2 = true;

	for (int i = n+1; i < lines; i++) {
		if (!checkIf(i)) {
			flag1 = true;
		}
		if (flag1) {
			//random_integer = rand() % (n + 1) + 1; // for arbitary number
			statement[n]->append(std::to_string(i+2));
			flag2 = false;
			break;
		}
	}
	if (flag1 && flag2) {
		statement[n]->append(std::to_string(n));
	}
}

bool checkIf(int n) {

	for (int i = 0; i < statement[n]->size(); i++) {
		if (statement[n]->at(i) == 'I') {
			if (statement[n]->at(i+1) == 'F') {
				return true;
			}
		}
	}
	return false;
}

void createFile(int n) {

	string name;
	string path;
	char c;
	int k = 0;

	name = name + std::to_string(n);
	name.append(".txt");
	
	cout << "\nEnter the path to the location of the files:\n";
	cout << "./\t  -> defines the source folder\n./\"path\"/ -> defines a path within that folder\n> ";
	while (cin.peek() != '\n') {
		cin >> c;
		path += c;
		k++;
	}

	ifile.open("./files/" + name);
	for (int i = lines-1; i >= 0; i--) {
		statement[i] = new string;
		if (i == 0) {
			writeFirstLine(i);
		}else if(i == lines-1 || i == lines - 2) {
			writeLastLine(i);
		}else{
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
	cout << "1. To Generate a new set of strategies." << endl;
	cout << "2. To run tournament with strategies in the \"files\" file." << endl;
	cout << "0. To Exit" << endl;
	cout << endl << ">";
}

int main() {

	int x, choice;
	Tournament* tour = new Tournament();

	showMenu();
	cin >> choice;

	while (choice != 0) {

		switch (choice) {
		case 0:
			break;
		case 1:
			cout << "Give number of strategies: ";
			cin >> x;

			cout << endl << "Creating Strategies ... ";
			for (int i = 1; i <= x; i++) {
				createFile(i);
			}
			cout << "Done!" << endl;
			break;
		case 2:
			tour->setNumofFiles(x);
			cout << endl << "Running Tournament ... ";
			tour->runTournament();
			cout << "Done!" << endl;
			cout << "Releasing Memory ... ";
			delete tour;
			cout << "Done!" << endl;
			break;
		default:
			cout << "Invalid input." << endl << "Try again." << endl;
			break;
		}

		showMenu();
		cin >> choice;
	}

	return 0;
}