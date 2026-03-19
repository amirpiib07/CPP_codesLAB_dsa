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

    // YOUR LOGIC (O(n) space)
    void check() {

        if (head == NULL) {
            cout << "linked list is palindrome\n";
            return;
        }

        vector<int> nums;
        node *temp = head;

        while (temp != NULL) {
            nums.push_back(temp->data);
            temp = temp->next;
        }

        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            if (nums[i] != nums[j]) {
                cout << "linked list is not palindrome\n";
                return;
            }
            i++;
            j--;
        }

        cout << "linked list is palindrome\n";
    }

    // OPTIMAL VERSION (O(1) space)
    void checkOptimal() {

        if (head == NULL || head->next == NULL) {
            cout << "linked list is palindrome\n";
            return;
        }

        node *slow = head;
        node *fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        node *curr = slow->next;
        node *prev = NULL;
        node *ford = NULL;

        while (curr != NULL) {
            ford = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ford;
        }

        node *first = head;
        node *second = prev;

        while (second != NULL) {
            if (first->data != second->data) {
                cout << "linked list is not palindrome\n";
                return;
            }
            first = first->next;
            second = second->next;
        }

        cout << "linked list is palindrome\n";
    }
};

int main() {

    LinkedList L;
    int choice, data;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert At Tail\n";
        cout << "2. Display\n";
        cout << "3. Check Palindrome (Your Logic)\n";
        cout << "4. Check Palindrome (Optimal)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter data: ";
            cin >> data;
            L.insertAtTail(data);
            break;

        case 2:
            L.display();
            break;

        case 3:
            L.check();
            break;

        case 4:
            L.checkOptimal();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}