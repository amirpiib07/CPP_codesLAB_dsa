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
int sizeofcl(node* head) {
    int count=1;
    node* temp=head;
    temp=temp->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}
    void deleteKthNode(node* head, int k) {
        node *temp = head;
        int s=sizeofcl(head);
        node* help=head;
        while (s!=1) {
            for (int i=1;i<=k;i++) {
                help=help->next;
            }
            temp->next=help;
            temp=help;
            s--;
        }
        cout<<temp->data<<" ";

    }



int main() {
    node *a = new node(1);
    node *b = new node(2);
    node *c = new node(3);
    node *d = new node(4);
    node *e = new node(5);
    // node *f = new node(60);
    // node *g = new node(70);
    a->next = b;


    b->next = c;
    c->next = d;
    d->next = e;
    e->next = a;
    // f->next = g;
    // g->next = a;
    deleteKthNode(a,2);

    return 0;
}
