#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    node *head = NULL;
    node *tail = NULL;
    int size = 0;

public:
    void insertAtTail(int data) {
        node *temp = new node(data);
        size++;
        if (tail == NULL) {
            tail = head = temp;
            head->next = NULL;
            tail->next = NULL;
            return;
        }
        tail->next = temp;
        tail = temp;
        return;
    }

    void display() {
        node *temp = head;
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList L;
    L.insertAtTail(10);
    L.insertAtTail(20);
    L.insertAtTail(30);
    L.insertAtTail(40);
    L.insertAtTail(50);
    L.display();
    return 0;
}
