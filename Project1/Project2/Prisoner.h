#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "Thread.h"
#include "Gang.h"

using namespace std;

class Prisoner : public Thread {
public:
	Prisoner(Gang* gname);
	virtual ~Prisoner();
	virtual void setCode(string code, int i);
	virtual int powOfN(int n, int p);
	virtual bool makeDecision();
	virtual int parseLine(int l);
	virtual int to_int(string num);
	virtual void setSpy();
	virtual Gang* getGang();
private:
	vector< vector< string> > code;
	Gang* g;
	bool spy;
protected:
	virtual void run();
};