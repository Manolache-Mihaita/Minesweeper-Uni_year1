// Minesweeper-Uni_year1.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define m_col 300
#define m_line 300
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define pos char(219)
#define gen_top char(205)
#define gen_side char(186)
#define gen_top_left char(201)
#define gen_top_right char(187)
#define gen_bot_left char(200)
#define gen_bot_right char(188)
#define c_bomb char(167)
using namespace std;

signed char mat_cout[300][300];
signed char mat_back[300][300];
int lin;
int col;
/*#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MINESWEEPERUNI_YEAR1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MINESWEEPERUNI_YEAR1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MINESWEEPERUNI_YEAR1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MINESWEEPERUNI_YEAR1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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
//  PURPOSE:  Processes messages for the main window.
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
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
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

*/
void gen_border(signed char mat[][300],int lin,int col) {
	unsigned char top = 205;
	unsigned char side = 186;
	unsigned char top_left = 201;
	unsigned char bot_left = 200;
	unsigned char top_right = 187;
	unsigned char bot_right = 188;

	for (int i = 0; i < col; i++) { 
		mat[0][i] = top;
		mat[lin - 1][i] = top;
	}
	for (int i = 0; i < lin; i++) {
		mat[i][0] = side;
		mat[i][col - 1] = side;
	}
	mat[0][0] = top_left;
	mat[lin-1][0] = bot_left;
	mat[0][col - 1] = top_right;
	mat[lin - 1][col - 1] = bot_right;
}
void rand_gen(long q) {
	 q = (rand() + time(0));
}
void gen_bombs(signed char mat[][300], int &Bombs, int lin, int col) {
	while (Bombs != 0) {
		int a = (rand() + time(0)) % lin;
		int b = (rand() + time(0)) % col;
		if (mat[a][b] != char(35)||mat[a][b]==char(48)) {
			while (mat[a][b] != char(35)) {
				a = (rand() + time(0)) % lin;
				b = (rand() + time(0)) % col;
			}
			mat[a][b] = 'B';
		}
		else mat[a][b] = 'B';
		Bombs--;
	}
}
void gen_numbers(signed char mat[][300], int lin, int col) {
	for (int i=0;i<lin;i++)
		for (int j = 0; j < col; j++) {
			int count = 0;
			if (mat[i][j] == char(35)) {
				if (mat[i - 1][j - 1] == 'B')count++;
				if (mat[i - 1][j] == 'B')count++;
				if (mat[i - 1][j + 1] == 'B')count++;
				if (mat[i][j - 1] == 'B')count++;
				if (mat[i][j + 1] == 'B')count++;
				if (mat[i + 1][j - 1] == 'B')count++;
				if (mat[i + 1][j] == 'B')count++;
				if (mat[i + 1][j + 1] == 'B')count++;
				if (count == 0)mat[i][j] = char(0);
				else mat[i][j] = count + '0';
			}
		}
}
void gen_start(signed char mat[][300], int lin, int col) {
	for (int i = 0; i < lin; i++)
		for (int j = 0; j < col; j++) {
			mat[i][j] = char(35);
		}
}
void gen_start_cout(signed char mat[][300], int lin, int col) {
	for (int i = 0; i < lin; i++)
		for (int j = 0; j < col; j++) {
			mat[i][j] = char(233);
		}
}
void draw(signed char mat[][300],int lin,int col) {
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}
	return;
}
//void if_pos_move(signed char mat_back[][300], signed char mat_cout[][300], int lin, int col, int i_c, int j_c)

