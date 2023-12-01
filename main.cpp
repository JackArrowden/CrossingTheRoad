// WindowsProject2.cpp : Defines the entry point for the application.
//
#include "BitMap.h"
#include "CGAME.h"
#include "fileHandling.h"

#define MAX_LOADSTRING 100

int windowState = 1;
int curState = 0;
int xTrain = 1200;
int xTrain_p = 1524;        //324
int xTrain_p1 = 1848;
int xTrain_e = 2172;
int xCar = 0;
int xBird = 1200;
int xMouse = 1200;
int xCat = 1200;
bool button1 = false, button2 = false, button3 = false, button4 = false, button5 = false, button6 = false;
bool gameSoundClick = false, objectSoundClick = false, gameSound = true, objectSound = true, backClick = false, gameSoundClick_temp = false, gameStage1Clicked = false;
bool isDataChanged = false; // This variable is used to check if the user's data is changed or not, if changed, calls sort function
vector <pair<string, string>> listAcc;

//// Main window
bitmapHandMake background1("Image\\mainWindow\\background.bmp");
bitmapHandMake playBtn("Image\\mainWindow\\playButton.bmp");
bitmapHandMake leaderBtn("Image\\mainWindow\\leaderButton.bmp");
bitmapHandMake logoutBtn("Image\\mainWindow\\logOutButton.bmp");
bitmapHandMake playRed("Image\\mainWindow\\redPlayBtn.bmp");
bitmapHandMake leaderRed("Image\\mainWindow\\redLeaderBtn.bmp");
bitmapHandMake logoutRed("Image\\mainWindow\\redLogOutBtn.bmp");
bitmapHandMake setting("Image\\mainWindow\\setting.bmp");
bitmapHandMake settingClicked("Image\\mainWindow\\settingClicked.bmp");

//// Game window
bitmapHandMake background2("Image\\gameWindow\\gameBgr.bmp");
bitmapHandMake background_city("Image\\gameWindow\\gameBgr_city.bmp");
bitmapHandMake train_h("Image\\gameWindow\\train_h.bmp");
//bitmapHandMake train_p("Image\\gameWindow\\train_p.bmp");
bitmapHandMake train_e("Image\\gameWindow\\train_e.bmp");
bitmapHandMake truck("Image\\gameWindow\\truck.bmp");
bitmapHandMake person("Image\\person.bmp");
bitmapHandMake car("Image\\gameWindow\\car.bmp");
bitmapHandMake mouse("Image\\gameWindow\\mouse.bmp");
bitmapHandMake bird("Image\\gameWindow\\bird.bmp");
bitmapHandMake cat("Image\\gameWindow\\cat.bmp");

//// Setting window
bitmapHandMake background3("Image\\soundSetting\\backgroundSetting.bmp");
bitmapHandMake greenBgr("Image\\soundSetting\\greenBgr.bmp");
bitmapHandMake redBgr("Image\\soundSetting\\redBgr.bmp");
bitmapHandMake yellowBgr("Image\\soundSetting\\yellowBgr.bmp");
bitmapHandMake gameSoundGreen("Image\\soundSetting\\gameSoundGreen.bmp");
bitmapHandMake gameSoundRed("Image\\soundSetting\\gameSoundRed.bmp");
bitmapHandMake objectSoundGreen("Image\\soundSetting\\objectSoundGreen.bmp");
bitmapHandMake objectSoundRed("Image\\soundSetting\\objectSoundRed.bmp");
bitmapHandMake greenLight("Image\\soundSetting\\greenLight.bmp");
bitmapHandMake redLight("Image\\soundSetting\\redLight.bmp");
bitmapHandMake turnOffGreen("Image\\soundSetting\\turnOffGreen.bmp");
bitmapHandMake turnOffYellow("Image\\soundSetting\\turnOffYellow.bmp");
bitmapHandMake turnOnRed("Image\\soundSetting\\turnOnRed.bmp");
bitmapHandMake turnOnYellow("Image\\soundSetting\\turnOnYellow.bmp");
bitmapHandMake backClicked("Image\\soundSetting\\backClicked.bmp");
bitmapHandMake backUnclicked("Image\\soundSetting\\backUnclicked.bmp");

