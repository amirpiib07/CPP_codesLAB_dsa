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
   void reverse(node* head) {
       if (head == NULL) {
           cout << "NULL" << endl;
           return ;
       }

       node* temp=head;
       while (temp->next != head) {
           temp = temp->next;
       }
       temp->next=nullptr;
       node* curr=head;
       node* prev=nullptr;
       node* ford=nullptr;
       while (curr != NULL) {
           ford=curr->next;
           curr->next=prev;
           prev=curr;
           curr=ford;
       }
       head->next=prev;
       head=prev;
       temp=head;
       while (temp->next != head ) {
           cout << temp->data<< " " ;
           temp = temp->next;
       }
       cout << temp->data<< endl;
   }

int main() {
    node* a=new node(10);
       node* b=new node(20);
       node* c=new node(30);
       node* d=new node(40);
       node* e=new node(50);
       node* f=new node(60);
       node* g=new node(80);
       a->next=b;


       b->next=c;
       c->next=d;
       d->next=e;
       e->next=f;
       f->next=g;
       g->next=a;
       reverse(a);
    return 0;
}
