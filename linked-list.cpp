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

class LinkedList
{
private:
    Node *head = NULL;

public:
    LinkedList(vector<int> v)
    {
        Node *temp = new Node(v[0]);
        head = temp;
        Node *cur = head;
        for (int i = 1; i < v.size(); i++)
        {
            temp = new Node(v[i]);
            cur->next = temp;
            cur = temp;
        }
    }

    int countNodes()
    {
        Node *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void InsertAtBegin(int x)
    {
        Node *temp = new Node(x);
        if (head)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            head = temp;
        }
    }

    void InsertAtPos(int x, int pos)
    {
        if (pos < 0 || pos > countNodes())
        {
            cout << "Invalid position";
            return;
        }
        if (x == 0)
        {
            InsertAtBegin(x);
            return;
        }
        Node *cur = head;
        Node *temp = new Node(x);
        for (int i = 1; i < pos; i++)
        {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
    }

    int DeleteBegin()
    {
        if (!head)
        {
            return -1;
        }
        Node *temp = head;
        head = head->next;
        int deletedVal = temp->val;
        delete temp;
        return deletedVal;
    }

    int DeleteVal(int x)
    {
        if (!head)
        {
            return -1;
        }
        Node *temp = head;
        Node *trail = NULL;
        while (temp && temp->val != x)
        {
            trail = temp;
            temp = temp->next;
        }
        if (!temp)
        {
            return -1;
        }
        trail->next = temp->next;
        int deletedVal = temp->val;
        delete temp;
        return deletedVal;
    }

    void DisplayList()
    {
        Node *temp = head;
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
    vector<int> v(5);
    for (int i = 0; i < 5; i++)
    {
        v[i] = i + 3;
    }
    LinkedList L(v);
    L.DisplayList();
    L.InsertAtBegin(99);
    L.DisplayList();
    L.DeleteBegin();
    L.DisplayList();
    L.DeleteVal(7);
    L.DisplayList();
    L.InsertAtPos(43, 3);
    L.DisplayList();
    return 0;
}