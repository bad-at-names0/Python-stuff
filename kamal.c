#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

typedef struct Node Node;

Node *head = NULL;
Node *cur = NULL;

void makeList(int x)
{
    if (!head)
    {
        head = (Node *)malloc(sizeof(Node));
        head->val = x;
        head->next = NULL;
        cur = head;
    }
    else
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->val = x;
        temp->next = NULL;
        cur->next = temp;
        cur = temp;
    }
}

void appendLastToFirst()
{
    if (!head)
    {
        return;
    }
    if (!head->next)
    {
        return;
    }
    Node *temp = head;
    Node *trail = NULL;
    while (temp->next)
    {
        trail = temp;
        temp = temp->next;
    }
    trail->next = NULL;
    temp->next = head;
    head = temp;
}

void sortList()
{
    Node *t;
    Node *s;
    int x;
    t = head;
    while (t != NULL)
    {
        s = t->next;
        while (s != NULL)
        {
            if (t->val > s->val)
            {
                x = t->val;
                t->val = s->val;
                s->val = x;
            }
            s = s->next;
        }
        t = t->next;
    }
}

void displayList()
{
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    // makeList(8) -> adds 8 to the end of the list ... used for making the list
    // appendToLast() -> remove the last node and adds it to the front of the linked list
    // displayList() -> used to display the contents of the list
    // sortList() ->used to sort the list
    return 0;
}