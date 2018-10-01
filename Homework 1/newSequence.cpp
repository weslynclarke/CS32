// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "newSequence.h"
#include <iostream>

Sequence::Sequence()
{
	m_lengthSequence = 0;
	m_maxLength = DEFAULT_MAX_ITEMS;
	m_sequenceArray = new ItemType[m_maxLength];
}

Sequence::Sequence(int maxItems)
{
	if (maxItems < 0)
		exit(1);
	m_lengthSequence = 0;
	m_maxLength = maxItems;
	m_sequenceArray = new ItemType[m_maxLength];
}

Sequence::Sequence(const Sequence & seqObject)
{
	m_maxLength = seqObject.m_maxLength;
	m_lengthSequence = seqObject.m_lengthSequence;
	m_sequenceArray = new ItemType[m_maxLength];
	for (int i = 0; i < m_lengthSequence; i++)
		m_sequenceArray[i] = seqObject.m_sequenceArray[i];
}

Sequence& Sequence::operator=(const Sequence& seqObject)
{
	if (this != &seqObject)
	{
		Sequence temp(seqObject);
		swap(temp);
	}
	return *this;
}

Sequence::~Sequence()
{
	delete [] m_sequenceArray;
}


bool Sequence::empty() const
{
	return (m_lengthSequence == 0);
}

int Sequence::size() const
{
	return m_lengthSequence;
}

bool Sequence::insert(int pos, const ItemType & value)
{
	// if pos < 0 or >= 200 or size = 200
	if (pos < 0 || pos > size() || size() >= DEFAULT_MAX_ITEMS)
		return false;
	else
	{
		// increase the length of the sequence by 1
		m_lengthSequence++;
		if (size() == 1)
		{
			m_sequenceArray[pos] = value;
			return true;
		}
		// loop backward so that at index i, the value becomes what was
		// at index i-1 until the index after pos
		for (int i = m_lengthSequence - 1; i > pos; i--)
		{
			m_sequenceArray[i] = m_sequenceArray[i - 1];
		}
		m_sequenceArray[pos] = value;
		return true;
	}
}

int Sequence::insert(const ItemType & value)
{
	int p;
	if (size() == m_maxLength)
		p = -1;
	else
	{
		p = 0;
		bool found = false;
		// increase length of the array by one
		m_lengthSequence++;
		while (p < size() && found != true)
		{
			if (m_lengthSequence == 1)
			{
				m_sequenceArray[p] = value;
				found = true;
			}
			else if (p == m_lengthSequence - 1)
			{
				m_sequenceArray[p] = value;
				found = true;
			}
			else if (!(value <= m_sequenceArray[p]))
			{
				p++;
			}
			else
			{
				// loop backward so that at index i, the value becomes what was
				// at index i-1 until the index after p
				for (int i = m_lengthSequence - 1; i > p; i--)
				{
					m_sequenceArray[i] = m_sequenceArray[i - 1];
				}
				m_sequenceArray[p] = value;
				found = true;
			}
		}
	}
	return p;
}

bool Sequence::erase(int pos)
{
	if (0 <= pos && pos < size())
	{
		if (pos == (size() - 1))
		{
			if (pos == 0)
				m_lengthSequence = 0;
			else
				m_lengthSequence--;
			return true;
		}
		// move every value in the index after pos down by one
		for (int i = pos; i < (size() - 1); i++)
		{
			m_sequenceArray[i] = m_sequenceArray[i + 1];
		}
		// decrease size of array by one
		m_lengthSequence--;
		return true;
	}
	else
		return false;
}

int Sequence::remove(const ItemType & value)
{
	int count = 0;
	for (int i = 0; i < m_lengthSequence; i++)
	{
		if (m_sequenceArray[i] == value)
		{
			for (int j = i; j < (size() - 1); j++)
				m_sequenceArray[j] = m_sequenceArray[j + 1];
			m_lengthSequence--;
			count++;
		}
	}
	return count;
}

bool Sequence::get(int pos, ItemType & value) const
{
	if (0 <= pos && pos < size())
	{
		value = m_sequenceArray[pos];
		return true;
	}
	else
		return false;
}

bool Sequence::set(int pos, const ItemType & value)
{
	if (0 <= pos && pos < size())
	{
		m_sequenceArray[pos] = value;
		return true;
	}
	else
	{
		return false;
	}
}

int Sequence::find(const ItemType & value) const
{
	int p = -1;
	if (size() > 0)
	{
		int i = 0;
		if (m_sequenceArray[i] == value)
			p = i;
		while ((m_sequenceArray[i] != value) && i < size() - 1)
		{
			i++;
			if (m_sequenceArray[i] == value)
				p = i;
		}
	}
	return p;
}

void Sequence::swap(Sequence & other)
{
	ItemType* temp_sequence;
	int temp_otherSize;
	int temp_otherMax;

	temp_sequence = m_sequenceArray;
	m_sequenceArray = other.m_sequenceArray;
	other.m_sequenceArray = temp_sequence;

	temp_otherSize = m_lengthSequence;
	m_lengthSequence = other.m_lengthSequence;
	other.m_lengthSequence = temp_otherSize;

	temp_otherMax = m_maxLength;
	m_maxLength = other.m_maxLength;
	other.m_maxLength = temp_otherMax;
}
