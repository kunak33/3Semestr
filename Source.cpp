// FZVO.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
// ��� ���������� ����������. ��� Windows 10 � ��������� ����������� ���� ����� ���������� ������ 
// "������������ ������� ������ �������" 

/*
���� �������� �������� ������ MyRect - �������������.
1. ��������� ���� �����, �������� ���������, ������������
�� ������ �������� �������������.�������� �����, ������� �����
����� �������.
2. ������� ��� ����� ������, ����������� �� MyRect : ������ �
������ ������� MyRect - �������������, ��������� ��������� �������
�������� �������, ���� � ����� ����������, �� ���� ������������ ������,
���������� ����� �� ����������.
��������� ���������, ������������ �� ����� �������� ����
�������� �������������, � �� ������ - �������� ������.
3. ������� ����� ����� "�����", ������� ��� �� �������� ��� ����
��� ��� ����� � ��������� ������ ���� ������ �������, ����� �������
������� ���������� �������� ��� ������������� ����� �� �������, ���������
� ���������� ���������� ������ 2. ������� ����������� ������ � ����� ���������
(����� ������� �� 4 �����) � ��� ���������� ��������� �������� ���� ���������.
*/

#include <windows.h>
#include <conio.h>
#include <time.h>

class MyRect                 //��� ������� "�������������"
{

private:

	// �� ������� ���� ������ �� ����� ������ ��� ��������� �� ������� ���������� 
	// ���������� ��� � ������� int sizex, siz��; ����� ����� ������ ������������ ����� �������� ��� ��������� ������������� �� ����� ��� ��������� ����� � ������ ����������, ��� �� � ������� )





	int visible;		        //���� ���������
public:
	int filled;			        //���� ��������
	int fillstyle;          //������ ��������
	int color; 	            //����
	int sizex, sizey; 		  //�������

	int x, y;			          //���������� ������
	//    (������������, ������������ , ������ , ������ , ����, ��� �������)
	MyRect(int initx, int inity, int initsizex, int initsizey, int initcolor, int initfillstyle);
	// ��������� ��������� ����������  ��������������
	virtual void show(HDC hdc);
	// ����������� �������������  �� ������
	virtual void hide(HDC hdc,int color);
	// ����� �����������  ��������������
	int isvisible();
	// ���������� �������� ����� ���������
	int isfilled();
	// ���������� �������� ����� ��������
	int getfillstyle();
	// ���������� �������� ������� ��������
	int getfigurecolor();
	// ���������� �������� ����� ��������������
	int getx();
	// ���������� X ���������� ������
	int gety();
	// ���������� Y ���������� ������
	int getwidth();
	// ���������� ������ �������������� �� ��� X
	int getheight();
	// ���������� ������ �������������� �� ��� Y
	void setvisibilityflag(int newvisible);
	// ������������� ���� ��������� �������
	void setfillflag(int newfilled);
	// ������������� ���� �������� �������
	void setfillstylem(int initfillstyle);
	// ������������� ������ �������� �������
	void setfigurecolor(int newcolor);
	// ������������� ���� �������
};

//************ ������� rect  **************

MyRect::MyRect(int initx, int inity, int initsizex, int initsizey,
	int initcolor, int initfillstyle)
{
	x = initx; y = inity;
	sizex = initsizex; sizey = initsizey;
	color = initcolor;
	visible = 1;
	fillstyle = initfillstyle;
	filled = 1;
}

void MyRect::show(HDC hdc) //����������� ������ �� ������
{
	if (filled)
	{
		HBRUSH hb = CreateHatchBrush(fillstyle, color);
		RECT r = { x - sizex / 2, y - sizey / 2, x + sizex / 2, y + sizey / 2 };
		FillRect(hdc, &r, hb);
		DeleteObject(hb);
	}
	else
	{
		HPEN hpen = CreatePen(PS_SOLID, 3, color);
		HPEN hp = (HPEN)SelectObject(hdc, hpen);
		MoveToEx(hdc, x - sizex / 2, y - sizey / 2, NULL);
		LineTo(hdc, x + sizex / 2, y - sizey / 2);
		LineTo(hdc, x + sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y - sizey / 2);
		DeleteObject(hpen);
	}
}

void MyRect::hide(HDC hdc,int color) // ����� ����������� �������
{
	if (filled)
	{
		HBRUSH hbr = CreateSolidBrush(color);
		RECT r = { x - sizex / 2, y - sizey / 2, x + sizex / 2, y + sizey / 2 };
		FillRect(hdc, &r, hbr);
		DeleteObject(hbr);
	}
	else
	{
		HPEN hpen = CreatePen(PS_SOLID, 3, 0);
		HPEN hp = (HPEN)SelectObject(hdc, hpen);
		MoveToEx(hdc, x - sizex / 2, y - sizey / 2, NULL);
		LineTo(hdc, x + sizex / 2, y - sizey / 2);
		LineTo(hdc, x + sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y - sizey / 2);
		DeleteObject(hpen);
	}
}

