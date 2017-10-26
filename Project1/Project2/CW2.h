/**
CSC5801
CW2.cpp
Purpose: Contains main function and handles strategy
creation and UI

@author Michael Yiangou (B7064124)
@version
*/


#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

//Each strategy created has 10 lines of code
const int lines = 10;

//handles the addition of an if statement
void addIfStatement(int n);

//handles the addition of a line of code
void writeStrategy(int n);

//writes the first line
void writeFirstLine(int n);

//writes the last 2 lines
void writeLastLine(int n);

//Creates the file in which the strategy will will be saved
void createFile(int n);

//handles the go to statement
void goToStatement(int n);

bool checkIf(int n);

void showMenu();

//The following 3 functions retrieve information about the tournamend and display them
void showDetailedRes();

void showStrAvg();

void showStrRanks();