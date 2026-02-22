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




};
   void split(node* head) {
       if (head == NULL) {
           cout << "NULL" << endl;
           return;
       }

       node* temp=head;
       while (temp->next != head) {
           temp = temp->next;
       }
       temp->next = nullptr;
       if (head->next == NULL) {
           cout<<head->data<<"->"<<"NULL" << endl;
           return;
       }

       node* slow=head;
       node* fast=head;
       while(fast!=nullptr&&fast->next!=nullptr && fast->next->next != nullptr) {
           slow = slow->next;
           fast = fast->next->next;
       }
       node* head2=slow->next;
       node* head1=head;
       slow->next = nullptr;
       temp=head1;
       while (temp!=nullptr) {
           cout << temp->data << "->";
           temp = temp->next;
       }
       cout << "NULL" << endl;
       temp=head2;
       while (temp!=nullptr) {
           cout << temp->data << "->";
           temp = temp->next;
       }
       cout << "NULL" << endl;
       return;
   }

int main() {
    node* a=new node(10);
       node* b=new node(20);
       node* c=new node(30);
       node* d=new node(40);
       node* e=new node(50);
       node* f=new node(60);
       node* g=new node(70);
       a->next=b;


       b->next=c;
       c->next=d;
       d->next=e;
       e->next=f;
       f->next=g;
       g->next=a;
       split(a);
    return 0;
}
