// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#ifndef WELL_INCLUDED
#define WELL_INCLUDED

#include "Piece.h"

class Screen;

const int cols = 12;
const int rows = 19;

class Well
{
public:
	Well();
	void display(Screen& screen, int x, int y); // display the well
	void emptyWell();
	bool spaceClear(int xCoord, int yCoord); // checks if a certain coordinate is empty
	bool canMove(int xCoord, int yCoord, Piece* piece, int rotation, int direction); // checks if you can move the piece 
	void storePiece(int xCoord, int yCoord, Piece* piece, int rotation, int pieceNum); // stores the piece on the board
	bool isRowFull(int yRow); // checks to see if a row is filled to delete it and score points
	void deleteRow(int yRow); // deletes a complete line
	void vaporBomb(int xCoord, int yCoord);
	void foamBomb(int xCoord, int yCoord);

private:
	char mWell[rows][cols]; // char multidimensional array of the well
	int foamX;
	int foamY;

};

#endif // WELL_INCLUDED
