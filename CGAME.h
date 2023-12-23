#pragma once

#include "ConsoleHandle.h"
#include "CPEOPLE.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CTRAFFIC_LIGHT.h"
#include "CAR.h"
#include "CTRUCK.h"
#include "CTRAIN.h"
#include "CBIRD.h"
#include "CAT.h"
#include "CMOUSE.h"
using namespace std;

#define CAR_NUMBER 1
#define TRUCK_NUMBER 2
#define TRAIN_NUMBER 3
#define BIRD_NUMBER 4
#define CAT_NUMBER 5
#define MOUSE_NUMBER 6

class CGAME
{
private:
	// Player
	string NameOfPlayer;
	int CurrentScore;
	int m_isRunning;
	int m_currentLevel;
	CPEOPLE* mainChar;

	// Vehicle
	int numOfCars;
	CAR* car;
	int numOfTrucks;
	CTRUCK* truck;
	int numOfTrains;
	CTRAIN* train;

	// Animal
	int numOfBirds;
	CBIRD* bird;
	int numOfCats;
	CAT* cat;
	int numOfMouses;
	CMOUSE* mouse;
	
	static bitmapHandMake gameBackground;
	std::map<int, vector<pair<void*, int>>> m;
	string FileBackGround;
public:
	//Frame's coordinate
	static const int MAX_LEVEL;
	static const int LEFT;
	static const int RIGHT;
	static const int TOP;
	static const int BOTTOM;
	//----------------------------
	static const char TITLE[][82];
	static const string MENU[];
	static const string INSTRUCTIONS[];
	static const string SETTINGS[];

	CGAME();
	CGAME(const std::string& file);
	~CGAME();
	bool readFile(const std::string& file);
	bool SaveGame();
	void PeopleMove(int direc);
	void clear();
	void run();
	virtual void tell();
	std::string getName() const;
	void Draw(Render_State& screen);
	int CheckStatePepple();
	bool SaveScoreToLeaderBoard();
	std::multimap<int, pair<string, string>> GetLeaderBoard();
	int getLevelScore() const;
	int getCurrentSpeed() const;
	bool checkState() const;
	bool loadNextLevel();
	bool isFinishGame();
	int getTotalScore() const;
	void SetNamePlayer(string);
	string GetNameOfPlayer();
	int getLevel() const;

	static pair<int, vector<pair<string, pair<string, string>>>> getListGames();
	static string getCurTime();
};

void fileForGameLoading(string, vector <pair<string, string>>&);