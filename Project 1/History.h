// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#ifndef HISTORY_H
#define HISTORY_H

#include "globals.h"

class History
{
public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;
private:
	int mh_rows;
	int mh_cols;
	int m_historyBoard[MAXROWS][MAXCOLS];
};

#endif // !HISTORY_H
