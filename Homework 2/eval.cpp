
// Created by Weslyn Clarke
// Copyright (c) 2018 Weslyn Clarke. All rights reserved.

#include <iostream>
#include <stack>
#include <string>
#include <assert.h>
using namespace std;


int evaluate(string infix, string& postfix, bool& result);

// helper functions
string removeSpaces(string infix);
bool isValidInfix(string infixed);
bool precedence(char db1, char db2);
string infixToPostfix(string infix, string& postfix);

string removeSpaces(string infix)
{
	string result;
	for (int i = 0; i < infix.size(); i++)
	{
		char db = infix[i];
		switch (db)
		{
		case ' ':
			break;
		default:
			result += db;
		}
	}
	return result;
}

bool isValidInfix(string infixed)
{
	if (infixed.size() == 0)
		return false;
	bool valid = true; // validity
	int parentheses = 0; // counting parentheses
	int operands = 0; // counting operands
	string infix = removeSpaces(infixed);
	for (int i = 0; i < infix.size(); i++) // loop over each character
	{
		char db = infix[i]; // character
		switch (db) // switch statement
		{
		case 'T':
		case 'F':
			if (i < infix.size() - 1 && infix[i + 1] != '|' && infix[i + 1] != ')' && infix[i + 1] != '&')
				// T and F must be followed by |, &, or )
				valid = false; // set valid to false
			if (i > 1 && operands > 0)
			{
				if (infix[i - 1] != '&' && infix[i - 1] != '|' && infix[i - 1] != '!' && infix[i - 1] != '(')
					valid = false; // set valid to false
				if (i > 2 && infix[i - 1] == '(' && infix[i - 2] != '&' && infix[i - 2] != '|')
					valid = false;
				if (i > 2 && infix[i - 1] == '!' && infix[i - 2] != '&' && infix[i - 2] != '|')
					valid = false;
			}
			operands++;
			break; 
		case'(':
			parentheses++; // increase parentheses
			if (i < infix.size() - 1 && infix[i + 1] != 'T' && infix[i + 1] != 'F' && infix[i + 1] != '(')
				valid = false;
			break;
		case')':
			parentheses++; // increase parentheses
			break;
		case '|':
		case '&':
			if (infix[infix.size() - 1] == db || infix[0] == db)  // first andlast character in infix cannot be | or &
			{
				valid = false; // set valid to false
				break;
			}
			else if (infix[i - 1] != 'T' && infix[i - 1] != 'F' && infix[i - 1] != ')')
				// character before has to be T, F, or )
				valid = false; // set valid to false
			else if (infix[i + 1] != 'T' && infix[i + 1] != 'F' && infix[i + 1] != '(' && infix[i+1] != '!')
				valid = false; // seet valid to false
			break;
		case '!':
		case ' ': // spaces are fine
			break;
		default: // any other characters are false
			valid = false; // set valid to false
			break;
		}
	}
	if (parentheses % 2 != 0) // if parentheses is not a multiple of 2
		valid = false; // set valid to false
	return valid;
}

string infixToPostfix(string infix, string& postfix)
{
	infix = removeSpaces(infix);
	if (isValidInfix(infix) == true)
	{
		postfix = ""; // set postfix to an empty string
		stack<char> opStack; // create an empty stack
		for (int i = 0; i < infix.size(); i++) // loop through infix
		{
			char db = infix[i]; // char db (like cardi b... anyways) is character in infix at position i
			switch (db) // switch case on db
			{
			case 'T':
			case 'F': // if db is an operand
				postfix += db;
				break;
			case '(': // if db is (
				opStack.push(db);
				break;
			case ')': // if db is )
				while (opStack.top() != '(') // while stack top is not (
				{
					postfix += opStack.top(); // add to postfix
					opStack.pop();
				}
				opStack.pop();
				break;
			case '|':
			case '&':
			case '!':
				while (opStack.empty() == false && precedence(opStack.top(), db) == true)
				{
					postfix += opStack.top(); // append stack top to postfic
					opStack.pop();
				}
				opStack.push(db);
				break;
			}
		}
		while (opStack.empty() == false)
		{
			postfix += opStack.top();
			opStack.pop();
		}
	}
	return postfix;
}

bool precedence(char db1, char db2) // db1 is stack top, db2 is char being compared
{
	int n_db1; // create ints to assign precedence numbers to
	int n_db2;
	switch (db1)
	{
	case '!':
		n_db1 = 3; // ! has highest precedence so I set it to the greatest int
		break;
	case '&':
		n_db1 = 2; // & has second highest precedence so I set it to the second greatest int
		break;
	case '|':
		n_db1 = 1; // | has lowest precedence so I set it to lowest int
		break;
	default:
		n_db1 = -1;
		break;
	}
	switch (db2)
	{
	case '!':
		n_db2 = 3; // ! has highest precedence so I set it to the greatest int
		break;
	case '&':
		n_db2 = 2; // & has second highest precedence so I set it to the second greatest int
		break;
	case '|':
		n_db2 = 1; // | has lowest precedence so I set it to lowest int
		break;
	default:
		n_db2 = -1;
		break;
	}
	return (n_db2 <= n_db1);
	// n_db2 is less than or equal to n_db1, return true
	// if n_db2 is greater than n_db1, return false
}

int evaluate(string infix, string& postfix, bool& result)
{
	if (isValidInfix(infix) == true)
	{
		postfix = infixToPostfix(infix, postfix);
		stack<char> opStack;
		for (int i = 0; i < postfix.size(); i++)
		{
			bool operand;
			char db = postfix[i];
			switch (db)
			{
			case 'F':
				opStack.push(false);
				break;
			case 'T':
				opStack.push(true);
				break;
			case '!':
				operand = opStack.top();
				opStack.pop();
				opStack.push(!operand);
				break;
			default:
				bool operand2 = opStack.top();
				opStack.pop();
				if (opStack.empty() == true)
					return 1;
				bool operand1 = opStack.top();
				opStack.pop();
				if (db == '&')
				{
					if ((operand1 && operand2) == true)
						opStack.push(true);
					else
						opStack.push(false);
				}
				if (db == '|')
				{
					if ((operand1 || operand2) == true)
						opStack.push(true);
					else
						opStack.push(false);
				}
				break;
			}
		}
		result = opStack.top();
		return 0;
	}
	return 1;
}
