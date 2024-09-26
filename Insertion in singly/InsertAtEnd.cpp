#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};



void insertAtEnd(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head;
    Node *tail;
    head = node1;
    tail = node1;

    insertAtEnd(tail, 12);

    insertAtEnd(tail, 16);
    print(head);
}
