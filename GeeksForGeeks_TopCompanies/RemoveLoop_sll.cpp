#include <iostream>
#include<unordered_set>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if (position == 0) return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if (!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next) return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node* head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

class Solution
{
public:
    unordered_set<Node*> pos_pointertonode_set;

    Node* iter_removeLoop(Node* head)
    {
        if (head == 0)
            return head;

        Node* start = head;
        Node* prev = 0;

        while (start != 0)
        {
            auto it = pos_pointertonode_set.find(start);
            if (it != pos_pointertonode_set.end())
            {
                if(prev != 0)
                    prev->next = 0;
                break;
            }
            prev = start;
            pos_pointertonode_set.insert(prev);
            start = start->next;
        }
        return head;
    }

    //Function to remove a loop in the linked list.
    // if pos == 0, meaning no loop in linkedlist
    void removeLoop(Node* head)
    {
        head = iter_removeLoop(head);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;
        //cout << n << "\n";

        Node* head, * tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            //cout << n << " ";
            tail->next = new Node(num);
            tail = tail->next;
        }
    
        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}
