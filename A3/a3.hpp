#ifndef A3_HPP
#define A3_HPP
//#include <vector>
#include <algorithm>
#include <iostream> 

#include "Maze.hpp"
using namespace std;
//int stack = 0;

int sorting(std::vector <int> vect)
{
	sort(vect.begin(), vect.end());

	return vect.front();
}

int minimum(int right, int down, int left, int up)
{
	if(right == -1)
		right = 10000; 
	if(down == -1)
		down = 10000;
	if(left == -1)
		left = 10000;
	if(up == -1)
		up = 10000;

	return min(min(right, down),min(left,up));
}
// implement your function distance
int distance(Maze& maze, int sx, int sy, int fx, int fy) {

	//std::vector<int>vect; 
	int min = -1;
	int right = -1;
	int left = -1;
	int down = -1;
	int up = -1;
	maze.mark(sx,sy); 
	if(sx == fx && sy == fy)
	{
		maze.unmark(sx, sy);  
		return 0; 
	}
	else 
	{
		if(!maze.is_visited(sx,sy+1) && maze.is_open(sx,sy+1))
		{
			right = distance(maze, sx, sy+1, fx, fy);
		}
		if(!maze.is_visited(sx + 1,sy) && maze.is_open(sx + 1,sy))
		{
			down = distance(maze, sx + 1, sy, fx, fy);
		}
		if(!maze.is_visited(sx,sy - 1) && maze.is_open(sx,sy - 1))
		{
			left = distance(maze, sx, sy - 1, fx, fy);
		}
		if(!maze.is_visited(sx - 1,sy) && maze.is_open(sx - 1,sy))
		{
			up = distance(maze, sx - 1, sy, fx, fy); 
		}

		//min = sorting(vect); 
	}
	// if(right != -1)
	// 	vect.push_back(right);
	// if(down != -1)
	// 	vect.push_back(down);
	// if(left != -1)
	// 	vect.push_back(left);
	// if(up != -1)
	// 	vect.push_back(up);
	//std::min(right)
	
	min = minimum(right,down,left,up);
	//vect.clear();
	maze.unmark(sx, sy);  
	return 1+min;


} 
// distance

#endif // A3_HPP
