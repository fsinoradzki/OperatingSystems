//
//  directory.hpp
//  CISC3595_5_atos-fs
//
//  Created by Angjelo Marku on 4/28/17.
//  
//

#ifndef directory_hpp 
#define directory_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

//declaration of class directory, represents a directory where a list of files is kept
//It will be able to add, delete and check if a file is part of the directory. 
//It also keeps track of the size of the directory and where each file is in the directory

class Directory{ 
    public:
        bool file_exists_check(string file_name);
        void add_file_to_dir(string file_name);
        void delete_file_from_dir (string file_name);
        void show_all();
        string show_specific(int index);
        int directorylength();
        Directory();
    
    
    private:
        vector<string> directory_vector; //the file names will be kept in a vector
    
    
    
    
};







#endif /* directory_hpp */
