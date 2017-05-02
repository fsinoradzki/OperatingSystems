//UI Class


#include <string>
using namespace std;

class UI{
        public:
                UI();						    //Constructor
				void Start();					//Starts the UI, prompts for input
				string getInstruction();		//Returns instruction
				string getFilename();			//Returns filename

		private:
			string instruction, filename;//Strings that hold info on the current instruction and filename
};
