//
//  directory.hpp
//  CISC3595_5_atos-fs
//
//  Created by Angjelo Marku on 4/28/17.
//  Copyright © 2017 Angjelo Marku. All rights reserved.
//

#ifndef directory_hpp
#define directory_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


class Directory{
    public:
        bool file_exists_check(string file_name);
        void add_file_to_dir(string file_name);
        void delete_file_from_dir (string file_name);
        void show_all();
    
    
    private:
        vector<string> directory_vector;
    
    
    
    
};







#endif /* directory_hpp */
