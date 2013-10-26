// **************************************************************
// *		   
// *  quadtree.h
// *		   
// *  Quadtree class
// *		   
// *  CS 225 Spring 2008
// *		   
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"

class Quadtree
{
	public:
		//Big Three
		Quadtree();
		Quadtree(const PNG & source, int resolution);
		Quadtree(Quadtree const & other);
		~Quadtree();
		
		//Member Functions
		Quadtree const & operator= (Quadtree const &other);
		void buildTree (PNG const &source, int resolution);
		RGBAPixel getPixel (int x, int y) const;
		PNG decompress () const;
	
	private:

	// A simple class representing a single node of a Quadtree.
	// You may want to add to this class; in particular, it could probably
	// use a constructor or two...
	class QuadtreeNode
	{
		public:
		QuadtreeNode* nwChild;  // pointer to northwest child
		QuadtreeNode* neChild;  // pointer to northeast child
		QuadtreeNode* swChild;  // pointer to southwest child
		QuadtreeNode* seChild;  // pointer to southeast child

		RGBAPixel element;  // the pixel stored as this node's "data"
		
		int x;
		int y;
		int res;
		
		QuadtreeNode(int xcoord, int ycoord, int resolution)
		{
			x = xcoord;
			y = ycoord;
			res = resolution;
			nwChild = neChild = swChild = seChild = NULL;
		}
		QuadtreeNode(int xcoord, int ycoord, int resolution, PNG & source)
		{
			x = xcoord;
			y = ycoord;
			res = resolution;
			nwChild = neChild = swChild = seChild = NULL;
			element = *(source(x,y));
		}
		QuadtreeNode(QuadtreeNode const * other)
		{
			x = other -> x;
			y = other -> y;
			res = other -> res;
			nwChild = neChild = swChild = seChild = NULL;
			element = other-> element;
		}
		
	};
	void clear(QuadtreeNode * & subRoot);
	QuadtreeNode* copy(QuadtreeNode *otherRoot);
	void treeHelper (PNG const & source, int resolution, QuadtreeNode *subRoot);
	RGBAPixel pixelHelper(int x, int y, QuadtreeNode *subRoot) const;
	bool inRange(int x, int y, QuadtreeNode *subroot) const;
	
	QuadtreeNode * root;    // pointer to root of quadtree
	
	
	
	/**** Functions added for testing/grading                ****/
	/**** Do not remove this line or copy its contents here! ****/
	#include "quadtree_given.h"
};

#endif
