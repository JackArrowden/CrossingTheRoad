// WindowsProject2.cpp : Defines the entry point for the application.
//
#include "BitMap.h"
#include "CGAME.h"


#define MAX_LOADSTRING 100


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

/*
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//HWND hwnd;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    HWND hwnd;
    static TCHAR szAppName[] = TEXT("test windows");
    MSG msg;
    WNDCLASS wndclass;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = CreatePatternBrush((HBITMAP)LoadImage(NULL, L"D:\\VS_test_projects\\win_api\\bitmap.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE));
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
    }

    hwnd = CreateWindow(szAppName, TEXT("Cross the road"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);

    // Disable minimize button
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(hwnd, GWL_STYLE, style);

    // Get window size
    RECT mainClientRect;
    GetClientRect(hwnd, &mainClientRect);

    UpdateWindow(hwnd);

    // Load background
    HWND background = CreateWindow(L"STATIC", L"background", SS_BITMAP | WS_CHILD | WS_VISIBLE, 0, 0, mainClientRect.right - mainClientRect.left, mainClientRect.bottom - mainClientRect.top, hwnd, NULL, NULL, NULL);
    HBITMAP hBmp = (HBITMAP)LoadImage(NULL, L"background.bmp", IMAGE_BITMAP, mainClientRect.right - mainClientRect.left, mainClientRect.bottom - mainClientRect.top, LR_LOADFROMFILE); // Load bitmap image
    int e = GetLastError();
    SendMessage(background, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);

    // Load play button
    int xStart = (mainClientRect.right - mainClientRect.left) / 2 - 175;
    int yStart = (mainClientRect.bottom - mainClientRect.top) / 2 - 50;
    HWND playButton = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP, xStart, yStart, 350, 100, background, (HMENU)1, NULL, NULL);
    HBITMAP hPlayBTN = (HBITMAP)LoadImage(NULL, L"playButton.bmp", IMAGE_BITMAP, 350, 100, LR_LOADFROMFILE);
    SendMessage(playButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hPlayBTN);


    HICON hIcon = (HICON)LoadImage(NULL, L"settings.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    HWND settingIcon = CreateWindowW(L"Button", L"Button Text", WS_VISIBLE | WS_CHILD | BS_ICON, 0, 0, 50, 50, background, NULL, NULL, NULL);
    SendMessage(settingIcon, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon);

    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return msg.wParam;
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        case 1:
            ::MessageBeep(MB_ICONERROR);
            ::MessageBox(hWnd, L"warning", L"warning", MB_OK);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        //...

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}*/

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;

	switch (uMsg) {
	case WM_CLOSE:
	case WM_DESTROY: {
		running = false;
	} break;

	case WM_SIZE: {
		RECT rect;
		GetClientRect(hwnd, &rect);
		int newWidth = rect.right - rect.left;
		int newHeight = rect.bottom - rect.top;
		render_state.resize(newHeight, newWidth);

	} break;

	default: {
		result = DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	}
	return result;
}

//void drawImage(const bitmapHandMake& image, Render_State&);

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	CGAME* game = new CGAME;
	game->tell();
	//ShowCursor(FALSE);
	bitmapHandMake bmpFile = readBitmapFile("background.bmp");
	bitmapHandMake button = readBitmapFile("playButton.bmp");
	bitmapHandMake train = readBitmapFile("train.bmp");
	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Window Class";
	window_class.lpfnWndProc = window_callback;

	// Register Class
	RegisterClass(&window_class);

	// Create Window
	HWND window = CreateWindow(window_class.lpszClassName, L"Cross Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
	//{
	//		//Fullscreen
	//		SetWindowLong(window, GWL_STYLE, GetWindowLong(window, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW);
	//		MONITORINFO mi = { sizeof(mi) };
	//		GetMonitorInfo(MonitorFromWindow(window, MONITOR_DEFAULTTOPRIMARY), &mi);
	//		SetWindowPos(window, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
	//	
	//}

	HDC hdc = GetDC(window);

	Input input = {};

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
	while (running) {
		// Input
		MSG message;

		for (int i = 0; i < BUTTON_COUNT; i++) {
			input.buttons[i].changed = false;
		}

		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {

			switch (message.message) {
			case WM_KEYUP:
			case WM_KEYDOWN: {
				u32 vk_code = (u32)message.wParam;
				bool is_down = ((message.lParam & (1 << 31)) == 0);

				#define process_button(b, vk)\
				case vk:\
					input.buttons[b].changed = is_down != input.buttons[b].is_down; \
					input.buttons[b].is_down = is_down; \
					break;

				switch (vk_code) {
					process_button(BUTTON_UP, VK_UP);
					process_button(BUTTON_DOWN, VK_DOWN);
					process_button(BUTTON_W, 'W');
					process_button(BUTTON_S, 'S');
					process_button(BUTTON_D, 'D');
					process_button(BUTTON_A, 'A');
					process_button(BUTTON_LEFT, VK_LEFT);
					process_button(BUTTON_RIGHT, VK_RIGHT);
					process_button(BUTTON_ENTER, VK_RETURN);
				}
			} break;

			default: {
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			}

		}


		//render_state.clearScreen(4319843);
		render_state.drawImageLT(bmpFile, 0, 0, 1);
		render_state.drawImageLT(button, 490, 50, 10);
		render_state.drawImageLT(train, 0, 0, 1, 16777215);
		//render_state.dynamicDrawReac(0.5, 0.5, 10, 20, 3248329);
		//render_state.drawReac2P(0, 100, 0, 100, 0xFFA500);
		//--x0;
		// Simulate
		// simulate_game(&input, delta_time);

		// Render
		StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

		LARGE_INTEGER frame_end_time;
		QueryPerformanceCounter(&frame_end_time);
		delta_time = (float)(frame_end_time.QuadPart - frame_begin_time.QuadPart) / performance_frequency;
		frame_begin_time = frame_end_time;
	}
	delete game;
	return 0;

}