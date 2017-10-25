#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Prisoner {
public:
	Prisoner();
	virtual ~Prisoner();
	virtual void setCode(string code, int i);
	virtual int powOfN(int n, int p);
	virtual bool makeDecision();
	virtual int parseLine(int l);
	virtual int to_int(string num);
	virtual void setSpy();
private:
	vector< vector< string> > code;
	bool spy;
};