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
    int size = 0;

public:
    void insertFront(int data) {
        node *temp = new node(data);
        size++;
        if (head == NULL) {
            head = temp;
            head->next = NULL;
            return;
        }
        temp->next = head;
        head = temp;
        return;
    }

    void undo() {
        if (head == NULL) {
            cout << "linked list is empty" << endl;
            return;
        }
        head = head->next;
        if (head == NULL) {
            cout << "linked list is now become empty" << endl;
        }
        return;
    }

    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList L;
    L.insertFront(10);
    L.insertFront(20);
    L.undo();
    L.display();
    return 0;
}
