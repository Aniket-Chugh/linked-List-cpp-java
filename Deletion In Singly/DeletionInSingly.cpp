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
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            cout << "deleted the node of value" << value;
            this->next = NULL;
        }
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

void DeleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *Prev = NULL;
        Node *curr = head;
        int count = 1;

        while (count < position)
        {
            Prev = curr;
            curr = curr->next;
            count++;
        }

        Prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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

    // Printing the linked list

    DeleteNode(head, 1);
    print(head);

    return 0;
}
