﻿#include <iostream>

using namespace std;
template<typename T>
class SingleLinkedList
{
private:
	int size;
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;
public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	}
	void PushFront(T data)
	{
		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node* newNode = new Node;
			newNode->next = head;
			newNode->data = data;
			head = newNode;
		}
		size++;
	}
	void PopFront()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			head = deleteNode->next;
			delete deleteNode;
			size--;
		}
	}
	void PushBack(T data)
	{
		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			Node* newNode = new Node;
			currentNode->next = newNode;
			newNode->data = data;
			newNode->next = nullptr;
		}
	}
	void PopBack()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			Node* previousNode = nullptr;
			if (size == 1)
			{
				head = deleteNode->next;
				delete deleteNode;
			}
			else
			{
				while (deleteNode->next != nullptr)
				{
					previousNode = deleteNode;
					deleteNode = deleteNode->next;
				}
				previousNode->next = deleteNode->next;
				delete deleteNode;
			}
			size--;
		}
	}
	void Show()
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}
	~SingleLinkedList()
	{
		if (head != nullptr)
		{
			while (head != nullptr)
			{
				PopBack();
			}
		}
	}
};

int main()
{
	SingleLinkedList<int> singleLinkedList;
	singleLinkedList.PushBack(10);
	singleLinkedList.PushBack(20);
	singleLinkedList.PushBack(30);

	singleLinkedList.PopBack();
	singleLinkedList.PopBack();
	singleLinkedList.PopBack();
	// singleLinkedList.PopFront();

	singleLinkedList.Show();

	return 0;
}