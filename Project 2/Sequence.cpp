// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include "Sequence.h"

Sequence::Sequence()
{
	m_size = 0; // initialize size to zero
	head = nullptr; // initialize head and tail pointers to nullptrs
	tail = nullptr;
}

Sequence::Sequence(const Sequence& copying) // copy constructor
{
	m_size = 0; // initialize size to zero
	head = nullptr; // initialize head and tail pointers to nullptrs
	tail = nullptr;
	for (int i = 0; i < copying.size(); i++) // loop through each node in the sequence being copied
	{
		ItemType value; // create a value to be used and updated
		copying.get(i, value); // get the value at the position specified
		insert(i, value); // insert it into the sequence copying the other
	}
}

Sequence& Sequence::operator=(const Sequence & assigning) // assignment operator
{
	if (this == &assigning)
		return *this;
	Sequence temporary = assigning; // set a new sequence equal to the 
									// assigned sequence
	swap(temporary); // swap the values
	return *this;
}

Sequence::~Sequence()
{
	while (head != nullptr) // while head is not a nullptr
	{
		Node* temp = head; // create a temp pointer to head
		head = head->next; // point head to the next node
		delete temp; // delete what is stored at temp
	}
}

bool Sequence::empty() const
{
	return (m_size == 0);
}

int Sequence::size() const
{
	return m_size;
}

bool Sequence::insert(int pos, const ItemType& value)
{
	if (pos < 0 || pos > size()) // if position is out of bounds
		return false; // return false
	Node *pointy = new Node; // create a new node
	pointy->m_value = value; // pointy's value = value
	if (empty() == true) // if size is zero
	{
		pointy->next = nullptr; // pointy's next = next
		pointy->prev = nullptr; // pointy's previous = prev
		head = pointy; // head is now equal to pointy
		tail = pointy; // point tail to pointy
		m_size++; // increase size by one
		return true; // return
	}
	else // if pos >= 0, pos <= size()
	{
		if (pos == size()) // if position == size()
		{
			tail->next = pointy; // set tail's next to pointy
			pointy->prev = tail; // set pointy's previous to tail
			tail = pointy; // set tail = p;
			pointy->next = nullptr; // set p's next equal to null ptr
			m_size++; // increase size
			return true; //return
		}
		else if (pos == 0) // if position is at very front
		{
			pointy->next = head; // pointy's next = head
			pointy->prev = nullptr; // pointy's previous becomes nullptr
			head->prev = pointy; // head's previous points to pointy
			head = pointy; // head becomes pointy
			m_size++; // increase size
			return true; // return
		}
		Node* temp = head; // create a new pointer
		for (int i = 0; i <= size(); i++) // loop through until you return or leave the loop
		{
			if (i == pos) // if at position
			{
				pointy->prev = temp->prev; // set pointy's previous to previous node
				temp->prev = pointy; // set temp's previous to pointy
				pointy->prev->next = pointy; // set node's before pointy next to pointy
				pointy->next = temp; // set pointy's next to temp
				m_size++; // increase size by 1
				return true; // return
			}
			temp = temp->next; // update temp
		}
		return false; // return if have not already
	}
}

int Sequence::insert(const ItemType& value)
{
	int position = 0; // set position equal to zero
	if (head == nullptr) // if sequence is empty
	{
		Node* nodey = new Node; // create a new node
		nodey->m_value = value; // set nodey's value to value
		nodey->prev = nullptr; // set nodey's previous pointer to nullptr
		nodey->next = nullptr; // set nodey's next pointer to nullptr
		head = nodey; // set head to nodey
		tail = nodey; // set tail to nodey
		m_size++; // increase the size by one
		return position; // return the position
	}
	else // otherwise
	{
		Node* nodey = head; // set a new node to head
		while (nodey != nullptr) // while nodey is not a nullptr
		{
			if (value <= nodey->m_value) // if the value is <= nodey's value
			{
				insert(position, value); // insert the value in at that position
				return position; // return the position
			}
			nodey = nodey->next; // move nodey forward one
			position++; // increase position by one
		}
		insert(size(), value); // insert the value at the end if it is greater than all other values
	}
	return position; // return the position
}


