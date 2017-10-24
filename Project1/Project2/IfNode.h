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
	int performComparison(int i);
	int ifSyntaxCheck(int i);
	int opSyntaxCheck(int i);
	int gotoSyntaxCheck(int i);
	int lheSyntaxCheck();
	int rheSyntaxCheck(int i);
	void resolve(int i);
	int getResult();
private:

	vector< string> if_stmt;
	int result;//the result of the expression after goto, -1 -> w, -2 -> x, -3 -> y, -4 -> z, -5 -> a, -6 -> b, -7 -> c, other numbers -> where to jump
	int operat; // 0 -> <, 1 -> >, 2 -> =

				//expandable expressions
	Expression* lhe;//left hand expression
	Expression* rhe;//right hand expression
	Expression* goto_pstn;//position to go to

	Prisoner* p;
};