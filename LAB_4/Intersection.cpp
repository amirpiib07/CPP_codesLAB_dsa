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

void insertAtTail(node* &head, int data) {
    node *temp = new node(data);

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

void display(node *head) {
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

node* getNodeAtPosition(node *head, int position) {
    int count = 1;
    node *temp = head;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    return temp;
}

int intersection(node *p, node *q) {

    if (p == NULL || q == NULL) return -1;

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
    if (net < 0) net = -net;

    temp = p;
    temp2 = q;

    if (count1 > count2) {
        for (int i = 0; i < net; i++)
            temp = temp->next;
    } else {
        for (int i = 0; i < net; i++)
            temp2 = temp2->next;
    }

    while (temp != NULL && temp2 != NULL) {
        if (temp == temp2) {
            return temp->data;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }

    return -1;
}

int main() {

    node *head1 = NULL;
    node *head2 = NULL;

    int choice, data, pos;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert in List 1\n";
        cout << "2. Insert in List 2\n";
        cout << "3. Create Intersection (Connect List2 to List1 at position)\n";
        cout << "4. Display List 1\n";
        cout << "5. Display List 2\n";
        cout << "6. Find Intersection\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter data: ";
            cin >> data;
            insertAtTail(head1, data);
            break;

        case 2:
            cout << "Enter data: ";
            cin >> data;
            insertAtTail(head2, data);
            break;

        case 3:
            cout << "Enter position in List1 to connect List2: ";
            cin >> pos;
            {
                node *target = getNodeAtPosition(head1, pos);
                if (target == NULL) {
                    cout << "Invalid position\n";
                } else {
                    node *temp = head2;
                    if (temp == NULL) {
                        cout << "List2 is empty\n";
                        break;
                    }
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = target;
                    cout << "Intersection created\n";
                }
            }
            break;

        case 4:
            display(head1);
            break;

        case 5:
            display(head2);
            break;

        case 6:
            {
                int ans = intersection(head1, head2);
                if (ans == -1)
                    cout << "No Intersection\n";
                else
                    cout << "Intersection at node with value: " << ans << endl;
            }
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}