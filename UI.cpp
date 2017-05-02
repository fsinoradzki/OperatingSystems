//Frank Sinoradzki



#include <iostream>
using namespace std;


UI::UI(){
	instruction = "";
	filename = "";
}

string UI::getInstruction(){
	return instruction;
}

string UI::getFilename(){
	return filename;
}
                  
//void UI::Edit(string fname){
//	cout<<"Let's edit yo\n";
//}    
//
//void UI::Create(string fname){
//	cout<<"CREATAN\n";
//}
//
//void UI::Delete(string fname){
//	cout<<"delet this\n";
//}  
//                 
//void UI::Type(string fname){
//	cout<<"You're just my type ;)\n";
//}  
//
//void UI::Dir(){
//	
//}
//
//void UI::ExecInstruction(string instr, string fname){
//	cout <<instruction<<endl;
//	cout <<filename<<endl;
//	if(instruction == "edit")
//		Edit(filename);
//	else if(instruction == "create")
//		Create(filename);
//	else if(instruction == "delete") 
//		Delete(filename);
//	else if(instruction == "type")   
//		Type(filename);
//	else if(instruction =="dir")    
//		Dir(); //Can possibly fudge up if there's no filename
//}

void UI::Start(){
	bool exit = false;
	string str = "";
	int pos;
	
	//If the input is null, nothing will execute
	//If there is input, split up the instruction and argument
	//Then exit if exit is the instruction, or execute the instruction if run
	cout << "$";
	getline(cin, str);
	
	//Everything before the space (text) is the instruction
	//Everything after the space  is the filename
	pos = str.find(" ");
	instruction = str.substr(0,pos);
	filename = str.substr(pos+1,str.length()-1);
	
	for(int i=0;i<instruction.length();i++)
		instruction[i] = tolower(instruction[i]);
}