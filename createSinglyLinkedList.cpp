#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    };

// Function to print the linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main()
{
    // Creating the first node with value 3
    Node *node1 = new Node(3);
    Node *head = node1;
    // Adding more nodes
    node1->next = new Node(4);
    node1->next->next = new Node(5);
    node1->next->next->next = new Node(6);
    node1->next->next->next->next = new Node(7);
    node1->next->next->next->next->next = new Node(8);


    // Printing the linked list

    print(head);

    return 0;
}
