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
bool playClick = false, leaderClick = false, logoutClick = false, settingClick = false;
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
bitmapHandMake train_h("Image\\train_h.bmp");
bitmapHandMake train_p("Image\\train_p.bmp");
bitmapHandMake train_e("Image\\train_e.bmp");
bitmapHandMake person("Image\\person.bmp");
bitmapHandMake car("Image\\gameWindow\\car.bmp");

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

static bool running = true;
CPEOPLE player;
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
void resetWindow1();
void resetWindow2();
void resetSettingWindow();
void resetLeaderboardWindow();
void apply(HWND);
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

	if (!playClick) render_state.drawImage(playBtn, 490, 250, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(playRed, 490, 250, 10, DEFAULT_BACKGROUND_COLOR);

	if (!leaderClick) render_state.drawImage(leaderBtn, 490, 150, 10,DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(leaderRed, 490, 150, 10, DEFAULT_BACKGROUND_COLOR);

	if (!logoutClick) render_state.drawImage(logoutBtn, 490, 50, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(logoutRed, 490, 50, 10, DEFAULT_BACKGROUND_COLOR);

	if (!settingClick) render_state.drawImage(setting, 1180, 610, 10, DEFAULT_BACKGROUND_COLOR);
	else render_state.drawImage(settingClicked, 1180, 610, 10, DEFAULT_BACKGROUND_COLOR);

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
	render_state.drawImage(train_h, xTrain, 40, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_p, xTrain_p, 40, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_p, xTrain_p1, 40, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(train_e, xTrain_e, 40, 2, DEFAULT_BACKGROUND_COLOR);
	render_state.drawImage(person, player.GetmX(), player.GetmY(), 4, DEFAULT_BACKGROUND_COLOR);
	if (xTrain > -1000) {
		xTrain--; xTrain_p--; xTrain_p1--; xTrain_e--;
	}
	render_state.drawImage(car, xCar, 160, 1, DEFAULT_BACKGROUND_COLOR);
	if (xCar < 1300) xCar++;
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

void resetSettingWindow() {
	windowState = 3;
	curState = 0;
	gameSoundClick = false;
	objectSoundClick = false;
	backClick = false;
}

void resetLeaderboardWindow() {
	windowState = 4;
	curState = 0;
	backClick = false;
}

void resetWindow1() {
	windowState = 1;
	curState = 0;
	playClick = false;
	leaderClick = false;
	logoutClick = false;
	settingClick = false;
}

void resetWindow2() {
	windowState = 2;
	xTrain = 1200;
	xTrain_p = 1360;
	xTrain_p1 = 1594;
	xTrain_e = 1828;
	xCar = 0;
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
					resetWindow2();
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
						settingClick = true;
						playClick = false;
						break;
					case 1:
						playClick = true;
						leaderClick = false;
						break;
					case 2:
						leaderClick = true;
						logoutClick = false;
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
						settingClick = false;
						playClick = true;
						break;
					case 2:
						playClick = false;
						leaderClick = true;
						break;
					case 3:
						leaderClick = false;
						logoutClick = true;
						break;
					default:
						break;
					}
				}
				break;
			case VK_RIGHT:
				{
					if (curState > 0) curState = 0;
					settingClick = true;
					playClick = false;
					leaderClick = false;
					logoutClick = false;
				}
				break;
			case VK_LEFT:
				{
					if (curState == 0) curState++;
					settingClick = false;
					playClick = true;
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
	}
}

/////////////////////////// CAN THEM CAC BIEN DE LUU DU LIEU VI TRI CAC DOI TUONG KHI LOAD GAME
/////////////////////////// XU LY AM THANH TRONG SETTING NHU THE NAO?