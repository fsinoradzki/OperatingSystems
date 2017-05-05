//Driver program
//Main authors: Frank Sinoradzki and Kevin Duncan

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

#include "UI.h"
#include "directory.h"
#include "diskprocess.h"
#include "file.h"

//GLOBAL VARIABLES
	//allows usage in functions without having to pass each variable
	
	Directory D;
	List L;
	int myBlockSize = 10;
	int myDiskSize = 10;
	DiskProcessType myDisk(myBlockSize,myDiskSize);
	DiskBlockType *myBuffer = new DiskBlockType(myBlockSize);
//END GLOBALS

void Edit(string fname);
void Create(string fname);
void Delete(string fname);
void Type(string fname);
void Dir();
void ExecInstruction(string instr, string fname);
void writeToDisk(string fname,string dataFromUI);
void deleteFromList(string fname);
void deleteFromDisk(int startBlock, int blocksUsed);
int Reposition(int start, int blocks);
                  

int main(){
	bool keepGoing = true;
	UI gui;
	
	//Initializes the UI and loops through it
	//Will get the instruction and filename from the UI class
	//Then sends that instruction to be executed	
	while(keepGoing){
		gui.Start();
		if(gui.getInstruction() == "exit")
			keepGoing = false;
		else
			ExecInstruction(gui.getInstruction(), gui.getFilename());
	}
}

//Edits the data in the linked list and disk
void Edit(string fname){
	if(!D.file_exists_check(fname) == true)
		cout << "File named '" <<fname<<"' does not exist.\n";
	else{
		string line;
		string data="";
		while(!cin.eof()){
			line = cin.get();
			if(!cin.eof())
			data += line;	
		}
		cin.clear();
		cout << endl;
		writeToDisk(fname,data);
	}
}    

//Checks to see if the file exists
//If it does, then the filename gets added to the directory and a new node to the list
void Create(string fname){
	if(D.file_exists_check(fname) == true)
		cout<<fname<<" already exists.\n";
	else{
		D.add_file_to_dir(fname);
		L.insertNode(fname);
	}
}

//Checks to see if the file exists
//If it does, it gets deleted from the Directory
void Delete(string fname){
	if(D.file_exists_check(fname) == true){
		D.delete_file_from_dir(fname);
		deleteFromList(fname);
	}
	else
		cout<<fname<<" doesn't exist.\n";
}  
           
//Prints out the data inside the specified filename      
void Type(string fname){
	L.printFileData(fname);
}  

//Prints out all members of the Directory along with their block sizes
void Dir(){
	cout << "\tATOS-FS Directory Listing" << endl;
	cout << "\tFILENAME\t\tSIZE (blks)" << endl;
	int totalBlocks = 0;
	for(int i = 0; i < D.directorylength(); i++){
		int block;
		block = L.getBlocksUsed(D.show_specific(i));
		totalBlocks += block;
		cout << "\t" << D.show_specific(i) << "\t\t\t" << block << " blocks"<<endl;
	}
	cout << "\tFREE SPACE " << (myDiskSize - totalBlocks) << " blks" << endl;
	// L.printAll();
}

//Determines what the instruction is and sends the program to the appropriate function to execute it
void ExecInstruction(string instr, string fname){
	if(instr == "edit")
		Edit(fname);
	else if(instr == "create")
		Create(fname);
	else if(instr == "delete") 
		Delete(fname);
	else if(instr == "type")   
		Type(fname);
	else if(instr =="dir")    
		Dir(); 
}

//Writes the contents of a string to the disk
void writeToDisk(string fname,string dataFromUI){
	double length = dataFromUI.length();
	int count = 0; 	//count needs to reset each time a new data string is passed
	int blocksNeeded = ceil(length / myBlockSize);
	int startBlock = myDisk.getNumCreated();

	//Checks to see if there is space
	//If there is, the node in the linked list gets the data
	//And the disk block gets as much data as it can hold
	if(blocksNeeded < (myDiskSize - startBlock)){
		L.setData(fname,dataFromUI);
		L.setDiskBlocks(fname,startBlock,myBlockSize);

		//Goes through the disk to put the data at the block
		for(int i = startBlock; i < startBlock + blocksNeeded; i++){
			for(int j = 0; j < myBlockSize; j++){
				myBuffer->data[j] = dataFromUI[count];
				count++;
			}
			myDisk.write(i,myBuffer);
		}

	}else{
		cerr << "Not enough blocks left" <<endl;
	}

}

//Repositions the data in the blocks after a deletion
//It does this by replacing the first block that is to be deleted with
//	the block directly after the last one to be deleted
//This avoids fragmentation issues!
//Returns the position of the last few blocks that have to be deleted
int Reposition(int start, int blocks){
	int count = 0;
	
	//Load the buffer with the next block after the one to be deleted
	//If it isn’t NULL then replace the original block with the new data
	myDisk.read(start+blocks, myBuffer);
	while(myDisk.write(start+count, myBuffer) !=0){
		count++;
		myDisk.read(start+blocks+count, myBuffer);
	}

	return start+count;
}

//Calls the List’s delete function
//Calls the Reposition function
//Calls the delete from disk with the position returned from Reposition
void deleteFromList(string fname){
	int start = L.getStartBlock(fname);
	int blocks = L.getBlocksUsed(fname);
	L.deleteNode(fname);
	int newStart = Reposition(start, blocks);
	deleteFromDisk(newStart,blocks);
}

//Creates an empty buffer
//Replaces the given block with the NULL buffer
void deleteFromDisk(int startBlock, int blocksUsed){
	for(int i = startBlock; i < startBlock+blocksUsed; i++){
		for(int j = 0; j<myBlockSize;j++){
			myBuffer->data[j] = '\0';
		}
		myDisk.numCreated--;
		myDisk.write(i,myBuffer);
	}

}
