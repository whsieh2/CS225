/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
#include <math.h>
#include <iostream>

template<int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim> & first, const Point<Dim> & second, int curDim) const
{
    /**
     * @todo Implement this function!
     
     */
    if (second[curDim]==first[curDim])
    	return first<second;
    else	 
   		return first[curDim]<second[curDim] ;
}


template<int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim> & target, const Point<Dim> & currentBest, const Point<Dim> & potential) const
{
    /**
     * @todo Implement this function!
     */
   
   	int d_potential  = distance(potential, target);   
    int d_current = distance(currentBest, target); 
   
    if (d_current == d_potential)
        return potential < currentBest;
    return d_current>d_potential;
}
template<int Dim>
int KDTree<Dim>::distance(const Point<Dim> &a, const Point<Dim>&b) const
{
    int ret = 0;
    for (int i = 0; i < Dim; i++)
    {
        ret+= pow(a[i]-b[i],2);
    }
    return ret;
}

template<int Dim>
KDTree<Dim>::KDTree(const vector< Point<Dim> > & newPoints)
{
    /**
     * @todo Implement this function!
     */
	points = newPoints;
    if (points.size()!=0)
        buildKD(0, 0, newPoints.size()-1);
}
template<int Dim>
void KDTree<Dim>::buildKD(int dim, int left, int right)
{
	int median = (left+right)/2;
    if(left==right)
        return;
	quickSelect(median, left, right, dim);
	if (right > median)
        buildKD((dim+1)%Dim, median+1, right);
    if (left < median)
        buildKD((dim+1)%Dim, left, median-1);
    
}
template<int Dim>
void KDTree<Dim>::quickSelect(int k, int left, int right, int curDim)
{
    //partition
    int pivotNewIndex = partition(left, right, k, curDim);
    while(left != right)
    {
        pivotNewIndex = partition(left, right, k, curDim);
        if (pivotNewIndex == k)
            return ;
        else if (k > pivotNewIndex) 
            left = pivotNewIndex+1;
        else
        {
           	right = pivotNewIndex-1;
        }
    }
}
template<int Dim>
int KDTree<Dim>::partition(int left, int right, int k, int curDim)
{
	int storeIndex = left;
	Point<Dim> temp = points[right];
	Point<Dim> pivot = points[k];
    points[right] = points[k];
    points[k] = temp;
   
    for (int i = left; i < right; i++)
    {
        if ( points[i] == pivot|| smallerDimVal(points[i], pivot, curDim))
        {
            temp = points[storeIndex];
            points[storeIndex] = points[i];
            points[i] = temp;
            storeIndex++;
        }
    }
    temp = points[right];
    points[right] = points[storeIndex];
    points[storeIndex] = temp;
    return storeIndex;
}

template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> & query) const
{
    /**
     * @todo Implement this function!
     */
    Point<Dim> value = NeighborHelper(0, query, 0, points.size()-1, points[(points.size()-1)/2]);
     
    return value;
}
template<int Dim>
Point<Dim> KDTree<Dim>::NeighborHelper(int curDim, const Point<Dim> &query, int left, int right, const Point<Dim> &currentBest) const
{
    bool target_left = true;
    int otherSubMedian;
    int median = (left + right)/2;
    Point<Dim> ret_val = currentBest;
    if (left == right)
    {
        // at leaf node
        // 1. check if closer than currentBest node
        if (shouldReplace(query, currentBest, points[left]))
        {
            // 2. return current best and radius
            ret_val = points[left];
            return ret_val;
        }
        ret_val = currentBest;
        return ret_val;
    }
    //Get closest point in the subtree containing target  
    if (smallerDimVal(query, points[median], curDim) && left < median)
    {   
        ret_val = NeighborHelper((curDim+1)%Dim, query, left, median-1, currentBest);
        target_left = true;
        otherSubMedian = (median+1+right-1)/2;
    }
	 if (smallerDimVal(points[median], query, curDim) && right > median)
    {
        ret_val = NeighborHelper((curDim+1)%Dim, query, median+1, right, currentBest);
        target_left = false;
        otherSubMedian = (left+median-1)/2;
    }
    //Check if current node is closer than obtained above
    if (shouldReplace(query, ret_val, points[median]))
        ret_val = points[median];
    
    //Check the other subtree
    Point<Dim> a = points[median];
    //cout<<"[split dist]: "<<a[curDim]-query[curDim]<<" [radius]: "<<distance(query, ret_val)<<" [median]: "<<points[median]<<" [ret_val]: "<<ret_val<<endl;
    if (pow(a[curDim] - query[curDim],2) <= distance(query, ret_val))
    {
    	if (!target_left && left < median)
            ret_val = NeighborHelper((curDim+1)%Dim, query, left, median-1, ret_val);
        if (target_left && right > median)
            ret_val = NeighborHelper((curDim+1)%Dim, query, median+1, right, ret_val);
      
    }
    return ret_val;

}

