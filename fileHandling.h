#pragma once

#include "ConsoleHandle.h"

struct userData {
	string name = "";
	int score = 0;
	int hour = 0, min = 0, sec = 0;
	bool isChanged = false;
};

// Check if the name from input contain a space character
bool checkUserInput(string);
bool isDataGreater(userData, userData);
void userFileToVect(string, vector<userData>);
void sortDescendingData(vector<userData>);
// Call this function when create a new account or load game
void updateData(vector<userData>, int, int, int, int, int);