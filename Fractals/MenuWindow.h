#include <Windows.h>
#include <CommCtrl.h>

static HWND mainWindow, sierpinskiButton, cantorButton, hWndComboBox;
static int idSelected;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void SetupWindowsClass(HINSTANCE);

HWND CreateButton(HWND, int, int, LPCWSTR);

HWND CreateComboBox(HWND, int, int);

template<int size>
void FillComboBox(HWND, LPWSTR(parameters)[size]);