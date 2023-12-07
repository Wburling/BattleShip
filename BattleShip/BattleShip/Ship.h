#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
const int ROWS = 10;
const int COLLUMS = 10;

class Ship
{
private:  
	int placement[10][10];
public: 
	void welcome(); 
	char conversion(string ship); 
	bool verifyRotationLegal(int cases, int x, int y, int ship); 
	void shipPlacement(int rows, int collums, string shipName);
	void manPlacement(string shipName); 
	int numberConversion(char c); 
	void update(); 
	void inti(); 
	bool outOfBounds(int shipLen, int coord[], string shipName, int cases);
	void out(int coord[], int cases, string shipName);
	string gameboard[10][10]; 
};

