// WindowsProject2.cpp : Defines the entry point for the application.
//
#include "BitMap.h"
#include "CGAME.h"

#define MAX_LOADSTRING 100

int windowState = 1;
//int countTime1 = 0, countTime2 = 0, countTime3 = 0, countTime4 = 0, countTime5 = 0, countTime6 = 0;
int countTime[6] = { 0 };
int curState = 0;
int xTrain = 1200;
int xTrain_p = 1524;        //324
int xTrain_p1 = 1848;
int xTrain_e = 2172;
int xCar = 0;
int xBird = 1200;
int xMouse = 1200;
int xCat = 1200;
bool button1 = false, button2 = false, button3 = false, button4 = false, button5 = false, button6 = false, button7 = false, button8 = false, button9 = false;
bool gameSound = true, objectSound = true, backClick = false, gameSoundClick_temp = false, gameStage1Clicked = false;
bool isDataChanged = false; // This variable is used to check if the user's data is changed or not, if changed, calls sort function
vector <pair<string, string>> listAcc;
multimap<int, pair<string, string>> leaderAcc;

//// Main window
bitmapHandMake background1("Image\\mainWindow\\background.bmp");
bitmapHandMake nameGamePic("Image\\mainWindow\\nameGamePic.bmp");
bitmapHandMake playBtn("Image\\mainWindow\\playButton.bmp");
bitmapHandMake leaderBtn("Image\\mainWindow\\leaderButton.bmp");
bitmapHandMake logoutBtn("Image\\mainWindow\\logOutButton.bmp");
bitmapHandMake playRed("Image\\mainWindow\\redPlayBtn.bmp");
bitmapHandMake leaderRed("Image\\mainWindow\\redLeaderBtn.bmp");
bitmapHandMake logoutRed("Image\\mainWindow\\redLogOutBtn.bmp");
bitmapHandMake setting("Image\\mainWindow\\setting.bmp");
bitmapHandMake settingClicked("Image\\mainWindow\\settingClicked.bmp");

//// Game window
bitmapHandMake level1("Image\\gameWindow\\level1.bmp");
bitmapHandMake level2("Image\\gameWindow\\level2.bmp");
bitmapHandMake level3("Image\\gameWindow\\level3.bmp");
bitmapHandMake level4("Image\\gameWindow\\level4.bmp");

//// Setting window
bitmapHandMake background3("Image\\soundSetting\\backgroundSetting.bmp");
bitmapHandMake backClicked("Image\\soundSetting\\backClicked.bmp");
bitmapHandMake backUnclicked("Image\\soundSetting\\backUnclicked.bmp");
bitmapHandMake gameSoundOn("Image\\soundSetting\\gameSoundOn.bmp");
bitmapHandMake gameSoundOff("Image\\soundSetting\\gameSoundOff.bmp");
bitmapHandMake objectSoundOn("Image\\soundSetting\\objectSoundOn.bmp");
bitmapHandMake objectSoundOff("Image\\soundSetting\\objectSoundOff.bmp");
bitmapHandMake gameSoundOnClicked("Image\\soundSetting\\gameSoundOnClicked.bmp");
bitmapHandMake gameSoundOffClicked("Image\\soundSetting\\gameSoundOffClicked.bmp");
bitmapHandMake objectSoundOnClicked("Image\\soundSetting\\objectSoundOnClicked.bmp");
bitmapHandMake objectSoundOffClicked("Image\\soundSetting\\objectSoundOffClicked.bmp");

// Leaderboard window
bitmapHandMake background4("Image\\leaderBoard\\leaderBoardBg.bmp");

// Enter game window
bool writingMode = false;
string tempName = "teo.txt", inputUserName = "";
char tempNameChar[1000] = "\0";
bool backSpace = false, isErased = false;
bitmapHandMake background5("Image\\playOrResume\\backgroundEnter.bmp");
bitmapHandMake choiceInput("Image\\playOrResume\\choiceInput.bmp");
bitmapHandMake choiceClicked("Image\\playOrResume\\choiceClicked.bmp");
bitmapHandMake nameInput("Image\\playOrResume\\nameInput.bmp");
bitmapHandMake nameClicked("Image\\playOrResume\\nameClicked.bmp");
bitmapHandMake playUnclicked("Image\\playOrResume\\playBtn.bmp");
bitmapHandMake playClicked("Image\\playOrResume\\playClicked.bmp");

// End game window
bitmapHandMake backgroundWin("Image\\endGame\\backgroundWin.bmp");
bitmapHandMake backgroundLose("Image\\endGame\\backgroundLose.bmp");
bitmapHandMake backEnd("Image\\endGame\\backEnd.bmp");
bitmapHandMake backEndClicked("Image\\endGame\\backEndClicked.bmp");
bitmapHandMake leaderEnd("Image\\endGame\\leaderEnd.bmp");
bitmapHandMake leaderEndClicked("Image\\endGame\\leaderEndClicked.bmp");

