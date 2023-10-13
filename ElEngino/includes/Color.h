#pragma once
typedef unsigned char uchar;
class Color
{
public:
	Color(uchar red, uchar green, uchar blue, uchar alpha);
	static const Color& RED;
	static const Color& GREEN;
	static const Color& BLUE;
	uchar red = 255;
	uchar green = 255;
	uchar blue = 255;
	uchar alpha = 255;
};