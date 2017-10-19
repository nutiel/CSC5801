#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Expression {
public:
	Expression();
	~Expression();
	int getValue();
private:
	int value;
};