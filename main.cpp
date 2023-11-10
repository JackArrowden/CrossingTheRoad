// WindowsProject2.cpp : Defines the entry point for the application.
//
#include "BitMap.h"
#include "CGAME.h"

#define MAX_LOADSTRING 100

int windowState = 1;
int curState = 0;
int xTrain = 1200;
bool playClick = false, leaderClick = false, logoutClick = false, settingClick = false;
bitmapHandMake background1("Image\\background.bmp");
bitmapHandMake background2("Image\\gameBgr.bmp");
bitmapHandMake playBtn("Image\\playButton.bmp");
bitmapHandMake leaderBtn("Image\\leaderButton.bmp");
bitmapHandMake logoutBtn("Image\\logOutButton.bmp");
bitmapHandMake playRed("Image\\redPlayBtn.bmp");
bitmapHandMake leaderRed("Image\\redLeaderBtn.bmp");
bitmapHandMake logoutRed("Image\\redLogOutBtn.bmp");
bitmapHandMake train("Image\\train.bmp");
bitmapHandMake car("Image\\car.bmp");
bitmapHandMake setting("Image\\setting.bmp");
bitmapHandMake settingClicked("Image\\settingClicked.bmp");

static bool running = true;

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
void resetWindow1();
void resetWindow2();
void resetWindow3();
void apply(HWND);
//void drawImage(const bitmapHandMake& image, Render_State&);

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	CGAME* game = new CGAME;
	//game->tell();

	//ShowCursor(FALSE);
	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Window Class";
	window_class.lpfnWndProc = WindowProcedure;

	// Register Class
	RegisterClass(&window_class);

	// Main Window
	HWND window = CreateWindow(window_class.lpszClassName, L"Cross Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
	//{
	//		//Fullscreen
	//		SetWindowLong(window, GWL_STYLE, GetWindowLong(window, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW);
	//		MONITORINFO mi = { sizeof(mi) };
	//		GetMonitorInfo(MonitorFromWindow(window, MONITOR_DEFAULTTOPRIMARY), &mi);
	//		SetWindowPos(window, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
	//	
	//}


	while (running) {
		switch (windowState) {
		case 1:
			drawWindow1(window);
			break;
		case 2:
			drawWindow2(window);
			break;
		case 3:
			drawWindow3(window);
			break;
		default:
			break;
		}
		//render_state.clearScreen(4319843);

		//render_state.drawReac2P(0, 100, 0, 100, 0xFFA500);
		//--x0;
		// Simulate
		// simulate_game(&input, delta_time);

		// Render

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
	render_state.drawReverseImage(car, xTrain, 200, 1, DEFAULT_BACKGROUND_COLOR);
	if (xTrain > -1000) xTrain--;
	
	apply(hWnd);
}

void drawWindow3(HWND hWnd) {
	render_state.drawImage(car, 0, 0, 5);

	apply(hWnd);
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
	xTrain = 1200;
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
					break;
				case 1:
					resetWindow2();
					windowState = 2;
					break;
				case 2:
					windowState = 3;
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
			case VK_UP:
			{
				//if (curState > 0) curState--;
				//switch (curState) {
				//case 0:
				//	break;
				//case 1:
				//	redPlayBtn(hWnd);
				//	break;
				//case 2:
				//	redLeaderBtn(hWnd);
				//	break;
				//case 3:
				//	break;
				//default:
				//	break;
				//}
			}
			break;
			case VK_DOWN:
			{
				//if (curState < 3) curState++;
				//switch (curState) {
				//case 0:
				//	break;
				//case 1:
				//	redPlayBtn(hWnd);
				//	break;
				//case 2:
				//	redLeaderBtn(hWnd);
				//	break;
				//case 3:
				//	redLogOutBtn(hWnd);
				//	break;
				//default:
				//	break;
				//}
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
	}
}

/////////////////////////// CAN THEM CAC BIEN DE LUU DU LIEU VI TRI CAC DOI TUONG KHI LOAD GAME
/////////////////////////// XU LY AM THANH TRONG SETTING NHU THE NAO?