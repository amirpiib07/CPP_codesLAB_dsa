#include <iostream>
#include <vector>
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

    vector<vector<int>> pairSum(int target) {
        vector<vector<int>> ans;
        node* i=head;
        node* j=tail;
        while (i!=j&&i!=j->prev) {
            if (target==i->data+j->data) {
                vector<int>v={i->data,j->data};
                ans.push_back(v);
                i=i->next;
                j=j->prev;
            }
            else if (target<i->data+j->data) {
                i=i->next;
            }
            else {
                j=j->prev;
            }
        }
        return ans;

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
    for (vector<int> i: l.pairSum(7)) {
        for (int j: i) cout << j << " ";
        cout << endl;
    }
    return 0;
}