// Save game window
bitmapHandMake saveGameBgr("Image\\saveGame\\saveGameBgr.bmp");
bitmapHandMake continueBtn("Image\\saveGame\\continueBtn.bmp");
bitmapHandMake continueClicked("Image\\saveGame\\continueClicked.bmp");
bitmapHandMake continueOrExit("Image\\saveGame\\continueOrExit.bmp");
bitmapHandMake exitReplayBtn("Image\\saveGame\\exitReplayBtn.bmp");
bitmapHandMake exitReplayBtnClicked("Image\\saveGame\\exitReplayBtnClicked.bmp");
bitmapHandMake exitSaveGame("Image\\saveGame\\exitSaveGame.bmp");
bitmapHandMake exitSaveGameClicked("Image\\saveGame\\exitSaveGameClicked.bmp");
bitmapHandMake leaveGame("Image\\saveGame\\leaveGame.bmp");
bitmapHandMake leaveGameClicked("Image\\saveGame\\leaveGameClicked.bmp");
bitmapHandMake saveGameBtn("Image\\saveGame\\saveGameBtn.bmp");
bitmapHandMake saveGameBtnClicked("Image\\saveGame\\saveGameBtnClicked.bmp");

// Char 
bitmapHandMake aUpper("Image\\char\\aUpper.bmp");
bitmapHandMake bUpper("Image\\char\\bUpper.bmp");
bitmapHandMake cUpper("Image\\char\\cUpper.bmp");
bitmapHandMake dUpper("Image\\char\\dUpper.bmp");
bitmapHandMake eUpper("Image\\char\\eUpper.bmp");
bitmapHandMake fUpper("Image\\char\\fUpper.bmp");
bitmapHandMake gUpper("Image\\char\\gUpper.bmp");
bitmapHandMake hUpper("Image\\char\\hUpper.bmp");
bitmapHandMake iUpper("Image\\char\\iUpper.bmp");
bitmapHandMake jUpper("Image\\char\\jUpper.bmp");
bitmapHandMake kUpper("Image\\char\\kUpper.bmp");
bitmapHandMake lUpper("Image\\char\\lUpper.bmp");
bitmapHandMake mUpper("Image\\char\\mUpper.bmp");
bitmapHandMake nUpper("Image\\char\\nUpper.bmp");
bitmapHandMake oUpper("Image\\char\\oUpper.bmp");
bitmapHandMake pUpper("Image\\char\\pUpper.bmp");
bitmapHandMake qUpper("Image\\char\\qUpper.bmp");
bitmapHandMake rUpper("Image\\char\\rUpper.bmp");
bitmapHandMake sUpper("Image\\char\\sUpper.bmp");
bitmapHandMake tUpper("Image\\char\\tUpper.bmp");
bitmapHandMake uUpper("Image\\char\\uUpper.bmp");
bitmapHandMake vUpper("Image\\char\\vUpper.bmp");
bitmapHandMake wUpper("Image\\char\\wUpper.bmp");
bitmapHandMake xUpper("Image\\char\\xUpper.bmp");
bitmapHandMake yUpper("Image\\char\\yUpper.bmp");
bitmapHandMake zUpper("Image\\char\\zUpper.bmp");
bitmapHandMake num0("Image\\char\\num0.bmp");
bitmapHandMake num1("Image\\char\\num1.bmp");
bitmapHandMake num2("Image\\char\\num2.bmp");
bitmapHandMake num3("Image\\char\\num3.bmp");
bitmapHandMake num4("Image\\char\\num4.bmp");
bitmapHandMake num5("Image\\char\\num5.bmp");
bitmapHandMake num6("Image\\char\\num6.bmp");
bitmapHandMake num7("Image\\char\\num7.bmp");
bitmapHandMake num8("Image\\char\\num8.bmp");
bitmapHandMake num9("Image\\char\\num9.bmp");
bitmapHandMake slash("Image\\char\\slash.bmp");
bitmapHandMake dot("Image\\char\\dot.bmp");
bitmapHandMake question("Image\\char\\question.bmp");
bitmapHandMake colon("Image\\char\\colon.bmp");

static bool running = true;

CTRAIN Train(1300, 350, -1, 3);

static Render_State render_state;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

void mainWindow(HWND);
void gameWindow(HWND);
void settingWindow(HWND);
void leaderboardWindow(HWND);
void enterGameWindow(HWND);
void gameOverWindow(HWND);
void gameWinWindow(HWND);
void saveGameWindow(HWND);
void resetMainWindow();
void resetGameWindow();
void resetSettingWindow();
void resetLeaderboardWindow();
void resetEnterGameWindow();
void resetGameOverWindow();
void resetGameWinWindow();
void resetSaveGameWindow();
void apply(HWND);
void resetBtn();
void stopObjectSound();
void printString(string str, int x, int y, int size);

