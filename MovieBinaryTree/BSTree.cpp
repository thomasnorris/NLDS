#include "stdafx.h"
#include "BSTree.h"
#include <iostream>

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

void BSTree::MovieNode::SetTitle(string title)
{
	this->Title = title;
}

void BSTree::MovieNode::SetRating(string rating)
{
	this->Rating = rating;
}

void BSTree::MovieNode::SetUrl(string url)
{
	this->Url = url;
}

void BSTree::MovieNode::SetYear(int year)
{
	this->Year = year;
}

void BSTree::MovieNode::SetRunTime(int runTime)
{
	this->RunTime = runTime;
}

void BSTree::MovieNode::SetLeftNode(MovieNode* leftNode)
{
	this->LeftNode = leftNode;
}

void BSTree::MovieNode::SetRightNode(MovieNode* rightNode)
{
	this->RightNode = rightNode;
}

void BSTree::MovieNode::SetParentNode(MovieNode* parentNode)
{
	this->ParentNode = parentNode;
}

bool BSTree::MovieNode::operator==(MovieNode& rhs)
{
	return ((this->Title == rhs.Title) && (this->Year == rhs.Year));
}

bool BSTree::MovieNode::operator<(MovieNode& rhs)
{
	if (this->Title < rhs.Title)
		return true;
	else if (this->Title == rhs.Title)
		return this->Year < rhs.Year;
	
	return false;
}

bool BSTree::MovieNode::operator>(MovieNode& rhs)
{
	if (this->Title > rhs.Title)
		return true;
	else if (this->Title == rhs.Title)
		return this->Year > rhs.Year;
	
	return false;
}

BSTree::BSTree()
{
	this->Root = nullptr;
}


BSTree::~BSTree()
{
	if (this->Root != nullptr)
	{
		delete this->Root;
		this->Root = nullptr;
	}
}

void BSTree::Insert(MovieNode* newNode)
{
	MovieNode* currentNode;
	auto inserted = false;

	if (this->Root == nullptr)
	{
		this->Root = newNode;
		inserted = true;
	}
	
	currentNode = this->Root;
	
	while (!inserted)
	{
		if (*newNode < *currentNode)
		{
			if (currentNode->GetLeftNode() == nullptr)
			{
				currentNode->SetLeftNode(newNode);
				newNode->SetParentNode(currentNode);
				inserted = true;
			}
			else
				currentNode = currentNode->GetLeftNode();
		}
		else
			if (currentNode->GetRightNode() == nullptr)
			{
				currentNode->SetRightNode(newNode);
				newNode->SetParentNode(currentNode);
				inserted = true;
			}
			else
				currentNode = currentNode->GetRightNode();
	}
}

void BSTree::Remove(MovieNode* nodeToRemove)
{
}

void BSTree::Search(MovieNode* nodeToFind)
{
}

BSTree::MovieNode* BSTree::GetRoot()
{
	return this->Root;
}

vector<BSTree::MovieNode*> BSTree::GetOrderedListOfNodes()
{
	TraverseInOrder(this->Root);
	return this->InOrderNodeList;
}

void BSTree::TraverseInOrder(MovieNode* node)
{
	if (node == nullptr)
		return;
	
	this->TraverseInOrder(node->GetLeftNode());
	this->InOrderNodeList.push_back(node);
	this->TraverseInOrder(node->GetRightNode());
}