// add to every function that calls this  lin and call or be a smartass and make em global
void uncover_area(signed char mat_back[][300], signed char mat_cout[][300], int i_c, int j_c) {
}
void if_pos_move(signed char mat_back[][300],signed char mat_cout[][300], int i_c, int j_c, unsigned char &o) {
	//if (mat_back[i_c][j_c] == 'B' || mat_back[i_c][j_c] == char(0))
	if (mat_back[i_c][j_c] <= '9'&& mat_back[i_c][j_c] >= '0') {
		mat_cout[i_c][j_c] = mat_back[i_c][j_c];
		o = mat_back[i_c][j_c];
	}
	if (mat_back[i_c][j_c] == char(0)) {
		uncover_area(mat_back, mat_cout, i_c, j_c);
		o = char(0);

	}
}
void move(signed char mat_cout[][300], int lin, int col, signed char mat_back[][300]) {
	unsigned char o;
	o = mat_cout[0][0];
	int i_c = 0;
	int j_c = 0;
	int c;
	mat_cout[0][0] = pos;
	while (1)
	{
		draw(mat_cout, lin, col);
		//Sleep(1000);
		switch ((c = _getch())) {
		case KEY_UP:
			mat_cout[i_c][j_c] = o;
			i_c--;
			if (i_c < 0)i_c = lin-1;
			i_c %= lin;
			o = mat_cout[i_c][j_c];
			mat_cout[i_c][j_c] = pos;
			system("CLS");
			//cout << endl << "Up" << endl;//key up
			//system("CLS");
			break;
		case KEY_DOWN:
			mat_cout[i_c][j_c] = o;
			i_c++;
			i_c %= lin;
			o = mat_cout[i_c][j_c];
			mat_cout[i_c][j_c] = pos;
			system("CLS");
			//cout << endl << "Down" << endl;   // key down
			//system("CLS");
			break;
		case KEY_LEFT:
			mat_cout[i_c][j_c] = o;
			j_c--;
			if (j_c < 0)j_c = col-1;
			j_c %= col;
			o = mat_cout[i_c][j_c];
			mat_cout[i_c][j_c] = pos;
			system("CLS");
			//cout << endl << "Left" << endl;  // key left
			//system("CLS");
			break;
		case KEY_RIGHT:
			mat_cout[i_c][j_c] = o;
			j_c++;
			j_c %= col;
			o = mat_cout[i_c][j_c];
			mat_cout[i_c][j_c] = pos;
			system("CLS");
			//cout << endl << "Right" << endl;  // key right
			//system("CLS");
			break;
			//default:
			//cout << endl << "null" << endl;  // not arrow
			//break;
		case KEY_ENTER:
			o = mat_cout[i_c][j_c];
			if_pos_move(mat_back, mat_cout, i_c, j_c, o);
			mat_cout[i_c][j_c] = o;
			system("CLS");
			break;
		default:cout << c;
		}

	}
}
void start() {
	signed char mat_back[300][300];
	signed int lin = 22;
	signed int col = 52;
	signed int Bombs = 80;
	gen_start(mat_back, lin, col);
	gen_border(mat_back, lin, col);
	gen_bombs(mat_back, Bombs, lin, col);
	gen_numbers(mat_back, lin, col);
	// cout for mat_back -- matrix with the numbers+bombs
	/*for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			cout << mat_back[i][j];
		}
		cout << '\n';
	}*/
	signed char mat_cout[300][300];
	gen_start_cout(mat_cout, lin, col);
	gen_border(mat_cout, lin, col);
	/*for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			cout << mat_cout[i][j];
		}
		cout << '\n';
	}

	//draw(mat_cout, lin, col);

	// display things? i hope so?*/
	move(mat_cout, lin, col, mat_back);



	}






int main() {

	start();
	/*int a = 1;
	while (a)
		if (GetKeyState('S') < 0) {
			cout << 100;
			break;
		}*/
	/*int c ;
	while (1)
	{
		Sleep(100);
		c;
		switch ((c = _getch())) {
		case KEY_UP:
			cout << endl << "Up" << endl;//key up
			break;
		case KEY_DOWN:
			cout << endl << "Down" << endl;   // key down
			break;
		case KEY_LEFT:
			cout << endl << "Left" << endl;  // key left
			break;
		case KEY_RIGHT:
			cout << endl << "Right" << endl;  // key right
			break;
		//default:
			//cout << endl << "null" << endl;  // not arrow
			//break;
		}

	}*/
	return 0;
	//use to clear console
	//system("CLS");

}