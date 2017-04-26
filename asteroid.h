#include "header.h"

class asteroid 
{
	string s;
	int positionX;
	int positionY; 
	float Vx;
	
	public:
	
	asteroid() 
	{
		s = "*";
		positionX = 0 + rand() % 60;
		positionY = 3 + rand() % 20;
		Vx = -1;
	}
	
	void display() 
	{
		moving();
		setcurpos(positionX, positionY);
		cout << s;
		escape();
		cout << " ";
	}
	
	void escape() 
	{
		if (positionX < 1)
		{   
			setcurpos(positionX, positionY);
			cout << " ";
			positionX = 60;
			positionY = 2 + rand() % 20;
		}
	}
	
	void moving() 
	{
		positionX += int(Vx);
	}
	
	friend void checkblow(class asteroid *, class ship &);
	
};
