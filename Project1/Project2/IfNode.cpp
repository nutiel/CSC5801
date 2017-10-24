#include "CW2.h"
#include "Prisoner.h"
#include "IfNode.h"
#include "Expression.h"

IfNode::IfNode(vector< string> input, Prisoner* pris) :
	if_stmt(input),
	p(pris) {

}

IfNode::~IfNode() {

}

int IfNode::performComparison(int i) {

	switch (operat) {
	case 0:
		if (lhe->getValue() < rhe->getValue()) {
			return result;
		}
		else {
			return i + 1;
		}
		break;
	case 1:
		if (lhe->getValue() > rhe->getValue()) {
			return result;
		}
		else {
			return i + 1;
		}
		break;
	case 2:
		if (lhe->getValue() == rhe->getValue()) {
			return result;
		}
		else {
			return i + 1;
		}
		break;
	}
	return -1;
}

int IfNode::ifSyntaxCheck(int i) {

	std::transform(if_stmt[1].begin(), if_stmt[1].end(), if_stmt[1].begin(), ::toupper);//transform to Uppercase

	if (if_stmt[1] == "IF" && lheSyntaxCheck() != -1) {
		return performComparison(i);
	}
	else {
		return -1;
	}
}

int IfNode::lheSyntaxCheck() {

	int i = 2;

	while (if_stmt[i] != "<" && if_stmt[i] != ">" && if_stmt[i] != "=") {
		i++;
	}

	lhe = new Expression(2, i - 1, if_stmt, p);
	lhe->runExpression();

	if (lhe->getSyntaxCheck()) {
		return opSyntaxCheck(i);
	}
	else {
		return -1;
	}
}

int IfNode::opSyntaxCheck(int i) {

	if (if_stmt[i] == "<") {
		operat = 0;
		return rheSyntaxCheck(i + 1);
	}
	else if (if_stmt[i] == ">") {
		operat = 1;
		return rheSyntaxCheck(i + 1);
	}
	else if (if_stmt[i] == "=") {
		operat = 2;
		return rheSyntaxCheck(i + 1);
	}
	else {
		return -1;
	}
}

int IfNode::rheSyntaxCheck(int i) {

	int j = i;

	std::transform(if_stmt[j].begin(), if_stmt[j].end(), if_stmt[j].begin(), ::toupper);//transform to Uppercase

	while (if_stmt[j] != "GOTO") {
		j++;
		std::transform(if_stmt[j].begin(), if_stmt[j].end(), if_stmt[j].begin(), ::toupper);//transform to Uppercase
	}

	rhe = new Expression(i, j - 1, if_stmt, p);
	rhe->runExpression();

	if (rhe->getSyntaxCheck()) {
		return gotoSyntaxCheck(j);
	}
	else {
		return -1;
	}
}

int IfNode::gotoSyntaxCheck(int i) {

	std::transform(if_stmt[i].begin(), if_stmt[i].end(), if_stmt[i].begin(), ::toupper);//transform to Uppercase

	if (if_stmt[i] == "GOTO") {
		goto_pstn = new Expression(i + 1, if_stmt.size() - 1, if_stmt, p);
		goto_pstn->runExpression();

		result = goto_pstn->getValue();
		return 0;
	}
	else {
		return -1;
	}
}


void IfNode::resolve(int i) {
	result = ifSyntaxCheck(i);
}

int IfNode::getResult() {
	return result;
}