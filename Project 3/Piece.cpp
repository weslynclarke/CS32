// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "Piece.h"
#include "UserInterface.h"
#include <queue>
using namespace std;

int PieceI::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return Io0[y][x];
		break;
	case 1:
		return Io1[y][x];
		break;
	case 2:
		return Io2[y][x];
		break;
	case 3:
		return Io3[y][x];
		break;
	default:
		break;
	}
	return 0; // shouldn't ever be called
}

int PieceL::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return Lo0[y][x];
		break;
	case 1:
		return Lo1[y][x];
		break;
	case 2:
		return Lo2[y][x];
		break;
	case 3:
		return Lo3[y][x];
		break;
	default:
		break;
	}
	return 0; 
}

int PieceJ::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return Jo0[y][x];
		break;
	case 1:
		return Jo1[y][x];
		break;
	case 2:
		return Jo2[y][x];
		break;
	case 3:
		return Jo3[y][x];
		break;
	default:
		break;
	}
	return 0;
}

int PieceT::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return To0[y][x];
		break;
	case 1:
		return To1[y][x];
		break;
	case 2:
		return To2[y][x];
		break;
	case 3:
		return To3[y][x];
		break;
	default:
		break;
	}
	return 0;
}

int PieceO::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return Oo0[y][x];
		break;
	case 1:
		return Oo1[y][x];
		break;
	case 2:
		return Oo2[y][x];
		break;
	case 3:
		return Oo3[y][x];
		break;
	default:
		break;
	}
	return 0;
}

int PieceS::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return So0[y][x];
		break;
	case 1:
		return So1[y][x];
		break;
	case 2:
		return So2[y][x];
		break;
	case 3:
		return So3[y][x];
		break;
	default:
		break;
	}
	return 0;
}

int PieceZ::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return Zo0[y][x];
		break;
	case 1:
		return Zo1[y][x];
		break;
	case 2:
		return Zo2[y][x];
		break;
	case 3:
		return Zo3[y][x];
		break;
	default:
		break;
	}
	return 0;
}

int PieceVapor::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return Vo0[y][x];
		break;
	case 1:
		return Vo1[y][x];
		break;
	case 2:
		return Vo2[y][x];
		break;
	case 3:
		return Vo3[y][x];
		break;
	default:
		break;
	}
	return 0;
}

int PieceFoam::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return Fo0[y][x];
		break;
	case 1:
		return Fo1[y][x];
		break;
	case 2:
		return Fo2[y][x];
		break;
	case 3:
		return Fo3[y][x];
		break;
	default:
		break;
	}
	return 0;
}

int PieceCrazy::getPiecePart(int pieceRotation, int x, int y)
{
	switch (pieceRotation) // switch on the input pieceRotation int
	{
	case 0:
		return Co0[y][x];
		break;
	case 1:
		return Co1[y][x];
		break;
	case 2:
		return Co2[y][x];
		break;
	case 3:
		return Co3[y][x];
		break;
	default:
		break;
	}
	return 0;
}

