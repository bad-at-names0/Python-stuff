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

class Queue
{
public:
    Node *end = NULL;
    Node *start = NULL;

    // push pop peek isEmpty display queue
    void push(int x)
    {
        Node *temp = new Node(x);
        if (!start)
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
    }

    int pop()
    {
        if (!start)
        {
            return -1;
        }
        else
        {
            Node *temp = start;
            start = start->next;
            int deletedVal = temp->val;
            delete temp;
            return deletedVal;
        }
    }

    int peek()
    {
        if (!start)
        {
            return -1;
        }
        else
            return start->val;
    }

    bool isEmpty()
    {
        if (!start)
            return true;
        return false;
    }

    void displayQueue()
    {
        Node *temp = start;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.push(4);
    q.push(6);
    q.push(9);
    q.displayQueue();
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    q.pop();
    cout << q.isEmpty() << endl;
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    return 0;
}