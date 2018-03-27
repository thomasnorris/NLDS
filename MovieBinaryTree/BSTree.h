#include "stdlib.h" 
#include <string>
#include <vector>
using namespace std;

class BSTree
{
public:
	class MovieNode
	{
	public:
		MovieNode(string title = "", int year = 0000, string rating = "", string url = "", int runTime = 0,
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
		// --Setters
		void SetTitle(string title = "");
		void SetRating(string rating = "");
		void SetUrl(string url = "");
		void SetYear(int year = 0000);
		void SetRunTime(int runTime = 0);
		void SetLeftNode(MovieNode* leftNode = nullptr);
		void SetRightNode(MovieNode* rightNode = nullptr);
		void SetParentNode(MovieNode* parentNode = nullptr);
		// --Operator overloads
		bool operator == (MovieNode& rhs);
		bool operator < (MovieNode& rhs);
		bool operator > (MovieNode& rhs);
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

	void Insert(MovieNode* newNode);
	void Delete(string title, int year);
	void SearchAndPrintMatch(string title, int year);
	void ListInOrder();
	MovieNode* GetRoot();
private:
protected:
	vector<MovieNode*> BuildVectorOfNodesInOrder();
	void TraverseInOrderAndAddToVector(MovieNode* node, vector<MovieNode*> &nodeVector);
	void DeleteInternal(MovieNode* node);
	void TransplantNode(MovieNode* x, MovieNode* y);
	MovieNode* GetMinimumSubtree(MovieNode* node);
	MovieNode* Root;
};

