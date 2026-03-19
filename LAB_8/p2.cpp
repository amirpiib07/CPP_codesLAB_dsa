#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        next = nullptr;
    }
};
class Stack {
    node* front=nullptr;
    node* rear=nullptr;
    public:
    void enqueue(int data) {
        node* newNode = new node(data);
        if(front == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
        return;
    }
    int dequeue() {
        if(front == nullptr) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        node* temp = front;
        int val=temp->data;
        front = front->next;
        delete temp;
        return val;
    }
    int peek() {
        if(front == nullptr) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
};
int main() {
    Stack s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    cout<<s.peek()<<endl;
    s.dequeue();
    cout<<s.peek()<<endl;
}