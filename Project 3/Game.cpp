// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "Game.h"
#include "Well.h"
#include "Piece.h"
#include "UserInterface.h"
#include <string>
#include <queue>

using namespace std;

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int WELL_X = 0;
const int WELL_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;

Game::Game(int width, int height)
	: m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1)
{
	maxTime = 1000 - (100 * (m_level - 1)); // initialize the maximum time
	down = 0; // assigning numbers to directions
	right = 1;
	left = 2;
	same = 3;
	mScore = 0; // score starts at zero
	scoreCalled = 0; // number of times the function scoreCalled has been called
	rowsLeft = 5; // initial rows left begins at 5
	currentPiece = nullptr; // set current piece as a new piece pointer
	nextPiece = nullptr; // set nextPiece to nullptr
	m_well = new Well; // build the well initially
}

Piece* Game::chooseRandomPiece(int& pieceNum)
{
	switch (chooseRandomPieceType())
	{
	case PIECE_I:
		pieceNum = 0;
		return new PieceI; // make the next piece an I piece
		break;
	case PIECE_L:
		pieceNum = 1;
		return new PieceL; // make the next piece an L piece
		break;
	case PIECE_J:
		pieceNum = 2;
		return new PieceJ; // make the next piece a J piece
		break;
	case PIECE_T:
		pieceNum = 3;
		return new PieceT; // make the next piece a T piece
		break;
	case PIECE_O:
		pieceNum = 4;
		return new PieceO; // make the next piece an O piece
		break;
	case PIECE_S:
		pieceNum = 5;
		return new PieceS; // make the next piece an S piece
		break;
	case PIECE_Z:
		pieceNum = 6;
		return new PieceZ; // make the next piece a Z piece
		break;
	case PIECE_VAPOR:
		pieceNum = 7;
		return new PieceVapor; // make the next piece a vapor piece
		break;
	case PIECE_FOAM:
		pieceNum = 8;
		return new PieceFoam; // make the next piece a foam piece
		break;
	case PIECE_CRAZY:
		pieceNum = 9;
		return new PieceCrazy; // make the next piece a crazy piece
		break;
	}
	return nullptr;
}

void Game::chooseNextPiece()
{
	nextPiece = chooseRandomPiece(nextPieceNum); // set next piece to something else and update nextPieceNum
}

void Game::updatePieces()
{
	if (currentPiece != nullptr)
		delete currentPiece; // delete what is stored at current pointer
	currentPiece = nextPiece; // assign current to next
	currentPieceNum = nextPieceNum; // set the current piece to the next piece
	chooseNextPiece(); // set next piece to something else
}

void Game::play()
{
	m_well->display(m_screen, WELL_X, WELL_Y); // display the well
	levelStarted = false; // level hasn't started so display status wont draw next piece
	displayStatus();  //  score, rows left, level
	displayPrompt("Press the Enter key to begin playing Chetyris!");
	waitForEnter();  // [in UserInterface.h]

	for (;;)
	{
		chooseNextPiece();
		if (!playOneLevel())
			break;
		displayPrompt("Good job!  Press the Enter key to start next level!");
		waitForEnter();
		m_level++; // after every level, increase by one
	}
	displayPrompt("Game Over!  Press the Enter key to exit!");
	waitForEnter();
}

void Game::displayPrompt(std::string s)
{
	m_screen.gotoXY(PROMPT_X, PROMPT_Y);
	m_screen.printStringClearLine(s);   // overwrites previous text
	m_screen.refresh();
}

void Game::displayStatus()
{
	if (levelStarted == true)
	{
		m_screen.gotoXY(NEXT_PIECE_TITLE_X, NEXT_PIECE_TITLE_Y); // go to (16, 3)
		m_screen.printString("Next piece:"); // insert Next piece string
		for (int i = NEXT_PIECE_Y; i < NEXT_PIECE_Y + 4; i++) // clear the area where a piece was previously drawn for new piece
		{
			m_screen.gotoXY(NEXT_PIECE_X, i);
			m_screen.printStringClearLine("");
		}
		drawPiece(m_screen, NEXT_PIECE_X, NEXT_PIECE_Y, nextPiece, 0);
	}
	m_screen.gotoXY(SCORE_X, SCORE_Y); // go to (16, 8)
	m_screen.printStringClearLine(toStringify(mScore)); // insert the Score string
	m_screen.gotoXY(ROWS_LEFT_X, ROWS_LEFT_Y); // go to (16, 9)
	m_screen.printStringClearLine(toStringify(rowsLeft)); // insert Rows left string
	m_screen.gotoXY(LEVEL_X, LEVEL_Y); // go to (16, 10)
	m_screen.printStringClearLine(toStringify(m_level)); // insert Level string
}

