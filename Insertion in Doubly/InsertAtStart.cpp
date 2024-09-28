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

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;

    cout << "this is the list after insertion  :";
    InsertAtStart(head, 22);
    InsertAtStart(head, 23);
    InsertAtStart(head, 24);
    InsertAtStart(head, 25);
    InsertAtStart(head, 26);

    print(head);
}

