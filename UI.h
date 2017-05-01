//UI Class


#include <string>
using namespace std;

class UI{
        public:
                UI(List Lis, Directory Dir);    //Constructor
                void Edit(string filename);     //Sends a filename and text to File System
                                                //      Only if Directory says it doesn't already exist
                void ExecInstruction(string instruction, string filename);
												//Parses instruction, sends data to corresponding function
                void Create(string filename);   //Sends a filename to Directory to see if it exists
                                                //      If it doesn't, sends to File System to create the entry
                void Delete(string filename);   //Sends a filename to Directory to see if it exists
                                                //      If it does, sends the filename to File System to delete it
                void Dir();                     //Gets all the filenames from Directory and all the file sizes from
                                                //      File System, then prints them. Also prints the remaining size.
                void Type(string filename);     //Sends the filename over to File System to print it out
				void Start();					//Starts the UI, prompts for input

		private:
			Directory D;
			List L;
};
