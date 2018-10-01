// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "Dictionary.h"
#include <string>
#include <list>
#include <cctype>
#include <utility>  // for swap
using namespace std;

inline void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);

const int MAX_ITEMS = 50000; // max number of buckets we can have is 50000

struct Bucket // each Bucket in the hash table
{
	Bucket(string str, unsigned long long int key);
	Bucket* next;
	string word;
	unsigned long long int mkey; // the number associated with the word, may be very very long and we dont want it to be negative
};

Bucket::Bucket(string str, unsigned long long int key) // input a long double number
{
	next = nullptr;
	word = str;
	mkey = key; // although key is a double, all i want is the integer associated
}

// This class does the real work of the implementation.

class DictionaryImpl
{
public:
	DictionaryImpl();
	~DictionaryImpl();
	void insert(string word); // will insert permutations/words into the hash table
	void lookup(string letters, void callback(string)); 
private:
	int hashFunction(string& word); // generates the key and the hashTable's index of the bucket
	Bucket* hashTable[MAX_ITEMS]; // hash table
	unsigned long long int m_key; // key of the current letter, may be very very long and we dont want it to be negative
};

DictionaryImpl::DictionaryImpl()
{
	for (int i = 0; i < MAX_ITEMS; i++)
		hashTable[i] = nullptr; //make each pointer in the hashtable a null ptr initially
}

DictionaryImpl::~DictionaryImpl()
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		Bucket* first = hashTable[i];
		while (first != nullptr)
		{
			Bucket* temp = first;
			first = first->next;
			delete temp;
		}
	}
}

int DictionaryImpl::hashFunction(string& word)
{
	removeNonLetters(word);
	int nums[26] = 
	{ 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 83, 89, 97, 101 };
	// {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}
	// these nums will be used to multipy characters of the input word to obtain a unique key
	unsigned long long int result = 1; // result is going to be a BIG number
	m_key = 1; // set m_key to one before every word
	for (int i = 0; i < word.length(); i++)
	{
		result = result * nums[word[i] - 'a']; // multiply the result by each character's respective prime number
		m_key = m_key * word[i]; // have each word have a unique key being the product of its characters
	}
	return (result % MAX_ITEMS); 
}

void DictionaryImpl::insert(string word)
{
	int index = hashFunction(word); // int returned corresponds to the index
	if (hashTable[index] == nullptr) // if pointer points to nothing at that index
		hashTable[index] = new Bucket(word, m_key); // point the pointer at a new bucket
	else
	{
		Bucket* nextBucket = new Bucket(word, m_key); // current bucket's next pointer points to a new bucket
		Bucket* temp = hashTable[index]; // temporary bucket pointer to the current bucket
		while (temp->next != nullptr) // while current bucket's next pointer isnt null
			temp = temp->next; // set the temp pointer equal to the next pointer
		temp->next = nextBucket; // once the next pointer is null, point it at the next bucket
	}
}

void DictionaryImpl::lookup(string letters, void callback(string))
{
	if (callback == nullptr || letters.empty())
		return;
	int index = hashFunction(letters); // int returned corresponds to the index
	if (hashTable[index] == nullptr) // if nothing there, there are no permutations
		return;
	else // if not a nullptr
	{
		Bucket* temp = hashTable[index]; // create a temporary pointer to the hashtable at that index
		while (temp != nullptr) // while you havent reached the end of the linked list
		{
			if (temp->mkey == m_key) // if temporary's key is equal to letter's key
				callback(temp->word); // callback on the word stored in that bucket
			temp = temp->next; // point temp to the next bucket
		}
	}
}

inline void removeNonLetters(string& s)
{
	string::iterator to = s.begin();
	for (string::const_iterator from = s.begin(); from != s.end(); from++)
	{
		if (isalpha(*from))
		{
			*to = tolower(*from);
			to++;
		}
	}
	s.erase(to, s.end());  // chop everything off from "to" to end.
}

// Each successive call to this function generates the next permutation of the
// characters in the parameter.  For example,
//    string s = "eel";
//    generateNextPermutation(s);  // now s == "ele"
//    generateNextPermutation(s);  // now s == "lee"
//    generateNextPermutation(s);  // now s == "eel"
// You don't have to understand this function's implementation.
void generateNextPermutation(string& permutation)
{
	string::iterator last = permutation.end() - 1;
	string::iterator p;

	for (p = last; p != permutation.begin() && *p <= *(p - 1); p--)
		;
	if (p != permutation.begin())
	{
		string::iterator q;
		for (q = p + 1; q <= last && *q > *(p - 1); q++)
			;
		swap(*(p - 1), *(q - 1));
	}
	for (; p < last; p++, last--)
		swap(*p, *last);
}

//******************** Dictionary functions ********************************

// These functions simply delegate to DictionaryImpl's functions.
// You probably don't want to change any of this code

Dictionary::Dictionary()
{
	m_impl = new DictionaryImpl;
}

Dictionary::~Dictionary()
{
	delete m_impl;
}

void Dictionary::insert(string word)
{
	m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
	m_impl->lookup(letters, callback);
}
