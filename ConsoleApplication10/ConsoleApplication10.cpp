//	Выполнил ст. группы М3О-214Б-19.
/*
	Практическое занятие 2 - перегрузка операторов, шаблоны.

0.	Реализовать хранение данных изображения, в классе разработанном на занятии 1 в динамической 
	памяти выделяемой в методе new (доработать конструктор и деструктор)
1.	Перегрузить следующие операторы:
	operator== (побайтовое сравнение изображений или сравнение при помощи гистограмм)
	operator=
	Конcтруктор копирования
2.	Сделать класс шаблонным, чтобы можно было менять тип данных для представления точки 
	(int, char или еще что-то, наример, rgb)
3.	Реализовать генерацию исключений при попытке записи или чтения за пределами изображения в
	методах доступа
4.	Написать программу для демонстрации функциональности, описанной в пунках 0..3
*/

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

class RGBA
{
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
public:
	RGBA(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255)
		: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{
	}
	void printRGBA() {
		cout << "R = " << static_cast<int>(m_red) << ';' <<
			" G = " << static_cast<int>(m_green) << ';' <<
			" B = " << static_cast<int>(m_blue) << ';' <<
			" A = " << static_cast<int>(m_alpha) << '\n';
	}
};

class Image
{
private:
	int mx;
	int my;
	int *data = new int[100'000];

public:
	Image(int tmx = 200, int tmy = 200)
		: mx(tmx), my(tmy)
	{
		assert(tmx >= 1 && tmx <= 200);
		assert(tmy >= 1 && tmy <= 200);

		for (int i = 0; i < tmx*tmy; i++)
			data[i] = 0;
	}

	friend bool operator== (const Image &im1, const Image &im2);
	friend bool operator!= (const Image &im1, const Image &im2);

	int getMx() { return mx; }
	int getMy() { return my; }
	int get(int x, int y) { return data[(x - 1) + (y - 1) * x]; }

	void show() {
		cout << "\t\t*Show func used* size: (" << mx << 'x' << my << ')' << endl;
		for (int i = 0; i < mx*my; i++) {
			cout << data[i];
			if (i % mx == mx - 1)
				cout << '\n';
		}
	}

	void set(int x, int y, int color) {
		cout << "\t\t*Setter used*\n\tx: " << x
			<< "\n\ty: " << y
			<< "\n\tcolor: " << color << endl;

		if (x < 1 || x > 200)	return;
		if (y < 1 || y > 200)	return;

		mx = x;
		my = y;
		for (int i = 0; i < x*y; i++)
			data[i] = color;
	}

	void set(int x, int color) {
		cout << "\t\t*Setter used*\n\tx: " << x
			<< "\n\tcolor: " << color << endl;

		if (x < 1 || x > 200)	return;
		if (my < 1 || my > 200)	return;

		for (int i = 0; i < my; i++) {
			int temp = x - 1 + i * mx;
			data[temp] = color;
		}
	}

	~Image()
	{
		delete[] data;
		data = nullptr;

		cout << "\n\t*Destructor worked*\n\n";
	}
};

bool operator== (const Image &im1, const Image &im2) {
	for (int i = 0; i < 5; i++) {
		if (im1.data[i] != im2.data[i]) {
			return false;
			break;
		}
	}
}

bool operator!= (const Image &im1, const Image &im2) {
	int i = 0;
	while (im1.data[i] == im2.data[i]) {
		i++;
		if (i == 5) break;
	}
	if (im1.data[i] == im2.data[i]) {
		return false;
	}
}

int main() {
	cout << "\n\n\t\tProgramm started...\n\n";
	Image a(5, 5);
	Image b(5, 5);
	a.show();
	b.show();
	
	if (a != b)
		cout << "!= TRUE" << endl;
	else
		cout << "!= FALSE" << endl;
	if (a == b)
		cout << "== TRUE" << endl;
	else
		cout << "== FALSE" << endl;

	b.set(4, 1);
	a.show();
	b.show();
	if (a != b)
		cout << "!= TRUE" << endl;
	else
		cout << "!= FALSE" << endl;
	if (a == b)
		cout << "== TRUE" << endl;
	else
		cout << "== FALSE" << endl;
	return 0;
}