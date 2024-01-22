// FZVO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Это консольное приложение. Для Windows 10 в свойствах консольного окна нужно установмит флажок 
// "Использовать прежнюю версию консоли" 

/*
Файл содержит описание класса MyRect - прямоугольник.
1. Используя этот класс, написать программу, изображающую
на экране мигающий прямоугольник.Изменить класс, объявив часть
полей личными.
2. Создать два новых класса, наследующих от MyRect : первый –
прямой потомок MyRect - прямоугольник, способный случайным образом
изменять размеры, цвет и стиль заполнения, от него унаследовать эллипс,
обладающий таким же поведением.
Составить программу, изображающую на одной половине окна
мигающий прямоугольник, а на другой - мигающий эллипс.
3. Создать новый класс "Среда", который мог бы занимать все окно
или его часть и содержать внутри себя четыре объекта, класс каждого
объекта выбирается случайно при инициализации среды из классов, созданных
в результате выполнения пункта 2. Объекты размещаются каждый в своем квадранте
(среда делится на 4 части) и при выполнении программы изменяют свои параметры.
*/

#include <windows.h>
#include <conio.h>
#include <time.h>

class MyRect                 //тип объекта "прямоугольник"
{

private:

	// НЕ понятно пока почему не упало ничего чем приватный от публики отлчачется 
	// Дополнение Был в привате int sizex, sizеу; Когда начал делать наследования начал ругаться что Рандомный Прямоугольник не видит эти переменые кинул в публик заработало, так же с колором )





	int visible;		        //флаг видимости
public:
	int filled;			        //флаг закраски
	int fillstyle;          //способ закраски
	int color; 	            //цвет
	int sizex, sizey; 		  //размеры

	int x, y;			          //координаты центра
	//    (Расположение, расположение , размер , размер , цвет, тип заливки)
	MyRect(int initx, int inity, int initsizex, int initsizey, int initcolor, int initfillstyle);
	// Начальная установка параметров  прямоугольника
	virtual void show(HDC hdc);
	// Высвечивает прямоугольник  на экране
	virtual void hide(HDC hdc,int color);
	// гасит изображение  прямоугольника
	int isvisible();
	// Возвращает значение флага видимости
	int isfilled();
	// Возвращает значение флага закраски
	int getfillstyle();
	// Возвращает значение способа закраски
	int getfigurecolor();
	// Возвращает значение цвета прямоугольника
	int getx();
	// Возвращает X координату центра
	int gety();
	// Возвращает Y координату центра
	int getwidth();
	// Возвращает размер прямоугольника по оси X
	int getheight();
	// Возвращает размер прямоугольника по оси Y
	void setvisibilityflag(int newvisible);
	// Устанавливает флаг видимости объекта
	void setfillflag(int newfilled);
	// Устанавливает флаг закраски объекта
	void setfillstylem(int initfillstyle);
	// Устанавливает способ закраски объекта
	void setfigurecolor(int newcolor);
	// Устанавливает цвет объекта
};

//************ функции rect  **************

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

void MyRect::show(HDC hdc) //высвечивает объект на экране
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

void MyRect::hide(HDC hdc,int color) // гасит изображение объекта
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

/// start ------------ ЗАДАНИЕ ДВА УНАСЛЕТОВАТЬ ОТ ПРЯМОУГОЛЬНИКА ----------------
class Random_MyRect : public MyRect
{
public:
	Random_MyRect(int initx, int inity, int initsizex, int initsizey, int initcolor, int initfillstyle) :MyRect(initx, inity, initsizex, initsizey, initcolor, initfillstyle) {

	}
	void random_value(int maxx, int maxy);
};
void Random_MyRect::random_value(int maxx, int maxy) {
	//Диапазон который задали
	//Генерация новых значений
	// --- Размеры ----
	//Переменная х = рандомное число до (90) + минималка 
	sizex = rand() % (maxx - 25) + 25;
	//Переменная y = рандомное число до (90) + минималка 
	sizey = rand() % (maxy - 25) + 25;
	// Цвет
	color = RGB(rand() % 255, rand() % 255, rand() % 255);
	fillstyle = 6;


}
// рандомный элипс от рандомного прямоугольника
class  Random_Elipse : public Random_MyRect {
public:
	Random_Elipse(int initx, int inity, int initsizex, int initsizey, int initcolor, int initfillstyle) :Random_MyRect(initx, inity, initsizex, initsizey, initcolor, initfillstyle) {

	}
	void show(HDC);
	void hide(HDC hdc);
};
void Random_Elipse::show(HDC hdc) //высвечивает объект на экране
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
//Стирает элипс
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
//3 задание
//Главная мысль запихнуть в квадрат 4 объекта
// Наследуем прямоугольник и зарисуем в него 4 изображения  150, 150 | 500, 150 | 550, 150 | 550, 550
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
void environment::show(HDC hdc) //высвечивает объект на экране
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
	HWND hwnd = GetConsoleWindow();		// дескриптор консольного окна
	HDC hdc = GetDC(hwnd);				// контекст устройсива
	//---

	// высвечивает треугольник который светиться каждые 500 мс
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
	// Задание 2

	//--
	///*Random_MyRect r(150, 150, 350, 350, RGB(1, 130, 70), 4);
	//Random_Elipse elipse(100, 150, 350, 350, RGB(1, 130, 70), 3);
	//do {
	//	Если рандом поставить после шоу то не будет стираться каша потмоу что-что ЧТО? у хайда другие значения

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
	// Конец задания 2

	/*задание 3*/
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

