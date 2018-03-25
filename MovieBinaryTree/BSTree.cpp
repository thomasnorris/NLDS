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

void BSTree::InsertNode(MovieNode* newNode)
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

void BSTree::RemoveNode(string title, int year)
{
	auto nodeVector = this->GetOrderedListOfNodes();

	for (auto node : nodeVector)
		if (node->GetTitle() == title && node->GetYear() == year)
		{
			this->DeleteNode(node);
			return;
		}

	cout << "Movie " << title << " not found; nothing to delete." << endl << endl;
}

void BSTree::SearchForNodeAndPrintMatch(string title, int year)
{
	auto nodeVector = this->GetOrderedListOfNodes();

	for (auto node : nodeVector)
		if (node->GetTitle() == title && node->GetYear() == year)
		{
			cout << "Match found!" << endl;
			cout << "Title: " << node->GetTitle() << endl;
			cout << "Rating: " << node->GetRating() << endl;
			cout << "URL: " << node->GetUrl() << endl;
			cout << "Year: " << node->GetYear() << endl;
			cout << "Run Time: " << node->GetRunTime() << "Minutes" << endl << endl;
			return;
		}

	cout << "No match found." << endl << endl;
}

BSTree::MovieNode* BSTree::GetRoot()
{
	return this->Root;
}

vector<BSTree::MovieNode*> BSTree::GetOrderedListOfNodes()
{
	vector<MovieNode*> nodeVector;
	this->TraverseInOrderAndAddToVector(this->Root, nodeVector);
	return nodeVector;
}

void BSTree::TraverseInOrderAndAddToVector(MovieNode* node, vector<MovieNode*> &nodeVector)
{
	if (node == nullptr)
		return;
	
	this->TraverseInOrderAndAddToVector(node->GetLeftNode(), nodeVector);
	nodeVector.push_back(node);
	this->TraverseInOrderAndAddToVector(node->GetRightNode(), nodeVector);
}

void BSTree::DeleteNode(MovieNode* node)
{
	if (node->GetLeftNode() == nullptr)
		this->TransplantNode(node, node->GetRightNode());
	else if (node->GetRightNode() == nullptr)
		this->TransplantNode(node, node->GetLeftNode());

	else
	{
		auto temp = this->GetMinimumSubtree(node->GetRightNode());
		if (temp->GetParentNode() != node)
		{
			this->TransplantNode(node, node->GetRightNode());
			temp->SetRightNode(node->GetRightNode());
			temp->GetRightNode()->SetParentNode(temp);
		}
		this->TransplantNode(node, temp);
		temp->SetLeftNode(node->GetLeftNode());
		temp->GetLeftNode()->SetParentNode(temp);
	}

	cout << "Movie " << node->GetTitle() << " deleted." << endl << endl;
}

// --Transplants node y to node x
void BSTree::TransplantNode(MovieNode* x, MovieNode* y)
{
	if (x->GetParentNode() == nullptr)
		this->Root = y;
	else if (x == x->GetParentNode()->GetLeftNode())
		x->GetParentNode()->SetLeftNode(y);
	else
		x->GetParentNode()->SetRightNode(y);

	if (y != nullptr)
		y->SetParentNode(x->GetParentNode());
}

BSTree::MovieNode* BSTree::GetMinimumSubtree(MovieNode* node)
{
	while (node->GetLeftNode() != nullptr)
		node = node->GetLeftNode();

	return node;
}
