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

//Functions Needed: Create, Delete, Read, Write, Stats
bool Create(string name);
void Stats(int num);
int Write(string dataFromUI);

//GLOBAL VARIABLES
	//allows usage in functions without having to pass each variable
	int myBlockSize = 10;
	int myDiskSize = 100;
	List list; 
	DiskProcessType myDisk(myBlockSize,myDiskSize);
	DiskBlockType *myBuffer = new DiskBlockType(myBlockSize);
//END GLOBALS

int main(){




	int blockStart = 0;
	int numFiles = 0;

	string name = "myFile.new";
	string dataFromUI = "this is some sample data for a file. make it super long to take up a lot of blocks";

	//---CREATE 
	if(Create(name)){
		cout<<"Successfully created file"<<endl;
		numFiles++;
	}else{
		cout<<"Error creating file"<<endl;
	}	
	//---END CREATE


	//---EDIT, data will be passed from UI
	list.setData(name,dataFromUI);
	blockStart = Write(dataFromUI);
	list.setDiskBlocks(name,blockStart,myBlockSize);
	//----END EDIT


	//----PRINT LIST STATS (DIR command)
	Stats(numFiles);
	//END STATS



//----helpful outputs showing whats in the diskprocess and each list node
	//---PRINT LIST
	// list.printAll();
	//END PRINT

	//---OUTPUT DISK BLOCKS AND CONTENTS
	// for (int i=0; i<15; i++) {
	//     myDisk.read(i,myBuffer);
	//     cout<<"Block "<<i<<" : ";
	// 	for (int j=0; j<myBlockSize; j++) cout << myBuffer->data[j];
	//     cout<<"\n";
 // 	}
   	//---END OUTPUT

	return 0;
}


bool Create(string name){
	list.insertNode(name);
	return true;
}

void Stats(int num){
	int fCounter = 0;
	int totalBlocks = 0;

	for(int i = 0; i < num; i++){
		totalBlocks += list.getStats(fCounter);
		fCounter++;
	}

	cout << "Blocks Left: " << (myDiskSize - totalBlocks) << endl;
}

int Write(string dataFromUI){
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