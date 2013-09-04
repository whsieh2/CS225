#include <ostream>
#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H
class RGBAPixel
{
	public:
	RGBAPixel(); //Constructor
	RGBAPixel(unsigned char red_new, unsigned char green_new, unsigned char blue_new); //Enhance constructor
	unsigned char red;
	unsigned char blue;	//members of the class
	unsigned char green;
	unsigned char alpha; 	

};
#endif

