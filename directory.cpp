//
//  directory.cpp
//  CISC3595_5_atos-fs
//
//  Created by Angjelo Marku on 4/28/17.
//  
//

#include "directory.h"
#include <iostream>
#include <algorithm>

using namespace std;

Directory::Directory() //constructor
{
 
}


bool Directory::file_exists_check(string file_name) //checks if file exists in directory list, returns bool value
{
  
    
    if (find(directory_vector.begin(), directory_vector.end(), file_name) != directory_vector.end())
    {
        
        return true;
    }
    else
    {
        return false;
    }
}




void Directory::add_file_to_dir(string file_name) //adds a file to the directory
{
    
    if(file_exists_check(file_name)==false) //first checks if file already exists
    {
        directory_vector.push_back(file_name);
        cout<<file_name<<" added"<<endl;
    }
   
    else
        cout<<"Error! A file with this name already exists!"<<endl;
}





void Directory::delete_file_from_dir(string file_name) //deletes a file if the file exists
{
    
     if(file_exists_check(file_name)==true)//checks if a file exists first
     {
         directory_vector.erase( find(directory_vector.begin(), directory_vector.end(), file_name));
         cout<<file_name<<" erased"<<endl;
     }
    
    else
    {
        cout<<file_name<<" does not exist, can't be erased!"<<endl;
    }
}



void Directory::show_all() //just shows all the contents of the directory
{
    for(int i=0; i< directory_vector.size(); ++i)
        cout << directory_vector[i] <<" "<<endl;
}

int Directory::directorylength() //returns directory length
{
    return directory_vector.size();
}

string Directory::show_specific(int index) //returns the content of the directory at a specific index
{
    return directory_vector[index];
}



