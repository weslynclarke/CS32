// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "Sequence.h"
#include <string>
#include <iostream>
#include <cassert> 
#include <vld.h>
using namespace std;

void test()
{
	// member functions tests
	////////////////////////////////////////
	Sequence s;
	assert(s.insert(0, "lavash"));   // testing bool insert function
	assert(s.insert(1, "tortilla")); 
	assert(s.size() == 2); // testing size function

	ItemType x = "injera";
	assert(s.get(1, x) && x == "tortilla"); // testing get function
	assert(s.get(0, x) && x == "lavash");
	assert(s.set(1, "pizza")); // testing the set function
	assert(s.get(1, x) && x == "pizza"); // testing set function worked correctly with the get function


	Sequence t; // will be testing the insert and erase functions back and forth
	assert(t.insert("lavash") == 0); 
	assert(t.insert("tortilla")== 1);
	assert(subsequence(s, t) == -1); // testing subsequence function
	assert(t.size() == 2); 
	assert(t.insert("tortilla") == 1);
	assert(subsequence(s, t) == -1); // testing subsequence function
	assert(t.size() == 3);
	assert(t.erase(1));
	assert(t.size() == 2);
	assert(t.erase(1));
	assert(t.size() == 1);


	Sequence s1; // setting up for the swap function
	assert(s1.insert(0, "paratha"));
	assert(s1.insert(0, "focaccia"));
	Sequence s2;
	assert(s2.insert(0, "roti"));
	s1.swap(s2); // testing swap function
	assert(s1.size() == 1 && s2.size() == 2);

	Sequence s4; 
	assert(s4.empty()); // testing empty function
	assert(s4.find("laobing") == -1); // testing find function
	assert(s4.insert("laobing") == 0);
	assert(s4.size() == 1 && s4.find("laobing") == 0);

	Sequence u;
	// For an empty sequence:
	assert(u.size() == 0);             // testing size function
	assert(u.empty());                 // testing empty function
	assert(u.remove("paratha") == 0);  // testing remove function
	assert(s1.size() == 1 && s1.find("roti") == 0 && s2.size() == 2 
		&& s2.find("focaccia") == 0 && s2.find("paratha") == 1); // testing find and size functions


	// subsequence test
///////////////////////////////////////////
	Sequence s3; // setting up a sequence
	assert(s3.insert(0, "dosa"));
	assert(s3.insert(1, "pita"));
	assert(s3.insert(2, ""));
	assert(s3.insert(3, "matzo"));
	assert(s3.remove("dosa")== 1);


	Sequence t1; // setting up another sequence
	assert(t1.insert(0, "paratha"));
	assert(t1.insert(1, "focaccia"));
	assert(t1.insert(2, "roti"));
	assert(t1.insert(3, "dosa"));
	assert(t1.insert(4, "pita"));
	assert(t1.insert(5, ""));
	assert(t1.insert(6, "matzo"));
	assert(t1.insert(3, "dosa"));
	assert(t1.insert(4, "pita"));
	assert(t1.insert(5, ""));
	assert(t1.insert(6, "matzo"));

	assert(subsequence(t1, s3) == 4); // testing subsequence 

	Sequence bubs;
	assert(bubs.insert("1111") == 0);
	assert(bubs.insert("1113") == 1);
	assert(bubs.insert("1113") == 1);
	assert(bubs.insert("1112") == 1);
	assert(bubs.insert("1") == 0);


	Sequence dubs;
	assert(dubs.insert("1113") == 0);
	assert(dubs.insert("1112") == 0);
	assert(subsequence(bubs, dubs) == 2); // testing subsequence 



	// interleave test
//////////////////////////////////////////////////
	Sequence t2; // settig up a sequence
	assert(t2.insert(0, "z"));
	assert(t2.insert(1, "b"));
	assert(t2.insert(2, "c"));
	assert(t2.insert(3, "d"));
	assert(t2.insert(4, "e"));
	assert(t2.insert(5, "f"));
	assert(t2.insert(6, "g"));
	assert(t2.insert(3, "h"));
	assert(t2.insert(4, "j"));
	assert(t2.insert(5, "j"));
	assert(t2.insert(6, "j"));
	assert(t2.remove("j") == 3);
		
	Sequence z; // setting up another sequence
	assert(z.insert(0, "dosa"));
	assert(z.insert(1, "pita"));
	assert(z.insert(2, ""));
	assert(z.insert(3, "matzo"));

	assert(z.find("matzo") == 3); // testing find function
	Sequence b;

	interleave(t2, z, b); // testing interleave function 
}

int main()
{
	test();
	cout << "Passed all tests" << endl;
	return 0;
} 
