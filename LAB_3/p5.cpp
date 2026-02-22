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
    void delteNthNodeFromEnd(int position) {
        if (head == NULL) {
            cout << "Linked List is Empty" << endl;
            return;
        }
        if (position > size || position <= 0) {
            cout << "invalid node" << endl;
            return;
        }
        if (head->next == NULL) {
            head = NULL;
            cout << "Linked List is now become Empty" << endl;
            return;
        }
        node *slow = head;
        node *fast = head;
        for (int i = 0; i < position; i++) {
            fast = fast->next;
        }

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
    }

    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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
    // //L.insertAtHead(5);
    // L.insertAtHead(4);
    L.insertAtHead(3);
    // L.insertAtHead(2);
    // L.insertAtHead(1);

    L.display();
    L.delteNthNodeFromEnd(1);
    L.display();
    return 0;
}
