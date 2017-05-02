#ifndef _FILESYSTEM
#define _FILESYSTEM

class Node{
public:
	string fileName;
	string data;
	Node *next;
	int startBlockNum;
	int endBlockNum;
	int blocksUsed;
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
	int getStartBlock(string name);
	int getBlocksUsed(string name);
	void insertNode(string name);
	void deleteNode(string name);
	void printAll(); 
	void printFileData(string name);
	void setData(string name,string info);
	void setDiskBlocks(string name, int blockNum, int blockSize);
	int getStats(int num); //run in a for loop from UI outputting each node name and blocks used
	//add getNode() method to traverse list and return the node object where names match
};

#endif