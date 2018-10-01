// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "History.h"
#include <iostream>
#include <cstring>
using namespace std;

History::History(int nRows, int nCols) 
	: mh_rows(nRows), mh_cols(nCols)
{
	for (int i = 0; i < mh_rows; i++)
	{
		for (int j = 0; j < mh_cols; j++)
		{
			m_historyBoard[i][j] = 0;
		}
	}
}

bool History::record(int r, int c)
{
	if (r <= 0 || r > mh_rows || c <= 0 || c > mh_cols)
		return false;
	else
	{
		m_historyBoard[r - 1][c - 1]++ ;
		// must subtract 1 due to the way arrays are read
		// row 1, col 1 considered upperleft most, while that is
		// equivalent to array[0][0]
		return true;
	}
}

void History::display() const
{
	clearScreen();
	char displayHistoryBoard[MAXROWS][MAXCOLS];
	int converted;
	for (int i = 0; i < mh_rows; i++)
	{
		for (int j = 0; j < mh_cols; j++)
		{
			converted = m_historyBoard[i][j];
			if (converted == 0)
				displayHistoryBoard[i][j] = '.';
			else if (converted > 'Y')
				displayHistoryBoard[i][j] = 'Z';
			else
				displayHistoryBoard[i][j] = 64 + converted;
		}
	}
	for (int k = 0; k < mh_rows; k++)
	{
		for (int l = 0; l < mh_cols; l++)
		{
			cout << displayHistoryBoard[k][l];
		}
		cout << endl;
	}

	cout << endl;
}

