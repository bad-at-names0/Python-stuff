#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->prev = NULL;
        this->next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head = NULL;

public:
    DoublyLinkedList(vector<int> v)
    {
        Node *temp = new Node(v[0]);
        head = temp;
        Node *cur = head;
        for (int i = 1; i < v.size(); i++)
        {
            temp = new Node(v[i]);
            cur->next = temp;
            temp->prev = cur;
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
            head->prev = temp;
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
        if (x < 0 || x > countNodes())
        {
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
        cur->next->prev = temp;
        cur->next = temp;
        temp->prev = cur;
    }

    int DeleteBegin()
    {
        if (!head)
        {
            return -1;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
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
        temp->next->prev = trail;
        int deletedVal = temp->val;
        delete temp;
        return deletedVal;
    }

    void PrintRev()
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;
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
    DoublyLinkedList L(v);
    // L.DisplayList();
    // L.PrintRev();
    L.InsertAtBegin(90);
    // L.DisplayList();
    // L.PrintRev();
    L.InsertAtPos(99, 3);
    L.DisplayList();
    L.PrintRev();
    L.DeleteBegin();
    L.DisplayList();
    L.PrintRev();
    L.DeleteVal(6);
    L.DisplayList();
    L.PrintRev();
    cout << "Worked";
    return 0;
}