bool Game::playOneLevel()
{
	discardPendingKeys();
	m_well->emptyWell(); // ensure well is empty at the beginning of each level
	rowsLeftUpdate();
	bool nextLevel = false;
	bool endLevel = false;
	bool fallDown = true;
	fallX = 4; //initial x coord on screen should start at 4
	fallY = 0; // initial y coord on screen should start at 0
	mRotation = 0; // initial rotation will be zero;
	//drawPiece(m_screen, fallX, fallY, currentPiece, mRotation);
	updatePieces();
	while (endLevel == false) // loop until game over
	{
		fallDown = true;
		levelStarted = true; // the level has started
		refreshScreen();
		Timer timer;
		while (timer.elapsed() < maxTime) // controls the pace of the fall
		{
			char userInput;
			if (fall(4, 0, nextPiece, mRotation, same) == false) // if the next piece isnt able to be inserted
			{
				endLevel = true; // end the level
				break; 
			}
			if (getCharIfAny(userInput) == true) // check if user input anything
			{
				switch (userInput)
				{
				case ARROW_DOWN:
					if (fall(fallX, fallY, currentPiece, mRotation, down) == true) // if can fall
					{
						fallY++; // increase fallY position by 1
						refreshScreen(); // refresh the screen
					}
					else
					{
						m_well->storePiece(fallX, fallY, currentPiece, mRotation, currentPieceNum); // otherwise store the piece in the well
						fallDown = false; // don't have it fall down again
						m_well->display(m_screen, WELL_X, WELL_Y); // display the well
						fallX = 4;
						fallY = 0;
						mRotation = 0;
						removeFilledRows(endLevel, nextLevel);
					}
					break;
				case ARROW_LEFT:
					if (currentPieceNum == 9)
					{
						if (fall(fallX, fallY, currentPiece, mRotation, right) == true)
							fallX++;
						refreshScreen();
						break;
					}
					else if (fall(fallX, fallY, currentPiece, mRotation, left) == true) // if can move left
						fallX--; // decrease fallX by 1
					refreshScreen();
					break;
				case ARROW_RIGHT:
					if (currentPieceNum == 9) // if crazy piece
					{
						if (fall(fallX, fallY, currentPiece, mRotation, left) == true)
							fallX--;
						refreshScreen();
						break;
					}
					else if (fall(fallX, fallY, currentPiece, mRotation, right) == true) // if can move left
						fallX++; // increase fallX by 1
					refreshScreen();
					break;
				case ARROW_UP:
					rotateCurrentPiece(currentPiece, mRotation);
					refreshScreen();
					break;
				case 'Q':
				case 'q':
					endLevel = true;
					nextLevel = false;
					refreshScreen();
					break;
				case ' ':
					while (fall(fallX, fallY, currentPiece, mRotation, down) == true)
					{
						fallY++;
					}
					m_well->storePiece(fallX, fallY, currentPiece, mRotation, currentPieceNum);
					m_well->display(m_screen, WELL_X, WELL_Y);
					fallX = 4;
					fallY = 0;
					mRotation = 0;
					removeFilledRows(endLevel, nextLevel);
					if (!endLevel)
						refreshScreen();
					fallDown = false;
					timer.start();
					break;
				default:
					discardPendingKeys();
					break;
				}
			}
			if (fallDown && !endLevel)
			{
				if (fall(fallX, fallY, currentPiece, mRotation, down) == true) // if can fall down
				{
					fallY++; // increase fallY by 1
					refreshScreen();
				}
				else
				{
					m_well->storePiece(fallX, fallY, currentPiece, mRotation, currentPieceNum);
					m_well->display(m_screen, WELL_X, WELL_Y);
					fallX = 4;
					fallY = 0;
					mRotation = 0;
					removeFilledRows(endLevel, nextLevel);
				}
				fallDown = false;
				if (!endLevel)
					refreshScreen();
			}
		}
	}
	return nextLevel; 
}


