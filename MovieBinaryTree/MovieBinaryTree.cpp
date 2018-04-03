// MovieBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BSTree.h"
#include "MovieBinaryTree.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const string INPUT_FILE_NAME = "movies.txt";
const string OUTPUT_FILE_NAME = INPUT_FILE_NAME;
const string LIST_COMMAND = "L";
const string INSERT_COMMAND = "I";
const string SEARCH_COMMAND = "S";
const string DELETE_COMMAND = "D";
const string QUIT_COMMAND = "Q";

BSTree* _tree;

int main()
{
	LoadFile();
	
	cout << "There are a number of commands that can be entered:" << endl;
	string command;
	while (command != QUIT_COMMAND)
	{
		cout << "\"" << LIST_COMMAND << "\" will list all movies currently stored in the tree." << endl;
		cout << "\"" << INSERT_COMMAND << "\" will further prompt to insert a movie into the tree." << endl;
		cout << "\"" << SEARCH_COMMAND << "\" will further prompt to search for a movie stored in the tree." << endl;
		cout << "\"" << DELETE_COMMAND << "\" will further prompt to delete a movie from the tree." << endl;
		cout << "\"" << QUIT_COMMAND << "\" will save the movies in the tree in order to \"" << OUTPUT_FILE_NAME << "\" and quit the program." << endl << endl;

		cout << "Enter one of the commands and press \"Enter\" (case sensitive): ";
		cin >> command;

		if (command == LIST_COMMAND)
		{
			if (_tree->GetRoot() == nullptr)
				cout << "The tree has no movies to list." << endl << endl;
			else
				_tree->ListInOrder();
		}
		else if (command == INSERT_COMMAND)
			PromptForMovieInfoAndAddToTree();

		else if (command == SEARCH_COMMAND)
		{
			auto movieToSearch = PromptForMovieTitleAndDate("search");
			_tree->SearchAndPrintMatch(movieToSearch->GetTitle(), movieToSearch->GetYear());
		}

		else if (command == DELETE_COMMAND)
		{
			auto movieToDelete = PromptForMovieTitleAndDate("delete");
			_tree->Delete(movieToDelete->GetTitle(), movieToDelete->GetYear());
		}
	}

	SaveFile();

	system("pause");

    return 0;
}

void LoadFile()
{
	_tree = new BSTree();
	ifstream inputFile;
	inputFile.open(INPUT_FILE_NAME);

	if (!inputFile.good())
		DisplayFileError(INPUT_FILE_NAME);

	string line;
	while (getline(inputFile, line))
	{
		auto movie = new BSTree::MovieNode();
		movie->SetTitle(line);
		getline(inputFile, line);
		movie->SetRating(line);
		getline(inputFile, line);
		movie->SetUrl(line);
		getline(inputFile, line);
		movie->SetYear(stoi(line));
		getline(inputFile, line);
		movie->SetRunTime(stoi(line));

		_tree->Insert(movie);
	}

	cout << "The file \"" << INPUT_FILE_NAME << "\" has loaded successfully." << endl << endl;
}

void DisplayFileError(string fileName)
{
	cout << "There was an issue opening the file \"" << fileName << "\". Please check the file and try again." << endl << endl;
	system("pause");
	_Exit(0);
}

void PromptForMovieInfoAndAddToTree()
{
	string line;
	BSTree::MovieNode* newMovie = new BSTree::MovieNode();

	cout << "Enter the title of the movie: ";
	cin >> line;
	newMovie->SetTitle(line);
	cout << "Enter the MPAA Rating of the movie: ";
	cin >> line;
	newMovie->SetRating(line);
	cout << "Enter the URL to stream the movie: ";
	cin >> line;
	newMovie->SetUrl(line);
	cout << "Enter the year the movie came out: ";
	cin >> line;
	newMovie->SetYear(stoi(line));
	cout << "Enter the run time (in minutes) of the movie: ";
	cin >> line;
	newMovie->SetRunTime(stoi(line));

	_tree->Insert(newMovie);

	cout << endl << "Movie \"" << newMovie->GetTitle() << "\" added successfully." << endl << endl;
}

BSTree::MovieNode* PromptForMovieTitleAndDate(string commandName)
{
	string title;
	int year;

	cout << "Enter the name of a movie for which to " << commandName << " (case sensitive): ";
	cin >> title;
	cout << "Enter the year the movie was released: ";
	cin >> year;

	return new BSTree::MovieNode(title, year);
}

void SaveFile()
{
	ofstream outputFile;
	outputFile.open(OUTPUT_FILE_NAME);

	if (!outputFile.good())
		DisplayFileError(OUTPUT_FILE_NAME);

	auto movies = _tree->GetVectorOfNodesInOrder();
	for (auto movie : movies) 
	{
		outputFile << movie->GetTitle() << endl;
		outputFile << movie->GetRating() << endl;
		outputFile << movie->GetUrl() << endl;
		outputFile << movie->GetYear() << endl;
		outputFile << movie->GetRunTime() << endl;
	}

	cout << "File \"" << OUTPUT_FILE_NAME << "\" saved successfully." << endl;
}
