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
public:
    void pushFront(int data) {
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
    void reverseList() {
        if (head==nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        node* curr=head;
        node* pre=nullptr;
        node* ford=nullptr;
        while (curr!=nullptr) {
            ford=curr->next;
            curr->next=pre;
            curr->prev=ford;
            pre=curr;
            curr=ford;
        }
        head=pre;
    }
};

int main() {
    DoubleLL l;
    l.pushFront(10);
    l.pushFront(20);
    l.pushFront(30);
    l.pushFront(40);
    l.pushFront(50);
    l.print();

    l.reverseList();
    l.print();
    l.reverseList();
    l.print();
    return 0;
}