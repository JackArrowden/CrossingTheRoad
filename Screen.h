#pragma once

#include "CGAME.h"
#include "Button.h"	
typedef unsigned long long u64;

class Screen{
	int windowState;
	vector<function<void()>> listWindow;
	u64 buttonState; // 6 buttons
	vector<Button> listButton;

	int curState;
	bool gameSound = true, objectSound = true, backClick = false, gameSoundClick_temp = false, gameStage1Clicked = false;
	bool isDataChanged = false; // This variable is used to check if the user's data is changed or not, if changed, calls sort function
	vector <pair<string, string>> listAccount;
	multimap<int, pair<string, string>> leaderAccount;
	
	CGAME* game;

	Render_State render_state;

protected:
	void drawMenuWindow();
	void drawGameWindow();
	void settingWindow();
	void leaderboardWindow();
	void enterGameWindow();
	void gameOverWindow();
	void gameWinWindow();
	void saveGameWindow();
	void resetWindow1();
	void resetWindow2();
	void resetSettingWindow();
	void resetLeaderboardWindow();
	void resetEnterGameWindow();
	void resetGameOverWindow();
	void resetGameWinWindow();
	void resetSaveGameWindow();
public:
	Screen();
	~Screen();
	void move();
	void draw();
	void render(HDC& hdc);
};

