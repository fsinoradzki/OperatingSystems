#ifndef _FILESYSTEM
#define _FILESYSTEM

/*
* Node class:
* Creates a Node object that holds a file name, some data, the starting block number on the disk, and the number
* of blocks used on the disk by the file held in this node
*/
class Node{
public:
	string fileName;
	string data;
	Node *next;
	int startBlockNum;
	int blocksUsed;
	Node(){}
	Node(string name){
		fileName = name;
	}
	//~Node();
};

/*
* List Class:
* Initiates a head and tail for the linked list of Nodes, and provides various methods for operations on the list
* The list represents a one-level flat file system where Node objects can be inserted, deleted, contents printed, and have data set
*/
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
};

#endif