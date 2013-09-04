#include <iostream>
#include "rgbapixel.h"
#include "png.h"
using namespace std;

int main()
{
	PNG image("in_02.png");
	int imageWidth = image.width();
	int imageHeight = image.height();
	int x;
	int y;
	PNG outImage(imageWidth, imageHeight);

	for (x=0; x < imageWidth; x++)
	{	
		for (y=0; y < imageHeight; y++)
		{
			*outImage((imageWidth-1)-x,(imageHeight-1)-y) = *image(x,y);
		}
	}
	image.writeToFile("output.png");
	return 0;
	
}


	
