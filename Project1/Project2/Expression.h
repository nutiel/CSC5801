/**
CSC5801
Expression.h
Purpose: Handles the resolution of simple and complex
expressions in if statements and returns their result

@author Michael Yiangou (B7064124)
@version
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Prisoner.h"

using namespace std;

class Expression {
public:
	Expression(int b, int e, vector< string> input, Prisoner* pris);
	~Expression();
	double getValue();
	void runExpression();
	bool getSyntaxCheck();
	void findValue();
	int to_int(string num);
	int powOfN(int n, int p);
private:
	vector< string> if_stmt;
	bool syntaxOk;
	int begin; // where it begins
	int end; // where it ends
	double value;
	Prisoner* p;
};