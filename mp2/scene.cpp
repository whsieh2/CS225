#include "scene.h"
#include "image.h"
#include <iostream>
using namespace std;

Scene::Scene(int max)
{
	layers = new Image * [max];
	xco = new int[max];
	yco = new int[max];
	for (int i = 0; i < max; i++)
	{
		layers[i] = NULL;
		xco = 0;
		yco = 0;
		
	}
}
Scene::~Scene()
{
	clear();
}
Scene::Scene(const Scene & source)
{
	copy(source);
}
//Constructor
const Scene & Scene::operator=(const Scene &source)	
{
	if (this != &source)
	{
		clear();
		copy(source);
		
	}
	return *this;
}

void Scene::changemaxlayers	(int newmax)
{
	if (newmax < max )
	{
		for (int i = newmax; i<max;i++)
		{
			if (layers [i]==NULL)
			{
				cout << "invalid newmax" << endl;
				return;
			}
		}
	}
	Image **newlayers = new Image *[newmax];
	int * newxco = new int [newmax];
	int * newyco = new int [newmax];
	
	for (int i = 0; i<newmax; i++)
	{
		newlayers[i] = NULL;
		newxco[i] = 0;
		newyco[i] = 0;
	}
	int small = (newmax<max)?newmax:max;
	
	
	for (int i = 0; i< small; i++)
	{
		*newlayers[i]= *layers[i];
		newxco[i]= xco[i];
		newyco[i]= yco[i];
	}
	clear();
	layers=newlayers;
	xco=newxco;
	yco=newyco;	
}
void Scene::addpicture (const char *FileName, int index, int x, int y) 
{
	if (index < max && index >=0)
    {
        //create new image
        Image *image = new Image();
        image->readFromFile(FileName);

        if (layers[index] != NULL)
        {
            delete layers[index];
        }
        //place in layers[index]
        layers[index] = image;
        
        //store x,y coords
        xco[index] = x;
        yco[index] = y;
    } 
    else
        cout<< "index out of bounds" << endl;
}

void Scene::changelayer (int index, int	newindex)	
{
	 if((index >=0 && index < max)&&(newindex >=0 && newindex <max))
    {
        //check self-assignment
        if (index == newindex)
            return;
        // delete the image originally there
        if(layers[newindex]!=NULL)
            delete layers[newindex];
        // have newindex pointer to original image
        layers[newindex] = layers[index];
        layers[index] = NULL;

        //update x,y coords
        xco[newindex] = xco[index];
        yco[newindex] = yco[index];
        xco[index] = 0;
        yco[index] = 0;
    } 
    else
        cout <<"invalid index" <<endl;   
}

void Scene::translate (int index, int xcor, int ycor)
{
	if ((index>=0&&index<max)&&(layers[index]!=NULL))
    {
    //change x,y coords
        xco[index] = xcor;
        yco[index] = ycor;
    } else
        cout<<"invalid index" <<endl;
}	

void Scene::deletepicture (int index)
{
	 if ((index>=0&&index<max)&&(layers[index]!=NULL))
    {
        //delete image
        delete layers[index];
        layers[index] = NULL;
        xco[index] = 0;
        yco[index] = 0;
    }
    else
        cout <<"invalid index"<<endl;
}

Image * Scene::getpicture(int index) const
{
	if ((index < max) && (index >=0))
        return layers[index];
    else
    {   
        cout<<"invalid index"<<endl;
        return NULL;
    }
}

Image Scene::drawscene () const
{
	int mheight = 0;
    int mwidth = 0;
    for(int i = 0; i < max; i++)
    {
        if(layers[i] != NULL)
        {
            cout << "Layer number: "<< i << endl;
            if(mheight < (layers[i]->height()+yco[i]))
                mheight = layers[i]->height()+yco[i];
            if(mwidth < (layers[i]->width()+xco[i]))
                mwidth = layers[i]->width()+xco[i];
        }
    }
    //declare an Image with the min height and width
    Image image;
    image.resize(mwidth,mheight);
    
    
    //loop through the layers from 0 to max-1
    for(int index = 0; index < max;index++)
    {
        if (layers[index] != NULL)
        {
            for(int x = 0; x < layers[index]->width(); x++)
            {
                for(int y = 0; y< layers[index]->height();y++)
                {
                 	*image(xco[index]+x,yco[index]+y) = *(*layers[index])(x,y);
                }
            }
        }
    }
    
    return image;
}

void Scene::copy (const Scene & temp)
{
	max = temp.max;
	layers = new Image *[max];
	xco = new int[max];
	yco = new int[max];
	for (int i = 0; i < max; i++)
	{
		if (temp.layers[i] != NULL)
			layers[i] = new Image (*(temp.layers[i]));
		else 
			layers[i] = NULL;
			
		xco[i] = temp.xco[i];
		yco[i] = temp.yco[i];
	}
}
void Scene::clear()
{
	for (int i=0; i<max; i++)
	{
		delete layers[i];
	}	
	delete [] layers;
	delete [] xco;
	delete [] yco;		
}
