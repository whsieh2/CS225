#include "image.h"
#include <iostream>


void Image::flipleft() 	// I used tempA as a temporary variable to hold the left most pixel value. 
//then I gave the leftmost pixel the value of the rightmost pixel, and vice versa.
{ 
	int imageWidth = (*this).width();
	int imageHeight = (*this).height();
	RGBAPixel * tempA = new RGBAPixel();
	for (int x=0; x < imageWidth/2; x++)
	{	
		for (int y=0; y < imageHeight; y++)
		{
			RGBAPixel * leftPixel = (*this)(x,y);
			RGBAPixel * rightPixel = (*this)((imageWidth - x)-1,y);
			
			*tempA = *leftPixel;
			*leftPixel = *rightPixel;
			*rightPixel = *tempA;
		}
	}
	delete tempA;
}
void Image::adjustbrightness(int r, int g, int b) // Took every pixel and add the parameter values to each pixel.
// if it was over 255, the value would cap at 255. 
{
	int imageWidth =(*this).width();
	int imageHeight = (*this).height();
	
	for (int x=0; x < imageWidth; x++)
	{	
		for (int y=0; y < imageHeight; y++)
		{
			RGBAPixel * pixel = (*this)(x,y);
			pixel-> red = pixel-> red + r;
			if (pixel-> red > 255)
				pixel-> red = 255;
			if (pixel-> red < 0)
				pixel-> red = 0;

			pixel->green = pixel-> green + g;
			if (pixel->green > 255)
				pixel->green = 255;
			if (pixel->green < 0)
				pixel->green = 0;

			pixel->blue = pixel-> blue + b;
			if (pixel->blue > 255)
				pixel->blue = 255;
			if (pixel->blue < 0)
				pixel->blue = 0;
		}
	}
}
void Image::invertcolors() // I took every pixel and subtracted each color value from 255.
{
	int imageWidth = (*this).width();
	int imageHeight = (*this).height();
	for (int x=0; x < imageWidth; x++)
	{	
		for (int y=0; y < imageHeight; y++)
		{
			RGBAPixel * pixel = (*this)(x,y);

			pixel-> red = 255 - pixel-> red;
			
			pixel-> green = 255 - pixel-> green;
			
			pixel-> blue = 255 - pixel-> blue;
			
		}
	}
}
