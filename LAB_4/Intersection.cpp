#include <iostream>
#include <vector>
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

int intersection(node *p, node *q) {
    node *temp = p;
    node *temp2 = q;
    int count1 = 0, count2 = 0;
    while (temp != NULL) {
        count1++;
        temp = temp->next;
    }
    while (temp2 != NULL) {
        count2++;
        temp2 = temp2->next;
    }
    int net = count1 - count2;
    if (net < 0) {
        net = (-net);
    }
    temp = p;
    temp2 = q;
    if (count1 > count2) {
        for (int i = 1; i <= net; i++) {
            temp = temp->next;
        }
    } else {
        for (int i = 1; i <= net; i++) {
            temp2 = temp2->next;
        }
    }
    while (temp != NULL && temp2 != NULL) {
        if (temp->next == temp2->next) {
            return temp->next->data;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    return -1;
}

int main() {
    node *p = new node(1); //head of the linked list(head1)
    node *q = new node(2);
    node *r = new node(3);
    node *s = new node(6);
    node *t = new node(7);
    node *u = new node(8);
    node *v = new node(4); //head2
    node *w = new node(5);
    p->next = q;
    q->next = r;
    r->next = s;
    s->next = t;
    t->next = u;
    u->next = NULL;
    v->next = w;
    w->next = s;
    cout << "Intersection point of the two linked lists is: " << intersection(p, v) << endl;


    return 0;
}
