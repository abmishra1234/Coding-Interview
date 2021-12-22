#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<iostream>
#include <sstream> 

using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input 
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	size_t i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

class Solution
{
public:
	bool result;
	int check(Node* root)
	{
		if (root->left == nullptr and root->right == nullptr)
		{
			// this is the case of leaf node 
			result = true;
			return root->data;
		}
		else if (root->left == nullptr)
		{
			// it means that you have only right child
			int rsum = 0;
			rsum += check(root->right);
			result = false;
			if (rsum == root->data)
			{
				result = true;
			}
			return rsum + root->data;
		}
		else if (root->right == nullptr)
		{
			// it means that you have only right child
			int lsum = 0;
			lsum += check(root->left);
			result = false;
			if (lsum == root->data)
			{
				result = true;
			}
			return lsum + root->data;
		}
		else
		{
			int lsum = 0, rsum = 0;
			lsum = check(root->left);
			rsum = check(root->right);

			result = false;
			if (lsum + rsum == root->data)
			{
				result = true;
			}
			return lsum + rsum + root->data;
		}
	}

	bool isSumTree(Node* root)
	{
		result = false;
		check(root);
		return result;
	}
};

int main()
{
	int t;
	scanf_s("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin, s);
		Node* root = buildTree(s);
		Solution ob;
		cout << ob.isSumTree(root) << endl;
	}
	return 1;
}
