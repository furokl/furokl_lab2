#include "Image.h"

using namespace std;

Image::Image(const Image &im)
	: mx(im.mx), my(im.my)
{
	for (int i = 0; i < im.mx*im.my; i++)
		data[i] = im.data[i];

	cout << "\n\t*Copy constructor worked*\n\n";
}

Image:: ~Image()
{
	delete[] data;

	cout << "\n\t*Destructor worked*\n\n";
}

void Image::set(int x, int y, RGB color) {
	cout << "\n\t\t*Setter used*\n\tsize: ("
		<< x << 'x' << y << ')'
		<< "\n\tcolor: " << color << '\n';

	assert(x >= 1 && x <= 200);
	assert(y >= 1 && y <= 200);

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
void Image::set(int x, RGB color) {
	cout << "\n\t\t*Setter used*\n\tx: " << x
		<< "\n\tcolor: " << color << '\n';
	//assert(x >= 1 && x <= 200);
	if (x < 1 || x > 200)
		throw x;

	for (int i = 0; i < my; i++)
		data[x - 1 + i * mx] = color;
}

void Image::show() {
	cout << "\n\t\t*Show func used* size: (" << mx << 'x' << my << ')' << '\n';
	for (int i = 0; i < mx*my; i++) {
		cout << data[i];
		if (i % mx == mx - 1)
			cout << '\n';
	}
}

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