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

#include "RGB.h"
#include "Image.h"

using std::cout;
using std::ostream;

int main() {
	cout << "\n\n\t\tProgramm started...\n\n";
	RGB black(0, 0, 0);
	RGB red(255, 0, 00);
	RGB yellow(255, 255, 0);
	RGB white(255, 255, 255);

	Image a(5, 5);

	a.set(6, 6, red);
	a.set(4, 4, yellow);
	a.set(2, 2, black);
	a.show();

	Image b = a;

	a.show();
	b.show();
	if (a != b)
		cout << "!= TRUE\n";
	else
		cout << "!= FALSE\n";
	if (a == b)
		cout << "== TRUE\n";
	else
		cout << "== FALSE\n";

	{
		try {
			b.set(5000, white);
		}
		catch (int xy)
		{
			cout << "    *!* INVALID VALUE: " << xy << '\n';
		}


		try {
			b.set(5, white);
		}
		catch (int xy)
		{
			cout << "\t\t INVALID VALUE: " << xy << '\n';
		}
	}

	a.show();
	b.show();
	if (a != b)
		cout << "!= TRUE\n";
	else
		cout << "!= FALSE\n";
	if (a == b)
		cout << "== TRUE\n";
	else
		cout << "== FALSE\n";

	return 0;
}