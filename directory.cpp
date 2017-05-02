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

Directory::Directory()
{
    cout << "Directory created." << endl;
}


bool Directory::file_exists_check(string file_name)
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




void Directory::add_file_to_dir(string file_name)
{
    
    if(file_exists_check(file_name)==false)
    {
        directory_vector.push_back(file_name);
        cout<<file_name<<" added"<<endl;
    }
   
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
         cout<<file_name<<" erased"<<endl;
     }
    
    else
    {
        cout<<file_name<<" does not exist, can't be erased!"<<endl;
    }
}



void Directory::show_all()
{
    for(int i=0; i< directory_vector.size(); ++i)
        cout << directory_vector[i] <<" "<<endl;
}

int Directory::directorylength()
{
    return directory_vector.size();
}

void Directory::show_specific(int index)
{
    cout<< directory_vector[index];
}


/*
int main()
{
    
    Directory dir;
  
   
    dir.add_file_to_dir("file1");
    dir.add_file_to_dir("file2");
    dir.add_file_to_dir("file3");
    cout<<endl;
    
    cout<<"Files in vector as of now:"<<endl;
    cout<<endl;
    dir.show_all();
    cout<<endl;

    cout<<"Checking if certain files exist"<<endl;
    
    if(dir.file_exists_check("file1"))
    {
        cout<<"file 1 exists(in the final program this function will just return a bool value for UI processing"<<endl;
    }
    else
    {
        cout<<"It does not exist"<<endl;
    }
    
    if(dir.file_exists_check("file 55"))
    {
        cout<<"file 55 exists(in the final program this function will just return a bool value for UI processing"<<endl;
    }
    else
    {
        cout<<"File 55 does not exist"<<endl;
    }
    
    cout<<endl;
    
    dir.delete_file_from_dir("file1");
    dir.delete_file_from_dir("file102");
    dir.delete_file_from_dir("file3");
    cout<<endl;
    
    cout<<"Files in vector as of now:"<<endl;
    dir.show_all();

    return 0;
    
    
    
    
}
 */

