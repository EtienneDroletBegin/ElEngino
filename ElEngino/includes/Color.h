#pragma once
typedef unsigned char uchar;
class Color
{
public:
	/// <summary>
	/// an assortment of thee uchars creating a RGBA code
	/// </summary>
	/// <param name="red"></param>
	/// <param name="green"></param>
	/// <param name="blue"></param>
	/// <param name="alpha"></param>
	Color(uchar red, uchar green, uchar blue, uchar alpha);
	static const Color& RED;
	static const Color& GREEN;
	static const Color& BLUE;
	static const Color& WHITE;
	uchar red = 255;
	uchar green = 255;
	uchar blue = 255;
	uchar alpha = 255;
};