bool Sequence::erase(int pos)
{
	if (pos < 0 || pos > size() || size() == 0 ) // if postion is out of bounds or there is nothing to erase
		return false; // return false
	if (size() == 1) // if there is only one node
	{
		delete head; // delete what is stored at head
		delete tail; // delete what is stored at tail
		head = nullptr; // set head to nullptr
		tail = nullptr; // set tail to a null ptr
		m_size--; // decrease size by one
		return true; // return true
	}
	Node* pointy = head; // set a new pointer pointy to head
	int i = 0; // set an int to 0
	while (pointy != nullptr) // while pointy is not a nullptr
	{
		if (pos == 0) // if position is 0
		{
			//pointy->next = head->next; // set pointy's next equal to head's next
			pointy->next->prev = nullptr; // set the next node's previous to nullptr 
			head = pointy->next; // set head to the next node
			delete pointy; // delete what is stored at pointy
			m_size--; // decrease size by one
			return true; // return true
		}
		else if (pos == size() - 1) // if position is at last node
		{
			pointy = tail; // set  pointy = tail
			//pointy->prev = tail->prev; // set pointy's previous equal to tail's previous
			pointy->prev->next = nullptr; // set 2nd-to-last node's next to nullptr
			tail = pointy->prev; // set tail to pointy's prev
			delete pointy; // delete what was stored at pointy
			m_size--; // decrease size by one
			return true; // return true
		}
		else if (i == pos) // if i reaches position
		{
			pointy->prev->next = pointy->next; // set the pointy's previous node's
												// next to pointy's next
			pointy->next->prev = pointy->prev;// set the pointy's next node's
												// previous to pointy's previous
			delete pointy; // delete what is stored at pointy
			m_size--; // decrease size by one
			return true; // return true
		}
		pointy = pointy->next; // update pointy to the next node
		i++; // increase i by one
	}
	return false; // return false if none of the above is true
}

int Sequence::remove(const ItemType& value)
{
	int count = 0; // initialize the count to 0
	Node* pointy = head; // create a new pointer
	if (size() == 1) // if old one node
	{
		if (pointy->m_value == value) // if head's value equals value
		{
			count++; // increase count by one
			delete pointy; // delete what is stored at pointy
			pointy = nullptr; // set pointy to a nullptr
		}
		return count;
	}
	while (pointy != nullptr) // while pointy is not a nullptr
	{
		if (pointy->m_value == value) // if pointy's value is equal to value
		{
			Node* nodey = pointy; // create a temporary pointer
			if (pointy == head) // if at head
			{
				pointy->next->prev = nullptr; // set the next node's previous pointer to nullptr
				head = pointy->next; // next node becomes the head
				pointy = pointy->next; // set pointy to the next node
				delete nodey; // delete what is stored at temp
			}
			else if (pointy == tail) // if pointy is at the tail
			{
				pointy->prev->next = nullptr; // set previous node's next pointer to nullptr
				tail = pointy->prev; // tail becomes the previous node
				pointy = pointy->next; // set pointy to the next node
				delete nodey; // delete what is stored at nodey
			}
			else
			{
				pointy->prev->next = nodey->next; // set previous node's next to the next node
				pointy->next->prev = nodey->prev; // set next node's previous to the prevous node
				pointy = pointy->next; // set pointy to the next node
				delete nodey; // delete what is stored at nodey
			}
			count++; // increase the count by one
			m_size--; // decrease the size by one
		}
		else
			pointy = pointy->next; // set pointy to the next node
	}
	return count; // return the count
}

bool Sequence::get(int pos, ItemType& value) const
{
	if (pos < 0 || pos >= size() || size() == 0) // if position is out of bounds or sequence is empty
		return false; // return false
	else if (pos >= 0 && pos < size()) // if position is within bound
	{
		Node* pointy = head; // create a new pointer
		int i = 0; // create a new integer
		while (pointy != nullptr) // while pointy is not a nullptr
		{
			if (i == pos) // if at position
			{
				value = pointy->m_value; // update m_value's value
				return true; // return true
			}
			i++; // increase i by one
			pointy = pointy->next; // set pointy to the next node
		}
	}
	return false; // return false since no nodes held the value
}

bool Sequence::set(int pos, const ItemType& value)
{
	if (pos < 0 || pos >= size()) // if position is out of bounds
		return false; // return false
	Node* pointy = head; // create a new pointer
	int i = 0; // initialize a integer
	while (i < size() && pointy != nullptr) // while i is less than the size of the sequence and pointy is not a nullptr
	{
		if (i == pos) // if at position
		{
			pointy->m_value = value; // set pointy's value equal to m_value
			return true; // return true
		}
		i++; // increase i by one
		pointy = pointy->next; // set pointy to the next node
	}
	return false; // return false otherwise
}

int Sequence::find(const ItemType& value) const
{
	int position = 0; // initialize a position integer
	Node* pointy = head; // set pointy to head
	while (pointy != nullptr && size() > 0) // if pointy is null then size is 0 or we reached tail's next
	{
		if (pointy->m_value == value) // if pointy's value equals m_value
			return position; // return the position
		position++; // increase position by one
		pointy = pointy->next; // set pointy to the next node
	}
	return -1; // return -1 otherwise
}

