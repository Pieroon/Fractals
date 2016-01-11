#include "MenuWindow.h"
#include "SierpinskiCarpet.h"
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, 
				   HINSTANCE hPrevInstance, 
				   LPSTR lpCmdLine, 
	               int nCmdShow)
{
	MSG msg;
	SetupWindowsClass(hInstance);

	mainWindow = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		L"Fractals",
		L"Tutorial",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		350,
		250,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (mainWindow == NULL)
	{
		LPCWSTR Error02 = L"Could not create window!";
		LPCWSTR Error02_Caption = L"Error";
		MessageBox(NULL, Error02, Error02_Caption, MB_OK | MB_ICONERROR);
	}

	ShowWindow(mainWindow, nCmdShow);
	UpdateWindow(mainWindow);

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LPWSTR parameters[6] = { L"Opcja 1", L"Opcja 2", L"Opcja 3", L"Opcja 4", L"Opcja 5", L"Opcja 6" };
	switch (Msg)
	{
	case WM_CREATE:
		sierpinskiButton = CreateButton(hwnd, 10, 10, L"Sierpinski");
		cantorButton = CreateButton(hwnd, 200, 10, L"Cantor");
		hWndComboBox = CreateComboBox(hwnd, 10, 70);
		FillComboBox<6>(hWndComboBox, parameters);
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case BN_CLICKED:
			if (sierpinskiButton == (HWND)lParam)
			{
				SierpinskiCarpet::CreateNew(603, 603, idSelected);
			}
			break;
		}

		switch (HIWORD(wParam))
		{
		case CBN_DROPDOWN:
			break;
		case BN_CLICKED:
			break;
		case CBN_SELCHANGE:
			idSelected = SendMessage(hWndComboBox, CB_GETCURSEL, (WPARAM)0, (LPARAM)0);		
			break;
		}
	}

	default:
		return DefWindowProc(hwnd, Msg, wParam, lParam);
	}
	return 0;
}

void SetupWindowsClass(HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"Fractals";
	wc.hIconSm = LoadIcon(NULL, IDC_ICON);
	wc.hIcon = LoadIcon(NULL, IDC_ICON);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	if (!RegisterClassEx(&wc))
	{
		LPWSTR Error01 = L"Could not register class";
		LPWSTR Error01_Caption = L"Error";
		MessageBox(NULL, Error01, Error01_Caption, MB_OK | MB_ICONERROR);
	}
}

HWND CreateButton(HWND hwndParent, int x, int y, LPCWSTR buttonText)
{
	return CreateWindow(
		L"BUTTON",
		buttonText,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		x,
		y,
		100,
		50,
		hwndParent,
		NULL,
		(HINSTANCE)GetWindowLong(hwndParent, GWL_HINSTANCE),
		NULL);
}

HWND CreateComboBox(HWND hwndParent, int x, int y)
{
	return CreateWindowEx(
		0,
		WC_COMBOBOX,
		0,
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | WS_VSCROLL,
		x,
		y,
		100,
		100,
		hwndParent,
		NULL,
		(HINSTANCE)GetWindowLong(hwndParent, GWL_HINSTANCE),
		NULL);
}

template<int size>
inline void FillComboBox(HWND comboBox, LPWSTR(parameters)[size])
{
	for each(LPWSTR parameter in parameters)
	{
		SendMessage(comboBox, CB_ADDSTRING, 0, (LPARAM)parameter);
	}
	SendMessage(comboBox, CB_SETCURSEL, 0, 0);
}
