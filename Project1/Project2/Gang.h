#pragma once

#include <iostream>
#include "Leader.h"
#include "Prisoner.h"

using namespace std;

class Gang {
public:
	Gang();
	~Gang();
	bool addSpy(int percent);
private:
	Leader *p1;
	Prisoner *p2, *p3, *p4, *p5;
};