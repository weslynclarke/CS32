// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#ifndef PIECE_INCLUDE
#define PIECE_INCLUDE

enum PieceType {
	PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
	PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

PieceType chooseRandomPieceType();

class Piece
{
public:
	Piece() {};
	virtual ~Piece() = default;
	virtual int getPiecePart(int pieceRotation, int x, int y) = 0;
};

class PieceI : public Piece // piece 0
{
public:
	PieceI() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece I
	int Io0[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	};
	int Io1[4][4] =
	{
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 }
	};
	int Io2[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	};
	int Io3[4][4] =
	{
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 }
	};
};


class PieceL : public Piece // piece 1
{
public:
	PieceL() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece L
	int Lo0[4][4] =
	{ // L orientation 0
		{ 0,0,0,0 },
		{ 1,1,1,0 },
		{ 1,0,0,0 },
		{ 0,0,0,0 }
	};
	int Lo1[4][4] =
	{ // L orientation 1
		{ 0,1,1,0 },
		{ 0,0,1,0 },
		{ 0,0,1,0 },
		{ 0,0,0,0 }
	};
	int Lo2[4][4] =
	{ // L orientation 2
		{ 0,0,0,0 },
		{ 0,0,1,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }
	};
	int Lo3[4][4] =
	{ // L orientation 3
		{ 0,0,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,1,0 }
	};
};


class PieceJ : public Piece // piece 2
{
public:
	PieceJ() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece J
	int Jo0[4][4] =
	{ // J orientation 0
		{ 0,0,0,0 },
	{ 0,1,1,1 },
	{ 0,0,0,1 },
	{ 0,0,0,0 }
	};
	int Jo1[4][4] =
	{ // J orientation 1
		{ 0,0,0,0 },
	{ 0,0,1,0 },
	{ 0,0,1,0 },
	{ 0,1,1,0 }
	};
	int Jo2[4][4] =
	{ // J orientation 2
		{ 0,0,0,0 },
	{ 0,1,0,0 },
	{ 0,1,1,1 },
	{ 0,0,0,0 }
	};
	int Jo3[4][4] =
	{
		{ 0,1,1,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 }
	};
};


class PieceT : public Piece // piece 3
{
public:
	PieceT() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece T
	int To0[4][4] =
	{ // T orientation 0
		{ 0,1,0,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	};
	int To1[4][4] =
	{ // T orientation 1
		{ 0,1,0,0 },
		{ 0,1,1,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	};
	int To2[4][4] =
	{ // T orientation 2
		{ 0,0,0,0 },
		{ 1,1,1,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	};
	int To3[4][4] =
	{ // T orientation 3
		{ 0,1,0,0 },
		{ 1,1,0,0 },
		{ 0,1,0,0 },
		{ 0,0,0,0 }
	};
};


class PieceO : public Piece // piece 4
{
public:
	PieceO() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece O
	int Oo0[4][4] =
	{ // O orientation 0
		{ 1,1,0,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Oo1[4][4] =
	{ // O orientation 1
		{ 1,1,0,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Oo2[4][4] =
	{ // O orientation 2
		{ 1,1,0,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Oo3[4][4] =
	{ // O orientation 3
		{ 1,1,0,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
};


class PieceS : public Piece // piece 5
{
public:
	PieceS() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece S
	int So0[4][4] =
	{ // S orientation 0
		{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 }
	};
	int So1[4][4] =
	{ // S orientation 1
		{ 0,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,1,0 },
	{ 0,0,0,0 }
	};
	int So2[4][4] =
	{ // S orientation 2
		{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 }
	};
	int So3[4][4] =
	{ // S orientation 3
		{ 0,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,1,0 },
	{ 0,0,0,0 }
	};
};


class PieceZ : public Piece // piece 6
{
public:
	PieceZ() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece Z
	int Zo0[4][4] =
	{ // Z orientation 0
		{ 0,0,0,0 },
	{ 1,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,0,0 }
	};
	int Zo1[4][4] =
	{ // Z orientation 1
		{ 0,0,1,0 },
	{ 0,1,1,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 }
	};
	int Zo2[4][4] =
	{ // Z orientation 2
		{ 0,0,0,0 },
	{ 1,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,0,0 }
	};
	int Zo3[4][4] =
	{ // Z orientation 3
		{ 0,0,1,0 },
	{ 0,1,1,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 }
	};
}; 


class PieceVapor : public Piece //piece 7
{
public:
	PieceVapor() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece Vapor
	int Vo0[4][4] =
	{ // vapor orientation 0
		{ 0,1,1,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Vo1[4][4] =
	{ // vapor orientation 1
		{ 0,1,1,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Vo2[4][4] =
	{ // vapor orientation 2
		{ 0,1,1,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Vo3[4][4] =
	{ // vapor orientation 3
		{ 0,1,1,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
};


class PieceFoam : public Piece // piece 8
{
public:
	PieceFoam() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece Foam
	int Fo0[4][4] = 
	{ // foam orientation 0
		{ 0,0,0,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Fo1[4][4] = 
	{ // foam orientation 1
		{ 0,0,0,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Fo2[4][4] = 
	{ // foam orientation 2
		{ 0,0,0,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Fo3[4][4] =
	{ // foam orientation 3
		{ 0,0,0,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
};


class PieceCrazy : public Piece // piece 9
{
public:
	PieceCrazy() {};
	virtual int getPiecePart(int pieceRotation, int x, int y);
private: // the 4 different orientations of piece Crazy
	int Co0[4][4] =
	{ // crazy shape orientation 0
		{ 1,0,0,1 },
	{ 0,1,1,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};
	int Co1[4][4] =
	{ // crazy shape orientation 1
		{ 0,0,0,1 },
	{ 0,0,1,0 },
	{ 0,0,1,0 },
	{ 0,0,0,1 }
	};
	int Co2[4][4] =
	{ // crazy shape orientation 2
		{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 1,0,0,1 }
	};
	int Co3[4][4] =
	{ // crazy shape orientation 3
		{ 1,0,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 1,0,0,0 }
	};
};


#endif // PIECE_INCLUDED
