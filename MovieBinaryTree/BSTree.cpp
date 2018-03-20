#include "stdafx.h"
#include "BSTree.h"


BSTree::MovieNode::MovieNode(string title, string rating, string url, int year, int runTime, MovieNode* leftNode,
	MovieNode* rightNode, MovieNode* parentNode)
{
	this->Title = title;
	this->Rating = rating;
	this->Url = url;
	this->Year = year;
	this->RunTime = runTime;
	this->LeftNode = leftNode;
	this->RightNode = rightNode;
	this->ParentNode = parentNode;
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
	return this->LeftNode;
}

BSTree::MovieNode* BSTree::MovieNode::GetRightNode()
{
	return this->RightNode;
}

BSTree::MovieNode* BSTree::MovieNode::GetParentNode()
{
	return this->ParentNode;
}

BSTree::BSTree()
{
}


BSTree::~BSTree()
{
}

void BSTree::Insert(string title, string rating, string url, int year, int runTime, MovieNode* leftNode, MovieNode* rightNode,
	MovieNode* parentNode)
{
	MovieNode* newMovie = new MovieNode(title, rating, url, year, runTime, leftNode, rightNode, parentNode);
}
