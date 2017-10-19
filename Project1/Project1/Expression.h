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
	int getValue();
	void runExpression();
	bool getSyntaxCheck();
	void findValue();
	int to_int(string num);
private:
	vector< string> if_stmt;
	bool syntaxOk;
	int begin; // where it begins
	int end; // where it ends
	int value;
	Prisoner* p;
};