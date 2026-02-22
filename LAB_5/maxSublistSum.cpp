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

    int maxSublistSum() {
        if (head==NULL) {
            cout << "List is empty" << endl;
            return 0;
        }
        node *temp = head;
        int currentSum = temp->data;
        int maxSum = temp->data;

        int count=1;
        int start=0, end=0;
        temp=temp->next;
        while (temp!=NULL) {

            if (temp->data> currentSum+temp->data) {
                currentSum = temp->data;
                start=count;
                end=start;
            }
            else {
                currentSum+=temp->data;
                end++;
            }
            if (currentSum>maxSum) {
                maxSum = currentSum;
            }
            temp = temp->next;
            count++;

        }

        temp = head;
        for (int i=0;i<start;i++) {
            temp = temp->next;
        }
        temp->prev=nullptr;
        head=temp;
        for (int i=start;i<end-1;i++) {
            temp = temp->next;
        }
        temp->next = nullptr;
        return maxSum;

    }
};

int main() {
    DoubleLL l;
    l.pushFront(-8);
    l.pushFront(7);
    l.pushFront(-1);
    l.pushFront(4);
    l.pushFront(5);
    l.pushFront(-4);
    l.pushFront(3);
    l.print();
    cout << l.maxSublistSum() << endl;
    l.print();




    return 0;
}
