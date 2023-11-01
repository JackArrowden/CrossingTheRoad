// WindowsProject2.cpp : Defines the entry point for the application.
//

#include "CGAME.h"

#define MAX_LOADSTRING 100

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
}