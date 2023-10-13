#include "Color.h";


Color::Color(uchar red, uchar green, uchar blue, uchar alpha = 255)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}
 
const Color& Color::RED = Color(255, 0, 0);
const Color& Color::GREEN = Color(0, 255, 0);
const Color& Color::BLUE = Color(0, 0, 255);