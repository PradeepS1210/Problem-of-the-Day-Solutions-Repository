/*
Asked in Oracle, Microsoft, Airbnb, Meesho, Deolitte, Tech Mahindra, ZS
Problem of the Day: Hit Target
problem Description: https://medium.com/@pradeepsooryavanshee1210/hit-target-unstop-solution-e01080f08911
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr) {}

    void append(int val)
    {
        if (!head)
        {
            head = new Node(val);
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    bool hasPairWithSum(int target)
    {
        unordered_set<int> seen;
        Node *temp = head;
        while (temp)
        {
            int complement = target - temp->data;
            if (seen.find(complement) != seen.end())
            {
                return true;
            }
            seen.insert(temp->data);
            temp = temp->next;
        }
        return false;
    }
};

int main()
{
    int n, target;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        list.append(value);
    }

    cin >> target;

    if (list.hasPairWithSum(target))
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }

    return 0;
}