// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "Well.h"
#include "UserInterface.h"
#include <queue>
using namespace std;

Well::Well()
{
	piecetype = new Piece;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			// if cols = 0 or 11
			if ((j == 0 || j == cols - 1) || i == rows-1)
				mWell[i][j] = '@';
			else
				mWell[i][j] = ' ';
		}
	}
}

void Well::display(Screen& screen, int x, int y) // displays the empty well on the screen
{
	for (int i = x; i < rows; i++) // loop over and create the entire well with borders starting at the top row
	{
		for (int j = y; j < cols; j++) // loop over y position
		{
			screen.gotoXY(j, i); // go to coordinate (i, j)
			screen.printChar(mWell[i][j]); // print out wall
		}
	} // have created an empty well and displayed an empty well
}

void Well::emptyWell()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			// if cols = 0 or 11
			if ((j == 0 || j == cols - 1) || i == rows - 1)
				mWell[i][j] = '@';
			else
				mWell[i][j] = ' ';
		}
	}
}

bool Well::spaceClear(int xCoord, int yCoord) // check if the space is clear
{
	if (mWell[yCoord][xCoord] == ' ') // if space is empty
		return true; // return true
	return false; // else return false
}

bool Well::canMove(int xCoord, int yCoord, int piece, int rotation, int direction) // can you move the tetromino?
{
	int xWell = xCoord;
	if (direction == 0) // if direction is down
	{
		for (int i = 0; i < 4; i++)
		{
			xWell = xCoord;
			for (int j = 0; j < 4; j++)
			{
				if (piecetype->getTetrominoPart(piece, rotation, j, i) == 1 && !spaceClear(xWell, yCoord + 1)) //if space isnt clear
					return false; // return false
				// else continue looping
				xWell++;
			}
			yCoord++;
		}
	}
	if (direction == 1) // if direction is right
	{
		for (int i = 0; i < 4; i++)
		{
			xWell = xCoord;
			for (int j = 0; j < 4; j++)
			{
				if (piecetype->getTetrominoPart(piece, rotation, j, i) == 1 && !spaceClear(xWell + 1, yCoord)) //if space isnt clear
					return false; // return false
				// else continue looping
				xWell++;
			}
			yCoord++;
		}
	}
	if (direction == 2) // if direction is left
	{
		for (int i = 0; i < 4; i++)
		{
			xWell = xCoord;
			for (int j = 0; j < 4; j++)
			{
				if (piecetype->getTetrominoPart(piece, rotation, j, i) == 1 && !spaceClear(xWell - 1, yCoord)) //if space isnt clear
					return false; // return false
				// else continue looping
				xWell++;
			}
			yCoord++;
		}
	}
	if (direction == 3) // if direction is the same position
	{
		for (int i = 0; i < 4; i++)
		{
			xWell = xCoord;
			for (int j = 0; j < 4; j++)
			{
				if (piecetype->getTetrominoPart(piece, rotation, j, i) == 1) // if tetromino part is a #
				{
					if (!spaceClear(xWell, yCoord)) //if space isnt clear
						return false; // return false
				}
				// else continue looping
				xWell++;
			}
			yCoord++;
		}
	}
	return true; // generally return true
}

bool Well::canRotate(int xCoord, int yCoord, int piece, int rotation)
{
	return(canMove(xCoord, yCoord, piece, rotation, 3));
}

void Well::storePiece(int xCoord, int yCoord, int piece, int rotation)
{
	if (piece == 8)
	{
		foamX = xCoord + 1;
		foamY = yCoord + 1;
		foamBomb(foamX, foamY);
	}
	else if (piece == 7)
		vaporBomb(xCoord, yCoord);
	else
	{
		for (int i = 0; i < 4; i++) // loop over tetromino's rows
		{
			int x = xCoord; // set x back to the x coord before each loop
			for (int j = 0; j < 4; j++) // loop over tetromino's columns
			{
				if (piecetype->getTetrominoPart(piece, rotation, j, i) == 1) // if piece is #
					mWell[yCoord][x] = '$'; // store at the x and y coordinate of the well $
				x++; // increase x by one
			}
			yCoord++;
		}
	}
}

void Well::foamBomb(int xCoord, int yCoord)
{
	int x = xCoord; 
	int y = yCoord;
	queue<int> xcoords; // one to track the x coordinates 
	queue<int> ycoords; // one to track the y coordinates
	xcoords.push(xCoord); // push the starting x onto the x queue
	ycoords.push(yCoord); // push the starting y onto the y queue
	while ((x >= xCoord - 2 && x <= xCoord + 2) && (y >= yCoord - 2 && y <= yCoord + 2) && !xcoords.empty() && !ycoords.empty())
	{
		mWell[y][x] = '*'; // set the coordinate in the well to *
		if (y-1 >= yCoord - 2 && spaceClear(x, y - 1)) // check north
		{
			xcoords.push(x);
			ycoords.push(y - 1);
			mWell[y - 1][x] = '.';
		}
		if (x-1 >= xCoord - 2 && spaceClear(x - 1, y)) // check west
		{
			xcoords.push(x - 1);
			ycoords.push(y);
			mWell[y][x - 1] = '.';
		}
		if (y+1 <= yCoord + 2 && spaceClear(x, y + 1)) // check south
		{
			xcoords.push(x);
			ycoords.push(y + 1);
			mWell[y + 1][x] = '.';
		}
		if (x+1 <= xCoord + 2 && spaceClear(x + 1, y)) // check east
		{
			xcoords.push(x + 1);
			ycoords.push(y);
			mWell[y][x + 1] = '.';
		}
		if (!xcoords.empty() && !ycoords.empty())
		{
			xcoords.pop(); // pop top values off of each queue
			ycoords.pop();
			if (xcoords.size() > 0 && ycoords.size() > 0)
			{
				x = xcoords.front(); // set x to the front x value
				y = ycoords.front(); // set y to the front y value
			}
		}
	}
	while (!xcoords.empty() && !ycoords.empty())
	{
		x = xcoords.front();
		y = ycoords.front();
		mWell[y][x] = '*';
		xcoords.pop();
		ycoords.pop();
	}
	mWell[yCoord][xCoord] = '*';
}


void Well::vaporBomb(int xCoord, int yCoord)
{ 
	while (yCoord - 2 >= 0) // y can never be less than zero
	{
		int y = yCoord - 2; // start two rows above
		int x = xCoord + 1; // start one x coord to the right since the vapor bomb block starts one over
		for (int i = 0; i < 5; i++) // loop for above and below vaporBomb and vapor bomb itself
		{
			for (int j = 0; j < 2; j++) // loop over the 2 coordinates
			{
				if (mWell[y][x] != '@')
					mWell[y][x] = ' ';
				x++;
			}
			x = x - 2; // set x back to original coordinate
			y++; // increase y by one, only 5 times
		}
		break; // don't save the piece
	}
}

bool Well::isRowFull(int yRow)
{
	for (int i = 0; i < cols; i++)
	{
		if (spaceClear(i, yRow))
			return false;
	}
	return true;
}

void Well::deleteRow(int yRow)
{
	for (int i = yRow; i >= 0; i--)
	{
		if (i == 0)
		{
			for (int j = 0; j < cols; j++) // use width - 1 because width-1 element is the wall
			{
				if (j == 0 || j == cols-1)
					mWell[i][0] = '@'; // set top row to empty
				else
					mWell[i][0] = ' '; // set top row to empty
			}
		}
		else
		{
			for (int j = 1; j < cols - 1; j++)
				mWell[i][j] = mWell[i - 1][j]; // set each block to the block previously above it
		}
	}
}
