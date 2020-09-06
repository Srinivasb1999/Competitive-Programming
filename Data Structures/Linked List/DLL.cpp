#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node* prev;
};

// Global Variable - Pointing to the head node
Node* head;

// Creates a new node (used instead of a constructor)
Node* getNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Inserts a node at the head
void insertAtHead(int data) {
    Node* newNode = getNewNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// Prints the linked list in forward direction
void print() {
    Node* temp = head;
    cout << "Forward : ";
    while (temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

// Prints the linked list in reverse direction
void reversePrint() {
    Node* temp = head;
    if (temp == nullptr) return;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    cout << "Reverse : ";
    while (temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << '\n';
}

// Inserts a node at the tail
void insertAtTail(int data) {
    Node* newNode = getNewNode(data);
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Deletes an element at any position
void deleteAtPosition(int position) {
    Node* temp = head;
    if (temp == nullptr) return;
    if (position == 1) {
        head = temp->next;
        (temp->next)->prev = nullptr;
        delete temp;
        return;
    }
    for (int i = 1; i < position; i++) {
        temp = temp->next;
    }
    Node* deleteNode = temp;
    (deleteNode->prev)->next = deleteNode->next;
    (deleteNode->next)->prev = deleteNode->prev;
    delete deleteNode;
}

// Inserts an element at any position
void insertAtPosition(int data, int position) {
    Node* newNode = getNewNode(data);
    Node* temp = head;
    if (position == 1) {
        temp->prev = newNode;
        newNode->next = temp;
        head = newNode;
        return;
    }

    for (int i = 1; i < position; i++) {
        temp = temp->next;
    }
    (temp->prev)->next = newNode;
    newNode->prev = temp->prev;

    temp->prev = newNode;
    newNode->next = temp;
}

int main() {
    head = nullptr;

    insertAtHead(2);          // 2
    insertAtHead(4);          // 4 2
    insertAtHead(6);          // 6 4 2
    insertAtTail(0);          // 6 4 2 0
    deleteAtPosition(3);      // 6 4 0
    insertAtPosition(1, 3);   // 6 4 1 0
    deleteAtPosition(1);      // 4 1 0
    insertAtPosition(10, 1);  // 10 4 1 0
    print();
    reversePrint();  // 0 1 4 10

    return 0;
}