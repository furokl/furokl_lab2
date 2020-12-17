#include "image.h"
#include "console_color.h"
#include <Windows.h>
#include <iostream>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Image::Image(int x, int y)
	: mx(x), my(y) {
	data = new (std::nothrow) int[mx*my];
	if (!data)
		std::cout << "Could not allocate memory" << std::endl;
	else {
		for (int i = 0; i < mx*my; i++)
			data[i] = LightGray;
	}
}
Image::~Image() {
	delete[] data;
	data = nullptr;
	std::cout << "\n\t*Destructor worked*\n\n";
}

// get X, Y
int Image::get(int x, int y) {
	try {
		if (x < 1 || x > mx)
			throw x;
		if (y < 1 || y > my)
			throw y;
		return data[(x - 1) + (y - 1) * mx];
	}
	catch (const int ex) {
		std::cout << "!!!\tinvalid variable\tget:\t" << ex << std::endl;
	}
}

// set X, Y
void Image::set(int x, int y, int color) {
	try {
		if (x < 1 || x > mx)
			throw x;
		if (y < 1 || y > my)
			throw y;
		data[mx * (y - 1) + (x - 1)] = color;
	}
	catch (const int ex) {
		std::cout << "!!!\tinvalid variable\tset:\t" << ex << std::endl;
	}
}

// set Y line
void Image::setY(int x, int color) {
	try {
		if (x < 1 || x > mx)
			throw x;

		for (int i = 0; i < my; i++)
			data[mx * i + (x - 1)] = color;
	}
	catch (const int ex) {
		std::cout << "!!!\tinvalid variable\tsetY:\t" << ex << std::endl;
	}
}

// set X line
void Image::setX(int y, int color) {
	try {
		if (y < 1 || y > mx)
			throw y;

		for (int i = 0; i < mx; i++)
			data[mx * (y - 1) + i] = color;
	}
	catch (const int ex) {
		std::cout << "!!!\tinvalid variable\tsetX:\t" << ex << std::endl;
	}
}

// std::cin >>
const int Image::cinFunc() {
	while (true) {
		int a;
		do {
			std::cin >> a;
			if (a < 0 || a > 32767)
				std::cout << "!!!\tinvalid value,\tretry:\t\t   ";
		} while (a < 0 || a > 32767);

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\n??\n";
		}
		else {
			std::cin.ignore(32767, '\n');
			return a;
		}
	}
}

// operator= overloading
Image::Image(const Image &im)
	: mx(im.mx), my(im.my)
{
	data = new (std::nothrow) int[im.mx*im.my];
	if (!data)
		std::cout << "Could not allocate memory" << std::endl;
	else {
		for (int i = 0; i < im.mx*im.my; i++)
			data[i] = im.data[i];
	}
	std::cout << "\n\t*Copy constructor worked*\n\n";
}

// operator== overloading
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

// operator!= overloading
bool operator!= (const Image &im1, const Image &im2) {
	if (im1.mx != im2.mx || im1.my != im2.my)
		return true;
	int i = 0;
	while (im1.data[i] == im2.data[i]) {
		i++;
		if (i == im1.mx*im1.my) 
			break;
	}
	if (im1.data[i] == im2.data[i]) {
		return false;
	}
}

// show picture
void Image::show() {
	for (int i = 0; i < mx*my; i++) {
		if (i == 0)
			std::cout << '\t';

		switch (data[i]) {
		case 0:
			SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | 0));
			std::cout << ' ';
			break;
		case 1:
			SetConsoleTextAttribute(hConsole, (WORD)((Blue << 4) | 0));
			std::cout << ' ';
			break;
		case 2:
			SetConsoleTextAttribute(hConsole, (WORD)((Green << 4) | 0));
			std::cout << ' ';
			break;
		case 3:
			SetConsoleTextAttribute(hConsole, (WORD)((Cyan << 4) | 0));
			std::cout << ' ';
			break;
		case 4:
			SetConsoleTextAttribute(hConsole, (WORD)((Red << 4) | 0));
			std::cout << ' ';
			break;
		case 5:
			SetConsoleTextAttribute(hConsole, (WORD)((Magenta << 4) | 0));
			std::cout << ' ';
			break;
		case 6:
			SetConsoleTextAttribute(hConsole, (WORD)((Brown << 4) | 0));
			std::cout << ' ';
			break;
		case 7:
			SetConsoleTextAttribute(hConsole, (WORD)((LightGray << 4) | 0));
			std::cout << ' ';
			break;
		case 8:
			SetConsoleTextAttribute(hConsole, (WORD)((DarkGray << 4) | 0));
			std::cout << ' ';
			break;
		case 9:
			SetConsoleTextAttribute(hConsole, (WORD)((LightBlue << 4) | 0));
			std::cout << ' ';
			break;
		case 10:
			SetConsoleTextAttribute(hConsole, (WORD)((LightGreen << 4) | 0));
			std::cout << ' ';
			break;
		case 11:
			SetConsoleTextAttribute(hConsole, (WORD)((LightCyan << 4) | 0));
			std::cout << ' ';
			break;
		case 12:
			SetConsoleTextAttribute(hConsole, (WORD)((LightMagenta << 4) | 0));
			std::cout << ' ';
			break;
		case 13:
			SetConsoleTextAttribute(hConsole, (WORD)((LightRed << 4) | 0));
			std::cout << ' ';
			break;
		case 14:
			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | 0));
			std::cout << ' ';
			break;
		case 15:
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | 0));
			std::cout << ' ';
			break;
		}

		if (i % mx == mx - 1) {
			SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
			std::cout << "\n\t";
		}
	}
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	std::cout << '\n';
}

