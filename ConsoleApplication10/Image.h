#ifndef IMAGE_H
#define IMAGE_H

#include "RGB.h"

class Image : public RGB
{
private:
	int mx;
	int my;
	int *data = new int[100'000];

public:
	friend bool operator== (const Image &im1, const Image &im2);
	friend bool operator!= (const Image &im1, const Image &im2);

	Image(int tmx, int tmy)
		: mx(tmx), my(tmy)
	{
		assert(tmx >= 1 && tmx <= 200);
		assert(tmy >= 1 && tmy <= 200);

		for (int i = 0; i < tmx*tmy; i++)
			data[i] = 0;

		cout << "\n\t*Constructor worked*\n\n";
	}
	Image(const Image &im);
	~Image();

	int get_x() { return mx; }
	int get_y() { return my; }
	int get(int x, int y) { return data[(x - 1) + (y - 1) * x]; }

	void set(int x, int y, RGB color);
	void set(int x, RGB color);
	void show();
};


#endif