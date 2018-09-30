// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "Piece.h"
#include "UserInterface.h"
#include <queue>
using namespace std;

Piece::Piece()
{}

int Piece::getTetrominoPart(int Type, int pieceRotation, int x, int y)
{
	return piece[Type][pieceRotation][y][x];
}

void Piece::choosePieces(int& current, int& next)
{
	queue<int> curAndNext;
	current = next;
	curAndNext.push(chooseRandomPieceType());
	next = curAndNext.front();
	curAndNext.pop();
}

