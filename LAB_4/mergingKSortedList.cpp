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
public:
    node *head = NULL;
    int size = 0;
    LinkedList() {
        head = NULL;
        size = 0;
    }

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

    node *headGroup() {
        return head;
    }
};
node* mergeLinkedList(node* head1, node* head2) {
    node *dummy = new node(-1);
    node *k = dummy;
    node *i = head1;
    node *j = head2;
    while (i != NULL && j != NULL) {
        if (i->data <= j->data) {
            k->next = i;
            i = i->next;

        } else {
            k->next = j;
            j = j->next;

        }
        k = k->next;
    }
    if(i != NULL) {
        k->next = i;
    }
    if (j != NULL) {
        k->next = j;
    }
    return dummy->next;
}

node *merge(vector<LinkedList>v) {
    vector<node*>node1;
    for (LinkedList L : v) {
        if (L.headGroup()!=NULL) {
            node1.push_back(L.headGroup());
        }
    }
    if (node1.size()==0) {
        return NULL;
    }
    while (node1.size()>1) {
        node* a=node1[0];
        node* b=node1[1];
        node* c=mergeLinkedList(a,b);
        node1.push_back(c);
        node1.erase(node1.begin(),node1.begin()+2);
    }
    return node1.front();
}

void printList(node *ptr) {
    node *curr = ptr;
    while (curr != NULL) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL";
}

int main() {
    LinkedList L;
    L.insertAtTail(10);
    L.insertAtTail(20);
    L.insertAtTail(30);
    L.insertAtTail(40);
    L.insertAtTail(50);
    L.display();
    LinkedList M;
    M.insertAtTail(60);
    M.insertAtTail(70);
    M.insertAtTail(80);
    M.insertAtTail(90);
    M.insertAtTail(100);
    M.display();
    LinkedList L2;
    L2.insertAtTail(0);
    L2.insertAtTail(20);

    L2.insertAtTail(45);
    L2.insertAtTail(52);
    L2.insertAtTail(75);
    L2.insertAtTail(95);

    L2.insertAtTail(101);
    L2.display();
    vector<LinkedList>v;
    v.push_back(L);
    v.push_back(L2);
    v.push_back(M);
    printList(merge(v));

    return 0;
}
