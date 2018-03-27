#include "stdlib.h" 
#include <string>
#include <vector>
using namespace std;

void LoadFile();
void DisplayFileError(string fileName);
void PromptForMovieInfoAndAddToTree();
BSTree::MovieNode* PromptForMovieTitleAndDate(string commandName);
void SaveFile();
