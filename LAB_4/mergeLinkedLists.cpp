#include <iostream>
#include <vector>
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
public:
    node *head = NULL;
    int size = 0;

    LinkedList() {
        head = NULL;
        size = 0;
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


    node *headGroup() {
        return head;
    }
};

node *merge(node *head1, node *head2) {
    node *dummy = new node(-1);
    node *k = dummy;
    node *i = head1;
    node *j = head2;
    while (i != NULL && j != NULL) {
        if (i->data <= j->data) {
            k->next = i;
            i = i->next;
        } else {
            k->next = j;
            j = j->next;
        }
        k = k->next;
    }
    if (i != NULL) {
        k->next = i;
    }
    if (j != NULL) {
        k->next = j;
    }
    return dummy->next;
}

void printList(node *ptr) {
    node *curr = ptr;
    while (curr != NULL) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL";
}

int main() {
    LinkedList L;
    L.insertAtTail(10);
    L.insertAtTail(20);
    L.insertAtTail(30);
    L.insertAtTail(40);
    L.insertAtTail(50);
    L.display();
    LinkedList M;
    M.insertAtTail(60);
    M.insertAtTail(70);
    M.insertAtTail(80);
    M.insertAtTail(90);
    M.insertAtTail(100);
    M.display();
    printList(merge(L.headGroup(), M.headGroup()));

    return 0;
}
