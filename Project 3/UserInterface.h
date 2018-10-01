#ifndef USERINTERFACE_INCLUDE
#define USERINTERFACE_INCLUDE

#include <string>

const char ARROW_UP = '8';
const char ARROW_DOWN = '2';
const char ARROW_LEFT = '4';
const char ARROW_RIGHT = '6';

///////////////////////////////////////////////////////////
// Screen -- Visual Output
//
// UserInterfaceWindows.cpp created and provided by David Smallberg for project purposes.
// Copyright (c) 2018 David Smallberg. All rights reserved.
///////////////////////////////////////////////////////////

class ScreenImpl;

class Screen
{
public:
	Screen(int width, int height);
	~Screen();
	void clear();
	void gotoXY(int x, int y); //positions cursor at the x and y coordinates supplied as parameters, text appears starting at this point
	void printChar(char ch); // write a single character
	void printString(std::string s); //write a single string
	void printStringClearLine(std::string s); //writes a string while clearing the rest of characters on current line
	void refresh();

private:
	ScreenImpl * m_impl;
};

///////////////////////////////////////////////////////////
// Functions for Keyboard Input
///////////////////////////////////////////////////////////

bool getCharIfAny(char& ch); // if user hits a key, return the character
void waitForEnter(); // pauses until user presses enter key
void discardPendingKeys(); //throws away unprocessed key presses

						   ///////////////////////////////////////////////////////////
						   // Class for Timing
						   ///////////////////////////////////////////////////////////

//========================================================================
// Timer t;                 // create and start a timer
// t.start();               // restart the timer
// double d = t.elapsed();  // milliseconds since timer was last started
//========================================================================

#include <chrono>

class Timer
{
public:
	Timer()
	{
		start();
	}
	void start()
	{
		m_time = std::chrono::high_resolution_clock::now();
	}
	double elapsed() const
	{
		std::chrono::duration<double, std::milli> diff =
			std::chrono::high_resolution_clock::now() - m_time;
		return diff.count();
	}
private:
	std::chrono::high_resolution_clock::time_point m_time;
};

#endif // USERINTERFACE_INCLUDE
