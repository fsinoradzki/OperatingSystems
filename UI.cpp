//Frank Sinoradzki



#include <iostream>
using namespace std;


UI::UI(List Lis, Directory Dir){
	D = Dir;
	L = Lis;
	cout << "Costructed the UI with the List and Dir\n";
}
                  
void UI::Edit(string filename){
	cout<<"Let's edit yo\n";
}    

void UI::Create(string filename){
	cout<<"CREATAN\n";
}

void UI::Delete(string filename){
	cout<<"delet this\n";
}  
                 
void UI::Type(string filename){
	cout<<"You're just my type ;)\n";
}  

void UI::Dir(){
	D.add_file_to_dir("file1");
    D.add_file_to_dir("file2");
    D.add_file_to_dir("file3");
	D.show_all();
}

void UI::ExecInstruction(string instruction, string filename){
	cout <<instruction<<endl;
	cout <<filename<<endl;
	if(instruction == "edit")
		Edit(filename);
	else if(instruction == "create")
		Create(filename);
	else if(instruction == "delete") 
		Delete(filename);
	else if(instruction == "type")   
		Type(filename);
	else if(instruction =="dir")    
		Dir(); //Can possibly fudge up if there's no filename
}

void UI::Start(){
	bool exit = false;
	string str = "", instr, fname;
	int pos;
	
	//Uses a while loop to loop through inputs
	//If the input is null, nothing will execute
	//If there is input, split up the instruction and argument
	//Then exit if exit is the instruction, or execute the instruction if run
	while(exit == false){
		cout << "$";
		getline(cin, str);
		
		//Everything before the space (text) is the instruction
		//Everything after the space  is the filename
		pos = str.find(" ");
		instr = str.substr(0,pos);
		fname = str.substr(pos+1,str.length()-1);
		
		for(int i=0;i<instr.length();i++)
			instr[i] = tolower(instr[i]);
		
		if(instr == "exit")
			exit = true;
		else
			ExecInstruction(instr, fname);
	}
}