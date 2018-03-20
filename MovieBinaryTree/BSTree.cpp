#include "stdafx.h"
#include "BSTree.h"


BSTree::MovieNode::MovieNode(string title, string rating, string url, int year, int runTime, MovieNode* left,
	MovieNode* right, MovieNode* parent)
{
	this->Title = title;
	this->Rating = rating;
	this->Url = url;
	this->Year = year;
	this->RunTime = runTime;
	this->Left = left;
	this->Right = right;
	this->Parent = parent;
}

BSTree::BSTree()
{
}


BSTree::~BSTree()
{
}
