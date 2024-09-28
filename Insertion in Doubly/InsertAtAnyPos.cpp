#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    head = head->next;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtStart(Node *&tail, Node *&head, int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else
    {

        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtEnd(Node *&head, Node *&tail, int d)
{

    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }

    else
    {
        Node *temp = new Node(d);

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void InsertAtAnyPoint(int pos, Node *&head, Node *&tail, int val)
{
    if (pos == 1)
    {
        InsertAtStart(tail, head, val);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    if (temp->next == NULL)
    {
        InsertAtEnd(head, tail, val);
    }

    Node *nodeToInsert = new Node(val);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;

    InsertAtStart(tail, head, 22);
    InsertAtStart(tail, head, 23);
    InsertAtStart(tail, head, 24);
    InsertAtStart(tail, head, 25);
    InsertAtStart(tail, head, 26);

    InsertAtEnd(head, tail, 345);

    InsertAtAnyPoint(2, head, tail, 1010);
    print(head);
}