// Leaderboard window
bitmapHandMake background4("Image\\leaderBoard\\leaderBoardBg.bmp");
bitmapHandMake top1("Image\\leaderBoard\\top1.bmp");
bitmapHandMake top2("Image\\leaderBoard\\top2.bmp");
bitmapHandMake top3("Image\\leaderBoard\\top3.bmp");
bitmapHandMake nameFrame("Image\\leaderBoard\\nameFrame.bmp");
bitmapHandMake scoreFrame("Image\\leaderBoard\\scoreFrame.bmp");
bitmapHandMake backClickLeader("Image\\leaderBoard\\backClickLeader.bmp");

// Enter game window
bool writingMode = false;
string tempName = "", choiceUserName = "", inputUserName = "";
char tempNameChar[1000] = "\0";
bool backSpace = false, isErased = false;
bitmapHandMake background5("Image\\playOrResume\\background5.bmp");
bitmapHandMake choiceInput("Image\\playOrResume\\choiceInput.bmp");
bitmapHandMake choiceClicked("Image\\playOrResume\\choiceClicked.bmp");
bitmapHandMake nameInput("Image\\playOrResume\\nameInput.bmp");
bitmapHandMake nameClicked("Image\\playOrResume\\nameClicked.bmp");
bitmapHandMake resumeBtn("Image\\playOrResume\\resumeBtn.bmp");
bitmapHandMake resumeClicked("Image\\playOrResume\\resumeClicked.bmp");
bitmapHandMake playUnclicked("Image\\playOrResume\\playBtn.bmp");
bitmapHandMake playClicked("Image\\playOrResume\\playClicked.bmp");
bitmapHandMake backWin5("Image\\playOrResume\\backWin5.bmp");
bitmapHandMake backClickedWin5("Image\\playOrResume\\backClickedWin5.bmp");

// Game over window
bitmapHandMake background6("Image\\gameOver\\background6.bmp");
bitmapHandMake backWin6("Image\\gameOver\\backWin6.bmp");
bitmapHandMake backClickedWin6("Image\\gameOver\\backClickedWin6.bmp");
bitmapHandMake leaderWin6("Image\\gameOver\\leaderWin6.bmp");
bitmapHandMake leaderClickedWin6("Image\\gameOver\\leaderClickedWin6.bmp");

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
CPEOPLE player;
CBIRD Bird(1300, 500, -1);
CAR Car(1300, 160, -1);
CAT Cat(1300, 300, -1);
CTRAIN Train(1300, 350, -1, 3);
CMOUSE Mouse(1300, 300, -1);
CTRUCK Truck(1300, 50, -1);
enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_W,
	BUTTON_S,
	BUTTON_A,
	BUTTON_D,
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_ENTER,

	BUTTON_COUNT, // Should be the last item
};

struct Button_State {
	bool is_down;
	bool changed;
};

struct Input {
	Button_State buttons[BUTTON_COUNT];
};

static Render_State render_state;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
void drawWindow1(HWND);
void drawWindow2(HWND);
void drawWindow3(HWND);
void settingWindow(HWND);
void leaderboardWindow(HWND);
void enterGameWindow(HWND);
void gameOverWindow(HWND);
void saveGameWindow(HWND hWnd);
void resetWindow1();
void resetWindow2();
void resetSettingWindow();
void resetLeaderboardWindow();
void resetEnterGameWindow();
void resetGameOverWindow();
void resetSaveGameWindow();
void apply(HWND);
void resetBtn();
void resetCharArray(char[]);
void stopObjectSound();
void printString(string str, int x, int y, int size);
//void drawImage(const bitmapHandMake& image, Render_State&);

