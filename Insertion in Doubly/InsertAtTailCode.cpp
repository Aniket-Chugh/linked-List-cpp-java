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

void InsertAtStart(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
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

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;

    cout << "this is the list after insertion  :";
    InsertAtStart(head, 22);
    InsertAtStart(head, 23);
    InsertAtStart(head, 24);
    InsertAtStart(head, 25);
    InsertAtStart(head, 26);

    InsertAtEnd(tail, 345);
    print(head);
}

