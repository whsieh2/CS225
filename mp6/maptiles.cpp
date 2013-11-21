/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */
	 			
#include <iostream>
#include <map>
#include "maptiles.h"
#include "kdtree.h"

using namespace std;

MosaicCanvas * mapTiles(SourceImage const & theSource, vector<TileImage> const & theTiles)
{
    /**
     * @todo Implement this function!
     */
    //Start building the canvas
    //Declare a new canvas
    int cols = theSource.getColumns();
    int rows = theSource.getRows();
    MosaicCanvas::MosaicCanvas *canvas = new MosaicCanvas(rows, cols);
         //Convert vector<TileImage> to vector< Point<3> >
    vector< TileImage >::iterator it;
    vector< Point<3> > colors;
    
    map<Point<3>, TileImage> theMap;
    for (int x = 0; x < theTiles.size(); x++)
    {
    	 //get average color
        RGBAPixel avgColor = theTiles.at(x).getAverageColor();
        Point<3> po(avgColor.red, avgColor.green, avgColor.blue);
        
        //put in vector
        colors.push_back(po);
        
        //map it
        theMap[po] = theTiles.at(x);
        
    }
    
      //Call kdtree constructor
    KDTree<3>::KDTree tree(colors);



    //loop through each tile
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //for each tile: 
            //grab the pixel from source
            RGBAPixel regionColor = theSource.getRegionColor(i, j); 
            //find the closest average color from kdtree using NNS
            Point<3> regionPoint(regionColor.red, regionColor.green, regionColor.blue);
            Point<3> closestPoint = tree.findNearestNeighbor(regionPoint);
            //use the map to find the tile 
            TileImage theTile = theMap[closestPoint];

            //put the tile onto canvas
            canvas->setTile(i,j,theTile);
        }
    }

    //return canvas
    return canvas;
	
}
