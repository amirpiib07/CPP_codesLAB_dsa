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

    void deleteByData(int data) {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }
        size--;
        node *temp = head;
        node *check = NULL;
        if (head->data == data) {
            head = head->next;
            if (head == NULL) {
                delete head;
                return;
            }

            return;
        }

        while (temp->data != data) {
            check = temp;
            temp = temp->next;
            if (temp == NULL) {
                cout << "data not found in the linked list" << endl;
                return;
            }
        }

        check->next = temp->next;
        delete temp;
    }

    void deleteByPosition(int position) {
        if (position < 0 || position > size - 1) {
            cout << "Position out of bounds" << endl;
            return;
        }
        size--;
        node *temp = head;
        if (position == 0) {
            head = head->next;
            if (head == NULL) {
                delete head;
                return;
            }
            return;
        }
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return;
    }

    void searchForValue(int data) {
        node *temp = head;
        while (temp != NULL) {
            if (temp->data == data) {
                cout << temp->data << " data found!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << temp->data << " data not found!" << endl;
        return;
    }

    void reverseList() {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }
        node *curr = head;
        node *prev = NULL;
        node *ford = NULL;
        while (curr != NULL) {
            ford = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ford;
        }
        head = prev;
        return;
    }

    void detectCycle() {
        node *slow = head;
        node *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Cycle detected" << endl;
                return;
            }
        }
        cout << "cycle not present in this linked list" << endl;
        return;
    }
};

int main() {
    LinkedList L;
    L.insertAtTail(10);
    L.insertAtTail(20);
    L.insertAtTail(30);
    L.deleteByData(20);
    L.reverseList();
    L.display();
    return 0;
}
