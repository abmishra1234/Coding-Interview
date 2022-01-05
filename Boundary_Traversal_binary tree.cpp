/*
TODO :  Need to re-word because output is not as expected in result.
*/

#include<iostream>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<queue>

using namespace std;

#define FORREF

#ifndef FORREF
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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


class Solution {
public:
    vector<int> output;
    vector<int> temp;
    void LeftBoundry(Node* root)
    {
        if (root)
        {
            if (root->left)
            {
                output.push_back(root->data);
                LeftBoundry(root->left);
            }
            else if (root->right)
            {
                output.push_back(root->data);
                LeftBoundry(root->right);
            }
        }
    }

    void LeafNode(Node* root)
    {
        if (root)
        {
            LeafNode(root->left);
            if (!root->left and !root->right) {
                output.push_back(root->data);
            }
            LeafNode(root->right);
        }
    }

    void RightBoundry(Node* root)
    {
        if (root)
        {
            if (root->right)
            {
                temp.push_back(root->data);
                RightBoundry(root->right);
            }
            else if (root->left)
            {
                temp.push_back(root->data);
                RightBoundry(root->left);
            }
        }
    }

    vector <int> boundary(Node* root)
    {
        // left boundry tree
        LeftBoundry(root);
        // Leaf Node
        LeafNode(root);
        // Right Boundry tree
        RightBoundry(root->right);

        for (int i = temp.size() - 1; i >= 0; --i)
        {
            output.push_back(temp[i]);
        }

        return output;
    }
};


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
#endif // !FORREF



  