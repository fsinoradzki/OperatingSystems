//Frank Sinoradzki

#include "UI.h"
#include "UI.cpp"
#include "directory.h"
#include "directory.cpp"
#include "diskprocess.h"
#include "diskprocess.cpp"
#include "file.h"
#include "file.cpp"


int main(){
        //Call File System to initialize a blank list with just head
        //Call Directory to initialize a blank Vector
        //Call Disk Process to initialize a new disk
        //Call UI to initialize the UI
        //Start the UI
		
		Directory D;
		List L;
		UI gui(D, L);
		gui.Start();
}
