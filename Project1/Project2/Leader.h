/**
CSC5801
Leader.h
Purpose: An extension of the prisoner class, has the responsibility of
spotting the spy

@author Michael Yiangou (B7064124)
@version
*/

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "Prisoner.h"


class Gang;

using namespace std;

class Leader : public Prisoner {
public:
	Leader(Gang* gname);
	virtual ~Leader();
	virtual int chooseSpy();
	virtual int changeChoice(int p);
private:
	int choice1, choice2;
};