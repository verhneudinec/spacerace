#include "header.h"
#include "modules.h"
#include <sys/stat.h>
#include "fstream" 
struct rec {
	char name[25];
	int points;
};
int t = 0;
int timer(){
	t++;
	return 60-t/40;
}
void game(int p) {
	if (p == 2) { 
		ship s1(1);
		ship s2(2);
		asteroid *a = new asteroid[20];
		while (timer>0) {
			s2.display();	checkblow(a, s2);	
			s1.display();	checkblow(a, s1);
			for (int q = 0; q < 20; q++) a[q].display();
			checkdefeat(s1, s2);
			Sleep(50);
			setcurpos(34, 27);
			cout << " ";
		}
	}
	else {
		ship s(3);
		asteroid *a = new asteroid[20];
		while (timer>0) {
			s.display(); checkblow(a, s);
			for (int q = 0; q < 20; q++)  a[q].display();
			checkdefeat(s);
			Sleep(50);
			setcurpos(34, 27);
			cout << " ";
		}
	}

}

void checkblow(asteroid *a, ship &s) {
	for (int w = 0; w < 20; w++)
	{
		if ((s.positionX - a[w].positionX <= 0) && (s.positionX - a[w].positionX >= -4) && (s.positionY == a[w].positionY)) {
			s.positionY = 25;
			s.Vy = 0;
			t += 200;
			cout << "    [-4 �������]";
			cout << "\a";
			Sleep(1000);
			system("cls");
		}
	}
}


void checkdefeat(ship &s) {
	if (timer()<=0)
	{
		
		setcurpos(0, 27);
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 12));
		cout << "���� �������� (!)" << endl;
		Sleep(1500);
		system("pause");
		int temp = s.getspacepoints();
		cout << "����: " << temp << endl << "������� ���� ���: ";
		writerec(temp);
	}
}

void checkdefeat(ship &s1, ship &s2) {
	if (timer() <= 0) {
		setcurpos(0, 27);
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 12));
		cout << "���� �������� (!)" << endl;
		if (s1.getspacepoints() > s2.getspacepoints())
		{
			cout << "1 ����� �������!" << endl;
		}
		else if(s1.getspacepoints() < s2.getspacepoints()) {
			cout << "2 ����� �������!" << endl;
		}
		Sleep(1500);
		system("pause");
		int temp = (s2.getspacepoints() + s1.getspacepoints()) / 2;
		cout << "����� ����: " << temp << endl << "������� �������� �������: ";
		writerec(temp);
		go2main();
	}
}

void writerec(int &pscore) {
	struct stat filesize;
	stat("spacetop.txt", &filesize);
	if (filesize.st_size == 0) {
		ofstream d("spacetop.txt");
		d << "������ " << 30 << endl;
		d << "CJIoHuK " << 22 << endl;
		d << "IceStorm " << 19 << endl;
		d << "V1tam1nk0 " << 10 << endl;
		d << "KyKyPy3a " << 3 << endl;
		d.close();
	}

	rec*ords = new rec[6];
	cin >> ords[5].name;
	ords[5].points = pscore;
	ifstream f("spacetop.txt");
	if (f)
	{
		int i = 0;
		while (!f.eof())
		{
			char temp[25];
			f.getline(temp, 30, '\n');
			sscanf(temp, "%s%d", ords[i].name, &ords[i].points);
			i++;
		}
	}
	else cout << "\n�� ������� ������� ���� (!)\n";
	f.close();

	for (int j = 0; j < 6; j++) {

		for (int k = 0; k < 5; k++) {
			if (ords[k].points < ords[k + 1].points) {
				rec temp;
				temp = ords[k];
				ords[k] = ords[k + 1];
				ords[k + 1] = temp;
			}
		}
	}
	ofstream g("spacetop.txt");
	for (int j = 0; j < 5; j++) {
		g << ords[j].name << " " << ords[j].points << endl;
	}
	g.close();
	go2main();

}