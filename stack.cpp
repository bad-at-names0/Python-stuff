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

class Stack
{
public:
    Node *head = NULL;
    // push pop read isEmpty

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    int pop()
    {
        if (!head)
        {
            return -1;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            int deletedVal = temp->val;
            delete temp;
            return deletedVal;
        }
    }

    int peek()
    {
        if (!head)
        {
            return -1;
        }
        return head->val;
    }

    bool isEmpty()
    {
        if (!head)
            return true;
        return false;
    }
};

int main()
{
    Stack S;
    S.push(5);
    cout << S.peek() << endl;
    S.push(9);

    cout << S.peek() << endl;
    S.pop();

    cout << S.peek() << endl;
    cout << S.isEmpty() << endl;
    S.pop();
    cout << S.isEmpty() << endl;
    cout << S.peek() << endl;

    return 0;
}