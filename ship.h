#include "header.h"

extern int t;
extern int timer();

class ship 
{
	string s;
	int positionX;
	int positionY; 
	int Vy;
	int num;
	int spacepoints;
	int cosmiclife;

	public:
	
	ship(int n)
	{
		s = "_/|\\_";
		if (n == 1) positionX = 34;
		if (n == 2) { positionX = 20;	s = "</|\\>"; }
		if (n == 3) positionX = 27;
		spacepoints = 0;
		positionY = 25;
		Vy = 0;
		num = n;
	}

	void display() 
	{
		kbht();
		moving();
		setcurpos(positionX, positionY);
		cout << s;
		escape();
		board();
	}

	void escape() 
	{
		if ((positionY < 2)||(positionY > 25))
		{
			if (positionY < 2) 
			{ 
				spacepoints++; cout << "    [+1 поинт, +2 секунды]"; t -= 100; Sleep(1000); 
			}
			positionY = 25;
			Vy = 0;
			system("cls");
		}
		
	}

	void moving() 
	{
		setcurpos(positionX, positionY);
		cout << "     ";
		positionY += Vy;
		Vy = 0;
	}

	int getspacepoints() 
	{
		return spacepoints;
	}

	void board() 
	{
		setcurpos(positionX - 1, 0);
		cout << "очки: " << spacepoints;
		c.X = 25; c.Y = 27; SetConsoleCursorPosition(hStdOut, c);
		cout << "таймер: " << timer();
	}

	void kbht();

	friend void checkblow(class asteroid *, class ship &);

};
