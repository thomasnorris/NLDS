#include "stdafx.h"
#include "BSTree.h"


BSTree::MovieNode::MovieNode(string title, string rating, string url, int year, int runTime, MovieNode *left,
	MovieNode *right, MovieNode *parent)
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

string BSTree::MovieNode::GetTitle()
{
	return this->Title;
}

string BSTree::MovieNode::GetRating()
{
	return this->Rating;
}

string BSTree::MovieNode::GetUrl()
{
	return this->Url;
}

int BSTree::MovieNode::GetYear()
{
	return this->Year;
}

int BSTree::MovieNode::GetRunTime()
{
	return this->RunTime;
}

BSTree::MovieNode* BSTree::MovieNode::GetLeftNode()
{
	return this->Left;
}

BSTree::MovieNode* BSTree::MovieNode::GetRightNode()
{
	return this->Right;
}

BSTree::MovieNode* BSTree::MovieNode::GetParentNode()
{
	return this->Parent;
}

BSTree::BSTree()
{
}


BSTree::~BSTree()
{
}

void BSTree::Insert(string title, string rating, string url, int year, int runTime, MovieNode *left, MovieNode *right,
	MovieNode *parent)
{
	MovieNode *newMovie = new MovieNode(title, rating, url, year, runTime, left, right, parent);
}
