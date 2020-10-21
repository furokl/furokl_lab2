#ifndef RGB_H
#define RGB_H

#include <iostream>
#include <cassert>

using std::cout;
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

		cout << "\t\t*Add color*\n";
	}

	int get_red() { return m_red; }
	int get_green() { return m_green; }
	int get_blue() { return m_blue; }

	operator int() { return (m_red + m_green + m_blue) / 81; }
	friend ostream &operator<< (ostream &out, const RGB &rgb);

	void printRGBA();
}; 

#endif