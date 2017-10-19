#include "CW1.h"
#include "Prisoner.h"
#include "Tournament.h"
#include "Game.h"
#include "IfNode.h"
#include "Expression.h"

IfNode::IfNode(vector< string> input) :
if_stmt(input) {

}

IfNode::~IfNode(){

}

int IfNode::performComparison(int i) {

	switch (operat) {
	case 0:
		if (lhe.getValue < rhe.getValue) {
			return result;
		}
		else {
			return i;
		}
		break;
	case 1:
		if (lhe.getValue > rhe.getValue) {
			return result;
		}
		else {
			return i;
		}
		break;
	case 2:
		if (lhe.getValue == rhe.getValue) {
			return result;
		}
		else {
			return i;
		}
		break;
	}
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

}

int IfNode::opSyntaxCheck(int i) {

	if (if_stmt[i] == "<") {
		operat = 0;
		return rheSyntaxCheck();
	}else if (if_stmt[i] == ">") {
		operat = 1;
		return rheSyntaxCheck();
	}else if (if_stmt[i] == "=") {
		operat = 2;
		return rheSyntaxCheck();
	}
	else {
		return -1;
	}
}

int IfNode::rheSyntaxCheck() {

}

int IfNode::gotoSyntaxCheck(int i) {

	std::transform(if_stmt[i].begin(), if_stmt[i].end(), if_stmt[i].begin(), ::toupper);//transform to Uppercase

	if (if_stmt[i] == "GOTO") {
		//return ; jump destination ADD FUNCTION
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