// MovieBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BSTree.h"
#include <iostream>
using namespace std;

int main()
{
	auto tree = new BSTree();
	auto movie = new BSTree::MovieNode("Up", "PG", "netflix.com", 2009, 90);

	tree->Insert(movie);

    return 0;
}

