// Timer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Clock.h"
#include <strsafe.h>
#include "../../Lib/Shape/shape.h"


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

int ClientWidth = 1280;
int ClientHeight = 720;
int WindowWidth;
int WindowHeight;

UINT IDT_TIMER = 1;
int sec_counter = 0;
bool swch = true;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;
	///////////////////////////////////////////////////////////
	GraphicWindow GraphicWindow(hInst);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CLOCK, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLOCK));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLOCK));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_CLOCK);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
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
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	RECT WindowRect = { 0,0,ClientWidth,ClientHeight };

	AdjustWindowRect(&WindowRect, WS_OVERLAPPEDWINDOW, TRUE);

	WindowWidth = WindowRect.right - WindowRect.left;
	WindowHeight = WindowRect.bottom - WindowRect.top;


	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW&~WS_MAXIMIZEBOX,
		(GetSystemMetrics(SM_CXSCREEN) - WindowWidth) / 2, (GetSystemMetrics(SM_CYSCREEN) - WindowHeight) / 2,
		WindowWidth, WindowHeight, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	// Set the timer
	SetTimer(hWnd, IDT_TIMER, 1000, (TIMERPROC)NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;

	static HDC hdcMemDC;
	static HBITMAP hbmGraphicBuffer;
	static HANDLE hNewFont;
	static HANDLE hOldFont;
	static RECT MinRect = { 0,0,450,400 };
	static RECT SecRect = { 550,0,1000,400 };
	static HBRUSH hBackground;

	switch (message)
	{
	case WM_CREATE:
	{
		hdc = GetDC(hWnd);
		hdcMemDC = CreateCompatibleDC(hdc);

		hbmGraphicBuffer = CreateCompatibleBitmap(hdc, ClientWidth, ClientHeight);
		SelectObject(hdcMemDC, hbmGraphicBuffer);

		ReleaseDC(hWnd, hdc);

		SetRect(&rect, 0, 0, ClientWidth, ClientHeight);
		hBackground = CreateSolidBrush(RGB(0, 0, 255));
		FillRect(hdcMemDC, &rect, hBackground);


		hNewFont = CreateFont(400, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
		hOldFont = (HFONT)SelectObject(hdcMemDC, hNewFont);

		SetTextColor(hdcMemDC, RGB(255, 255, 255));
		SetBkColor(hdcMemDC, RGB(0, 0, 255));
		SetBkMode(hdcMemDC, TRANSPARENT/*OPAQUE*/);


		DrawTextA(hdcMemDC, "0", 1, &MinRect, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);

		SetRect(&rect, 450, 0, 550, 400);
		DrawTextA(hdcMemDC, ":", 1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		DrawTextA(hdcMemDC, "00", 2, &SecRect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);

		break;
	}
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_GETMINMAXINFO:

		LPMINMAXINFO lpMMI;
		lpMMI = (LPMINMAXINFO)lParam;
		lpMMI->ptMinTrackSize.x = WindowWidth;
		lpMMI->ptMinTrackSize.y = WindowHeight;
		lpMMI->ptMaxTrackSize.x = WindowWidth;
		lpMMI->ptMaxTrackSize.y = WindowHeight;

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		BitBlt(hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right - ps.rcPaint.left,
			ps.rcPaint.bottom - ps.rcPaint.top, hdcMemDC, ps.rcPaint.left, ps.rcPaint.top, SRCCOPY);

		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		if (swch) {
			sec_counter++;

			int sec;
			char buffer[3];

			sec = sec_counter % 60;

			if (!sec) {

				int min = sec_counter / 60;
				StringCchPrintfA(buffer, 3, "%i", min);
				size_t length;
				StringCchLengthA(buffer, 3, &length);
				FillRect(hdcMemDC, &MinRect, hBackground);
				DrawTextA(hdcMemDC, buffer, (int)length, &MinRect, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
				InvalidateRect(hWnd, &MinRect, FALSE);

			}

			StringCchPrintfA(buffer, 3, "%02i", sec);
			FillRect(hdcMemDC, &SecRect, hBackground);
			DrawTextA(hdcMemDC, buffer, 2, &SecRect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
			InvalidateRect(hWnd, &SecRect, FALSE);

			UpdateWindow(hWnd);

		}
		break;
	case WM_LBUTTONDOWN:
		swch = !swch;
		break;

	case WM_CHAR:

		switch (wParam)
		{
		case 'r': case 'R':
			sec_counter = 0;
			FillRect(hdcMemDC, &MinRect, hBackground);
			DrawTextA(hdcMemDC, "0", 1, &MinRect, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
			FillRect(hdcMemDC, &SecRect, hBackground);
			DrawTextA(hdcMemDC, "00", 2, &SecRect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);

			SetRect(&rect, 0, 0, 1000, 400);
			InvalidateRect(hWnd, &rect, FALSE);
			UpdateWindow(hWnd);
			break;
		default:
			break;
		}
		break;

	case WM_DESTROY:
		DeleteObject(hbmGraphicBuffer);
		SelectObject(hdcMemDC, hOldFont);
		DeleteObject(hNewFont);
		DeleteDC(hdcMemDC);
		DeleteObject(hBackground);
		//Destroy the timer
		KillTimer(hWnd, IDT_TIMER);
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