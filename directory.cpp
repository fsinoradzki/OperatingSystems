//
//  directory.cpp
//  CISC3595_5_atos-fs
//
//  Created by Angjelo Marku on 4/28/17.
//  Copyright © 2017 Angjelo Marku. All rights reserved.
//

#include "directory.h"
#include <iostream>
#include <algorithm>
using namespace std;




bool Directory::file_exists_check(string file_name)
{
    vector<string>::iterator it;  // declare an iterator to a vector of strings
  
    
    if (find(directory_vector.begin(), directory_vector.end(), file_name) != directory_vector.end())
    {
        
        return true;
    }
    else
    {
        return false;
    }
}




void Directory::add_file_to_dir(string file_name)
{
    
    if(file_exists_check(file_name)==false)
        directory_vector.push_back(file_name);
    
   
    else
        cout<<"Error! A file with this name already exists!"<<endl;
}





void Directory::delete_file_from_dir(string file_name)
{
   /* directory_vector.erase(remove(directory_vector.begin(), directory_vector.end(), file_name), directory_vector.end());
    cout<<"erased"<<endl;
    */
    
     if(file_exists_check(file_name)==true)
     {
         directory_vector.erase( find(directory_vector.begin(), directory_vector.end(), file_name));
         cout<<"erased"<<endl;
     }
    
    else
    {
        cout<<"This file does not exist"<<endl;
    }
}



void Directory::show_all()
{
    for(int i=0; i< directory_vector.size(); ++i)
        cout << directory_vector[i] <<" " <<endl;
}


int main()
{
    
    Directory dir;
  
    
    dir.add_file_to_dir("file1");
    dir.add_file_to_dir("file2");
    dir.add_file_to_dir("file3");
   
    dir.show_all();
    cout<<endl;

    dir.delete_file_from_dir("file1");
    dir.delete_file_from_dir("sqbhsuuq");
    dir.delete_file_from_dir("file3");
    cout<<endl;
    
    dir.show_all();

    return 0;
    
    
    
    
}
