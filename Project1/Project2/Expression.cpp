/**
CSC5801
Expression.cpp
Purpose: Handles the resolution of simple and complex
expressions in if statements and returns their result

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

Expression::Expression(int b, int e, vector< string> input, Prisoner* pris) :
	value(0),
	begin(b),
	end(e),
	syntaxOk(true),
	if_stmt(input),
	p(pris) {

}

Expression::~Expression() {

}

double Expression::getValue() {
	return value;
}

bool Expression::getSyntaxCheck() {
	return syntaxOk;
}

void Expression::runExpression() {

	if ((end - begin) % 2 == 0) {
		if ((end - begin) == 0) {
			findValue();
		}
		else {
			if (if_stmt[begin + 1] != "+" && if_stmt[begin + 1] != "-") {
				value = -8;
			}
			else {
				Expression* rhs = new Expression(begin + 2, end, if_stmt, p);
				rhs->runExpression();
				findValue();
				if (rhs->value < 0) {
					cout << "Syntax error!\n";
					syntaxOk = false;
					value = -8;
				}
				else if (if_stmt[begin + 1] == "+") {
					value = value + rhs->value;
				}
				else {
					value = value - rhs->value;
				}
			}
		}
	}
	else {
		syntaxOk = false;
	}
}

void Expression::findValue() {

	std::transform(if_stmt[begin].begin(), if_stmt[begin].end(), if_stmt[begin].begin(), ::toupper);//transform to Uppercase

	if (if_stmt[begin] == "W") {
		value = -1;
	}
	else if (if_stmt[begin] == "X") {
		value = -2;
	}
	else if (if_stmt[begin] == "Y") {
		value = -3;
	}
	else if (if_stmt[begin] == "Z") {
		value = -4;
	}
	else if (if_stmt[begin] == "LASTOUTCOME") {
		value = p->getGang()->LASTOUTCOME();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_A") {
		value = p->getGang()->ALLOUTCOMES_A();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_B") {
		value = p->getGang()->ALLOUTCOMES_B();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_C") {
		value = p->getGang()->ALLOUTCOMES_C();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_W") {
		value = p->getGang()->ALLOUTCOMES_W();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_X") {
		value = p->getGang()->ALLOUTCOMES_X();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_Y") {
		value = p->getGang()->ALLOUTCOMES_Y();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_Z") {
		value = p->getGang()->ALLOUTCOMES_Z();
	}
	else if (if_stmt[begin] == "ITERATIONS") {
		value = p->getGang()->ITERATIONS();
	}
	else if (if_stmt[begin] == "MYSCORE") {
		value = p->getGang()->MYSCORE();
	}
	else {
		value = to_int(if_stmt[begin]);
	}

}

int Expression::powOfN(int n, int p) {

	int temp = 1;

	if (p == 0) {
		return 1;
	}
	else {
		for (int i = 1; i <= p; i++) {
			temp = temp * n;
		}
	}
	return temp;
}

int Expression::to_int(string num) {

	int temp = 0, j = num.size() - 1;

	for (std::string::iterator c = num.begin(); c != num.end(); ++c) {
		temp += (*c - 48) * powOfN(10, j);
		j--;
	}
	return temp;
}