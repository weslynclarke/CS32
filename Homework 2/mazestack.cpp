// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include <stack>
#include <iostream>
using namespace std;

bool pathExists(char maze[][10], int sr, int sc, int er, int ec);

class Coord
{
public:
	Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
	int r() const { return m_r; }
	int c() const { return m_c; }
private:
	int m_r;
	int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
	bool pathfound = false;
	Coord startingCoord(sr, sc); // create a starting point coordinate
	Coord endingCoord(er, ec); // create an ending point coordinate
	stack<Coord> coordStack; 
	coordStack.push(startingCoord); // push the starting coordinate on the stack
	maze[sr][sc] = '@'; // mark that spot as @ meaning visited
	int row = sr; // keep track of the row
	int col = sc; // keep track of the column
	while (coordStack.empty() != true)
	{
		Coord currentCoord = coordStack.top(); // keep track of the current coordinate
		coordStack.pop(); // pop the current coordinate off of the stack
		row = currentCoord.r(); // set the row to the current coordinate's row
		col = currentCoord.c(); // set the col to the current coordinate's col
		if (row == endingCoord.r() && col == endingCoord.c()) // if current coordinate is the end point
		{
			pathfound = true; // set pathfound to true
			break; // break out of the loop
		}
		if (maze[row-1][col] != 'X' && maze[row-1][col] != '@') // can move north & not visited?
		{
			Coord currentCoord(row - 1, col); // make the current coordinate the free coordinate
			coordStack.push(currentCoord); // push the current coordinate onto the stack
			maze[row - 1][col] = '@'; // mark that spot as visited
		}
		if (maze[row][col - 1] != 'X' && maze[row][col - 1] != '@') // can move west & not visited?
		{
			Coord currentCoord(row, col - 1); // make the current coordinate the free coordinate
			coordStack.push(currentCoord); // push the coordinate onto the stack
			maze[row][col - 1] = '@'; // mark the spot as visited
		}
		if (maze[row + 1][col] != 'X' && maze[row + 1][col] != '@') // can move south & not visited?
		{
			Coord currentCoord(row + 1, col); // make the current coordinate the free coordinate
			coordStack.push(currentCoord); // push the coordinate onto the stack
			maze[row + 1][col] = '@'; // mark the spot as visited
		}
		if (maze[row][col + 1] != 'X' && maze[row][col + 1] != '@') // can move east & not visited?
		{
			Coord currentCoord(row, col + 1); // make the current coordinate the free coordinate
			coordStack.push(currentCoord); // push the coordinate onto the stack
			maze[row][col + 1] = '@'; // mark the spot as visited
		}
	}
	return pathfound;
}


