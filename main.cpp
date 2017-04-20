#include "header.h"
#include "modules.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	system("mode con cols=60 lines=30");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO conCurInf;
	GetConsoleCursorInfo(hStdOut, &conCurInf);
	conCurInf.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &conCurInf);
	home();
}
