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
    void insertAtHead(int data) {
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

    void insertAtTail(int data) {
        node *temp = new node(data);
        size++;
        if (head == NULL) {
            head = temp;
            head->next = NULL;
            return;
        }
        node *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = temp;
        tail = temp;
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

    void reverseList() {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }
        node *curr = head;
        node *prev = NULL;
        node *ford = NULL;
        while (curr != NULL) {
            ford = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ford;
        }
        head = prev;
        return;
    }
};

int main() {
    LinkedList L;
    L.insertAtTail(10);
    L.insertAtTail(20);
    L.insertAtTail(30);
    cout << "original linked list" << endl;
    L.display();
    cout << "reverse linked list" << endl;
    L.reverseList();
    L.display();
    return 0;
}
