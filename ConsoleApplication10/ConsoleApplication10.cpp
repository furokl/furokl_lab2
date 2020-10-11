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

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::ostream;

class RGB
{
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;

public:
	RGB(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0)
		: m_red(red), m_green(green), m_blue(blue)
	{
		assert(red >= 0 && red <= 255);
		assert(green >= 0 && green <= 255);
		assert(blue >= 0 && blue <= 255);
	}

	int get_red() { return m_red; }
	int get_green() { return m_green; }
	int get_blue() { return m_blue; }

	operator int() { return (m_red+m_green+m_blue)/81; }
	friend ostream &operator<< (ostream &out, const RGB &rgb);

	void printRGBA() {
		cout << "R = " << static_cast<int>(m_red) << ';' <<
			" G = " << static_cast<int>(m_green) << ';' <<
			" B = " << static_cast<int>(m_blue) << ';';
	}
};

ostream  &operator<< (ostream &out, const RGB &rgb) {
	out << '(' << static_cast<int>(rgb.m_red)
		<< ", " << static_cast<int>(rgb.m_green)
		<< ", " << static_cast<int>(rgb.m_blue) << ')';
	return out;
}

class Image : public RGB
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

		cout << "\n\t*Constructor worked*\n\n";
	}

	friend bool operator== (const Image &im1, const Image &im2);
	friend bool operator!= (const Image &im1, const Image &im2);
	Image(const Image &im)
		: mx(im.mx), my(im.my){
		for (int i = 0; i < im.mx*im.my; i++)
			data[i] = im.data[i];

		cout << "\n\t*Copy constructor worked*\n\n";
	}

	int get_x() { return mx; }
	int get_y() { return my; }
	int get(int x, int y) { return data[(x - 1) + (y - 1) * x]; }

	void set(int x, int y, RGB color) {
		cout << "\t\t*Setter used*\n\tsize: (" 
			<< x << 'x' << y << ')' 
			<< "\n\tcolor: " << color << endl;
		assert(x > 1 && x < 200);
		assert(y > 1 && y < 200);

		int temp = mx - x;

		for (int i = 0; i < mx*my; i++) {
			data[i] = color;
			if (i % x == x - 1) {
				i += temp;
				x += mx;
			}
			if (i == ((mx*my) - (my - y)*mx) - 1)
				break;
		}
	}
	void set(int x, RGB color) {
		cout << "\t\t*Setter used*\n\tx: " << x
			<< "\n\tcolor: " << color << endl;
		assert(x > 1 && x < 200);

		for (int i = 0; i < my; i++)
			data[x - 1 + i * mx] = color;
	}

	void show() {
		cout << "\t\t*Show func used* size: (" << mx << 'x' << my << ')' << endl;
		for (int i = 0; i < mx*my; i++) {
			cout << data[i];
			if (i % mx == mx - 1)
				cout << '\n';
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
	if (im1.mx != im2.mx || im1.my != im2.my)
		return false;
	for (int i = 0; i < im1.mx * im1.my; i++) {
		if (im1.data[i] != im2.data[i]) {
			return false;
			break;
		}
	}
}
bool operator!= (const Image &im1, const Image &im2) {
	if (im1.mx != im2.mx || im1.my != im2.my)
		return true;
	int i = 0;
	while (im1.data[i] == im2.data[i]) {
		i++;
		if (i == im1.mx*im1.my) break;
	}
	if (im1.data[i] == im2.data[i]) {
		return false;
	}
}

int main() {
	cout << "\n\n\t\tProgramm started...\n\n";
	Image a(5, 5);
	a.set(4, 4, (1, 3, 4));
	a.set(3, 3, (10, 3, 5));
	a.set(2, 2, (100, 35, 53));
	a.show();
	Image b = a;

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
	
	b.set(5, (33, 33, 33));
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