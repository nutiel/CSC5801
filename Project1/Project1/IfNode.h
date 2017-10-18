#pragma once

#include <iostream>
#include <string>

using namespace std;

class IfNode {
public:
	IfNode();
	~IfNode();
	bool ifSyntaxCheck(string kwrd);
	bool opSyntaxCheck(string kwrd);
	bool gotoSyntaxCheck(string kwrd);
	bool lheSyntaxCheck();
	bool rheSyntaxCheck();
private:
	//if statement keywords
	string if_kwrd;
	string op_kwrd;
	string goto_kwrd;

	//expandable expressions
	Expression<E> lhe;//left hand expression
	Expression<E> rhe;//right hand expression
	Expression<int> goto_pstn;//position to go to
};