#pragma once

#include <iostream>

using namespace std;

class Game {
public:
	Game();
	~Game();
	void setStrategy(string string1, string string2);
	string getStrategy1();
	string getStrategy2();
private:
	string strategy1;
	string strategy2;
};