void Game::drawPiece(Screen& screen, int xCoord, int yCoord, Piece* piece, int rotation) // draws the piece in the game
{
	int l = 0;
	for (int i = xCoord; i < xCoord + 4; i++)
	{
		int k = 0;
		for (int j = yCoord; j < yCoord + 4; j++)
		{
			screen.gotoXY(i, j);
			if (piece->getPiecePart(rotation, l, k) == 1)
				screen.printChar('#');
			k++;
		}
		l++;
	}
	screen.gotoXY(90000, 1000000);
}

bool Game::fall(int x, int y, Piece* piece, int rotation, int direction)
{
	if (m_well->canMove(x, y, piece, rotation, direction))
		return true;
	return false;
}

bool Game::rotateCurrentPiece(Piece* piece, int& currentRotation) // rotate the current piece
{
	currentRotation++;
	if (currentRotation == 4)
	{
		currentRotation = 0;
		if (m_well->canMove(fallX, fallY, piece, currentRotation, 3) == true)
		{
			return true;
		}
		else
			currentRotation = 3;
		return false;
	}
	if (m_well->canMove(fallX, fallY, piece, currentRotation, 3) == true)
	{
		return true;
	}
	else
		currentRotation--;
	return false;
}

int Game::scoreFunction() // deterimines the score
{
	switch (scoreCalled)
	{
	case 0: 
		break;
	case 1:
		mScore = mScore + 100;
		break;
	case 2:
		mScore = mScore + 200;
		break;
	case 3:
		mScore = mScore + 300;
		break;
	case 4:
		mScore = mScore + 800;
		break;
	default:
		mScore = mScore + 1600;
		break;
	}
	scoreCalled = 0;
	if (rowsLeft <= 0)
		rowsLeft = 0;
	return mScore;
}

void Game::refreshScreen() // refreshes the screen
{
	displayStatus(); // update the status
	m_well->display(m_screen, WELL_X, WELL_Y); // redisplay the well
	drawPiece(m_screen, fallX, fallY, currentPiece, mRotation); // draw the current piece
	//m_screen.gotoXY(9999999999999, 999999999); // trying to get the cursor away... didnt work
}

void Game::rowsLeftUpdate()
{
	rowsLeft = 5 * m_level; // rows left at the beginning of each level
}

string Game::toStringify(int becomeString) // general function for the display prompts
{
	string str = to_string(becomeString); // convert the number of rows left into a string
	int len = str.length(); // get the length of the string
	int difference = 7 - len; // get the difference between the size of the right justified field and the length of the #
	string result = ""; // create an empty string that we will be adding the numbers into starting with the last number
	for (int i = 0; i < difference; i++) // add in the number of preceding spaces required
		result += " ";
	for (int i = 0; i < len; i++) // add in the contents of the string from beginning to end
		result += str[i];
	if (becomeString == rowsLeft)
		return ("Rows Left: " + result);
	if (becomeString == m_level)
		return ("Level:     " + result);
	if (becomeString == mScore)
		return ("Score:     " + result);
	else
		return "";
}

void Game::removeFilledRows(bool& endLevel, bool& nextLevel) // called once a piece is stored
{ 
	for (int i = 0; i < 18; i++) // loop over every row besides the very bottom wall
	{
		if (m_well->isRowFull(i) == true) // if the row is filled
		{
			scoreCalled++; // increment the number of times scoreCalled
			rowsLeft--; // decrease number of rows left
			if (rowsLeft <= 0) // if rows left is 0 or less
			{
				endLevel = true; // end the level
				nextLevel = true; // move on to the next level
				m_well->display(m_screen, WELL_X, WELL_Y); // display the well once more
			}
			else // if not yet ended level
			{
				m_well->deleteRow(i); // delete the full row
				discardPendingKeys(); 
			}
		}
	}
	scoreFunction(); // call the score function to determine how many points to add to the score
	if (rowsLeft <= 0) // if level ended
		displayStatus(); // only redisplay the status, not refresh the screen
	else // if level not ended
	{
		updatePieces(); // give the next piece pointer a new piece
		discardPendingKeys();
	}
}

Game::~Game()
{
	delete m_well;
	delete currentPiece;
	delete nextPiece;
}
