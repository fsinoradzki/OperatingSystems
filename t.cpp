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

using namespace std;

#include "file.h"
#include "diskprocess.h"

bool Create(string name);
int Write(string dataFromUI);

//GLOBAL VARIABLES
	//allows usage in functions without having to pass each variable
	int myBlockSize = 10;
	int myDiskSize = 1000;
	List list; 
	DiskProcessType myDisk(myBlockSize,myDiskSize);
	DiskBlockType *myBuffer = new DiskBlockType(myBlockSize);
//END GLOBALS

int main(){
	int blockStart;
	string name[3] = {"test file 1", "file 2", "file 3"};
	string dataFromUI[3] = {"this is some sample data for file1", "file 2 data to be written to the disk", "file3 data into multiple data blocks"};	

	for(int x = 0; x < 3; x++){
		//---CREATE 
		if(Create(name[x])){
			cout<<"Successfully created file"<<endl;
		}else{
			cout<<"Error creating file"<<endl;
		}	
		//---END CREATE


		//---EDIT, data will be passed from UI
		list.setData(name[x],dataFromUI[x]);
		blockStart = Write(dataFromUI[x]);
		list.setStartBlock(name[x],blockStart);
		//----END EDIT
	}

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
   	//---END OUTPUT

	return 0;
}


bool Create(string name){
	list.insertNode(name);
	return true;
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