#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"
#include "Expression.h"

Prisoner::Prisoner() :
	w(0), x(0),	y(0), z(0),
	score(0), 
	iterations(0),
	last_outcome(' ') {

}

Prisoner::~Prisoner() {

}

char Prisoner::LASTOUTCOME() {
	return last_outcome;
}

int Prisoner::ALLOUTCOMES_W() {
	return w;
}

int Prisoner::ALLOUTCOMES_X() {
	return x;
}

int Prisoner::ALLOUTCOMES_Y() {
	return y;
}

int Prisoner::ALLOUTCOMES_Z() {
	return z;
}

int Prisoner::ITERATIONS() {
	return iterations;
}

int Prisoner::MYSCORE() {
	return score;
}

void Prisoner::increaseIterations() {
	iterations++;
}

void Prisoner::setCode(string line, int i) {

	string word;
	vector<string> temp(0, "");

	for (std::string::iterator c = line.begin(); c != line.end(); c++) {
		if (*c == ' ') {
			c++;
		}
		else {
			while (*c != ' ') {
				word += *c;
				if (c + 1 != line.end()) {
					c++;
				}
				else {
					break;
				}
			}

			temp.push_back(word); //temporary vector
			word = "";
		}
	}
	code.push_back(temp);
}

bool Prisoner::makeDecision() {

	int currLine;

	for (int i = 0; i < (int)code.size(); i++) {
		currLine = parseLine(i); // -1 -> Syntax error, 0 -> Silence, 1 -> betray, any other number -> jump to that line
		switch (currLine) {
		case -1:
			cout << "Strategy not structured correctly (line: " << i << " )\n";
			return false;
			break;
		case 0:
			return true;
			break;
		case 1:
			return false;
			break;
		default:
			for (int j = 0; j < (int)code.size(); j++) {
				if (currLine == to_int(code[j][0])) {
					i = j;
				}
				else {
					i = (int)code.size() - 1;
				}
			}
			break;
		}
	}
}

int Prisoner::powOfN(int n, int p) {

	int temp = n;

	if (p = 0) {
		return 1;
	}
	else {
		for (int i = 1; i <= p; i++) {
			temp = temp * n;
		}
	}
}

int Prisoner::to_int(string num) {

	int temp = 0, j = num.size();

	for (std::string::iterator c = num.begin(); c != num.end(); ++c) {
		temp += (*c - 48) * powOfN(10, j);
	}
	return temp;
}

int Prisoner::parseLine(int n) {

	//check line number correctness
	if (to_int(code[n][0]) <= 0 || to_int(code[n][0]) > (int)code.size()) {
		cout << "Line number format incorrect. (line: " << n << " )";
		return -1;
	}

	std::transform(code[n][1].begin(), code[n][1].end(), code[n][1].begin(), ::toupper);

	if (code[n][1] == "SILENCE") {
		return 0;
	}
	else if (code[n][1] == "BETRAY") {
		return 1;
	}
	else if (code[n][1] == "RANDOM") {
		return rand() % 2; //Generates and returns either 1 or 0
	}
	else if (code[n][1] == "IF") {
		IfNode* f = new IfNode(code[n], this);
		f->resolve(n);
		if (f->getResult() < 0) {
			return -1;
		}
		else {
			return parseLine(f->getResult());
		}
		
	}
	else {
		cout << "Syntax error. (line: " << n << " )";
		return -1;
	}
}

/*
 * 
 * bool result1 - prisoners own decision
 * bool result2 - other prisoners decision
 * 
 * true = silence, false = betray
 * 
 */
void Prisoner::result(bool result1, bool result2) {
	if(result1 && result2) {
		w++;
		score += 2;
		this->last_outcome = 'w';
	}else if (result1 && !result2) {
		x++;
		score += 5;
		this->last_outcome = 'x';
	}else if (!result1 && result2) {
		y++;
		score += 0;
		this->last_outcome = 'y';
	}
	else {
		z++;
		score += 4;
		this->last_outcome = 'z';
	}
}