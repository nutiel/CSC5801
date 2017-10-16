#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

ofstream ifile;

void addIfStatement() {
	ifile << "IF";

}

void writeStrategy(int n) {

	int random_integer;
	random_integer = rand() % 4 + 1; // generates random int nums from 1 to 10

	ifile << n << " ";

	switch (random_integer) {
	case 1:
		addIfStatement();
		break;
	case 2:
		ifile << " BETRAY";
		break;
	case 3:
		ifile << " SILENCE";
		break;
	case 4:
		ifile << " RANDOM";
		break;
	default:
		cout << "Random number generation produced unexpected results!";
		cout << "In \"CW1.c++\" file, writeStrategy() function.";
		return;
		break;
	}
	ifile << endl;
}

void createFile(int n) {

	string name;

	name = name + std::to_string(n);
	name.append(".txt");
	ifile.open(name);
	for (int i = 1; i < 10; i++) {
		writeStrategy(i);
	}
	ifile.close();
}

int main() {

	int x;

	cout << "Give number of strategies: ";
	cin >> x;

	for (int i = 1; i <= x; i++) {
		createFile(i);
	}
	cin >> x;

	return 0;
}