CGAME* game = new CGAME;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	//game->tell();
	//ShowCursor(FALSE);
	// ########################################################
	//						Window Class
	// ########################################################
	// Create Window Class
	WNDCLASS window_class = {};
	HANDLE hIcon = LoadImage(0, _T("Image/road.ico"), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	window_class.hIcon = (HICON)hIcon;
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Window Class";
	window_class.lpfnWndProc = WindowProcedure;
	window_class.hInstance = hInstance;

	// Register Class
	RegisterClass(&window_class);

	// ########################################################
	//						Main Window
	// ########################################################
	HWND window = CreateWindow(window_class.lpszClassName, L"Cross Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 759, 0, 0, hInstance, 0);
	LONG style = GetWindowLong(window, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(window, GWL_STYLE, style);

	HDC hdc = GetDC(window);
	float delta_time = 0.016666f;
	LARGE_INTEGER frame_begin_time;
	QueryPerformanceCounter(&frame_begin_time);

	float performance_frequency;
	{
		LARGE_INTEGER perf;
		QueryPerformanceFrequency(&perf);
		performance_frequency = (float)perf.QuadPart;
	}


	while (running) {
		if (gameSoundClick_temp) {
			if (gameSound) {
				game->tell();
			}
			else {
				mciSendStringA("close MyFile", NULL, 0, NULL);
			}
			gameSoundClick_temp = false;
		}

		switch (windowState) {
		case 1:
			mainWindow(window);
			break;
		case 2:
			gameWindow(window);
			break;
		case 3:
			settingWindow(window);
			break;
		case 4:
			leaderboardWindow(window);
			break;
		case 5:
			enterGameWindow(window);
			break;
		case 6:
			gameOverWindow(window);
			break;
		case 7:
			saveGameWindow(window);
			break;
		case 8:
			gameWinWindow(window);
			break;
		}

		MSG msg;
		while (PeekMessage(&msg, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}

		StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

		LARGE_INTEGER frame_end_time;
		QueryPerformanceCounter(&frame_end_time);
		delta_time = (float)(frame_end_time.QuadPart - frame_begin_time.QuadPart) / performance_frequency;
		frame_begin_time = frame_end_time;
	}
	delete game;
	return 0;
}

void mainWindow(HWND hWnd) {
	render_state.drawImage(background1, 0, 0, 1);
	render_state.drawImage(nameGamePic, 120, 470, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button1) render_state.drawImage(setting, 1180, 610, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(settingClicked, 1180, 610, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button2) render_state.drawImage(playBtn, 490, 250, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(playRed, 490, 250, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button3) render_state.drawImage(leaderBtn, 490, 150, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(leaderRed, 490, 150, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button4) render_state.drawImage(logoutBtn, 490, 50, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(logoutRed, 490, 50, 10, DEFAULT_BACKGROUND_COLOR);
}

void gameWindow(HWND hWnd) {
	if (gameStage1Clicked) {
		if (objectSound) {
			game->tell();
			Train.tell();
		}
		gameStage1Clicked = false;
	}

	if (game->isFinishGame()) {
		game->SaveScoreToLeaderBoard();
		gameWinWindow(hWnd);
		resetGameWinWindow();
		
	}
	else
	{
		game->Draw(render_state);
		game->run();
	}

	if (game->CheckStatePepple() == 1 || game->CheckStatePepple() == 2) {
		resetGameOverWindow();
		game->SaveScoreToLeaderBoard();
	}

	int level = game->getLevel();
	int xPrint = 800, yPrint = 640, sizePrint = 4;
	switch (level) {
	case 1:
		render_state.drawImage(level1, xPrint, yPrint, sizePrint, DEFAULT_BACKGROUND_COLOR);
		break;
	case 2:
		render_state.drawImage(level2, xPrint, yPrint, sizePrint, DEFAULT_BACKGROUND_COLOR);
		break;
	case 3:
		render_state.drawImage(level3, xPrint, yPrint, sizePrint, DEFAULT_BACKGROUND_COLOR);
		break;
	case 4:
		render_state.drawImage(level4, xPrint, yPrint, sizePrint, DEFAULT_BACKGROUND_COLOR);
		break;
	}
}

void enterGameWindow(HWND hWnd) {
	render_state.drawImage(background5, 0, 0, 1);

	if (button1) render_state.drawImage(backClicked, 30, 540, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(backUnclicked, 30, 540, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button2) render_state.drawImage(nameInput, 165, 320, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(nameClicked, 165, 320, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button3) render_state.drawImage(playUnclicked, 260, 220, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(playClicked, 260, 220, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button4) render_state.drawImage(choiceInput, 735, 430, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(choiceClicked, 735, 430, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button5) render_state.drawImage(choiceInput, 735, 365, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(choiceClicked, 735, 365, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button6) render_state.drawImage(choiceInput, 735, 300, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(choiceClicked, 735, 300, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button7) render_state.drawImage(choiceInput, 735, 235, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(choiceClicked, 735, 235, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button8) render_state.drawImage(choiceInput, 735, 170, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(choiceClicked, 735, 170, 4, DEFAULT_BACKGROUND_COLOR);

	////////////////////////////// LIST ACCOUNT /////////////////
	int firstX = 740, firstY = 437, index = 1;
	for (int i = 0; i < listAcc.size(); i++) {
		printString(listAcc[i].first, firstX + 25, firstY, 30);

		string strFirst = "", strSecond = "", strTime = listAcc[i].second;
		bool next = false;
		for (char c : strTime) {
			if (c == 'T') {
				next = true;
				continue;
			}
			if (!next) strFirst += c;
			else strSecond += c;
		}
		printString(strSecond, firstX + 194, firstY, 30);
		printString(strFirst, firstX + 294, firstY, 30);

		firstY -= 65;
		index++;
	}

	if (inputUserName.length() == 13) {
		countTime[0] = 250;
		inputUserName = inputUserName.substr(0, inputUserName.size() - 1);
	}

	firstX = 122;
	if (countTime[0] > 0) {
		printString("MAXIMUM", firstX, 400, 28);
		printString("LENGTH", firstX + 110, 400, 28);
		printString("IS", firstX + 195, 400, 28);
		printString("12", firstX + 225, 400, 28);
		printString("CHARACTER", firstX + 255, 400, 28);
		countTime[0]--;
	}

	int secondX = 878;
	for (int i = 1; i < 6; i++) {
		if (countTime[i] > 0) {
			printString("NO", secondX, 502 - 65 * i, 28);
			printString("DATA", secondX + 35, 502 - 65 * i, 28);
			printString("HERE", secondX + 98, 502 - 65 * i, 28);
			countTime[i]--;
		}
	}

	printString(inputUserName, 210, 330, 22);
}

void gameOverWindow(HWND hWnd) {
	render_state.drawImage(backgroundLose, 0, 0, 1);

	if (!button1) render_state.drawImage(backEnd, 30, 320, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(backEndClicked, 30, 320, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button2) render_state.drawImage(leaderEnd, 925, 320, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(leaderEndClicked, 925, 320, 10, DEFAULT_BACKGROUND_COLOR);

	printString(to_string(game->getTotalScore()), 640, 517, 20);
}

void gameWinWindow(HWND hWnd) {
	render_state.drawImage(backgroundWin, 0, 0, 1);
	
	if (!button1) render_state.drawImage(backEnd, 30, 320, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(backEndClicked, 30, 320, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button2) render_state.drawImage(leaderEnd, 925, 320, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(leaderEndClicked, 925, 320, 10, DEFAULT_BACKGROUND_COLOR);

	printString(to_string(game->getTotalScore()), 640, 517, 20);
}

void settingWindow(HWND hWnd) {
	render_state.drawImage(background3, 0, 0, 1);

	// back
	if (button1) render_state.drawImage(backClicked, 10, 470, 8, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(backUnclicked, 10, 470, 8, DEFAULT_BACKGROUND_COLOR);

	// game
	if (gameSound) {
		if (button2) render_state.drawImage(gameSoundOnClicked, 900, 390, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(gameSoundOn, 900, 390, 4, DEFAULT_BACKGROUND_COLOR);
	} else {
		if (button2) render_state.drawImage(gameSoundOffClicked, 900, 390, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(gameSoundOff, 900, 390, 4, DEFAULT_BACKGROUND_COLOR);
	}

	// object
	if (objectSound) {
		if (button3) render_state.drawImage(objectSoundOnClicked, 900, 190, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(objectSoundOn, 900, 190, 4, DEFAULT_BACKGROUND_COLOR);
	} else {
		if (button3) render_state.drawImage(objectSoundOffClicked, 900, 190, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(objectSoundOff, 900, 190, 4, DEFAULT_BACKGROUND_COLOR);
	}
}

void leaderboardWindow(HWND hWnd) {
	render_state.drawImage(background4, 0, 0, 1);

	// back
	if (!button1) render_state.drawImage(backUnclicked, 10, 540, 8, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(backClicked, 10, 540, 8, DEFAULT_BACKGROUND_COLOR);

	int size = static_cast<int>(leaderAcc.size()), firstY = 0;
	if (size == 3) firstY = 180;
	else if (size == 2) firstY = 302;
	else if (size == 1) firstY = 424;

	for (auto i : leaderAcc) {
		int size = 20;
		if (to_string(i.first).length() > 4) size = 22; // small dummy code
		printString(i.second.first, 369, firstY, 20);
		printString(to_string(i.first), 612, firstY, size);
		string strFirst = "", strSecond = "", strTime = i.second.second;
		bool next = false;
		for (char c : strTime) {
			if (c == 'T') {
				next = true;
				continue;
			}
			if (!next) strFirst += c;
			else strSecond += c;
		}
		printString(strSecond, 804, firstY, 20);
		printString(strFirst, 1034, firstY, 20);
		firstY += 122;
	}
}

void saveGameWindow(HWND hWnd) {
	if (!button4) { // Button4: virtual button
		render_state.drawImage(saveGameBgr, 0, 0, 1);

		// back
		if (!button1) render_state.drawImage(exitSaveGame, 260, 340, 3, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(exitSaveGameClicked, 260, 340, 3, DEFAULT_BACKGROUND_COLOR);

		if (!button2) render_state.drawImage(saveGameBtn, 541, 340, 3, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(saveGameBtnClicked, 541, 340, 3, DEFAULT_BACKGROUND_COLOR);

		if (!button3) render_state.drawImage(leaveGame, 825, 340, 3, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(leaveGameClicked, 825, 340, 3, DEFAULT_BACKGROUND_COLOR);
	}
	else {
		render_state.drawImage(continueOrExit, 138, 150, 3);

		if (!button5) render_state.drawImage(continueBtn, 270, 210, 3, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(continueClicked, 270, 210, 3, DEFAULT_BACKGROUND_COLOR);

		if (!button6) render_state.drawImage(exitReplayBtn, 690, 210, 3, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(exitReplayBtnClicked, 690, 210, 3, DEFAULT_BACKGROUND_COLOR);
	}
}

void resetBtn() {
	curState = 0;
	button1 = true;
	button2 = button3 = button4 = button5 = button6 = button7 = button8 = false;
}

void resetSettingWindow() {
	windowState = 3;
	backClick = false;
	resetBtn();
}

void resetEnterGameWindow() {
	windowState = 5;
	listAcc.clear();
	fileForGameLoading("Data\\FileName.txt", listAcc);
	resetBtn();
}

void resetLeaderboardWindow() {
	windowState = 4;
	leaderAcc = game->GetLeaderBoard();
	resetBtn();
}

void resetMainWindow() {
	windowState = 1;
	resetBtn();
}

void resetGameWindow() {
	windowState = 2;
	resetBtn();
}

void resetGameOverWindow() {
	windowState = 6;
	resetBtn();
}

void resetGameWinWindow() {
	windowState = 8;
	resetBtn();
}

void resetSaveGameWindow() {
	windowState = 7;
	writingMode = true;
	resetBtn();
}

void stopObjectSound() {
	mciSendStringA("close Train", NULL, 0, NULL);
	mciSendStringA("close Bird", NULL, 0, NULL);
	mciSendStringA("close Car", NULL, 0, NULL);
	mciSendStringA("close Cat", NULL, 0, NULL);
	mciSendStringA("close Mouse", NULL, 0, NULL);
	mciSendStringA("close Truck", NULL, 0, NULL);
}

void apply(HWND hWnd) {
	HDC hdc = GetDC(hWnd);
	//float delta_time = 0.016666f;
	//LARGE_INTEGER frame_begin_time;
	//QueryPerformanceCounter(&frame_begin_time);

	//float performance_frequency;
	//{
	//	LARGE_INTEGER perf;
	//	QueryPerformanceFrequency(&perf);
	//	performance_frequency = (float)perf.QuadPart;
	//}

	StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

	//LARGE_INTEGER frame_end_time;
	//QueryPerformanceCounter(&frame_end_time);
	//delta_time = (float)(frame_end_time.QuadPart - frame_begin_time.QuadPart) / performance_frequency;
	//frame_begin_time = frame_end_time;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	if (writingMode) {
		switch (msg)
		{
		case WM_DESTROY:
		{
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_KEYDOWN:
		{	
			if (inputUserName.length() <= 12) {
				int key = LOWORD(wp);
				switch (key)
					{
					case VK_0:
						inputUserName += '0';
						break;
					case VK_1:
						inputUserName += '1';
						break;
					case VK_2:
						inputUserName += '2';
						break;
					case VK_3:
						inputUserName += '3';
						break;
					case VK_4:
						inputUserName += '4';
						break;
					case VK_5:
						inputUserName += '5';
						break;
					case VK_6:
						inputUserName += '6';
						break;
					case VK_7:
						inputUserName += '7';
						break;
					case VK_8:
						inputUserName += '8';
						break;
					case VK_9:
						inputUserName += '9';
						break;
					case VK_A:
						inputUserName += 'A';
						break;
					case VK_B:
						inputUserName += 'B';
						break;
					case VK_C:
						inputUserName += 'C';
						break;
					case VK_D:
						inputUserName += 'D';
						break;
					case VK_E:
						inputUserName += 'E';
						break;
					case VK_F:
						inputUserName += 'F';
						break;
					case VK_G:
						inputUserName += 'G';
						break;
					case VK_H:
						inputUserName += 'H';
						break;
					case VK_I:
						inputUserName += 'I';
						break;
					case VK_J:
						inputUserName += 'J';
						break;
					case VK_K:
						inputUserName += 'K';
						break;
					case VK_L:
						inputUserName += 'L';
						break;
					case VK_M:
						inputUserName += 'M';
						break;
					case VK_N:
						inputUserName += 'N';
						break;
					case VK_O:
						inputUserName += 'O';
						break;
					case VK_P:
						inputUserName += 'P';
						break;
					case VK_Q:
						inputUserName += 'Q';
						break;
					case VK_R:
						inputUserName += 'R';
						break;
					case VK_S:
						inputUserName += 'S';
						break;
					case VK_T:
						inputUserName += 'T';
						break;
					case VK_U:
						inputUserName += 'U';
						break;
					case VK_V:
						inputUserName += 'V';
						break;
					case VK_W:
						inputUserName += 'W';
						break;
					case VK_X:
						inputUserName += 'X';
						break;
					case VK_Y:
						inputUserName += 'Y';
						break;
					case VK_Z:
						inputUserName += 'Z';
						break;
					case VK_DOC:
						inputUserName += '.';
						break;
					case VK_SLASH:
						inputUserName += '/';
						break;
					case VK_BACK:
						backSpace = true;
						inputUserName = inputUserName.substr(0, inputUserName.size() - 1);
						break;
					case VK_DOWN:
						writingMode = false;
						break;
					default:
						break;
					}
			}
		} break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	if (windowState == 1) {
		switch (msg)
		{
		case WM_CREATE:
			mciSendStringA("open Sound/BACKGROUND.wav type waveaudio alias MyFile", NULL, 0, 0);
			mciSendStringA("play MyFile notify", NULL, 0, hWnd);
			break;
		case MM_MCINOTIFY:
			mciSendStringA("seek MyFile to start", NULL, 0, NULL);
			mciSendStringA("play MyFile notify", NULL, 0, hWnd);
			break;
		case WM_DESTROY:
			mciSendString(_T("close music"), NULL, 0, NULL);
			running = false;
			PostQuitMessage(0);
			break;
		case WM_SIZE: {
			RECT rect;
			GetClientRect(hWnd, &rect);
			int newWidth = rect.right - rect.left;
			int newHeight = rect.bottom - rect.top;
			render_state.resize(newHeight, newWidth);

		} break;
		case WM_KEYDOWN:
		{
			int key = LOWORD(wp);
			switch (key)
			{
			case VK_RETURN:
			{
				switch (curState) {
				case 0:
					resetSettingWindow();
					break;
				case 1:
					resetEnterGameWindow();
					break;
				case 2:
					resetLeaderboardWindow();
					break;
				case 3:
					running = false;
					PostQuitMessage(0);
					break;
				default:
					break;
				}
			}
			break;
			case VK_UP:
			{
				if (curState > 0) curState--;
				if (curState == 0) {
					button1 = true;
					button2 = false;
				}
				else if (curState == 1) {
					button2 = true;
					button3 = false;
				}
				else if (curState == 2) {
					button3 = true;
					button4 = false;
				}
			}
			break;
			case VK_DOWN:
			{
				if (curState < 3) curState++;
				if (curState == 1) {
					button1 = false;
					button2 = true;
				}
				else if (curState == 2) {
					button2 = false;
					button3 = true;
				}
				else if (curState == 3) {
					button3 = false;
					button4 = true;
				}
			}
			break;
			case VK_RIGHT:
			{
				if (curState > 0) curState = 0;
				button1 = true;
				button2 = button3 = button4 = false;
			}
			break;
			case VK_LEFT:
			{
				if (curState == 0) {
					curState = 1;
					button1 = false;
					button2 = true;
				}
			}
			break;
			default:
				break;
			}
		}
		break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	else if (windowState == 2) {
		switch (msg)
		{
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_SIZE: {
			RECT rect;
			GetClientRect(hWnd, &rect);
			int newWidth = rect.right - rect.left;
			int newHeight = rect.bottom - rect.top;
			render_state.resize(newHeight, newWidth);

		} break;
		case WM_KEYDOWN:
		{

			int key = LOWORD(wp);
			switch (key) {
			case VK_RETURN:
				resetMainWindow();
				stopObjectSound();
				break;
			case VK_A:
				game->PeopleMove(1);
				break;
			case VK_LEFT:
				game->PeopleMove(1);
				break;
			case VK_D:
				game->PeopleMove(2);
				break;
			case VK_RIGHT:
				game->PeopleMove(2);
				break;
			case VK_S:
				game->PeopleMove(4);
				break;
			case VK_DOWN:
				game->PeopleMove(4);
				break;
			case VK_W:
				game->PeopleMove(3);
				break;
			case VK_UP:
				game->PeopleMove(3);
				break;
			case VK_L:
			{
				writingMode = true;
				resetSaveGameWindow();
				stopObjectSound();
			}
			break;
			if (game->checkState()) {
				game->SaveScoreToLeaderBoard();
				gameOverWindow(hWnd);
				resetGameOverWindow();
			}
			if (game->isFinishGame()) {
				game->SaveScoreToLeaderBoard();
				gameWinWindow(hWnd);
				resetGameWinWindow();
			}
			}
		} break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	else if (windowState == 3) {
		switch (msg)
		{
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_SIZE: {
			RECT rect;
			GetClientRect(hWnd, &rect);
			int newWidth = rect.right - rect.left;
			int newHeight = rect.bottom - rect.top;
			render_state.resize(newHeight, newWidth);

		} break;
		case WM_KEYDOWN:
		{
			int key = LOWORD(wp);
			switch (key)
			{
			case VK_RETURN:
			{
				switch (curState) {
				case 0:
					if (button1) resetMainWindow();
					break;
				case 1:
					gameSound = !gameSound;
					gameSoundClick_temp = true;
					break;
				case 2:
					objectSound = !objectSound;
					break;
				default:
					break;
				}
			}
			break;
			case VK_UP:
			{
				if (curState > 0) curState--;
				switch (curState) {
				case 0:
					button1 = true;
					button2 = false;
					break;
				case 1:
					button2 = true;
					button3 = false;
					break;
				default:
					break;
				}
			}
			break;
			case VK_DOWN:
			{
				if (curState < 2) curState++;
				switch (curState) {
				case 1:
					button1 = false;
					button2 = true;
					break;
				case 2:
					button2 = false;
					button3 = true;
					break;
				default:
					break;
				}
			}
			break;
			case VK_LEFT:
			{
				button2 = true;
				if (curState > 0) curState--;
				switch (curState) {
				case 0:
					button1 = true;
					button2 = false;
					break;
				case 1:
					button2 = true;
					button3 = false;
					break;
				default:
					break;
				}
			}
			break;
			case VK_RIGHT:
			{
				if (curState < 2) curState++;
				switch (curState) {
				case 1:
					button1 = false;
					button2 = true;
					break;
				case 2:
					button2 = false;
					button3 = true;
					break;
				default:
					break;
				}
			}
			break;
			default:
				break;
			}
		}
		break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	else if (windowState == 4) {
		switch (msg)
		{
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_SIZE: {
			RECT rect;
			GetClientRect(hWnd, &rect);
			int newWidth = rect.right - rect.left;
			int newHeight = rect.bottom - rect.top;
			render_state.resize(newHeight, newWidth);

		} break;
		case WM_KEYDOWN:
		{
			int key = LOWORD(wp);
			if (key == VK_RETURN && button1) resetMainWindow();
			else  if (key == VK_UP || key == VK_DOWN || key == VK_LEFT || key == VK_RIGHT) button1 = !button1;
		}
		break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	else if (windowState == 5) {
		switch (msg)
		{
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_SIZE: {
			RECT rect;
			GetClientRect(hWnd, &rect);
			int newWidth = rect.right - rect.left;
			int newHeight = rect.bottom - rect.top;
			render_state.resize(newHeight, newWidth);

		} break;
		case WM_KEYDOWN:
		{
			int key = LOWORD(wp);
			switch (key)
			{
			case VK_RETURN:
			{
				if (curState == 0) {
					tempName = "";
					inputUserName = "";
					resetMainWindow();
				} else if (curState == 2 && inputUserName.length() > 0) {
					game->readFile("Data\\Default1.txt");
					game->SetNamePlayer(inputUserName);
					inputUserName = "";
					resetGameWindow();
					gameStage1Clicked = true;
				} else if (curState == 3 || curState == 4 || curState == 5 || curState == 6 || curState == 7) {
					if ((curState - 3) < listAcc.size()) {
						game->readFile("Data\\" + to_string(curState - 3) + ".txt");
						inputUserName = "";
						resetGameWindow();
						gameStage1Clicked = true;
					} else {
						countTime[curState - 2] = 200;
					}
				}
			}
			break;
			case VK_UP: {
				switch (curState) {
				case 1:
					writingMode = false;
					curState = 0;
					button1 = true;
					button2 = false;
					break;
				case 2:
					writingMode = true;
					curState = 1;
					button2 = true;
					button3 = false;
					break;
				case 4:
					curState = 3;
					button4 = true;
					button5 = false;
					break;
				case 5:
					curState = 4;
					button5 = true;
					button6 = false;
					break;
				case 6:
					curState = 5;
					button6 = true;
					button7 = false;
					break;
				case 7:
					curState = 6;
					button7 = true;
					button8 = false;
					break;
				}
			} break;
			case VK_DOWN: {
				switch (curState) {
				case 0:
					writingMode = true;
					curState = 1;
					button1 = false;
					button2 = true;
					break;
				case 1:
					writingMode = false;
					curState = 2;
					button2 = false;
					button3 = true;
					break;
				case 3:
					curState = 4;
					button4 = false;
					button5 = true;
					break;
				case 4:
					curState = 5;
					button5 = false;
					button6 = true;
					break;
				case 5:
					curState = 6;
					button6 = false;
					button7 = true;
					break;
				case 6:
					curState = 7;
					button7 = false;
					button8 = true;
					break;
				}
			} break;
			case VK_RIGHT: {
				if (curState == 0) {
					curState = 1;
					writingMode = true;
					button1 = false;
					button2 = true;
				}
				else if (curState == 1 || curState == 2) {
					curState = 3;
					writingMode = false;
					button4 = true;
					button2 = button3 = false;
				}
			} break;
			case VK_LEFT: {
				if (curState == 1 || curState == 2) {
					writingMode = false;
					curState = 0;
					button1 = true;
					button2 = button3 = false;
				}
				else if (curState == 3 || curState == 4 || curState == 5 || curState == 6 || curState == 7) {
					writingMode = true;
					curState = 1;
					button2 = true;
					button4 = button5 = button6 = button7 = button8 = false;
				}
			} break;
			}
		}
		break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	else if (windowState == 6 || windowState == 8) {
		switch (msg)
		{
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_SIZE: {
			RECT rect;
			GetClientRect(hWnd, &rect);
			int newWidth = rect.right - rect.left;
			int newHeight = rect.bottom - rect.top;
			render_state.resize(newHeight, newWidth);

		} break;
		case WM_KEYDOWN:
		{
			int key = LOWORD(wp);
			if (key == VK_RETURN) {
				if (curState == 0) resetMainWindow();
				else if (curState == 1) resetLeaderboardWindow();
			}
			else if (key == VK_RIGHT) {
				curState = 1;
				button1 = false;
				button2 = true;
			}
			else if (key == VK_LEFT) {
				curState = 0;
				button1 = true;
				button2 = false;
			}
		}
		break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	else if (windowState == 7) {
		switch (msg)
		{
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_SIZE: {
			RECT rect;
			GetClientRect(hWnd, &rect);
			int newWidth = rect.right - rect.left;
			int newHeight = rect.bottom - rect.top;
			render_state.resize(newHeight, newWidth);

		} break;
		case WM_KEYDOWN:
		{
			int key = LOWORD(wp);
			if (key == VK_RETURN) {
				writingMode = false;
				if (curState == 0 || curState == 3) resetGameWindow();
				else if (curState == 1) {
					game->SaveGame();
					curState = 3;
					button4 = button5 = true;
				}
				else if (curState == 2 || curState == 4) resetMainWindow();
			}
			else if (key == VK_RIGHT) {
				if (curState == 0) {
					curState = 1;
					button1 = false;
					button2 = true;
				}
				else if (curState == 1) {
					curState = 2;
					button2 = false;
					button3 = true;
				}
				else if (curState == 3) {
					curState = 4;
					button5 = false;
					button6 = true;
				}
			}
			else if (key == VK_LEFT) {
				if (curState == 1) {
					curState = 0;
					button1 = true;
					button2 = false;
				}
				else if (curState == 2) {
					curState = 1;
					button2 = true;
					button3 = false;
				}
				else if (curState == 4) {
					curState = 3;
					button5 = true;
					button6 = false;
				}
			}
		}
		break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	return DefWindowProcW(hWnd, msg, wp, lp);
}

void printString(string str, int x, int y, int size) {
	for (char c : str) {
		if (c >= 'A' && c <= 'Z') {
			if (c <= 'L') {
				if (c <= 'F') {
					switch (c) {
					case 'A': {
						render_state.drawImage(aUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 420 / size;
					} break;
					case 'B': {
						render_state.drawImage(bUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 370 / size;
					} break;
					case 'C': {
						render_state.drawImage(cUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'D': {
						render_state.drawImage(dUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'E': {
						render_state.drawImage(eUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 350 / size;
					} break;
					case 'F': {
						render_state.drawImage(fUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 320 / size;
					} break;
					}
				}
				else {
					switch (c) {
					case 'G': {
						render_state.drawImage(gUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'H': {
						render_state.drawImage(hUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'I': {
						render_state.drawImage(iUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 300 / size;
					} break;
					case 'J': {
						render_state.drawImage(jUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 320 / size;
					} break;
					case 'K': {
						render_state.drawImage(kUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'L': {
						render_state.drawImage(lUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 320 / size;
					} break;
					}
				}
			}
			else {
				if (c <= 'S') {
					switch (c) {
					case 'M': {
						render_state.drawImage(mUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 480 / size;
					} break;
					case 'N': {
						render_state.drawImage(nUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'O': {
						render_state.drawImage(oUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 440 / size;
					} break;
					case 'P': {
						render_state.drawImage(pUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 380 / size;
					} break;
					case 'Q': {
						render_state.drawImage(qUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 430 / size;
					} break;
					case 'R': {
						render_state.drawImage(rUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'S': {
						render_state.drawImage(sUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 380 / size;
					} break;
					}
				}
				else {
					switch (c) {
					case 'T': {
						render_state.drawImage(tUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'U': {
						render_state.drawImage(uUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'V': {
						render_state.drawImage(vUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'W': {
						render_state.drawImage(wUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 480 / size;
					} break;
					case 'X': {
						render_state.drawImage(xUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'Y': {
						render_state.drawImage(yUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 400 / size;
					} break;
					case 'Z': {
						render_state.drawImage(zUpper, x, y, size, DEFAULT_BACKGROUND_COLOR);
						x += 380 / size;
					} break;
					}
				}
			}
		}
		else if (c >= '0' && c <= '9') {
			switch (c) {
			case '0': {
				render_state.drawImage(num0, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '1': {
				render_state.drawImage(num1, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '2': {
				render_state.drawImage(num2, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '3': {
				render_state.drawImage(num3, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '4': {
				render_state.drawImage(num4, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '5': {
				render_state.drawImage(num5, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '6': {
				render_state.drawImage(num6, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '7': {
				render_state.drawImage(num7, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '8': {
				render_state.drawImage(num8, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			case '9': {
				render_state.drawImage(num9, x, y, size, DEFAULT_BACKGROUND_COLOR);
				x += 380 / size;
			} break;
			}
		}
		else if (c == '/') { // 36: slash
			render_state.drawImage(slash, x, y, size, DEFAULT_BACKGROUND_COLOR);
			x += 300 / size;
		}
		else if (c == '.') { // 37: dot
			render_state.drawImage(dot, x, y, size, DEFAULT_BACKGROUND_COLOR);
			x += 150 / size;
		}
		else if (c == '?') { // 38: question
			render_state.drawImage(question, x, y, size, DEFAULT_BACKGROUND_COLOR);
			x += 380 / size;
		}
		else if (c == ':') { // 39: colon
			render_state.drawImage(colon, x, y, size, DEFAULT_BACKGROUND_COLOR);
			x += 150 / size;
		}
	}
}