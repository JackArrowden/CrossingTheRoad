#include "ConsoleHandle.h"

struct userData {
	string name = "";
	int score = 0;
	int hour = 0, min = 0, sec = 0;
	bool isChanged = false;
};

// Check if the name from input contain a space character
static bool checkUserInput(string name) {
	if (name.length() > 10) return false; // The name must have the max length of 10 characters
	for (auto i : name) {
		if (i == ' ') return false;
	}
	return true;
}

static bool isDataGreater(userData X, userData Y) {
	if (X.score > Y.score) return true;
	else if (X.score == Y.score) {
		int secX = X.hour * 3600 + X.min * 60 + X.sec;
		int secY = Y.hour * 3600 + Y.min * 60 + Y.sec;
		if (secX > secY) return true;
	}
	return false;
}

static vector<userData> userFileToVect(string folderName) {
	vector<userData> res;

	ifstream ifs;
	for (int i = 0; i < 10; i++) {
		userData temp;
		string curPath = folderName + "\\user" + to_string(i + 1) + ".txt";
		ifs.open(curPath);
		if (ifs.is_open()) {
			ifs >> temp.name;
			ifs >> temp.score;
			ifs >> temp.hour;
			ifs >> temp.min;
			ifs >> temp.sec;
		}
		ifs.close();
		res.push_back(temp);
	}

	return res;
}

static void sortDescendingData(vector<userData> vect) {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (isDataGreater(vect[j], vect[i])) {
				swap(vect[i], vect[i]);
			}
		}
	}
}

// Call this function when create a new account or load game
static void updateData(vector<userData> vect, int nameN, int scoreN, int hourN, int minN, int secN) {
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i].isChanged) {
			vect[i].name = nameN;
			vect[i].score = scoreN;
			vect[i].hour = hourN;
			vect[i].min = minN;
			vect[i].sec = secN;
			vect[i].isChanged = false;
			return;
		}
	}
}