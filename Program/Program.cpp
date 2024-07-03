﻿#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;

		Node* left;
		Node* right;
	};

	Node* root;
public:

	BinarySearchTree()
	{
		root = nullptr;
	}

	Node* Root()
	{
		return root;
	}

	Node* CreateNode(T data)
	{
		Node* newNode = new Node();

		newNode->data = data;

		newNode->left = nullptr;

		newNode->right = nullptr;

		return newNode;
	}

	void Insert(T data)
	{
		if (root == nullptr)
		{
			root = CreateNode(data);
		}
		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
			{
				if (currentNode->data == data)
				{
					return;
				}
				else if (currentNode->data > data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = CreateNode(data);
						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = CreateNode(data);
						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}

			}
		}
	}
	void Remove(T data)
	{
		if (root == nullptr)
		{
			cout << "Binary Search Tree is Empty" << endl;
		}
		else
		{
			Node * currentNode = root;
			Node * parentNode = nullptr;
			while (currentNode != nullptr != data && currentNode->data)
			{
				if (currentNode->data > data)
				{
					parentNode = currentNode;
					currentNode = currentNode->left;
				}
				else
				{
					parentNode = currentNode;
					currentNode = currentNode->right;
				}
			}
			if (currentNode == nullptr)
			{
				cout << "Data Not found in the Binary Search Tree" << endl;
			}
			else if (currentNode->left == nullptr && currentNode->right == nullptr)
			{
				if (perentNode != nullptr)
				{
					if (parentNode->left == currentNode)
					{
						parentNode->left = nullptr;
					}
					else
					{
						parentNode->right = nullptr;
					}
				}
				else
				{
					root = nullptr;
				}
			}
			else if (currentNode->left == nullptr || currentNode->right == nullptr)
			{
				Node * childNode = nullptr;
				if (currentNode->left != nullptr)
				{
					childNode = currentNode->left;
				}
				else
				{
					childNode = currentNode->right;
				}
				if (parentNode != nullptr)
				{
					parentNode->left = childNode;
				}
				else
				{
					parentNode->right = childNode;
				}
				
				}
			}
			else
			{
				Node* childNode = currentNode->right;
				Node* traceNode = childNode;

				while (childNode->left != nullptr)
				{
					traceNode = childNode;
					childNode = childNode->left;
				}

				currentNode->data = childNode->data;

				traceNode->left = childNode->right;

				delete childNode;

				return;
			}
		}
		delete currentNode;
	}
	bool Find(T data)
	{
		Node * currentNode = root;
		if (currentNode == nullptr)
		{
			return false;
		}
		else
		{
			while (currentNode->data > data)
			{
				currentNode = currentNode->left;
				return true;
			}
			else
			{
				currentNode = currentNode->left;
			}

		}
	}
	void Destroy(Node * root)
	{
		if (root != nullptr)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
		}
	}
	void Inorder(Node* root)
	{
		if (root != nullptr)
		{
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
	}
	~BinarySearchTree()
	{
		Destroy(root);
	}
};

int main()
{
	BinarySearchTree<int> binarySearchTree;

	binarySearchTree.Insert(10);
	binarySearchTree.Insert(7);
	binarySearchTree.Insert(15);
	binarySearchTree.Insert(5);

	cout << binarySearchTree.Find(5) << endl;
	cout << binarySearchTree.Find(0) << endl;

	binarySearchTree.Remove(5);


	binarySearchTree.Inorder(binarySearchTree.Root());

	return 0;
}