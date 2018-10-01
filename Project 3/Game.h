// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#ifndef GAME_INCLUDE
#define GAME_INCLUDE

#include "Well.h"
#include "UserInterface.h"
#include <string>

class Game
{
public:
	Game(int width, int height);
	~Game();
	void play();
	bool playOneLevel();
	void displayPrompt(std::string s);
	void displayStatus();

	void drawPiece(Screen& screen, int xCoord, int yCoord, Piece* piece, int rotation); // draws the piece
	bool fall(int x, int y, Piece* piece, int rotation, int direction); // checks if the piece can fall
	bool rotateCurrentPiece(Piece* piece, int& currentRotation); // checks if the current piece can rotate
	int scoreFunction(); // increments the score
	void refreshScreen(); // refreshes the screen
	void rowsLeftUpdate(); // updates the number of rows left after each level
	void removeFilledRows(bool& endLevel, bool& nextLevel); // deletes filled rows in the well
	std::string toStringify(int becomeString); // turns numebrs into strings for status output
	void updatePieces(); // sets current piece to the next piece
	void chooseNextPiece(); // chooses the pieces
	Piece* chooseRandomPiece(int& pieceNum);

private:
	Well* m_well;
	Screen  m_screen;
	int     m_level;

	int fallX; // position x of the falling piece
	int fallY; // position y of the falling piece
	int down; // 0
	int right; // 1
	int left; // 2
	int same; // used for rotating a piece in place
	int mScore; // score count
	Piece* currentPiece; // keep track of current piece
	Piece* nextPiece; // number of the next piece
	int mRotation; // orientation number
	bool levelStarted; // level has started or not
	int maxTime; // the max timer time
	int scoreCalled; // number of times score function is called at once
	int rowsLeft; // the rows left till next level
	int currentPieceNum; // stores the enum number of the current piece
	int nextPieceNum; // stores the enum number of the next piece
};

#endif // GAME_INCLUDED
