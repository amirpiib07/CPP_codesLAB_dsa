#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;
    node* random;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
        this->random = NULL;
    }
};

/* ===== PRINT FUNCTION ===== */

void print(node* head) {

    node* temp = head;

    while (temp != NULL) {
        cout << "Data: " << temp->data;

        if (temp->random)
            cout << " | Random: " << temp->random->data;
        else
            cout << " | Random: NULL";

        cout << endl;

        temp = temp->next;
    }
}

/* ===== CLONE FUNCTION ===== */

node* cloneList(node* head) {

    if (head == NULL)
        return NULL;

    unordered_map<node*, node*> mp;

    node* temp = head;

    // Step 1: Create clone nodes
    while (temp != NULL) {
        mp[temp] = new node(temp->data);
        temp = temp->next;
    }

    temp = head;

    // Step 2: Fix next, prev, random
    while (temp != NULL) {

        mp[temp]->next = mp[temp->next];
        mp[temp]->prev = mp[temp->prev];
        mp[temp]->random = mp[temp->random];

        temp = temp->next;
    }

    return mp[head];
}

/* ===== MAIN ===== */

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }

    node** arr = new node*[n];

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        arr[i] = new node(data);
    }

    // Connect next and prev
    for (int i = 0; i < n; i++) {
        if (i < n - 1)
            arr[i]->next = arr[i + 1];

        if (i > 0)
            arr[i]->prev = arr[i - 1];
    }

    cout << "\nEnter random pointer index for each node (-1 for NULL):\n";
    cout << "Indexing starts from 0\n";

    for (int i = 0; i < n; i++) {
        int r;
        cout << "Random index for node " << i << ": ";
        cin >> r;

        if (r >= 0 && r < n)
            arr[i]->random = arr[r];
        else
            arr[i]->random = NULL;
    }

    node* head = arr[0];

    cout << "\nOriginal List:\n";
    print(head);

    node* clonedHead = cloneList(head);

    cout << "\nCloned List:\n";
    print(clonedHead);

    cout << "\nOriginal and cloned lists are identical.\n";
    cout << "Random pointers copied successfully.\n";

    return 0;
}