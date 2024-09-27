#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

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

    Node *node1 = new Node(3);
    Node *head = node1;

    Node *node2 = new Node(4);
    node1->next = node2;
    node2->prev = node1;

    Node *node3 = new Node(5);
    node2->next = node3;
    node3->prev = node2;

    Node *node4 = new Node(6);
    node3->next = node4;
    node4->prev = node3;

    Node *node5 = new Node(7);
    node4->next = node5;
    node5->prev = node4;

    print(head);

    return 0;
}
