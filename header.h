#pragma once
#define setcurpos(x,y) HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); COORD c; c.X = x; c.Y = y; SetConsoleCursorPosition(hStdOut, c);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;