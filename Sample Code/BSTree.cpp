#include "BStree.h"

BSTree::MovieNode::MovieNode(string title, int year, string rating,
	int runningTime, string url,
	MovieNode * left, MovieNode * right,
	MovieNode *parent){

	this->title = title;
	this->year = year;
	this->rating = rating;
	this->runningTime = runningTime;
	this->url = url;
	this->left = left;
	this->right = right;
	this->parent = parent;
}

/* 
 * Iterative method to insert a new movie into the binary search tree.  The routine
 * is responsible for allocating the node and inserting in place in the tree. 
 */
void BSTree::insert(string title, int year, string rating, int runningTime, string url) {
	/*
	 * Create the Movie Node
	 */
	MovieNode *newMovie = new MovieNode(title, year, rating, runningTime, url);
	/*
	 * Insert it at the root if the tree is empty.
	 */
	MovieNode *current;
	if (root == nullptr) { // Tree is empty -- insert the node
		root = newMovie;
		return;
	}
	/*
	 * If the tree is not empty then set current to the root and find the spot
	 * to insert the node by comparing the current node with the node to be 
	 * inserted.  When the spot is found insert the node and return.
	 */
	current = root;
	do {
		if (*newMovie < *current) {  // add to left
			if (current->getLeft() == nullptr) {
				current->setLeft(newMovie);
				newMovie->setParent(current);
				return;
			}
			else {
				current = current->getLeft();
			}
		}
		else { // add to right
			if (current->getRight() == nullptr) {
				current->setRight(newMovie);
				newMovie->setParent(current);
				return;
			}
			else {
				current = current->getRight();
			}

		}
	} while (true);
}
/*
 * Method to remove a node from the BSTree. 
 */
void BSTree::remove(string title, int year)
{
	throw exception("remove not yet implemented");
}
/*
 * method to read the contents of a file (filename) and 
 * to build a tree. 
 */
void BSTree::readFromFile(string filename)
{
	throw exception("readFromFile method not yet implemented");
}

/*
 * write the contents of the tree out the the file given
 * as the filename.  
 */
void BSTree::writeToFile(string filename)
{
	throw exception("writeToFile method not yet implemented");
}
/*
 * This method searches the tree for a matching movie.  If it
 * finds the movie it returns a pointer to the movie.  Otherwise
 * it returns a null pointer.
 */
BSTree::MovieNode* BSTree::search(string title, int year)
{
	throw exception("search method not yet implemented");
	return nullptr;
}
/*
 * Method to list all the items in the tree using an inorder 
 * traversal.
 */
void BSTree::list()
{
	throw exception("list method not yet implemented");
}
