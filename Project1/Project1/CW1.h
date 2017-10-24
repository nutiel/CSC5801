#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const int lines = 10; //Each program generated has 10 lines of code

void addIfStatement(int n); //Creates an if statement and adds it to the strategy

void writeStrategy(int n); //Chooses and adds components to the strategy

void writeFirstLine(int n); //Writes the first line of the strategy

void writeLastLine(int n); //writes the last 2 lines of the strategy

void createFile(int n); //Creates the file in which the strategy will be stored

void goToStatement(int n); //Adds the goto part at the end of the if statement

bool checkIf(int n); //Checks if line n is an if statement

void showMenu(); //Displays the menu

void showDetailedRes();

void showStrAvg();

void showStrRanks();