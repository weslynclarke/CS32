#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Well.h"
#include "UserInterface.h"
#include <string>
// [Add other #include directives as necessary.]

class Game
{
  public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus();
    // [Add other members as necessary.]
	void drawPiece(Screen& screen, int xCoord, int yCoord, int piece, int rotation);
	bool fall(int x, int y, int piece, int rotation, int direction);
	bool rotateCurrentPiece(int piece, int& currentRotation);
	int scoreFunction();
	void refreshScreen();
	void rowsLeftUpdate();
	void removeFilledRows(bool& endLevel, bool& nextLevel); // deletes filled rows in the well
	std::string toStringify(int becomeString);
	std::string levelStr();
	std::string scoreStr();

  private:
    Well*    m_well;
    Screen  m_screen;
    int     m_level;
    // [Add other members as necessary.]
	int fallX; // position x of the falling piece
	int fallY; // position y of the falling piece
	int down; // 0
	int right; // 1
	int left; // 2
	int same; // used for rotating a piece in place
	int mScore; // score count
	int currentPiece; // keep track of current piece
	int nextPiece; // number of the next piece
	int mRotation; // orientation number
	bool levelStarted; // level has started or not
	int maxTime; // the max timer time
	int scoreCalled; // number of times score function is called at once
	int rowsLeft; // the rows left till next level
	Piece* tetro; // piece pointer to access the piece functions
};

#endif // GAME_INCLUDED
