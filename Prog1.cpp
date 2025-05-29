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

class DynamicMemoryAllocation
{
public:
    int size;
    Node *head;

    DynamicMemoryAllocation()
    {
        this->head = NULL;
        this->size = 0;
    }

    void appendNodeToList(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            Node *ptr = this->head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        this->size++;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }

    void searchByIndex(int index)
    {
        if (index >= 0 && index < size)
        {
            Node *ptr = this->head;
            for (int i = 0; i < index; i++)
            {
                ptr = ptr->next;
            }
            cout << "Search element is: " << ptr->data << endl;
        }
        else
        {
            cout << "Index out of bounds." << endl;
        }
    }

    void deleteByIndex(int index)
    {
        if (index >= 0 && index < size)
        {
            Node *ptr = this->head;
            if (index == 0)
            {
                this->head = head->next;
            }
            else
            {
                for (int i = 0; i < index - 1; i++)
                {
                    ptr = ptr->next;
                }
                ptr->next = ptr->next->next;
            }
            this->size--;
        }
        else
        {
            cout << "Index out of bounds." << endl;
        }
    }

    void reverseList()
    {
        Node *prev = NULL;
        Node *current = this->head;
        Node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
        Node *ptr = this->head;
        cout << "Reverse Linked List: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void displayList()
    {
        Node *ptr = this->head;
        cout << "Linked List: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};
int main()
{

    int choice, index, element;
    DynamicMemoryAllocation list;

    do
    {
        cout << endl;
        cout << "Enter 1 for Append Node to List" << endl;
        cout << "Enter 2 for Insert at beginning" << endl;
        cout << "Enter 3 for Search Node by index" << endl;
        cout << "Enter 4 for Delete Node by index" << endl;
        cout << "Enter 5 for Reverse List" << endl;
        cout << "Enter 6 for Display List" << endl;
        cout << "Enter 0 for Exit" << endl;
        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> element;
            list.appendNodeToList(element);
            break;
        case 2:
            cout << "Enter element: ";
            cin >> element;
            list.insertAtBeginning(element);
            break;
        case 3:
            cout << "Enter index for search: ";
            cin >> index;
            list.searchByIndex(index);
            break;
        case 4:
            cout << "Enter index for delete: ";
            cin >> index;
            list.deleteByIndex(index);
            break;
        case 5:
            list.reverseList();
            break;
        case 6:
            list.displayList();
            break;
        case 0:
            cout << "Exit." << endl;
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}