CGAME* game = new CGAME;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	game->readFile("Data\\Default4.txt");
	game->tell();
	//ShowCursor(FALSE);
	// ########################################################
	//						Window Class
	// ########################################################
	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Window Class";
	window_class.lpfnWndProc = WindowProcedure;

	// Register Class
	RegisterClass(&window_class);

	// ########################################################
	//						Main Window
	// ########################################################
	HWND window = CreateWindow(window_class.lpszClassName, L"Cross Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
	LONG style = GetWindowLong(window, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(window, GWL_STYLE, style);

	while (running) {
		if (gameSoundClick_temp) {
			if (gameSound) {
				game->tell();
			}
			else {
				mciSendStringA("close MyFile", NULL, 0, NULL);
				//PlaySound(0, NULL, 0);
			}
			gameSoundClick_temp = false;
		}

		switch (windowState) {
		case 1:
			drawWindow1(window);
			break;
		case 2:
			drawWindow2(window);
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
		default:
			break;
		}

		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}
	delete game;
	return 0;
}

void drawWindow1(HWND hWnd) {
	render_state.drawImage(background1, 0, 0, 1);

	if (!button1) render_state.drawImage(setting, 1180, 610, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(settingClicked, 1180, 610, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button2) render_state.drawImage(playBtn, 490, 250, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(playRed, 490, 250, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button3) render_state.drawImage(leaderBtn, 490, 150, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(leaderRed, 490, 150, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button4) render_state.drawImage(logoutBtn, 490, 50, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(logoutRed, 490, 50, 10, DEFAULT_BACKGROUND_COLOR);

	apply(hWnd);
}

void drawWindow2(HWND hWnd) {
	if (gameStage1Clicked) {
		if (objectSound) {
			Train.tell();
		}
		gameStage1Clicked = false;
	}

	game->Draw(render_state);
	game->run();
	if (game->CheckStatePepple() == 1 || game->CheckStatePepple() == 2) resetGameOverWindow();
	apply(hWnd);
}

void drawWindow3(HWND hWnd) {
	//render_state.drawImage(background_city, 0, 0, 1);
	//game->Draw(render_state);
	//game->run();
	//apply(hWnd);
	game->Draw(render_state);
	game->run();
	if (game->CheckStatePepple() == 1 || game->CheckStatePepple() == 2) resetGameOverWindow();
	apply(hWnd);
}

void enterGameWindow(HWND hWnd) {
	render_state.drawImage(background5, 0, 0, 1);

	if (!button1) render_state.drawImage(choiceInput, 275, 180, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(choiceClicked, 275, 180, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button2) render_state.drawImage(nameInput, 755, 410, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(nameClicked, 755, 410, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button3) render_state.drawImage(resumeBtn, 350, 120, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(resumeClicked, 350, 120, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button4) render_state.drawImage(playUnclicked, 835, 350, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(playClicked, 835, 350, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button5) render_state.drawImage(backWin5, 740, 120, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(backClickedWin5, 740, 120, 4, DEFAULT_BACKGROUND_COLOR);

	////////////////////////////// LIST ACCOUNT /////////////////
	int firstX = 270, firstY = 475, index = 1;
	for (int i = 0; i < listAcc.size(); i++) {
		printString(to_string(index) + '.', firstX, firstY, 34);
		printString(listAcc[i].first, firstX + 25, firstY, 34);
		printString(listAcc[i].second, firstX + 170, firstY, 34);
		firstY -= 50;
		index++;
	}

	printString(choiceUserName, 392, 183, 38);
	printString(inputUserName, 870, 420, 38);

	apply(hWnd);
}

void gameOverWindow(HWND hWnd) {
	render_state.drawImage(background6, 0, 0, 1);

	if (!button1) render_state.drawImage(backWin6, 50, 320, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(backClickedWin6, 50, 320, 4, DEFAULT_BACKGROUND_COLOR);

	if (!button2) render_state.drawImage(leaderWin6, 943, 320, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(leaderClickedWin6, 943, 320, 4, DEFAULT_BACKGROUND_COLOR);

	apply(hWnd);
}

void settingWindow(HWND hWnd) {
	render_state.drawImage(background3, 0, 0, 1);

	// back
	if (backClick) render_state.drawImage(backClicked, 30, 610, 5, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(backUnclicked, 30, 610, 5, DEFAULT_BACKGROUND_COLOR);

	// box
	if (gameSound && objectSound) render_state.drawImage(greenBgr, 270, 150, 4, DEFAULT_BACKGROUND_COLOR);
	else if (!gameSound && !objectSound) render_state.drawImage(redBgr, 270, 150, 4, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(yellowBgr, 270, 150, 4, DEFAULT_BACKGROUND_COLOR);

	// game
	if (gameSound) {
		// light
		render_state.drawImage(gameSoundGreen, 380, 440, 4, DEFAULT_BACKGROUND_COLOR);
		render_state.drawImage(greenLight, 440, 330, 4, DEFAULT_BACKGROUND_COLOR);
		// button
		if (gameSoundClick) render_state.drawImage(turnOffYellow, 410, 250, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(turnOffGreen, 410, 250, 4, DEFAULT_BACKGROUND_COLOR);
	}
	else {
		// light
		render_state.drawImage(gameSoundRed, 380, 440, 4, DEFAULT_BACKGROUND_COLOR);
		render_state.drawImage(redLight, 440, 330, 4, DEFAULT_BACKGROUND_COLOR);
		// button
		if (gameSoundClick) render_state.drawImage(turnOnYellow, 410, 250, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(turnOnRed, 410, 250, 4, DEFAULT_BACKGROUND_COLOR);
	}

	// object
	if (objectSound) {
		// light
		render_state.drawImage(objectSoundGreen, 680, 440, 4, DEFAULT_BACKGROUND_COLOR);
		render_state.drawImage(greenLight, 740, 330, 4, DEFAULT_BACKGROUND_COLOR);
		// button
		if (objectSoundClick) render_state.drawImage(turnOffYellow, 710, 250, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(turnOffGreen, 710, 250, 4, DEFAULT_BACKGROUND_COLOR);
	}
	else {
		// light
		render_state.drawImage(objectSoundRed, 680, 440, 4, DEFAULT_BACKGROUND_COLOR);
		render_state.drawImage(redLight, 740, 330, 4, DEFAULT_BACKGROUND_COLOR);
		// button
		if (objectSoundClick) render_state.drawImage(turnOnYellow, 710, 250, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(turnOnRed, 710, 250, 4, DEFAULT_BACKGROUND_COLOR);
	}

	apply(hWnd);
}

void leaderboardWindow(HWND hWnd) {
	render_state.drawImage(background4, 0, 0, 1);

	// back
	render_state.drawImage(backClickLeader, 30, 610, 5, DEFAULT_BACKGROUND_COLOR);

	render_state.drawImage(top1, 320, 405, 3, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(top2, 320, 285, 3, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(top3, 320, 165, 3, DEFAULT_BACKGROUND_COLOR);

	render_state.drawImage(nameFrame, 470, 420, 3, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(nameFrame, 470, 300, 3, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(nameFrame, 470, 180, 3, DEFAULT_BACKGROUND_COLOR);

	render_state.drawImage(scoreFrame, 830, 420, 3, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(scoreFrame, 830, 300, 3, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(scoreFrame, 830, 180, 3, DEFAULT_BACKGROUND_COLOR);

	apply(hWnd);
}

void saveGameWindow(HWND hWnd) {
	if (!button4) { // Button4: virtual button
		render_state.drawImage(saveGameBgr, 0, 0, 1);

		// back
		if (!button1) render_state.drawImage(exitSaveGame, 160, 160, 3, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(exitSaveGameClicked, 160, 160, 3, DEFAULT_BACKGROUND_COLOR);

		if (!button2) render_state.drawImage(saveGameBtn, 465, 130, 3, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(saveGameBtnClicked, 465, 130, 3, DEFAULT_BACKGROUND_COLOR);

		if (!button3) render_state.drawImage(leaveGame, 780, 160, 3, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(leaveGameClicked, 780, 160, 3, DEFAULT_BACKGROUND_COLOR);

		//if (backSpace) {
		//	resetCharArray(tempNameChar);
		//	backSpace = false;
		//}

		//int index = 0;
		//for (auto i : tempName) {
		//	tempNameChar[index] = i;
		//	index++;
		//}
		//tempName[index] = '\0';
		//render_state.draw_text(tempNameChar, -70, -2, 1, 0x000000);
		printString(tempName, 130, 282, 14);
	}
	else {
		render_state.drawImage(continueOrExit, 0, 0, 1);

		if (!button5) render_state.drawImage(continueBtn, 225, 165, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(continueClicked, 225, 165, 4, DEFAULT_BACKGROUND_COLOR);

		if (!button6) render_state.drawImage(exitReplayBtn, 650, 165, 4, DEFAULT_BACKGROUND_COLOR);
		else render_state.drawImage(exitReplayBtnClicked, 650, 165, 4, DEFAULT_BACKGROUND_COLOR);
	}

	apply(hWnd);
}

void resetBtn() {
	curState = 0;
	button1 = true;
	button2 = button3 = button4 = button5 = button6 = false;
}

void resetSettingWindow() {
	windowState = 3;
	gameSoundClick = false;
	objectSoundClick = false;
	backClick = false;
	resetBtn();
}

void resetEnterGameWindow() {
	windowState = 5;
	writingMode = true;
	listAcc.clear();
	fileForGameLoading("Data\\FileName.txt", listAcc);
	resetBtn();
}

void resetLeaderboardWindow() {
	windowState = 4;
	resetBtn();
}

void resetWindow1() {
	windowState = 1;
	resetBtn();
}

void resetWindow2() {
	windowState = 2;
	xTrain = 1200;
	xTrain_p = 1360;
	xTrain_p1 = 1594;
	xTrain_e = 1828;
	xCar = 0;
	resetBtn();
}

void resetGameOverWindow() {
	windowState = 6;
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
	float delta_time = 0.016666f;
	LARGE_INTEGER frame_begin_time;
	QueryPerformanceCounter(&frame_begin_time);

	float performance_frequency;
	{
		LARGE_INTEGER perf;
		QueryPerformanceFrequency(&perf);
		performance_frequency = (float)perf.QuadPart;
	}

	StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

	LARGE_INTEGER frame_end_time;
	QueryPerformanceCounter(&frame_end_time);
	delta_time = (float)(frame_end_time.QuadPart - frame_begin_time.QuadPart) / performance_frequency;
	frame_begin_time = frame_end_time;
}

void resetCharArray(char arr[]) {
	int index = 0;
	while (arr[index] != '\0') {
		arr[index] = '\0';
		index++;
	}
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	if (writingMode) {
		switch (msg)
		{
		case WM_DESTROY:
		{
			running = false;
			PostQuitMessage(0);
		}
		break;
		case WM_KEYDOWN:
		{
			int key = LOWORD(wp);
			if (button1) {
				switch (key)
				{
				case VK_0:
					choiceUserName += '0';
					break;
				case VK_1:
					choiceUserName += '1';
					break;
				case VK_2:
					choiceUserName += '2';
					break;
				case VK_3:
					choiceUserName += '3';
					break;
				case VK_4:
					choiceUserName += '4';
					break;
				case VK_5:
					choiceUserName += '5';
					break;
				case VK_6:
					choiceUserName += '6';
					break;
				case VK_7:
					choiceUserName += '7';
					break;
				case VK_8:
					choiceUserName += '8';
					break;
				case VK_9:
					choiceUserName += '9';
					break;
				case VK_A:
					choiceUserName += 'A';
					break;
				case VK_B:
					choiceUserName += 'B';
					break;
				case VK_C:
					choiceUserName += 'C';
					break;
				case VK_D:
					choiceUserName += 'D';
					break;
				case VK_E:
					choiceUserName += 'E';
					break;
				case VK_F:
					choiceUserName += 'F';
					break;
				case VK_G:
					choiceUserName += 'G';
					break;
				case VK_H:
					choiceUserName += 'H';
					break;
				case VK_I:
					choiceUserName += 'I';
					break;
				case VK_J:
					choiceUserName += 'J';
					break;
				case VK_K:
					choiceUserName += 'K';
					break;
				case VK_L:
					choiceUserName += 'L';
					break;
				case VK_M:
					choiceUserName += 'M';
					break;
				case VK_N:
					choiceUserName += 'N';
					break;
				case VK_O:
					choiceUserName += 'O';
					break;
				case VK_P:
					choiceUserName += 'P';
					break;
				case VK_Q:
					choiceUserName += 'Q';
					break;
				case VK_R:
					choiceUserName += 'R';
					break;
				case VK_S:
					choiceUserName += 'S';
					break;
				case VK_T:
					choiceUserName += 'T';
					break;
				case VK_U:
					choiceUserName += 'U';
					break;
				case VK_V:
					choiceUserName += 'V';
					break;
				case VK_W:
					choiceUserName += 'W';
					break;
				case VK_X:
					choiceUserName += 'X';
					break;
				case VK_Y:
					choiceUserName += 'Y';
					break;
				case VK_Z:
					choiceUserName += 'Z';
					break;
				case VK_DOC:
					choiceUserName += '.';
					break;
				case VK_SLASH:
					choiceUserName += '/';
					break;
				case VK_BACK:
					backSpace = true;
					choiceUserName = choiceUserName.substr(0, choiceUserName.size() - 1);
					break;
				case VK_DOWN:
					writingMode = false;
					break;
				default:
					break;
				}
			}
			else if (button2) {
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
		}
		break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	}
	if (windowState == 1) {
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
					resetSettingWindow();
					break;
				case 1:
					resetEnterGameWindow();
					break;
				case 2:
					resetLeaderboardWindow();
					break;
				case 3:
					resetGameOverWindow();
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
				curState = 1;
				button1 = false;
				button2 = true;
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
			switch (key)
			{
			case VK_RETURN:
				resetWindow1();
				stopObjectSound();
				break;
			case VK_A:
			{
				//game->currentPeople = 1;
				//player.Left(10);
				game->PeopleMove(1);


			}
			break;
			case VK_D:
			{
				//game->currentPeople = 2;
				//
				//player.Right(10);
				game->PeopleMove(2);

			}
			break;
			case VK_S:
			{
				//game->currentPeople = 4;
				//
				//player.Down(10);
				game->PeopleMove(4);

			}
			break;
			case VK_W:
			{
				//game->currentPeople = 3;
				//player.Up(10);
				game->PeopleMove(3);
			}
			break;
			case VK_L:
			{
				writingMode = true;
				resetSaveGameWindow();
				stopObjectSound();
			}
			break;
			case VK_RIGHT:
				CreateWindowW(L"static", L"Enter right text here: ", WS_VISIBLE | WS_CHILD, 200, 100, 300, 50, hWnd, NULL, NULL, NULL);
				//MessageBox(hWnd, L"Arrow right clicked", L"Alert", MB_OK | MB_ICONINFORMATION);
				break;
			case VK_LEFT:
				CreateWindowW(L"static", L"Enter left text here: ", WS_VISIBLE | WS_CHILD, 200, 100, 300, 50, hWnd, NULL, NULL, NULL);
				//MessageBox(hWnd, L"Arrow left clicked", L"Alert", MB_OK | MB_ICONINFORMATION);
				break;
			default:
				break;
			}
			if (game->CheckStatePepple() == 1 || game->CheckStatePepple() == 2) {
				gameOverWindow(hWnd);
				resetGameOverWindow();
			}
		}
		break;
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
					resetWindow1();
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
					backClick = true;
					gameSoundClick = false;
					break;
				case 1:
					gameSoundClick = true;
					objectSoundClick = false;
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
					gameSoundClick = true;
					backClick = false;
					break;
				case 2:
					gameSoundClick = false;
					objectSoundClick = true;
					break;
				default:
					break;
				}
			}
			break;
			case VK_LEFT:
			{
				gameSoundClick = true;
				if (curState > 0) curState--;
				switch (curState) {
				case 0:
					backClick = true;
					gameSoundClick = false;
					break;
				case 1:
					gameSoundClick = true;
					objectSoundClick = false;
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
					gameSoundClick = true;
					backClick = false;
					break;
				case 2:
					gameSoundClick = false;
					objectSoundClick = true;
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
			switch (key)
			{
			case VK_RETURN:
				resetWindow1();
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
				switch (curState) {
				case 2:
					tempName = "";
					resetWindow2();
					choiceUserName = "";
					inputUserName = "";
					gameStage1Clicked = true;
					break;
				case 3:
					tempName = "";
					choiceUserName = "";
					inputUserName = "";
					game->readFile("Data\\Default.txt");
					resetWindow2();
					gameStage1Clicked = true;
					break;
				case 4:
					tempName = "";
					choiceUserName = "";
					inputUserName = "";
					resetWindow1();
					break;
				default:
					break;
				}
			}
			break;
			case VK_UP:
			{
				switch (curState) {
				case 0:
					writingMode = true;
					curState = 1;
					button2 = true;
					button1 = false;
					break;
				case 2:
					writingMode = true;
					curState = 0;
					button1 = true;
					button3 = false;
					break;
				case 3:
					writingMode = true;
					curState = 1;
					button2 = true;
					button4 = false;
					break;
				case 4:
					writingMode = false;
					curState = 3;
					button4 = true;
					button5 = false;
					break;
				default:
					break;
				}
			}
			break;
			case VK_DOWN:
			{
				switch (curState) {
				case 0:
					writingMode = false;
					curState = 2;
					button1 = false;
					button3 = true;
					break;
				case 1:
					writingMode = false;
					curState = 3;
					button2 = false;
					button4 = true;
					break;
				case 3:
					writingMode = false;
					curState = 4;
					button4 = false;
					button5 = true;
					break;
				default:
					break;
				}
			}
			break;
			case VK_RIGHT:
			{
				if (curState == 0) {
					writingMode = true;
					curState = 1;
					button2 = true;
					button1 = false;
				}
				else if (curState == 2) {
					writingMode = false;
					curState = 4;
					button5 = true;
					button3 = false;
				}
			}
			break;
			case VK_LEFT:
			{
				if (curState == 1 || curState == 3) {
					writingMode = true;
					curState = 0;
					button1 = true;
					button2 = button4 = false;
				}
				else if (curState == 4) {
					writingMode = false;
					curState = 2;
					button3 = true;
					button5 = false;
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
	else if (windowState == 6) {
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
				if (curState == 0) resetWindow1();
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
				if (curState == 0 || curState == 3) resetWindow2();
				else if (curState == 1) {
					game->SaveGame(tempName);
					curState = 3;
					button4 = button5 = true;
				}
				else if (curState == 2 || curState == 4) resetWindow1();
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