void Sequence::swap(Sequence& other)
{
	Node* temporary_head; // declare a new temporary node head
	Node* temporary_tail; // declare a new temporary node tail
	int temporary_size; // declare a the new temporary node's size

	temporary_head = other.head; // initilize temporary head, hold other.head's old head
	other.head = head; // update other.head
	head = temporary_head; // point head to temporary_head

	temporary_tail = other.tail; // initilize temporary tail, hold other.tail's old tail
	other.tail = tail; // update other.tail
	tail = temporary_tail; // point head to temporary_tail

	temporary_size = other.m_size; // set temporary_size equal to other's size
	other.m_size = m_size; // set other's size equal to m_size;
	m_size = temporary_size; // set m_size equal to temporary_size
}

int subsequence(const Sequence & seq1, const Sequence & seq2)
{
	if (seq2.empty() || seq2.size() > seq1.size()) // if seq2 is empty or seq2 is longer than seq1
		return -1;
	ItemType value1; // create two values that can be updated
	ItemType value2;
	bool sub = false; // create a bool to control the loop
	int i = 0; // counts how many in a values match consecutively in a sequence
	for (int j = 0; i < seq1.size(); i++) // a loop to trasverse seq1
	{
		seq1.get(i, value1); // set value1 equal to value at position i of seq1
		seq2.get(j, value2); // set value2 equal to the value at position j of seq2
		int k = i; // set k to i
		if (value1 == value2) // if the values are true
			sub = true; // set sub to true so that the following loop is not executed
		while (value1 == value2 && j < seq2.size() && sub == true) // while the values are equal, j is within bounds, and sub is true
		{
			k++; // increase i by one
			j++; // increase j by one
			if (j >= seq2.size()) // if j reaches the end of seq2
				break; // break out of the loop
			seq1.get(k, value1); // get a new value1 at position k of seq1
			seq2.get(j, value2); // get a new value2 at position j of seq2
			if (value1 != value2) // if the values are no longer equal
				sub = false; // set sub back to false
		}
		if (j >= seq2.size()) // if j reaches the end of seq2 
			break; // break the loop
	}
	if (sub) // if sub is true, return the position i
		return i;
	return -1; // if sub is false, return -1
}

void interleave(const Sequence & seq1, const Sequence & seq2, Sequence & result)
{
	Sequence temporary = result; // create a new sequence and set it equal to result
	// this is to avoid aliasing such as in a case where result = seq1
	while (temporary.empty() == false) // while temporary is not empty
		temporary.erase(0); // erase the head of temporary
	if (seq1.empty() == true) // if seq1 is empty
		temporary = seq2; // set temporary equal to seq2
	else if (seq2.empty() == true) // if seq2 is empty
		temporary = seq1; // set temporary equal to seq1
	ItemType value1; // declare two values that will be updated
	ItemType value2;
	int i = 0; // initialize 3 values for looping and inserting into temporary
	int j = 0;
	int k = 0;
	seq1.get(i, value1); // get a value for value1
	seq2.get(j, value2); // get a value for value2
	if (value1 <= value2) 
	{
		while (i < seq1.size() || j < seq2.size()) // loop until reaching end of both seq1 and seq2
		{
			if (i < seq1.size()) // input seq1 value first
			{
				seq1.get(i, value1); // get value for value1
				temporary.insert(k, value1); // insert value1 into position k in temporary
				i++; // increase i by one
				k++; // increase k by one
			}
			if (j < seq2.size()) // input seq2 value second
			{
				seq2.get(j, value2); // get value for value2
				temporary.insert(k, value2); // insert value2 into position k in temporary
				j++; // increase j by one
				k++; // increase k by one
			}
		}
	}
	else if (value2 < value1)
	{
		while (i < seq1.size() || j < seq2.size()) // loop until reaching the end of both seq1 and seq2
		{
			if (j < seq2.size()) // input seq2 value first 
			{
				seq2.get(j, value2); // get value for value2
				temporary.insert(k, value2); // insert value2 into position k in temporary
				j++; // increase j by one
				k++; // increase k by one
			}
			if (i < seq1.size()) // input seq1 value second
			{
				seq1.get(i, value1); // get value for value1
				temporary.insert(k, value1); // insert value1 into position k in temporary
				i++; // increase i by one
				k++; // increase k by one
			}
		}
	}
	result = temporary; // make result the same as temporary
}
