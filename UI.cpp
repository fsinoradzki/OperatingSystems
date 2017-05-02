//Frank Sinoradzki



#include <iostream>
using namespace std;

//Constructor. Sets instruction and filename to blank strings
UI::UI(){
	instruction = "";
	filename = "";
}

//Returns instruction
string UI::getInstruction(){
	return instruction;
}

//Returns filename
string UI::getFilename(){
	return filename;
}

void UI::Start(){
	bool exit = false;
	string str = "";
	int pos;
	
	//If the input is null, nothing will execute
	//If there is input, split up the instruction and argument
	cout << "$";
	getline(cin, str);
	
	//Everything before the space (text) is the instruction
	//Everything after the space  is the filename
	pos = str.find(" ");
	instruction = str.substr(0,pos);
	filename = str.substr(pos+1,str.length()-1);
	
	//Puts the instruction in all lower case
	for(int i=0;i<instruction.length();i++)
		instruction[i] = tolower(instruction[i]);
}