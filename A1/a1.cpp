// // File: a1.cpp
// // Ken	
// // Zhou
// // I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// // I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// // I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include <math.h>
using namespace std;

int conversion(int a, int b)
{
	int store = a * b;
	return store;

}

void print(vector<int> foo, vector<int>count, string line, int k, int p)
{	
	//store the values as the index that way there wont be any repeats, only one value, also make a count. 
	vector<string> vect;
	int size = foo.size() - k;
	int store = 0;
	int i = k - 1; 
	int vectSize = vect.size();
	for(int b = 0; b < (pow(4,k)); b++)
    {
    	vect.push_back("");
    }
	for(int x = 0; x <= size; x++)
	{
		for(int y = 0; y < k; y++) 
		{
			int pos = x+y;
			store += conversion(foo.at(pos),(pow(4,i)));  
			i--; 
		}
		if(i < 1)
		{
			vect.at(store) = line.substr(x,k);
			count.at(store)++; 
			i = k - 1;
			store = 0;
		}
	}
	for(int a = 0; a < vect.size(); a++)
	{
		if(vect.at(a)!= "" && count.at(a) >= p)
		{
			std::cout << vect.at(a) << " " << count.at(a) << endl;
		}
	}
}
int main(int argc, char* argv[])
{
	ifstream inputfile(argv[1]); 
	int k = atoi(argv[2]);
	int p = atoi(argv[3]);
	vector<int> foo;
	vector<int> count;
	vector<string>str; 
	string line;
	getline(inputfile,line);
	int a = 0, c = 1, t = 3, g = 2;
	int A = 0, C = 0, T = 0, G = 0;
	int length = line.length();

   	// if(length < k){
    // 	std::cout << "error" << "\n"; 
    // }
    //else 
   // {
		for(int x = 0; x <= length; x++)
		{
			if(line[x] == 'A')
			{
	    		foo.push_back(a);
	    		A++;
			}
	    	if(line[x] == 'C')
	    	{
	    		foo.push_back(c);
	    		C++;
	    	}
	    	if(line[x] == 'T')
	    	{
	    		foo.push_back(t);
	    		T++;
	    	}
	    	if (line[x]== 'G')
	    	{
	    		foo.push_back(g);
	    		G++;
	    	}
	    }
	    for(int x = 0; x < pow(4,k); x++)
	    {
	    	count.push_back(0);
	    }
	
		std::cout << 0 << " " << k << " " << length << endl;
		std::cout << 1 << " " <<  A << " " << C << " " << G << " " << T << "\n";
		if(length < k)
		{
			std::cout<< "error" << endl;
		}
		else{
		print(foo, count, line, k, p);
   		}
    
}
