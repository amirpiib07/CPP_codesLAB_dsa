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

    void insertAtTail(int data) {
        node *temp = new node(data);
        size++;

        if (head == NULL) {
            head = temp;
            return;
        }

        node *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = temp;
    }

    void display() {
        if (head == NULL) {
            cout << "Empty List\n";
            return;
        }

        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
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

    if (i != NULL) k->next = i;
    if (j != NULL) k->next = j;

    node* result = dummy->next;
    delete dummy;          // Memory leak fixed
    return result;
}

// Optimal Divide & Conquer
node* mergeK(vector<node*>& lists, int left, int right) {

    if (left > right) return NULL;
    if (left == right) return lists[left];

    int mid = (left + right) / 2;

    node* l1 = mergeK(lists, left, mid);
    node* l2 = mergeK(lists, mid + 1, right);

    return mergeLinkedList(l1, l2);
}

node* merge(vector<LinkedList>& v) {

    vector<node*> node1;

    for (LinkedList& L : v) {
        if (L.headGroup() != NULL) {
            node1.push_back(L.headGroup());
        }
    }

    if (node1.size() == 0) return NULL;

    return mergeK(node1, 0, node1.size() - 1);
}

void printList(node *ptr) {

    if (ptr == NULL) {
        cout << "Empty List\n";
        return;
    }

    node *curr = ptr;
    while (curr != NULL) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int main() {

    vector<LinkedList> v;
    int choice, listIndex, data, k;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Create New List\n";
        cout << "2. Insert Into List\n";
        cout << "3. Display A List\n";
        cout << "4. Merge All Lists (Optimal)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            v.push_back(LinkedList());
            cout << "New List Created. Index: " << v.size() - 1 << endl;
            break;

        case 2:
            cout << "Enter List Index: ";
            cin >> listIndex;
            if (listIndex < 0 || listIndex >= v.size()) {
                cout << "Invalid Index\n";
                break;
            }
            cout << "Enter data (sorted order): ";
            cin >> data;
            v[listIndex].insertAtTail(data);
            break;

        case 3:
            cout << "Enter List Index: ";
            cin >> listIndex;
            if (listIndex < 0 || listIndex >= v.size()) {
                cout << "Invalid Index\n";
                break;
            }
            v[listIndex].display();
            break;

        case 4:
            printList(merge(v));
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}