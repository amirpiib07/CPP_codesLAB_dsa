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


    void check() {
        vector<int> nums;
        node *temp = head;
        while (temp != NULL) {
            nums.push_back(temp->data);
            temp = temp->next;
        }
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] == nums[j]) {
                i++;
                j--;
            } else {
                cout << "linked list is not palindrome" << endl;
                return;
            }
        }
        cout << "linked list is palindrome" << endl;
    }
};

int main() {
    LinkedList L;
    L.insertAtTail(1);
    L.insertAtTail(2);
    L.insertAtTail(3);
    L.insertAtTail(2);
    L.insertAtTail(1);
    L.check();
    return 0;
}
