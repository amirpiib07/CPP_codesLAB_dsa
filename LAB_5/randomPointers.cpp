#include<iostream>
#include <unordered_map>
using namespace std;
class node {
    public:
    node* next;
    node* prev;
    node* random;
    int data;
    node(int data) {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
        this->random=nullptr;
    }
};
node* deepCopy(node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    unordered_map<node*, node*> map;
    node*temp=head;
    node* dummy= new node(-1);
    node* k=dummy;
    while (temp!=nullptr) {
        node* i=new node(temp->data);
        k->next=i;
        i->prev=k;
        k=k->next;
        temp=temp->next;
    }
    node* temp1=head;
    node* temp2=dummy->next;
    while (temp1!=nullptr) {
        map[temp1]=temp2;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp1=head;
    temp2=dummy->next;
    while (temp1!=nullptr) {
        temp2->random=map[temp1->random];
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return dummy->next;

}
void display(node* head) {
    node* temp=head;
    while (temp!=nullptr) {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}
int main() {
    node* a=new node(1);
    node* b=new node(3);
    node* c=new node(5);
    node* d=new node(9);
    a->prev=nullptr;
    a->next=b;
    b->prev=a;
    b->next=c;
    c->prev=b;
    c->next=d;
    d->prev=c;
    d->next=nullptr;
    a->random=c;
    b->random=c;
    c->random=nullptr;
    d->random=c;
    display(a);
    display(deepCopy(a));
    return 0;
}