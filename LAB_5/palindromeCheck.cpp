#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *prev;

    node(int data) {
        this->next = NULL;
        this->prev = NULL;
        this->data = data;
    }
};

class DoubleLL {
    node *head = NULL;
    node *tail = NULL;
    int size = 0;

public:
    void pushFront(int data) {
        size++;
        node *temp = new node(data);
        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }

    void print() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool check() {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return false;
        }
        node* temp = head;
        node* temp1=tail;
        while (temp1!=temp && temp->prev!=temp1) {
            if (temp1->data != temp->data) {
                return false;
            }
            temp=temp->next;
            temp1=temp1->prev;
        }
        return true;
    }
};

int main() {
    DoubleLL l;
    l.pushFront(3);
    l.pushFront(5);
    l.pushFront(2);
    l.pushFront(2);
    l.pushFront(5);
    l.pushFront(3);
    l.print();
    cout<<l.check();


    return 0;
}
