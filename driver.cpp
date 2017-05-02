//Frank Sinoradzki

//TO DO:
//Implement Edit with List
//Implement Type with List
//Implement Delete with List
//Implement Dir with List stats

#include "UI.h"
#include "UI.cpp"
#include "directory.h"
#include "directory.cpp"
#include "diskprocess.h"
#include "diskprocess.cpp"
#include "file.h"
#include "file.cpp"

//GLOBAL VARIABLES
	//allows usage in functions without having to pass each variable
	
	Directory D;
	List L;
	int myBlockSize = 10;
	int myDiskSize = 100;
	DiskProcessType myDisk(myBlockSize,myDiskSize);
	DiskBlockType *myBuffer = new DiskBlockType(myBlockSize);
//END GLOBALS
                  
void Edit(string fname){
	string line;
	string data="";
	while(!cin.eof()){
		data += cin.get();
		cout<<"Got char\n";
	}
	cin.clear();
	
	cout << data;
	cout <<"Finished up in Edit\n";
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
	if(D.file_exists_check(fname) == true)
		D.delete_file_from_dir(fname);
	else
		cout<<fname<<" doesn't exist.\n";
}  
                 
void Type(string fname){
	//L.read(fname);
}  

//Prints out all members of the Directory along with their block sizes
void Dir(){
	for(int i = 0; i < D.directorylength(); i++){
		D.show_specific(i);
		cout<<" x blocks"<<endl;
	}
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
		Dir(); //Can possibly fudge up if there's no filename
}

int main(){
        //Call File System to initialize a blank list with just head
        //Call Directory to initialize a blank Vector
        //Call Disk Process to initialize a new disk
        //Call UI to initialize the UI
        //Start the UI
		

		bool keepGoing = true;
		UI gui;
		
		while(keepGoing){
			gui.Start();
			if(gui.getInstruction() == "exit")
				keepGoing = false;
			else
				ExecInstruction(gui.getInstruction(), gui.getFilename());
		}
}
