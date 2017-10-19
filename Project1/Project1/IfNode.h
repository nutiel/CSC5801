#pragma once

#include <iostream>
#include <string>

using namespace std;

class IfNode {
public:
	IfNode(vector< string> input);
	~IfNode();
	int performComparison(int i);
	int ifSyntaxCheck(int i);
	int opSyntaxCheck(int i);
	int gotoSyntaxCheck(int i);
	int lheSyntaxCheck();
	int rheSyntaxCheck();
	void resolve(int i);
	int getResult();
private:

	vector< string> if_stmt;
	int result;
	int operat; // 0 -> <, 1 -> >, 2 -> =

	//expandable expressions
	Expression lhe;//left hand expression
	Expression rhe;//right hand expression
	Expression goto_pstn;//position to go to
};