// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "ScoreList.h"

ScoreList::ScoreList() : m_scoreSequence()
{
}

bool ScoreList::add(unsigned long score)
{
	if (score >= 0 && score <= 100)
	{
		if (m_scoreSequence.size() < 200)
		{
			m_scoreSequence.insert(score);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool ScoreList::remove(unsigned long score)
{
	// if the score is in the sequence
	if (m_scoreSequence.find(score) != -1)
	{
		m_scoreSequence.erase(m_scoreSequence.find(score));
		return true;
	}
	else
		return false;
}

int ScoreList::size() const
{
	return (m_scoreSequence.size());
}

unsigned long ScoreList::minimum() const
{
	if (size() == 0)
		return NO_SCORE;
	else
	{
		unsigned long minimumVal = 0;
		bool found = false;
		while (found != true && minimumVal <= 100)
		{
			if (m_scoreSequence.find(minimumVal) != -1)
			{
				found = true;
				return minimumVal;
			}
			else
			{
				minimumVal++;
			}
		}
		return minimumVal;
	}
}

unsigned long ScoreList::maximum() const
{
	if (size() == 0)
		return NO_SCORE;
	else
	{
		unsigned long maximumVal = 100;
		bool found = false;
		while (found != true && maximumVal >= 0)
		{
			if (m_scoreSequence.find(maximumVal) != -1)
			{
				found = true;
				return maximumVal;
			}
			else
			{
				maximumVal--;
			}
		}
		return maximumVal;
	}
}