int MyRect::isvisible()
{
	return visible;
}

int MyRect::isfilled()
{
	return filled;
}

int MyRect::getfillstyle()
{
	return fillstyle;
}

int MyRect::getfigurecolor()
{
	return color;
}

int MyRect::getx()
{
	return x;
}

int MyRect::gety()
{
	return y;
}

int MyRect::getwidth()
{
	return sizex;
}

int MyRect::getheight()
{
	return sizey;
}

void MyRect::setvisibilityflag(int newvisible)
{
	visible = newvisible;
}

void MyRect::setfillflag(int newfilled)
{
	filled = newfilled;
}

void MyRect::setfillstylem(int initfillstyle)
{
	fillstyle = initfillstyle;
}

void MyRect::setfigurecolor(int newcolor)
{
	color = newcolor;
}

/// start ------------ ������� ��� ������������ �� �������������� ----------------
class Random_MyRect : public MyRect
{
public:
	Random_MyRect(int initx, int inity, int initsizex, int initsizey, int initcolor, int initfillstyle) :MyRect(initx, inity, initsizex, initsizey, initcolor, initfillstyle) {

	}
	void random_value(int maxx, int maxy);
};
void Random_MyRect::random_value(int maxx, int maxy) {
	//�������� ������� ������
	//��������� ����� ��������
	// --- ������� ----
	//���������� � = ��������� ����� �� (90) + ��������� 
	sizex = rand() % (maxx - 25) + 25;
	//���������� y = ��������� ����� �� (90) + ��������� 
	sizey = rand() % (maxy - 25) + 25;
	// ����
	color = RGB(rand() % 255, rand() % 255, rand() % 255);
	fillstyle = 6;


}
// ��������� ����� �� ���������� ��������������
class  Random_Elipse : public Random_MyRect {
public:
	Random_Elipse(int initx, int inity, int initsizex, int initsizey, int initcolor, int initfillstyle) :Random_MyRect(initx, inity, initsizex, initsizey, initcolor, initfillstyle) {

	}
	void show(HDC);
	void hide(HDC hdc);
};
void Random_Elipse::show(HDC hdc) //����������� ������ �� ������
{
	if (filled)
	{
		HBRUSH hb = CreateHatchBrush(fillstyle, color);
		SelectObject(hdc, hb);
		Ellipse(hdc, x - sizex / 2, y - sizey / 2, x + sizex / 2, y + sizey / 2);
		DeleteObject(hb);
	}
	else
	{
		HPEN hpen = CreatePen(PS_SOLID, 3, 0);
		SelectObject(hdc, hpen);
		Ellipse(hdc, x - sizex / 2, y - sizey / 2, x + sizex / 2, y + sizey / 2);
		MoveToEx(hdc, x - sizex / 2, y - sizey / 2, NULL);
		LineTo(hdc, x + sizex / 2, y - sizey / 2);
		LineTo(hdc, x + sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y - sizey / 2);
		DeleteObject(hpen);
	}
}
//������� �����
void Random_Elipse::hide(HDC hdc)
{
	if (filled)
	{
		HBRUSH hbr = CreateSolidBrush(0);
		RECT r = { x - sizex / 2, y - sizey / 2, x + sizex / 2, y + sizey / 2 };
		FillRect(hdc, &r, hbr);
		DeleteObject(hbr);
	}
	else
	{
		HPEN hpen = CreatePen(PS_SOLID, 3, 0);
		HPEN hp = (HPEN)SelectObject(hdc, hpen);
		MoveToEx(hdc, x - sizex / 2, y - sizey / 2, NULL);
		LineTo(hdc, x + sizex / 2, y - sizey / 2);
		LineTo(hdc, x + sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y - sizey / 2);
		DeleteObject(hpen);
	}
}
//3 �������
//������� ����� ��������� � ������� 4 �������
// ��������� ������������� � �������� � ���� 4 �����������  150, 150 | 500, 150 | 550, 150 | 550, 550
class environment : public MyRect
{

	Random_MyRect** obj;
public:


