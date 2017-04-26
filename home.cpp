#include "header.h"
#include "modules.h"
#include <conio.h>
#include "fstream"

void main();

void home() 
{

	int text = 7, background = 0;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int flag = 0, key = 0;

	while (flag == 0)
	{
		int x = 1;
		while (key != 13) 
		{
			SetConsoleTextAttribute(hStdOut, 11);
			cout << " ]]]]  ]]]]]   ]]]]   ]]]]  ]]]]]\n]]     ]]  ]] ]]  ]] ]]  ]] ]]\n ]]]]  ]]]]]  ]]]]]] ]]     ]]]]\n    ]] ]]     ]]  ]] ]]  ]] ]]\n ]]]]  ]]     ]]  ]]  ]]]]  ]]]]]" << endl << endl << "]]]]]   ]]]]   ]]]]  ]]]]]\n]]  ]] ]]  ]] ]]  ]] ]]\n]]]]]  ]]]]]] ]]     ]]]]\n]]  ]] ]]  ]] ]]  ]] ]]\n]]  ]] ]]  ]]  ]]]]  ]]]]]" << endl << endl << endl;

			text = 7; background = 0; if (x == 1) { text = 0; background = 14; }
			SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
			cout << "1. Одиночная игра \n\n";

			text = 7; background = 0; if (x == 2) { text = 0; background = 13; }
			SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
			cout << "2. Игра с другом \n\n";

			text = 7; background = 0; if (x == 3) { text = 0; background = 10; }
			SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
			cout << "3. Помощь \n\n";

			text = 7; background = 0; if (x == 4) { text = 0; background = 11; }
			SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
			cout << "4. Таблица рекордов \n\n";

			text = 7; background = 0; if (x == 5) { text = 0; background = 12; }
			SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
			cout << "5. Выход \n\n";

			text = 7; background = 0;
			SetConsoleTextAttribute(hStdOut, (WORD)((background << 12) | text));

			while (true)
			{
				key = _getch(); if (key == 224)key = _getch(); if (key == 72 || key == 80 || key == 13)break;
			}

			if (key == 72) { x--; if (x == 0)x = 5; }
			if (key == 80) { x++; if (x == 6)x = 1; }
			system("cls");
		} key = 0;
		switch (x)
		{
		case 1: { system("cls"); game(1); break; }
		case 2: { system("cls"); game(2); break; }
		case 3: { system("cls"); help(); break; }
		case 4: { system("cls"); seerec(); break; }
		case 5: { system("cls"); exit(0); break; }
		}
	}
}

void go2main() 
{
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, (WORD)((14 << 4) | 0));
	cout << "\n\n-> Меню (Enter)";
	int x = 1;	int key = _getch();
	if (key == 13) main();
}

void help() 
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, 14);
	cout << "\n]]]]]]   ]]]]   ]]   ]]   ]]]]   ]]   ]]  ]]\n]]  ]]  ]]  ]]  ]]] ]]]  ]]  ]]  ]]   ]]  ]]\n]]  ]]  ]]  ]]  ]] ] ]]  ]]  ]]  ]] ] ]]  ]]]]\n]]  ]]  ]]  ]]  ]]   ]]  ]]  ]]  ]] ] ]]  ]]  ]]\n]]  ]]   ]]]]   ]]   ]]   ]]]]   ]]]]] ]] ]]]]]\n\n";
	cout << "Правила: " << "\n- за пролет через все поле +1 космический поинт и +2 секунды;\n- за столкновение с астероидом -4 секунды.\n\n";
	cout << "Управление: " << "\n1 игрок: стрелки;\n2 игрок: w, a, s, d.";
	go2main();
}

void seerec() 
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, 11);
	cout << "\n######  ####  ######    #####\n  ##   ##  ## ##  ##    ##\n  ##   ##  ## ##  ##    #####\n  ##   ##  ## ##  ##        ##\n  ##    ####  ##  ##    #####\n\n" << endl;
	ifstream f("spacetop.txt");
	if (f)
	{
		int n = 1;
		while (n<6)
		{
			char temp[30];
			f.getline(temp, 255, '\n');
			cout << n << ". " << temp << endl;
			n++;
		}

	}
	else cout << "\nВы еще не играли (!)\n";
	f.close();
	go2main();
}
