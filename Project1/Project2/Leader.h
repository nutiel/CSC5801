#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "Prisoner.h"

using namespace std;

class Leader : public Prisoner {
public:
	Leader();
	virtual ~Leader();
	virtual int chooseSpy();
	virtual int changeChoice(int p);
private:
	int choice;
};