// WindowsProject2.cpp : Defines the entry point for the application.
//
#include "BitMap.h"
#include "CGAME.h"
#include "fileHandling.h"

#define MAX_LOADSTRING 100

int windowState = 1;
int curState = 0;
int xTrain = 1200;
int xTrain_p = 1360;
int xTrain_p1 = 1594;
int xTrain_e = 1828;
int xCar = 0;
bool button1 = false, button2 = false, button3 = false, button4 = false, button5 = false;
bool gameSoundClick = false, objectSoundClick = false, gameSound = true, objectSound = true, backClick = false, gameSoundClick_temp = false;
bool isDataChanged = false; // This variable is used to check if the user's data is changed or not, if changed, calls sort function

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
bitmapHandMake train_p("Image\\gameWindow\\train_p.bmp");
bitmapHandMake train_e("Image\\gameWindow\\train_e.bmp");
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
string tempName = "";
char tempNameChar[1000];
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

static bool running = true;
CPEOPLE player;
CAR Car(1000, 160, -1);
CAT Cat(1500, 300, -1);
CMOUSE Mouse(1000, 300, -1);
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
void resetWindow1();
void resetWindow2();
void resetSettingWindow();
void resetLeaderboardWindow();
void resetEnterGameWindow();
void apply(HWND);
void resetBtn();
//void drawImage(const bitmapHandMake& image, Render_State&);

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	//vector<userData> listUser(10);
	//userFileToVect("USER", listUser);
	//sortDescendingData(listUser);

	CGAME* game = new CGAME;
	//game->tell();

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

	while (running) {
		if (gameSoundClick_temp) {
			if (gameSound) {
				game->tell();
			} else {
				PlaySound(0, NULL, 0);
			}
			gameSoundClick_temp = false;
		}

		switch (windowState) {
			case 1:
				drawWindow1(window);
				break;
			case 2:
				drawWindow3(window);
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

	if (!button3) render_state.drawImage(leaderBtn, 490, 150, 10,DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(leaderRed, 490, 150, 10, DEFAULT_BACKGROUND_COLOR);

	if (!button4) render_state.drawImage(logoutBtn, 490, 50, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(logoutRed, 490, 50, 10, DEFAULT_BACKGROUND_COLOR);

	apply(hWnd);
}

void drawWindow2(HWND hWnd) {
	render_state.drawImage(background2, 0, 0, 1);
	render_state.drawImage(train_h, xTrain, 350, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_p, xTrain_p, 350, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_p, xTrain_p1, 350, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_e, xTrain_e, 350, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(person, player.GetmX(), player.GetmY(), 3, DEFAULT_BACKGROUND_COLOR);
	if (xTrain > -1000) {
		xTrain--; xTrain_p--; xTrain_p1--; xTrain_e--;
	}
	render_state.drawImage(car, xCar, 80, 1, DEFAULT_BACKGROUND_COLOR);
	if (xCar < 1300) xCar++;
	apply(hWnd);
}

void drawWindow3(HWND hWnd) {
	render_state.drawImage(background_city, 0, 0, 1);
	render_state.draw_text("HELLO", -73, 40, 1, 0xffffff);
	Cat.draw(render_state);
	Cat.Move(1);
	Mouse.draw(render_state);
	Mouse.Move(1);

	render_state.drawImage(train_h, xTrain, 40, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_p, xTrain_p, 40, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_p, xTrain_p1, 40, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_e, xTrain_e, 40, 2, DEFAULT_BACKGROUND_COLOR);
	player.draw(render_state);
	if (xTrain > -1000) {
		xTrain--; xTrain_p--; xTrain_p1--; xTrain_e--;
	}
	Car.draw(render_state);
	Car.Move(1);
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

	if (writingMode) {
		int index = 0;
		for (auto i : tempName) {
			tempNameChar[index] = i;
			index++;
		}
		tempName[index] = '\0';
		render_state.draw_text(tempNameChar, -50, -25, 1, 0xcccccc);
	}

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

void resetBtn() {
	curState = 0;
	button1 = button2 = button3 = button4 = button5 = false;
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
			switch (key)
			{
			case VK_0:
				tempName += '0';
				break;
			case VK_1:
				tempName += '1';
				break;
			case VK_2:
				tempName += '2';
				break;
			case VK_3:
				tempName += '3';
				break;
			case VK_4:
				tempName += '4';
				break;
			case VK_5:
				tempName += '5';
				break;
			case VK_6:
				tempName += '6';
				break;
			case VK_7:
				tempName += '7';
				break;
			case VK_8:
				tempName += '8';
				break;
			case VK_9:
				tempName += '9';
				break;
			case VK_A:
				tempName += 'A';
				break;
			case VK_B:
				tempName += 'B';
				break;
			case VK_C:
				tempName += 'C';
				break;
			case VK_D:
				tempName += 'D';
				break;
			case VK_E:
				tempName += 'E';
				break;
			case VK_F:
				tempName += 'F';
				break;
			case VK_G:
				tempName += 'G';
				break;
			case VK_H:
				tempName += 'H';
				break;
			case VK_I:
				tempName += 'I';
				break;
			case VK_J:
				tempName += 'J';
				break;
			case VK_K:
				tempName += 'K';
				break;
			case VK_L:
				tempName += 'L';
				break;
			case VK_M:
				tempName += 'M';
				break;
			case VK_N:
				tempName += 'N';
				break;
			case VK_O:
				tempName += 'O';
				break;
			case VK_P:
				tempName += 'P';
				break;
			case VK_Q:
				tempName += 'Q';
				break;
			case VK_R:
				tempName += 'R';
				break;
			case VK_S:
				tempName += 'S';
				break;
			case VK_T:
				tempName += 'T';
				break;
			case VK_U:
				tempName += 'U';
				break;
			case VK_V:
				tempName += 'V';
				break;
			case VK_W:
				tempName += 'W';
				break;
			case VK_X:
				tempName += 'X';
				break;
			case VK_Y:
				tempName += 'Y';
				break;
			case VK_Z:
				tempName += 'Z';
				break;
			default:
				writingMode = false;
				break;
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
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_CREATE:
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
					case 2:
						button3 = true;
						button4 = false;
						break;
					default:
						break;
					}
				}
				break;
			case VK_DOWN:
				{
					if (curState < 3) curState++;
					switch (curState) {
					case 1:
						button1 = false;
						button2 = true;
						break;
					case 2:
						button2 = false;
						button3 = true;
						break;
					case 3:
						button3 = false;
						button4 = true;
						break;
					default:
						break;
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
	} else if (windowState == 2) {
		switch (msg)
		{
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_CREATE:
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
				resetWindow1();
				drawWindow1(hWnd);
			break;
			case VK_A:
			{
				player.Left(10);
				
			}
			break;
			case VK_D:
			{
				player.Right(10);
				
			}
			break;
			case VK_S:
			{
				player.Down(10);

			}
			break;
			case VK_W:
			{
				player.Up(10);

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
		}
		break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
		}
	} else if (windowState == 3) {
		switch (msg)
		{
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_CREATE:
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
	} else if (windowState == 4) {
		switch (msg)
		{
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_CREATE:
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
	} else if (windowState == 5) {
		switch (msg)
		{
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
			PostQuitMessage(0);
		} break;
		case WM_CREATE:
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
					writingMode = true;
					tempName = "";
					break;
				case 1:
					writingMode = true;
					tempName = "";
					break;
				case 2:
					resetWindow2();
					break;
				case 3:
					resetWindow2();
					break;
				case 4:
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
					curState = 1;
					button2 = true;
					button1 = false;
					break;
				case 2:
					curState = 0;
					button1 = true;
					button3 = false;
					break;
				case 3:
					curState = 1;
					button2 = true;
					button4 = false;
					break;
				case 4:
					curState = 3;
					button4 = true;
					button5 = false;
				default:
					break;
				}
			}
			break;
			case VK_DOWN:
			{
				switch (curState) {
				case 0:
					curState = 2;
					button1 = false;
					button3 = true;
					break;
				case 1:
					curState = 3;
					button2 = false;
					button4 = true;
					break;
				case 3:
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
					curState = 1;
					button2 = true;
					button1 = false;
				} else if (curState == 2) {
					curState = 4;
					button5 = true;
					button3 = false;
				}
			}
			break;
			case VK_LEFT:
			{
				if (curState == 1 || curState == 3) {
					curState = 0;
					button1 = true;
					button2 = button4 = false;
				} else if (curState == 4) {
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
}

/////////////////////////// CAN THEM CAC BIEN DE LUU DU LIEU VI TRI CAC DOI TUONG KHI LOAD GAME
/////////////////////////// XU LY AM THANH TRONG SETTING NHU THE NAO?