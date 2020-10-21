#include "RGB.h"

void RGB::printRGBA() {
	cout << "R = " << static_cast<int>(m_red) << ';' <<
		" G = " << static_cast<int>(m_green) << ';' <<
		" B = " << static_cast<int>(m_blue) << ';';
}

ostream  &operator<< (ostream &out, const RGB &rgb) {
	out << '(' << static_cast<int>(rgb.m_red)
		<< ", " << static_cast<int>(rgb.m_green)
		<< ", " << static_cast<int>(rgb.m_blue) << ')';
	return out;
}