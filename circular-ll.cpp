#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

class CircularLL
{
private:
    Node *head = NULL;
    Node *last = head;

public:
    CircularLL(vector<int> v)
    {
        Node *temp = new Node(v[0]);
        head = temp;
        temp->next = head;
        Node *cur = head;
        for (int i = 1; i < v.size(); i++)
        {
            temp = new Node(v[i]);
            cur->next = temp;
            temp->next = head;
            cur = temp;
        }
    }

    void DisplayCLL()
    {
        Node *temp = head;
        do
        {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    vector<int> v(5);
    for (int i = 0; i < 5; i++)
    {
        v[i] = i + 3;
    }
    CircularLL L(v);
    L.DisplayCLL();
    return 0;
}