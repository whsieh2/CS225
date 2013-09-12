#include "png.h"
#ifndef IMAGE_H
#define IMAGE_H

class Image : public PNG
{
	public:  //constructor 
   		void flipleft();  //flips the image around the y axis.
		void adjustbrightness(int r, int g, int b);  //adds to the red, blue, and green pixel values.
		void invertcolors(); //makes each rgb pixel to 255 minus its original value 
};
#endif
