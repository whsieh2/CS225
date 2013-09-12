#include <iostream>
#include "rgbapixel.h"
#include "png.h"
using namespace std;

int main()
{
	PNG image("in.png");
	int imageWidth = image.width();
	int imageHeight = image.height();
	PNG outImage(imageWidth, imageHeight);

	for (int x=0; x < imageWidth; x++)
	{	
		for (int y=0; y < imageHeight; y++)
		{
			RGBAPixel pixel = *image((imageWidth-1)-x,(imageHeight-1)-y);
			outImage(x,y) -> red = pixel.red;
			outImage(x,y) -> green = pixel.green;
			outImage(x,y) -> blue = pixel.blue;
			outImage(x,y) -> alpha = pixel.alpha;
		}
	}
	outImage.writeToFile("out.png");
	return 0;
	
};



	
