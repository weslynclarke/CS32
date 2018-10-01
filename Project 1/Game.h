// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;

class City;

class Game
{
public:
	// Constructor/destructor
	Game(int rows, int cols, int nFlatulans);
	~Game();

	// Mutators
	void play();

private:
	City * m_city;
};

int decodeDirection(char dir);

#endif // GAME_INCLUDED
