//	Выполнил ст. группы М3О-214Б-19.
/*
	Практическое занятие 2 - перегрузка операторов, шаблоны.

0.	Реализовать хранение данных изображения, в классе разработанном на занятии 1 в динамической
	памяти выделяемой в методе new (доработать конструктор и деструктор)
1.	Перегрузить следующие операторы:
	operator== (побайтовое сравнение изображений или сравнение при помощи гистограмм)
	operator= (конcтруктор копирования)
2.	Сделать класс шаблонным, чтобы можно было менять тип данных для представления точки
	(int, char или еще что-то, наример, rgb)
3.	Реализовать генерацию исключений при попытке записи или чтения за пределами изображения в
	методах доступа
4.	Написать программу для демонстрации функциональности, описанной в пунках 0..3
*/

// Тест пункта 0 и 3 есть в furokl_lab1

#include "draw.h"
#include "console_color.h"
#include <Windows.h>
#include <iostream>

int main() {
	system("color F0");
	int x, y;
	setlocale(LC_ALL, "Russian");

	// for test;
	std::cout << "\n\n\t\tПривет!\n\n";

		// copy constructor
	Image a(2, 2);
	a.show();
	Image b = a;
	b.show();
	
		// operator== && operator!= 
			// a = b
	(a != b) ?
		std::cout << "operator!=\treturn TRUE\n" :
		std::cout << "operator!=\treturn FALSE\n";
	(a == b) ?
		std::cout << "operator==\treturn TRUE\n" :
		std::cout << "operator==\treturn FALSE\n";

			// change element color
	b.set(1, 2, Black);
	a.show();
	b.show();
	(a != b) ? 
		std::cout << "operator!=\treturn TRUE\n":
		std::cout << "operator!=\treturn FALSE\n";
	(a == b) ?
		std::cout << "operator==\treturn TRUE\n":
		std::cout << "operator==\treturn FALSE\n";

			// X1 > X2
	Image a1(3, 1);
	a1.show();
	Image a2(6, 1);
	a2.show();
	(a1 != a2) ? 
		std::cout << "operator!=\treturn TRUE\n":
		std::cout << "operator!=\treturn FALSE\n";
	(a1 == a2) ? 
		std::cout << "operator==\treturn TRUE\n":
		std::cout << "operator==\treturn FALSE\n";

			// Y1 > Y2
	Image b1(1, 3);
	b1.show();
	Image b2(1, 6);
	b2.show();
	(b1 != b2) ?
		std::cout << "operator!=\treturn TRUE\n" :
		std::cout << "operator!=\treturn FALSE\n";
	(b1 == b2) ?
		std::cout << "operator==\treturn TRUE\n" :
		std::cout << "operator==\treturn FALSE\n";

	std::cout << "\n\n\t\tДемонстрация тестовой части закончилась!\n"
		<< "\n\t===========================================\n";

	// for draw
	std::cout << "\n\n\tQ - рисовать по точкам\n"
		<< "\tW - рисовать вертикальными линиями\n"
		<< "\tE - рисовать горизонтальными линиями\n"
		<< "\tR - смена цвета\n"
		<< "\tesc - закрыть приложение\n"
		<< "\n\tВведите размер желаемого изображения:\n"
		<< "\t\t\t\t\tX: ";
	x = Image::cinFunc();
	std::cout << "\t\t\t\t\tY: ";
	y = Image::cinFunc();
	std::cout << "\n\n"
		<< "\n\tВозможен переход в редактор через q, w, e\n"
		<< std::endl;
	Draw d(x, y);
	d.show();
	d.move();

	return 0;
}