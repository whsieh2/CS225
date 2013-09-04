#include "rgbapixel.h"
#include <iostream>


RGBAPixel::RGBAPixel() //default constructor
	{
		red=255;
		green=255;
		blue=255;
		alpha=255;
	}
RGBAPixel::RGBAPixel (unsigned char red_new, unsigned char green_new, unsigned char blue_new) //enhanced constructor
	{
		red=red_new;
		green=green_new;
		blue=blue_new;
		alpha=255;
	}
