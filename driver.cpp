//Frank Sinoradzki

#include "UI.h"
#include "UI.cpp"
#include "directory.h"
#include "directory.cpp"
#include "diskprocess.h"
#include "diskprocess.cpp"
#include "file.h"
#include "file.cpp"

Directory D;
List L;
                  
void Edit(string fname){
	cout<<"Let's edit yo\n";
}    

void Create(string fname){
	if(D.file_exists_check(fname) == true)
		cout<<fname<<" already exists.\n";
	else
		D.add_file_to_dir(fname);
}

void Delete(string fname){
	if(D.file_exists_check(fname) == true)
		D.delete_file_from_dir(fname);
	else
		cout<<fname<<" doesn't exist.\n";
}  
                 
void Type(string fname){
	cout<<"You're just my type ;)\n";
}  

void Dir(){
	for(int i = 0; i < D.directorylength(); i++){
		D.show_specific(i);
		cout<<" x blocks"<<endl;
	}
}

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
