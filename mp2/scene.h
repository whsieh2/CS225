#ifndef SCENE_H
#define SCENE_H

#include "png.h"
#include "image.h"

class Scene
{
	public:
	//Initializes this Scene object to be able to hold "max" number of images with indices 0 	through max-1. 
	Scene(int max);
	
	//Frees all space that was dynamically allocated by this Scene. 
	~Scene();
	
	//The copy constructor makes this Scene an independent copy of the source. 
	Scene(const Scene &source);
	
	//The assignment operator for the Scene class. 
	const Scene & operator= (const Scene &source);
	
	//Modifies the size of the array of Image pointers without changing their indices. 
	void changemaxlayers (int newmax);
	
	//This function will add a picture to the scene, by placing it in the array cell corresponding to the given index, and storing its x coordinate and y coordinate. 
	void addpicture (const char *Filename, int index, int x, int y);
	
	//Moves an Image from one layer to another. 
	void changelayer (int index, int newindex);

	//Changes the x and y coordinates of the Image in the specified layer. 
	void translate (int index, int xco, int yco);
	
	//Deletes the Image at the given index. 
	void deletepicture (int index);
	
	//This function will return a pointer to the Image at the specified index, not a copy of it. 
	Image * getpicture(int index) const;
	
	//Draws the whole scene on one Image and returns that Image by value. 
	Image drawscene() const;
	
	private:
	int max;
	Image ** layers;
	int * xco;
	int * yco;
	void copy(const Scene & other);
	void clear();
	
};
#endif
