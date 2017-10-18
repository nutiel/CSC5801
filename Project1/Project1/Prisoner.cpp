#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"

Prisoner::Prisoner() :
	w(0), x(0),	y(0), z(0),
	score(0), 
	last_outcome(' ') {
	code.resize(lines, std::vector<string>(0, ""));
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

int Prisoner::MYSCORE() {
	return score;
}

void Prisoner::setCode(string line, int i) {
	
	int j = 0;
	bool flag = false;
	string word;

	for (std::string::iterator c = line.begin(); c != line.end(); ++c) {
		if (*c == ' ' && flag) {
			j++;
		}
		else if (*c == ' ') {
			// Do Nothing
		}
		else {
			do {
				word += *c;
				c++;
			} while (*c + 1 != ' ');

			code[i][j].push_back(word);
			flag = true;
		}
	}
}

bool Prisoner::makeDecision(int iterations) {

	int currLine;

	for (int i = 0; i < lines; i++) {
		currLine = parseLine(i, iterations); // -1 -> Syntax error, 0 -> Silence, 1 -> betray, any other number -> jump to that line
		switch (currLine) {
		case -1:
			/**
			 * //TO_DO// handle the error
			 */
			break;
		case 0:
			return true;
			break;
		case 1:
			return false;
			break;
		default:
			if (currLine - 1 >= lines || currLine - 1 < 0) {
				//show error message
			} else if (currLine - 1 == i) {
				//show error message
			} else {
				i = currLine - 1;
			}
			break;
		}
	}
}

int Prisoner::parseLine(int n, int iterations) {

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