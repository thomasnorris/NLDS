// MovieBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BSTree.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	auto tree = new BSTree();
	auto movieList = vector<BSTree::MovieNode*>();

	movieList.push_back(new BSTree::MovieNode("Up", "PG", "netflix.com", 2009, 90));
	movieList.push_back(new BSTree::MovieNode("Frozen", "PG", "", 2013, 90));

	for (BSTree::MovieNode* movie : movieList)
	{
		tree->Insert(movie);
	}

    return 0;
}

