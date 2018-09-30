// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "Game.h"
#include "Well.h"
#include "Piece.h"
#include "UserInterface.h"
#include <string>


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

const char pieces[10 /*10 different shapes*/][4 /*4 different rotations for each*/][4][4] =
{
	{ // I, 0
		{ // I orientation 0
			{ '.','.','.','.' },
			{ '#','#','#','#' },
			{ '.','.','.','.' },
			{ '.','.','.','.' }
		},
			{ // I orientation 1
				{ '.','#','.','.' },
{ '.','#','.','.' },
{ '.','#','.','.' },
{ '.','#','.','.' }
			},
			{ // I orientation 2
				{ '.', '.', '.', '.' },
{ '#','#','#','#' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // I orientation 3
				{ '.','#','.','.' },
{ '.','#','.','.' },
{ '.','#','.','.' },
{ '.','#','.','.' }
			}
	},
		{ // L, 1
			{ // L orientation 0
				{ '.','.','.','.' },
{ '#','#','#','.' },
{ '#','.','.','.' },
{ '.','.','.','.' }
			},
			{ // L orientation 1
				{ '.','#','#','.' },
{ '.','.','#','.' },
{ '.','.','#','.' },
{ '.','.','.','.' }
			},
			{ // L orientation 2
				{ '.','.','.','.' },
{ '.','.','#','.' },
{ '#','#','#','.' },
{ '.','.','.','.' }
			},
			{ // L orientation 3
				{ '.','.','.','.' },
{ '.','#','.','.' },
{ '.','#','.','.' },
{ '.','#','#','.' }
			}
		},
		{ // J, 2
			{ // J orientation 0
				{ '.','.','.','.' },
{ '.','#','#','#' },
{ '.','.','.','#' },
{ '.','.','.','.' }
			},
			{ // J orientation 1
				{ '.','.','.','.' },
{ '.','.','#','.' },
{ '.','.','#','.' },
{ '.','#','#','.' }
			},
			{ // J orientation 2
				{ '.','.','.','.' },
{ '.','#','.','.' },
{ '.','#','#','#' },
{ '.','.','.','.' }
			},
			{
				{ '.','#','#','.' },
{ '.','#','.','.' },
{ '.','#','.','.' },
{ '.','.','.','.' }
			},
		},
		{ // T, 3
			{ // T orientation 0
				{ '.','#','.','.' },
{ '#','#','#','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // T orientation 1
				{ '.','#','.','.' },
{ '.','#','#','.' },
{ '.','#','.','.' },
{ '.','.','.','.' }
			},
			{ // T orientation 2
				{ '.','.','.','.' },
{ '#','#','#','.' },
{ '.','#','.','.' },
{ '.','.','.','.' }
			},
			{ // T orientation 3
				{ '.','#','.','.' },
{ '#','#','.','.' },
{ '.','#','.','.' },
{ '.','.','.','.' }
			},
		},
		{ // O, 4 
			{ // O orientation 0
				{ '#','#','.','.' },
{ '#','#','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // O orientation 1
				{ '#','#','.','.' },
{ '#','#','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // O orientation 2
				{ '#','#','.','.' },
{ '#','#','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // O orientation 3
				{ '#','#','.','.' },
{ '#','#','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
		},
		{ // S, 5 
			{ // S orientation 0
				{ '.','.','.','.' },
{ '.','#','#','.' },
{ '#','#','.','.' },
{ '.','.','.','.' }
			},
			{ // S orientation 1
				{ '.','#','.','.' },
{ '.','#','#','.' },
{ '.','.','#','.' },
{ '.','.','.','.' }
			},
			{ // S orientation 2
				{ '.','.','.','.' },
{ '.','#','#','.' },
{ '#','#','.','.' },
{ '.','.','.','.' }
			},
			{ // S orientation 3
				{ '.','#','.','.' },
{ '.','#','#','.' },
{ '.','.','#','.' },
{ '.','.','.','.' }
			},
		},
		{ // Z, 6
			{ // Z orientation 0
				{ '.','.','.','.' },
{ '#','#','.','.' },
{ '.','#','#','.' },
{ '.','.','.','.' }
			},
			{ // Z orientation 1
				{ '.','.','#','.' },
{ '.','#','#','.' },
{ '.','#','.','.' },
{ '.','.','.','.' }
			},
			{ // Z orientation 2
				{ '.','.','.','.' },
{ '#','#','.','.' },
{ '.','#','#','.' },
{ '.','.','.','.' }
			},
			{ // Z orientation 3
				{ '.','.','#','.' },
{ '.','#','#','.' },
{ '.','#','.','.' },
{ '.','.','.','.' }
			},
		},
		{ // vapor, 7
			{ // vapor orientation 0
				{ '.','#','#','.' },
{ '.','.','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // vapor orientation 1
				{ '.','#','#','.' },
{ '.','.','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // vapor orientation 2
				{ '.','#','#','.' },
{ '.','.','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // vapor orientation 3
				{ '.','#','#','.' },
{ '.','.','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			}
		},
		{ // foam, 8
			{ // foam orientation 0
				{ '.','.','.','.' },
{ '.','#','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // foam orientation 1
				{ '.','.','.','.' },
{ '.','#','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // foam orientation 2
				{ '.','.','.','.' },
{ '.','#','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // foam orientation 3
				{ '.','.','.','.' },
{ '.','#','.','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
		},
		{ // crazy shape, 9
			{ // crazy shape orientation 0
				{ '#','.','.','#' },
{ '.','#','#','.' },
{ '.','.','.','.' },
{ '.','.','.','.' }
			},
			{ // crazy shape orientation 1
				{ '.','.','.','#' },
{ '.','.','#','.' },
{ '.','.','#','.' },
{ '.','.','.','#' }
			},
			{ // crazy shape orientation 2
				{ '.','.','.','.' },
{ '.','.','.','.' },
{ '.','#','#','.' },
{ '#','.','.','#' }
			},
			{ // crazy shape orientation 3
				{ '#','.','.','.' },
{ '.','#','.','.' },
{ '.','#','.','.' },
{ '#','.','.','.' }
			}
		}
};

Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1)
{
	maxTime = 1000 - (100 * (m_level - 1));
	m_well = new Well;
	down = 0;
	right = 1;
	left = 2;
	same = 3;
	mScore = 0;
	scoreCalled = 0;
	rowsLeft = 5;
}

void Game::play()
{
    m_well->display(m_screen, WELL_X, WELL_Y);
	levelStarted = false;
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Chetyris!");
    waitForEnter();  // [in UserInterface.h]
	nextPiece = chooseRandomPieceType();
    for(;;)
    {
        if ( ! playOneLevel())
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
	tetro->choosePieces(currentPiece, nextPiece); // assign the pieces
	while (endLevel == false) // loop until game over
	{
		fallDown = true; 
		levelStarted = true; // the level has started
		refreshScreen();
		Timer timer;
		while (timer.elapsed() < maxTime) // controls the pace of the fall
		{
			char userInput;
			if (fall(4, 0, nextPiece, mRotation, same) == false)
			{
				endLevel = true;
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
						refreshScreen();
					}
					else
					{
						m_well->storePiece(fallX, fallY, currentPiece, mRotation); // otherwise store the piece in the well
						fallDown = false;
						m_well->display(m_screen, WELL_X, WELL_Y);
						fallX = 4;
						fallY = 0;
						mRotation = 0;
						removeFilledRows(endLevel, nextLevel);
					}
					break;
				case ARROW_LEFT:
					if (currentPiece == 9)
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
					if (currentPiece == 9) // if crazy piece
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
					m_well->storePiece(fallX, fallY, currentPiece, mRotation);
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
					m_well->storePiece(fallX, fallY, currentPiece, mRotation);
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


void Game::drawPiece(Screen& screen, int xCoord, int yCoord, int piece, int rotation) // draws the piece in the game
{
	int l = 0;
	for (int i = xCoord; i < xCoord + 4; i++)
	{
		int k = 0;
		for (int j = yCoord; j < yCoord + 4; j++)
		{
			screen.gotoXY(i, j);
			if (pieces[piece][rotation][k][l] == '#')
				screen.printChar(pieces[piece][rotation][k][l]);
			k++;
		}
		l++;
	}
	screen.gotoXY(90000, 1000000);
}

bool Game::fall(int x, int y, int piece, int rotation, int direction)
{
	if (m_well->canMove(x, y, piece, rotation, direction))
	{
		return true;
	}
	return false;
}

bool Game::rotateCurrentPiece(int piece, int& currentRotation)
{
	currentRotation++;
	if (currentRotation == 4)
	{
		currentRotation = 0;
		if (m_well->canRotate(fallX, fallY, piece, currentRotation) == true)
		{
			return true;
		}
		else
			currentRotation = 3;
		return false;
	}
	if (m_well->canRotate(fallX, fallY, piece, currentRotation) == true)
	{
		return true;
	}
	else
		currentRotation--;
	return false;
}

int Game::scoreFunction()
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

void Game::refreshScreen()
{
	displayStatus(); // refresh the screen
	m_well->display(m_screen, WELL_X, WELL_Y);
	drawPiece(m_screen, fallX, fallY, currentPiece, mRotation);
}

void Game::rowsLeftUpdate()
{
	rowsLeft = 5 * m_level;
}

string Game::toStringify(int becomeString)
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

void Game::removeFilledRows(bool& endLevel, bool& nextLevel)
{
	for (int i = 0; i < 18; i++)
	{
		if (m_well->isRowFull(i) == true)
		{
			scoreCalled++;
			rowsLeft--;
			if (rowsLeft <= 0)
			{
				endLevel = true;
				nextLevel = true;
				m_well->display(m_screen, WELL_X, WELL_Y);
				fallX = 4;
				fallY = 0;
				mRotation = 0;
				break;
			}
			else
			{
				m_well->deleteRow(i);
				discardPendingKeys();
			}
		}
	}
	scoreFunction();
	if (rowsLeft <= 0)
		displayStatus();
	else
	{
		tetro->choosePieces(currentPiece, nextPiece);
		discardPendingKeys();
	}
}
