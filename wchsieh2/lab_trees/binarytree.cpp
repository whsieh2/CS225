/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary tree
 *  is just the length of the longest path from the root to a leaf, and that the
 *  height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
	// Call recursive helper function on root
	return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	// Base case
	if (subRoot == NULL)
        return -1;
	
	// Recursive definition
	return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that node
 *  itself, and everything to the right of a node will be printed out after that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
	// Call recursive helper function on the root
	printLeftToRight(root);

	// Finish the line
	cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node * subRoot) const
{
	// Base case - null node
	if (subRoot == NULL)
		return;

	// Print left subtree
	printLeftToRight(subRoot->left);

	// Print this node
	cout << subRoot->elem << ' ';

	// Print right subtree
	printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
	mirror(root);
}
template <typename T>
void BinaryTree<T>::mirror( Node *subRoot)
{
    if (subRoot == NULL)
        return;
    Node *temp = subRoot->left;
    subRoot->left = subRoot->right;
    subRoot->right = temp;

    mirror(subRoot->left);
    mirror(subRoot->right);
}

/**
 * @return True if an in-order traversal of the tree would produce a nondecreasing list
 *  output values, and false otherwise. This is also the criterion for a binary tree to be
 *  a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
    // your code here
	return isOrdered(root);
}
template <typename T>
bool BinaryTree<T>::isOrdered(const Node* subRoot) const
{
    bool lefOrdered = false, rigOrdered = false;
    int rigMost = 0, lefMost = 0;
    if (subRoot == NULL)
        return true;
    if (subRoot->left != NULL)
    {
        lefOrdered = isOrdered(subRoot->left);
        rigMost = rightMost(subRoot->left);
    }
    else
    {
        lefOrdered = true;
        rigMost = subRoot->elem;
    }

    if (subRoot->right != NULL)
    {
        rigOrdered = isOrdered(subRoot->right);
        lefMost = leftMost(subRoot->right);
    }
    else
    {   
        rigOrdered = true;
        lefMost = subRoot->elem;
    }
    if (lefOrdered && rigOrdered && (lefMost>=subRoot->elem) && (rigMost<=subRoot->elem))
        return true;
    return false;
}

/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards, ending at a
 *  leaf node. Paths ending in a left node should be printed before paths ending in a node
 *  further to the right.
 */

template <typename T>
T BinaryTree<T>::leftMost(const Node* subRoot) const
{
    if (subRoot->left == NULL)
        return subRoot->elem;
    return leftMost(subRoot->left);
}

/**
 * return the right-most node on the tree
 */
template <typename T>
T BinaryTree<T>::rightMost(const Node* subRoot) const
{
    if (subRoot->right == NULL)
        return subRoot->elem;
    return rightMost(subRoot->right);

}
template <typename T>
void BinaryTree<T>::printPaths() const
{
    int path[1000];
    printPathsHelper(root, path, 0);
}

template <typename T>
void BinaryTree<T>::printPathsHelper(const Node* subRoot, int path[], int size) const
{
    if (subRoot == NULL)
        return;

    path[size] = subRoot->elem;
    size++;

    if (subRoot->left ==NULL && subRoot->right == NULL)
    {
        cout<<"Path:";
        for(int i = 0; i < size; i++)
        {
            cout<<" "<<path[i];
        }
        cout<<endl;
    }
    else
    {
        printPathsHelper(subRoot->left,path,size);
        printPathsHelper(subRoot->right,path,size);
    }
}
/**
 * Each node in a tree has a distance from the root node - the depth of that node,
 *  or the number of edges along the path from that node to the root. This function returns
 *  the sum of the distances of all nodes to the root node (the sum of the depths of all
 *  the nodes). Your solution should take O(n) time, where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    int count = 0;
    return sumDistHelper(root,count);
}

template <typename T>
int BinaryTree<T>::sumDistHelper(const Node* subRoot, int count) const
{
    if (subRoot == NULL)
        return 0;
    int retVal = sumDistHelper(subRoot->left, ++count) + sumDistHelper(subRoot->right, count)+count;
    return retVal-1;
}

