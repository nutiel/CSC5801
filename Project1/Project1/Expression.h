#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Expression {
public:
	Expression(int b, int e, vector< string> input);
	~Expression();
	int getValue();
	bool getSyntaxCheck();
private:
	vector< string> if_stmt;
	bool syntaxOk;
	int begin; // where it begins
	int end; // where it ends
	int value;
};