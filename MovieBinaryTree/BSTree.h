#include "stdlib.h" 
#include <string>
using namespace std;

class BSTree
{
	class MovieNode
	{
	public:
		MovieNode()
		{
			this->Title = "";
			this->Rating = "";
			this->URL = "";
			this->Year = 0000;
			this->RunTime = 00;
			this->Left = nullptr;
			this->Right = nullptr;
			this->Parent = nullptr;
		}
		~MovieNode() {};
	private:
	protected:
		string Title;
		string Rating;
		string URL;
		int Year;
		int RunTime;
		MovieNode *Left;
		MovieNode *Right;
		MovieNode *Parent;
	};
public:
	BSTree();
	~BSTree();
};

