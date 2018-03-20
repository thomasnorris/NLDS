#include "stdlib.h" 
#include <string>
using namespace std;

class BSTree
{
public:
	class MovieNode
	{
	public:
		MovieNode(string title = "", string rating = "", string url = "", int year = 0000, int runTime = 0,
		          MovieNode* leftNode = nullptr, MovieNode* rightNode = nullptr, MovieNode* parentNode = nullptr);
		~MovieNode() {};
		// --Getters
		string GetTitle();
		string GetRating();
		string GetUrl();
		int GetYear();
		int GetRunTime();
		MovieNode* GetLeftNode();
		MovieNode* GetRightNode();
		MovieNode* GetParentNode();
	private:
	protected:
		string Title;
		string Rating;
		string Url;
		int Year;
		int RunTime;
		MovieNode* LeftNode;
		MovieNode* RightNode;
		MovieNode* ParentNode;
	};
	BSTree();
	~BSTree();

	void Insert(string title = "", string rating = "", string url = "", int year = 0000, int runTime = 0,
		MovieNode* left = nullptr, MovieNode* right = nullptr, MovieNode* parent = nullptr);
	void Remove() {};
	void ReadFromFile() {};
	void WriteToFile() {};
	void Search() {};
	void Delete() {};
private:
protected:
};

