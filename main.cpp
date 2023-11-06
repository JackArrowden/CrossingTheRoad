// WindowsProject2.cpp : Defines the entry point for the application.
//
#include "BitMap.h"
#include "CGAME.h"


#define MAX_LOADSTRING 100

int windowState = 1;
int curState = 0;
int xTrain = 1200;

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
		if (windowState == 1) drawWindow1(window);
		else if (windowState == 2) {
			drawWindow2(window);
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
	//return msg.wParam;
}

void drawWindow1(HWND hWnd) {
	bitmapHandMake bmpFile("background.bmp");
	bitmapHandMake button1("playButton.bmp");
	bitmapHandMake button2("leaderButton.bmp");
	bitmapHandMake button3("logOutButton.bmp");
	render_state.drawImageBT(bmpFile, 0, 0, 1);
	render_state.drawImageBT(button1, 490, 250, 10);
	render_state.drawImageBT(button2, 490, 150, 10);
	render_state.drawImageBT(button3, 490, 50, 10);

	apply(hWnd);
}

void drawWindow3(HWND hWnd) {
	bitmapHandMake car("car.bmp");
	render_state.drawImageBT(car, 0, 0, 5);

	apply(hWnd);
}

void drawWindow2(HWND hWnd) {
	bitmapHandMake bmpFile2("gameBgr.bmp");
	//bitmapHandMake car = readBitmapFile("car.bmp");
	render_state.drawImageBT(bmpFile2, 0, 0, 1);
	//render_state.drawImageLT(car, 0, 0, 5);
	bitmapHandMake train("car.bmp");
	render_state.drawImageBT(train, xTrain, 200, 1, 16777215);
	if (xTrain > -1000) xTrain--;

	apply(hWnd);
}

void redPlayBtn(HWND hWnd) {
	bitmapHandMake play("redPlayBtn.bmp");
	bitmapHandMake button1("leaderButton.bmp");
	bitmapHandMake button2("logOutButton.bmp");
	render_state.drawImageBT(play, 490, 250, 10);
	render_state.drawImageBT(button1, 490, 150, 10);
	render_state.drawImageBT(button2, 490, 50, 10);

	apply(hWnd);
}

void redLeaderBtn(HWND hWnd) {
	bitmapHandMake button1("playButton.bmp");
	bitmapHandMake leader("redLeaderBtn.bmp");
	bitmapHandMake button2("logOutButton.bmp");
	render_state.drawImageBT(button1, 490, 250, 10);
	render_state.drawImageBT(leader, 490, 150, 10);
	render_state.drawImageBT(button2, 490, 50, 10);

	apply(hWnd);
}

void redLogOutBtn(HWND hWnd) {
	bitmapHandMake button1("playButton.bmp");
	bitmapHandMake button2("leaderButton.bmp");
	bitmapHandMake logout("redLogOutBtn.bmp");
	render_state.drawImageBT(button1, 490, 250, 10);
	render_state.drawImageBT(button2, 490, 150, 10);
	render_state.drawImageBT(logout, 490, 50, 10);

	apply(hWnd);
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

	int x0 = 1500;
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
		//case WM_DESTROY:
		//	break;
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
					windowState = 2;
					break;
				case 2:
				drawWindow3(hWnd);
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
						break;
					case 1:
					redPlayBtn(hWnd);
						break;
					case 2:
					redLeaderBtn(hWnd);
						break;
				case 3:
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
				case 0:
					break;
					case 1:
					redPlayBtn(hWnd);
						break;
					case 2:
					redLeaderBtn(hWnd);
						break;
					case 3:
					redLogOutBtn(hWnd);
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
	//case WM_KEYDOWN: {
	//	int vk_code = LOWORD(wParam);
	//	bool is_down = ((vk_code & (1 << 31)) == 0);

	//#define process_button(b, vk)\
	//	case vk:\
	//		input.buttons[b].changed = is_down != input.buttons[b].is_down; \
	//		input.buttons[b].is_down = is_down; \
	//		break;

	//	switch (vk_code) {
	//		process_button(BUTTON_UP, VK_UP);
	//		process_button(BUTTON_DOWN, VK_DOWN);
	//		process_button(BUTTON_W, 'W');
	//		process_button(BUTTON_S, 'S');
	//		process_button(BUTTON_D, 'D');
	//		process_button(BUTTON_A, 'A');
	//		process_button(BUTTON_LEFT, VK_LEFT);
	//		process_button(BUTTON_RIGHT, VK_RIGHT);
	//		process_button(BUTTON_ENTER, VK_RETURN);
	//	}
	//} break;
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
			//case WM_DESTROY:
			//	break;
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
				curState = 0;
				windowState = 1;
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
