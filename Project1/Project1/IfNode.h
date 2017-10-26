/**
CSC5801
IfNode.h
Purpose: Handles the resolution of an if statement

@author Michael Yiangou (B7064124)
@version
*/

#pragma once

#include <iostream>
#include <string>
#include "Expression.h"
#include "Prisoner.h"

using namespace std;

class IfNode {
public:
	IfNode(vector< string> input, Prisoner* pris);
	~IfNode();
	//If everything is ok this performs the comparison of the if statement and returns the result
	int performComparison(int i);
	//Checks the syntax of the if statement
	int ifSyntaxCheck(int i);
	//Checks the syntax of the operator
	int opSyntaxCheck(int i);
	//Checks the syntax of the goto part
	int gotoSyntaxCheck(int i);
	//Check the syntax of the left hand expression
	int lheSyntaxCheck();
	//Check the syntax of the right hand expression
	int rheSyntaxCheck(int i);
	void resolve(int i);
	int getResult();
private:

	vector< string> if_stmt;
	int result;//the result of the expression after goto, -1 -> w, -2 -> x, -3 -> y, -4 -> z, other numbers -> where to jump
	int operat; // 0 -> <, 1 -> >, 2 -> =

	//expandable expressions
	Expression* lhe;//left hand expression
	Expression* rhe;//right hand expression
	Expression* goto_pstn;//position to go to

	Prisoner* p;
};