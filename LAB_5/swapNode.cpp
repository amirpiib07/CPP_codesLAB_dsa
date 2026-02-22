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

    node* headgroup() {
        return head;
    }

    void swap(int m, int n) {
        if (m==n) return;
        node* prev1=nullptr,*curr1=head;
        node* prev2=nullptr, *curr2=head;
        int count=1;

        while (curr1 && count<m) {
            prev1=curr1;
            curr1=curr1->next;
            count++;
        }

        count=1;
        while (curr2 && count<n) {
            prev2=curr2;
            curr2=curr2->next;
            count++;
        }

        if (!curr1 || !curr2) return;
        if (prev1) prev1->next=curr2;
        else head=curr2;
        if (prev2) prev2->next=curr1;
        else head=curr1;

        node* temp=curr1->next;
        curr1->next=curr2->next;
        curr2->next=temp;
    }
};



int main() {
    DoubleLL l;
    l.pushFront(6);
    l.pushFront(6);
    l.pushFront(4);
    l.pushFront(4);
    l.pushFront(1);
    l.pushFront(-1);
    l.print();
    l.swap(1,6);
    l.print();

    return 0;
}
