#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * basic class being defined by Spring 2018 Nonlinear Data Structures
 * class.  The class is untested and incomplete.  The code is available
 * as a starting point for project 3.
 *
 * Date:  March 20, 2018
 *
 * Revisions:
 *	Added exceptions to be thrown for unimplemented methods to prevent
 *        their accidental use.
 *   Modified search to return a pointer to a node.  The search function
 *        will be useful in the case of the remove method as well.
 *   Added title and year arguments to methods that needed them.
 *
 */

class BSTree {
public:
	class MovieNode {
	private:
	protected:
		string title, rating, url;
		int year, runningTime;
		MovieNode *left, *right, *parent;
	public:
		MovieNode(string title = "", int year = 0, string rating = "",
			int runningTime = 0, string url = "",
			MovieNode * left = nullptr, MovieNode * right = nullptr,
			MovieNode *parent = nullptr);
		MovieNode(MovieNode &orig) {}
		~MovieNode() {
			if (left != nullptr) {
				delete left;
				left = nullptr;
			}
			if (right != nullptr) {
				delete right;
				right = nullptr;
			}
		}
		bool operator == (MovieNode& rhs) {  // equal to comparison -- both title and year must match.
			return ((title == rhs.title) && (year == rhs.year));
		}

		bool operator < (MovieNode& rhs) { // less than comparison 
			if (title < rhs.title)
				return true;
			else if (title == rhs.title) {
				return year < rhs.year;
			}
			else {
				return false;
			}
		}

		bool operator > (MovieNode& rhs) {
			throw exception("bool operator > not implemented yet");
			return false;
		}

		string getTitle() { return title; }
		string getRating() { return rating; }
		string getURL() { return url; }
		int getRunningTime() { return runningTime; }
		int getYear() { return year; }
		MovieNode *getRight() { return right; }
		MovieNode *getLeft() { return left; }
		MovieNode *getParent() { return parent; }

		void setRight(MovieNode *ptr) { right = ptr; }
		void setLeft(MovieNode *ptr) { left = ptr; }
		void setParent(MovieNode *ptr) { parent = ptr; }
	};
private:
protected:
	MovieNode *root;
public:
	BSTree() { root = nullptr; }
	~BSTree() {
		if (root != nullptr) {
			delete root;
			root = nullptr;
		}
	}
	void insert(string title, int year, string rating = "", int runningTime = 0, string url = "");
	void remove(string title, int year);
	void readFromFile(string filename);
	void writeToFile(string filename);
	MovieNode* search(string title, int year);
	void list();

};


#endif