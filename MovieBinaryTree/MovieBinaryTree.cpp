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

	movieList.push_back(new BSTree::MovieNode("Up", "PG", "netflix.com", 2009, 96));
	movieList.push_back(new BSTree::MovieNode("Frozen", "PG", "seeitintheatersnearyou.org", 2013, 109));
	movieList.push_back(new BSTree::MovieNode("It", "R", "nourl.com", 2017, 135));
	movieList.push_back(new BSTree::MovieNode("Finding Nemo", "PG", "pirate.movies.com", 2003, 100));
	movieList.push_back(new BSTree::MovieNode("Finding Dory", "PG", "othernetflix.com", 2016, 100));
	movieList.push_back(new BSTree::MovieNode("Apples", "NC-17", "thisisnotamovie", 2018, 1000));

	for (BSTree::MovieNode* movie : movieList)
	{
		tree->InsertNode(movie);
	}

	auto list = tree->GetOrderedListOfNodes();

	tree->SearchForNodeAndPrintMatch("Up", 2009);
	tree->SearchForNodeAndPrintMatch("Schindler's List", 1993);

    return 0;
}

