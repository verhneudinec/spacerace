#include "header.h"
#include "modules.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO conCurInf;
	GetConsoleCursorInfo(hStdOut, &conCurInf);
	conCurInf.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &conCurInf);
	CONSOLE_FONT_INFOEX fontInf;
	fontInf.cbSize = sizeof(fontInf);
	GetCurrentConsoleFontEx(hStdOut, TRUE, &fontInf);
	wcscpy(fontInf.FaceName, L"Consolas");
	fontInf.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(hStdOut, TRUE, &fontInf);
	system("mode con cols=60 lines=30");
	
	home();
}
