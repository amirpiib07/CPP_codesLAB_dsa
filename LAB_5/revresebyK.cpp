#include <iostream>
using namespace  std;
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
    node* head=NULL;
    node* tail=NULL;
    int size=0;
public:
    void pushFront(int data) {
        size++;
        node *temp = new node(data);
        if (head == NULL) {
            head = temp;
            tail=temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }
    void print() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data<< " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseByK(int k) {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }
        k%=size;
        node* head1 = head;
        node* temp=head;
        for (int i=0; i<k-1; i++) {
            temp=temp->next;
        }
        node* temp2 = temp->next;
        temp->next=nullptr;
        temp2->prev=nullptr;
        tail->next=head;
        head->prev=tail;
        head=temp2;
    }



};

int main() {
    DoubleLL l;
    l.pushFront(1);
    l.pushFront(2);
    l.pushFront(4);
    l.pushFront(5);
    l.pushFront(6);
    l.print();
    l.reverseByK(3);
    l.print();

    return 0;
}
