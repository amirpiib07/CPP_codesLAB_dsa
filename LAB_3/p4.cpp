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
    void insertionByPosition(int position, int data) {
        if (position < 0 || position > size) {
            cout << "Position out of bounds" << endl;
            return;
        }
        size++;
        node *temp = new node(data);
        if (head == NULL) {
            head = temp;
            return;
        }
        if (position == 0) {
            temp->next = head;
            head = temp;
            return;
        }
        node *check = head;
        for (int i = 1; i < position; i++) {
            check = check->next;
        }
        temp->next = check->next;
        check->next = temp;
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

    void deleteByPosition(int position) {
        if (position < 0 || position > size - 1) {
            cout << "Position out of bounds" << endl;
            return;
        }
        size--;
        node *temp = head;
        if (position == 0) {
            head = head->next;
            if (head == NULL) {
                delete head;
                return;
            }
            return;
        }
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return;
    }

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
};

int main() {
    LinkedList L;
    L.insertAtHead(40);
    L.insertAtHead(30);
    L.insertAtHead(20);
    L.insertAtHead(10);
    L.insertionByPosition(2, 25);
    L.deleteByPosition(4);
    L.display();
    return 0;
}
