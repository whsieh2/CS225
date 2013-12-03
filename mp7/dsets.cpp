#include <vector>
#include "dsets.h"

void DisjointSets::addelements(int num)
{
    int prevSize = v.size();

    v.resize( v.size() + num );

    for (int i = prevSize; i < v.size(); i++)
    {
        v[i]=-1;
    }
}

int DisjointSets::find(int elem)
{
    if (v[elem] >= 0) 
    {
        return find( find(v[ elem ]) );
    }
    	
    else 
    {
		return elem;
    }
}

void DisjointSets::setunion(int a, int b)
{
    b = find(b);
    a = find(a);

    int newSize = v[a]+v[b];
    if ( v[a] > v[b])
    {
        v[a] = b;
        v[b] = newSize;
    }
    else 
    {

        v[b] = a;
        v[a] = newSize;
    }
}

bool DisjointSets::isBigger(int c, int d)
{
    return v[d]>v[c];
}
