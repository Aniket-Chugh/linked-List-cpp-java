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
    ~Node()
    {
        int val = this->data;
        if (this->next == NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "delete the node of value : " << val << endl;
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

void deletion(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *prev = NULL;
        Node *curr = head;

        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;

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

    cout << "list after deletion " << endl;
    deletion(head, tail, 3);
    print(head);
    return 0;
}

