#include "png.h"
#ifndef IMAGE_H
#define IMAGE_H

class Image : public PNG
{
	public:  //constructor 
   		void flipleft();
		void adjustbrightness(int r, int g, int b);
		void invertcolors();
};
#endif