	environment(int initx, int inity, int initsizex, int initsizey, int initcolor, int initfillstyle) : MyRect(initx, inity, initsizex, initsizey, initcolor, initfillstyle)
	{
		obj = new Random_MyRect * [4];

		for (int i = 0; i < 4; i++)
		{
			int rand1 = rand() % 2;
			switch (i)
			{

			case 0:
				if (rand1)
					obj[i] = new Random_MyRect(x - sizex / 4, y - sizey / 4, sizex / 6, sizex/6 , RGB(0, 255, 0), 3);
				else
					obj[i] = new Random_Elipse(x - sizex / 4, y - sizey / 4, sizex / 6, sizex / 6, RGB(255, 0, 0), 3);
				break;

			case 1:
				if (rand1)
					obj[i] = new Random_MyRect(x + sizex / 4, y - sizey / 4, sizex / 6, sizex / 6, RGB(0, 255, 0), 3);
				else
					obj[i] = new Random_Elipse(x + sizex / 4, y - sizey / 4, sizex / 6, sizex / 6, RGB(0, 255, 0), 3);
				break;
			case 2:
				if (rand1)
					obj[i] = new Random_MyRect(x - sizex / 4, y + sizey / 4, sizex / 6, sizex / 6, RGB(0, 255, 0), 3);
				else
					obj[i] = new Random_Elipse(x - sizex / 4, y + sizey / 4, sizex / 6, sizex / 6, RGB(0, 255, 0), 3);
				break;
			case 3:
				if (rand1)
					obj[i] = new Random_MyRect(x + sizex / 4, y + sizey / 4, sizex / 6, sizex / 6, RGB(0, 255, 0), 3);
				else
					obj[i] = new Random_Elipse(x + sizex / 4, y + sizey / 4, sizex / 6, sizex / 6, RGB(0, 255, 0), 3);
				break;
			}
		}

	
	}
	

	void fg(HDC hdc);
	void show(HDC hdc);
	void hide(HDC hdc);
	void random_res();
	void execute(HDC hdc);
	void rand_fig();
};
void environment::show(HDC hdc) //����������� ������ �� ������
{
	if (filled)
	{
		HBRUSH hb = CreateHatchBrush(fillstyle, color);
		RECT r = { x - sizex / 2, y - sizey / 2, x + sizex / 2, y + sizey / 2 };
		FillRect(hdc, &r, hb);
		DeleteObject(hb);
	}
	else
	{
		HPEN hpen = CreatePen(PS_SOLID, 3, color);
		HPEN hp = (HPEN)SelectObject(hdc, hpen);
		MoveToEx(hdc, x - sizex / 2, y - sizey / 2, NULL);
		LineTo(hdc, x + sizex / 2, y - sizey / 2);
		LineTo(hdc, x + sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y + sizey / 2);
		LineTo(hdc, x - sizex / 2, y - sizey / 2);
		DeleteObject(hpen);
	}
}
void environment::fg(HDC hdc) {
	obj[0]->show(hdc);
	obj[1]->show(hdc);
	obj[2]->show(hdc);
	obj[3]->show(hdc);
}
void environment::hide(HDC hdc) {
	obj[0]->hide(hdc, color);
	obj[1]->hide(hdc, color);
	obj[2]->hide(hdc, color);
	obj[3]->hide(hdc, color);
}
void environment::random_res() {
	obj[0]->random_value(sizex / 2, sizey / 2);
	obj[1]->random_value(sizex / 2, sizey / 2);
	obj[2]->random_value(sizex / 2, sizey / 2);
	obj[3]->random_value(sizex / 2, sizey / 2);
}

int main()
{
	srand(time(nullptr));
	HWND hwnd = GetConsoleWindow();		// ���������� ����������� ����
	HDC hdc = GetDC(hwnd);				// �������� ����������
	//---

	// ����������� ����������� ������� ��������� ������ 500 ��
	/*MyRect r(150, 250, 350, 350, RGB(1, 130, 70), 4);
	do {
		r.show(hdc);
		Sleep(500);
		r.hide(hdc);
		Sleep(500);
	} while (true);
	system("pause");*/


	// ---
	// 
	// ������� 2

	//--
	///*Random_MyRect r(150, 150, 350, 350, RGB(1, 130, 70), 4);
	//Random_Elipse elipse(100, 150, 350, 350, RGB(1, 130, 70), 3);
	//do {
	//	���� ������ ��������� ����� ��� �� �� ����� ��������� ���� ������ ���-��� ���? � ����� ������ ��������

	//	r.show(hdc);
	//	elipse.random_value();
	//	elipse.show(hdc);
	//	Sleep(1000);
	//	r.hide(hdc);
	//	elipse.hide(hdc);
	//	Sleep(1000);
	//	r.random_value();
	//} while (true);
	//system("pause");*/

	//--
	// ����� ������� 2

	/*������� 3*/
	environment r(300, 200, 600, 600, RGB(200, 20, 0), 6);
	r.show(hdc);
	Sleep(500);

	do {
		//r.show(hdc);
		Sleep(500);
		r.fg(hdc);
		Sleep(500);
		r.hide(hdc);
		r.random_res();
		//r.rand_fig();
		//system("pause");
	} while (true);



	return 0;
}

