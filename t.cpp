#include <iostream>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

#include "file.h"
#include "diskprocess.h"

//API function definitions
bool Create(string fName);
void Stats(int num);
void Write(string fName,string dataFromUI);
int writeToDisk(string dataFromUI);
void Read(string fName);
void Delete(string fName);
void deleteFromDisk(int startBlock, int blocksUsed);


//GLOBAL VARIABLES
	//allows usage in functions without having to pass each variable
	int myBlockSize = 10;
	int myDiskSize = 100;
	List list; 
	DiskProcessType myDisk(myBlockSize,myDiskSize);
	DiskBlockType *myBuffer = new DiskBlockType(myBlockSize);
//END GLOBALS



int main(){

	int numFiles = 0;
	string name = "myFile.new";
	string dataFromUI = "this is some sample data for a file";
 

 	string name2 = "myFile2.txt";
 	string name3 = "file3.ppt";

	//---CREATE [CREATE command]
		Create(name);
		Create(name2);
		Create(name3);
		numFiles = 3;
	//---END CREATE


	//---WRITE [EDIT command]
		Write(name,dataFromUI);
		Write(name2,"asfas gs asg asga");
		Write(name3,"xcuysifhan fsaj gpqir ");
	//----END WRITE

	//---READ [TYPE command]
		Read(name);
	//END READ


	//---DELETE [DELETE command]
		Delete(name);
		numFiles = 2;
	//END DELETE

	//----PRINT LIST STATS [DIR command]
		Stats(numFiles);
	//END STATS



//----helpful outputs showing whats in the diskprocess and each list node
	//---PRINT LIST
	list.printAll();
	//END PRINT

	//---OUTPUT DISK BLOCKS AND CONTENTS
	for (int i=0; i<15; i++) {
	    myDisk.read(i,myBuffer);
	    cout<<"Block "<<i<<" : ";
		for (int j=0; j<myBlockSize; j++) cout << myBuffer->data[j];
	    cout<<"\n";
 	}
   	// ---END OUTPUT

	return 0;
}


bool Create(string fName){
	list.insertNode(fName);
	return true;
}

void Stats(int num){
	int totalBlocks = 0;

	if(num > 1){
		for(int i = 0; i < num; i++){
			totalBlocks += list.getStats(i);
		}
	}else{
		totalBlocks = list.getStats(0);
	}

	cout << "Blocks Left: " << (myDiskSize - totalBlocks) << endl;
}

void Write(string fName, string dataFromUI){
	list.setData(fName,dataFromUI);
	int blockStart = writeToDisk(dataFromUI);
	list.setDiskBlocks(fName,blockStart,myBlockSize);
}

int writeToDisk(string dataFromUI){
	double length = dataFromUI.length();
	int count = 0; 	//count needs to reset each time a new data string is passed
	int blocksNeeded = ceil(length / myBlockSize);
	int startBlock = myDisk.getNumCreated();
	// int a[] = {startBlock, startBlock+blocksNeeded};

	for(int i = startBlock; i < startBlock + blocksNeeded; i++){
		for(int j = 0; j < myBlockSize; j++){
			myBuffer->data[j] = dataFromUI[count];
			count++;
		}
		myDisk.write(i,myBuffer);
	}

	return startBlock;
}

void Read(string fName){
	list.printFileData(fName);
}

void Delete(string fName){
	int start = list.getStartBlock(fName);
	int blocks = list.getBlocksUsed(fName);
	list.deleteNode(fName);
	deleteFromDisk(start,blocks);
}

void deleteFromDisk(int startBlock, int blocksUsed){
	for(int i = startBlock; i < startBlock+blocksUsed; i++){
		for(int j = 0; j<myBlockSize;j++){
			myBuffer->data[j] = '\0';
		}
		myDisk.write(i,myBuffer);
	}
}

