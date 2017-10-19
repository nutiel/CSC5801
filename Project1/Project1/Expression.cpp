#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"
#include "Expression.h"

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

int Expression::getValue() {
	return value;
}

bool Expression::getSyntaxCheck() {
	return syntaxOk;
}

void Expression::runExpression() {

	if ((end-begin)%2 == 0) {
		if ((end - begin) == 0) {
			findValue();
		}
		else {
			if (if_stmt[begin + 1] != "+" && if_stmt[begin + 1] != "-") {
				value = -5;
			}
			else {
				Expression* rhs = new Expression(begin+2, end, if_stmt, p);
				rhs->runExpression();
				findValue();
				if (rhs->value < 0) {
					cout << "Syntax error!\n";
					syntaxOk = false;
					value = -5;
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
		value = p->LASTOUTCOME();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_W") {
		value = p->ALLOUTCOMES_W();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_X") {
		value = p->ALLOUTCOMES_X();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_Y") {
		value = p->ALLOUTCOMES_Y();
	}
	else if (if_stmt[begin] == "ALLOUTCOMES_Z") {
		value = p->ALLOUTCOMES_Z();
	}
	else if (if_stmt[begin] == "ITERATIONS") {
		value = p->ITERATIONS();
	}
	else if (if_stmt[begin] == "MYSCORE") {
		value = p->MYSCORE();
	}
	else {
		value = to_int(if_stmt[begin]);
	}

}

int Expression::to_int(string num) {

	int temp = 0, j = 1;

	for (std::string::iterator c = num.end(); c != num.begin(); --c) {
		temp += (*c - 48) * j++;
	}
	return temp;
}