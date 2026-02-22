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
public:
    node *head = NULL;
    int size = 0;

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

    void reverse(int k) {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }
        //use dummy node to simplify the problem of head handling
        node *dummy = new node(-1);
        dummy->next = head;
        node *prevGroupTail = dummy;
        node *curr = head;

        //count total nodes
        int count = 0;
        while (curr != NULL) {
            curr = curr->next;
            count++;
        }
        curr = head;

        //reverse the node in k group first
        while (count >= k) {
            node *groupHead = curr;
            node *prev = NULL;
            node *ford = NULL;

            //reverse k node first
            for (int i = 0; i < k; i++) {
                ford = curr->next;
                curr->next = prev;
                prev = curr;
                curr = ford;
            }

            //connect previous group node with the current
            prevGroupTail->next = prev;
            groupHead->next = curr;

            //move previous group tail
            prevGroupTail = groupHead;

            count -= k;
        }
        head = dummy->next;
        return;
    }
};


int main() {
    LinkedList L;
    L.insertAtHead(8);
    L.insertAtHead(7);
    L.insertAtHead(6);
    L.insertAtHead(5);
    L.insertAtHead(4);
    L.insertAtHead(3);
    L.insertAtHead(2);
    L.insertAtHead(1);
    cout<<"original linked list"<<endl;
    L.display();
    L.reverse(3);
    cout<<"reversed linked list"<<endl;
    L.display();
    return 0;
}
