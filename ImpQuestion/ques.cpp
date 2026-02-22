#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int data) {
       this->data = data;
        next = NULL;
    }
};
class LL {
    public:
    node* head=nullptr;
    void insertAtPos(int data, int pos) {
        node* temp = new node(data);
        if (pos<0) {
            cout<<"invalid position"<<endl;
            return;
        }
        if (pos>sizeof(ll)) {
            cout<<"invalid position"<<endl;
        }

        if (pos==0&&head==NULL) {
            head=temp;
            return;
        }
        node* temp2=head;
        if (pos==0) {
            temp->next=head;
            head=temp;
            return;
        }
        for (int i=1;i<=pos-1;i++) {
            temp2=temp2->next;
        }
        temp->next=temp2->next;
        temp2->next=temp;

    }
};