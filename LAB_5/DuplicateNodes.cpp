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

    void deleteDuplicates() {
        vector<int> ans;
        node *temp = head;
        while (temp != NULL) {
            ans.push_back(temp->data);
            temp = temp->next;
        }
        int n = ans.size();
        vector<int> nond;
        for (int i = 0; i < ans.size(); i++) {
            int count = 0;
            for (int j = 0; j < ans.size(); j++) {
                if (ans[i] == ans[j]) {
                    count++;
                }
            }
            if (count==1) {
                nond.push_back(ans[i]);
            }
        }

        node *c = new node(nond[0]);
        tail = head = c;

        for (int i = 1; i < nond.size(); i++) {
            node *n = new node(nond[i]);
            if (head == NULL) {
                tail = head = temp;
            } else {
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
        }
    }
    };

    int main() {
        DoubleLL l;
        l.pushFront(3);
        l.pushFront(5);
        l.pushFront(2);
        l.pushFront(4);
        l.pushFront(2);
        l.pushFront(5);
        l.print();
        l.deleteDuplicates();
        l.print();


        return 0;
    }