// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#ifndef FLATULAN_INCLUDED
#define FLATULAN_INCLUDED

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;


class City;  // This is needed to let the compiler know that City is a
			 // type name, since it's mentioned in the Flatulan declaration.

class Flatulan
{
public:
	// Constructor
	Flatulan(City* cp, int r, int c);

	// Accessors
	int  row() const;
	int  col() const;

	// Mutators
	void move();
	bool possiblyGetConverted();

private:
	City * m_city;
	int   m_row;
	int   m_col;
};


#endif // FLATULAN_INCLUDED
