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
};

    node* merge(node* head1, node* head2) {
        if (head1 == NULL && head2 == NULL) {
            cout<<"Empty"<<endl;
            return NULL;
        }
        node* dummy= new node(-1);
        node* k=dummy;
        node* temp1= head1;
        node* temp2= head2;
        while (temp1!=nullptr && temp2!=nullptr) {
            if (temp1->data<=temp2->data) {
                k->next=temp1;
                temp1->prev=k;
                temp1=temp1->next;
            }
            else {
                k->next=temp2;
                temp2->prev=k;
                temp2=temp2->next;
            }
            k=k->next;
        }
        if (temp1!=nullptr) {
            k->next=temp1;
            temp1->prev=k;
        }
        if (temp2!=nullptr) {
            k->next=temp2;
            temp2->prev=k;
        }
        node* head=dummy->next;
        head->prev=nullptr;
        return head;
    }

    void display(node* head) {
        node* temp = head;
        while (temp!=NULL) {
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
        return;
    }

int main() {
    DoubleLL l;
    l.pushFront(6);
    l.pushFront(6);
    l.pushFront(4);
    l.pushFront(4);
    l.pushFront(1);
    l.pushFront(-1);
    DoubleLL m;
    m.pushFront(10);
        m.pushFront(2);
        m.pushFront(2);
        m.pushFront(-3);
        m.pushFront(-8);
        m.pushFront(-10);
node* t=merge(l.headgroup(),m.headgroup());
        display(t);

    return 0;
}
