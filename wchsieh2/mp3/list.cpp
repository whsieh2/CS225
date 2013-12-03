/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
	clear();
    /// @todo Graded in MP3.1
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
	
	if (!empty())
    {
        // delete every until you hit tail
        ListNode * next = head;
        while (next != NULL)  {
            next = head->next;
            delete head;
            head = next;
        }
    }
    /// @todo Graded in MP3.1
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata)
{	
	ListNode * newnode = new ListNode(ndata);
	if (empty())
	{
		head = newnode;
		tail = newnode;
		length++;

	}
	else
	{
		newnode -> next = head ;
		head ->prev = newnode;
		head = newnode;
		length++;
		head -> prev = NULL;
	}
	newnode = NULL;
	
    /// @todo Graded in MP3.1
}	

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack( const T & ndata )
{
    /// @todo Graded in MP3.1
    ListNode * newnode = new ListNode(ndata);
    if (tail != NULL)
    {
    	tail -> next = newnode;
    	newnode -> prev = tail;
		tail = newnode;
		tail -> next = NULL;
		length++;
		
    }
    else
	{
		head = newnode;
		tail = newnode;
		length++;
	}
	newnode = NULL;
    
}


/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse( ListNode * & startPoint, ListNode * & endPoint )
{

	if (!empty())
    {
    	// save the prev/next pointers of start/end
        ListNode * startPrev = startPoint->prev;
        ListNode * endNext = endPoint->next;
        // used to swap the next/prev pointers of each node
        ListNode * tempSwap;
        // save the old StartPoint/endPoint to flip them at the end
        ListNode * oldStart = startPoint;
        ListNode * oldEnd = endPoint;
        // check distance, distance is used to be for loop counter
        tempSwap = startPoint;      
        // counter to check distance between start and end
        int x = 0;
        
 

        while(tempSwap != endPoint)
        {
            tempSwap=tempSwap->next;
            x++;
        }
 
        for (int i = 0; i <= x; i++)
        {
            // swap prev/next pointers of current node
            tempSwap = startPoint->prev;
            startPoint->prev = startPoint->next;
            startPoint->next = tempSwap;
            startPoint = startPoint->prev;
        }
 
        // flip startPoint and endPoint and its pointers
        startPoint = oldEnd;
        endPoint   = oldStart;
        if (startPrev == NULL)
        {
			startPoint->prev = NULL;
        }
        else
        {
        	startPoint->prev = startPrev;
            startPrev->next = startPoint;
        }
            
        if (endNext == NULL)
        {
        	endPoint->next = NULL;

        }
        else
        {
        	endPoint->next = endNext;
            endNext->prev = endPoint;
        }
            
    }
	
	
	
	
    /// @todo Graded in MP3.1
}


/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth( int n )
{
	if(empty())
		return;
	if (n == length)
	{
		reverse();
		return;
	}
	
	ListNode * endTemp = head; // temporarily
	ListNode * temp = NULL;
	ListNode * headTemp = head;
	
	
	int count;
	if(length%n != 0)
		count = (length/n) + 1;
	else 
		count = (length/n);
	
	for(int j =0;j < count; j++) //iterate over the entire list in chunks
	{ 
		for (int i = 0; i < n-1; i++) // find the tail of the group
		{
			
			if(endTemp->next != NULL)
				endTemp = endTemp->next;
		} 
		if(j == 0) //only the first iteration
		{
			reverse(head,endTemp);
			head = head; 
		}
		else 
		{
			reverse(headTemp,endTemp);
			headTemp->prev = temp;	//correcting pointers
			temp->next = headTemp;
			tail = endTemp;
		}
		temp = endTemp;			//correct all the pointers
		headTemp = endTemp->next;
		endTemp = endTemp->next;
	} 
    /// @todo Graded in MP3.1
}


/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
	int num = 1;

    ListNode * temp1 = head;
    ListNode * temp2 = head;
	 if (length == 0)
        return;
    


    while ((temp1->next != tail) && (temp1 != tail) && (temp1 != NULL))
    {
        while (num>0)
        {
            temp2 = temp1;
            temp1 = temp1 ->next;
            num--;
        }

        temp2->next = temp1 ->next;
        temp1->next->prev = temp2;

        tail -> next = temp1;
        temp1 -> next = NULL;
        temp1 -> prev = tail;
        tail = temp1;

        temp1 = temp2->next;

        num = 1;
    }

    temp1 = NULL;
    temp2 = NULL;
    delete temp1;
    delete temp2;

	//implement reverse
	//but loop it.
    /// @todo Graded in MP3.1
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head)
    {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    }
    else
    {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL)
    {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint)
{
    ListNode * splitHere = start;
    ListNode * secondHead;
   
    // get the location of where it is split
    for (int i = 0; i < splitPoint - 1; i++)
        splitHere = splitHere->next;
    secondHead = splitHere->next;
    // split the list by pointing next/prev to NULL
    splitHere->next = NULL;
    secondHead->prev = NULL;
    return secondHead;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T> & otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if(tail != NULL)
    {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode * second)
{
	if(first == NULL)
		return second;
	else if(second == NULL)
		return first;
	else if (first ==NULL && second ==NULL)
		return NULL;
	else if((first->data) < (second->data))
	{
		first->next = merge(first->next,second);
		first->next->prev = first; //corrects pointers
		return first;
	}
	else
	{
		second->next = merge(first,second->next);
		second->next->prev = second; //corrects pointers
		return second;
	}
 
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode * List<T>::mergesort(ListNode * start, int chainLength)
{
    ListNode * left;
    ListNode * right;
    int leftPart, rightPart;
    
    if (start ==NULL)
    	return NULL;
    else if (chainLength <= 1) 
    	return start;
   	else if (chainLength %2 ==0) //See's if the length is even
    {
    	rightPart = chainLength/2;
    	leftPart = chainLength/2;
    	
    }
    else //if it's not, rightPart will have the bigger side
    {
    	leftPart = chainLength/2;
    	rightPart = chainLength/2 + 1;
    }
    left = start;
    right = split(start, leftPart);
    left = mergesort(left, leftPart);
    right = mergesort(right, rightPart);
    return merge(left,right);
}
