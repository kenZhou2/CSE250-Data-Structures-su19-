// File: a2.hpp
//  Ken        
// Zhou
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A2_HPP
#define A2_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF key_value_sequences IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS THAN
// <algorithm>, <list>, <vector>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>
#include <list>
#include <vector>
using namespace std;

class key_value_sequences {
    vector<vector<int>>vect; 
    vector<int>seq;
    //list<int>temp;  
    vector<int>temp; 
    //vector<int> temp;
    //vector<int> seq;
    public:
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY

    // IMPLEMENT ME: SHOULD RETURN SIZE OF A SEQUENCE FOR GIVEN KEY
    
    int size(int key)const
    {
        // int size = 0; 
        // int length = vect.size(); 
        // for(int x = 0; x < length; x++)
        // {
        //     if(vect.at(x).front() == key)
        //     {
        //         size++;
        //     }

        // }
        int size = 0;
        for(int x = 0; x < vect.size(); x++)
        {
            if(vect.at(x).front() == key)
            {
                size = vect.at(x).size() - 1;
                return size; 
            }

        }
        return 0; 
        

    }
    // IMPLEMENT ME: SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
    const int* data(int key)const
    { 
        vector<int>seq; 
        for(int x = 0; x < vect.size(); x++)
        {
            if(vect.at(x).front() == key)
            {
                return vect.at(x).data() + 1; 
            }
        }
        return nullptr;
    }
    // IMPLEMENT ME: INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
    void insert(int key, int value)
    {
        int check = 0;
        for(int x =0; x < vect.size(); x++)
        {
            if(vect.at(x).front() == key)
            {
                vect.at(x).push_back(value);
                check = 1;  
            }
        }
        if(check == 0)
        {
            temp.push_back(key); 
            temp.push_back(value);
            vect.push_back(temp);
            temp.clear();
        }
    }

}; // class key_value_sequences

#endif // A2_HPP


//niggers