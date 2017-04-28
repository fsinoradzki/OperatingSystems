#ifndef _FILESYSTEM
#define _FILESYSTEM

class Node{
public:
	string fileName;
	string data;
	Node *next;
	int startBlockNum;
	Node(){}
	Node(string name){
		fileName = name;
	}
	// ~Node();
};

class List{
private:
	Node* head;
	Node* tail;
public:
	void insertNode(string name);
	void deleteNode(string name);
	void printAll();
	void setData(string name,string info);
	void setStartBlock(string name, int blockNum);
};

#endif