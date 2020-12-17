#ifndef IMAGE_H
#define IMAGE_H

class Image
{
private:
	int mx;
	int my;
	int *data;
public:
	Image(int, int);
	~Image();
	int getMx() { return mx; }
	int getMy() { return my; }
	int get(int, int);
	void show();
	static const int cinFunc();
	void set(int x, int y, int color);
	void setY(int x, int color);
	void setX(int y, int color);
	Image(const Image &im);
	friend bool operator== (const Image &im1, const Image &im2);
	friend bool operator!= (const Image &im1, const Image &im2);
};

#endif