﻿#include <iostream>

using namespace std;

#define SIZE 10
template<typename T>
class Stack
{
private:
	int top;
	T container[SIZE];
public:
	Stack()
	{
		top = -1;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = 0;
		}
	}
	void Push(T data)
	{
		if (top >= SIZE-1)
		{
			cout << "Stack Overflow" << endl;
		}
		else 
		{
			container[++top] = data;
		}
	}
	void Pop()
	{
		if (Empty)
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			top--;
		}
	}
	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int & Size()
	{
		return top;
	}
	T & Top()
	{
		return container[top];
	}	
};
bool CheckBracket(std::string content)
	{
	Stack<char> bracket;
		{
		if (content.length() <= 0)
		{
			{
				return false;
			}
		}
	}	
int main()
{
	Stack<int> stack;

	return 0;
}