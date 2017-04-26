#include <iostream>
#include "ship.h"
#include <conio.h>

void ship::kbht() 
{
	int a = 0;
	if (_kbhit())
	{
		a = _getch();
		if (num == 2) 
		{
			if ((a == 119) || (a == 230)) Vy = -1;
			if ((a == 115) || (a == 235)) Vy = 1;
		}
		else
		{
			if (a == 72) Vy = -1;
			if (a == 80) Vy = 1;
		}
	}
}
