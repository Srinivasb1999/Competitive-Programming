#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int input) {
        this->data = input;
        this->next = nullptr;
    };
};

// Global variable - pointer to head node
Node* head;

/* All operations performed on a linked list
    1. Insert node at head
    2. Insert node at any position
    3. Delete node from any position
    4. Print Linked List
    5. Reverse Print Linked List
    6. Reverse Linked list Iteratively
    7. Reverse Linked List Recursively
*/

// Inserts a node at the head of the Linked List
void insertAtHead(int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// This function adds an element at any position, and at the head by default
void insert(int data, int pos = 1) {
    Node* temp1 = new Node(data);
    temp1->next = nullptr;
    if (pos == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for (int i = 1; i < pos - 1; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return;
}

// Delete a node at any position
void deleteNode(int pos) {
    Node* temp = head;
    if (pos == 1) {
        head = temp->next;
        delete temp;
        return;
    }
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    // temp -> next = (temp -> next)-> next;
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

// Prints the entire linked list from head to tail
void printLinkedList() {
    Node* a = head;
    while (a != NULL) {
        cout << a->data << ' ';
        a = a->next;
    }
}

// Printing in reverse order using Recursion
void reversePrint(Node* head) {
    Node* temp = head;
    if (temp == nullptr) return;
    reversePrint(temp->next);
    cout << temp->data << ' ';
}

// Iterative Reversal
void reverseIterative() {
    Node *prev, *current, *next;
    current = head;
    prev = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Recursive Reversal
Node* reverseRecursive(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* rest = reverseRecursive(head->next);
    Node* temp = head->next;
    temp->next = head;
    // same as head->next->next = head;

    head->next = NULL;
    return rest;
}

// Finds a loop in the linked list and returns the head
Node* findLoop(Node* head) {
    unordered_set<Node*> s;
    while (head != nullptr) {
        if (s.find(head) != s.end()) return head;
        s.insert(head);

        head = head->next;
    }
    return head;
}

// Another method to find a loop (Floyd's cycle finder algorithm)
Node* findLoop2(Node* head) {
    // Write your code here.
    Node *slow, *fast;
    slow = head->next;
    fast = head->next->next;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    head = NULL;
    // Node* one = new Node(10);   // first node
    // Node* two = new Node(20);   // second node
    // Node* three = new Node(30); // third node
    // head = one;
    // one->next = two;
    // two->next = three;
    // three->next = nullptr;
    insertAtHead(0);  // inserts at beginning
    insert(-1, 1);    // inserts at beginning too
    insert(1, 2);
    insert(2, 3);
    // cout<<"Before deleting node -1: ";
    // printLinkedList();          // prints linked list
    // deleteNode(1);              // deleting node at the beginning
    // cout<<"\nAfter deleting node -1: ";
    // cout<<"The Linked List is: ";
    printLinkedList();
    head = reverseRecursive(head);  // Also try reverseIterative(head)
    cout << "\nReverse of the Linked List is: ";
    printLinkedList();
    // reversePrint(head);         // Recursive Reverse Print
    return 0;
}
