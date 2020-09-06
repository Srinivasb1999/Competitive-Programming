#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node* slow) {
    Node *next, *current = slow, *prev = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    Node *slow = head, *fast = head;
    while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = head;
    slow = reverse(slow);

    while (slow != nullptr) {
        if (fast->data != slow->data) {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main() {

    return 0;
}