#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
Node* top = nullptr;

void push(int data){
    Node* temp = new Node();
    temp -> data = data;
    temp -> next = top;
    top = temp;
}

void pop(){
    Node* temp = top;
    if(top == nullptr){
        cout<<"Stack is empty\n";
        return;
    }
    cout<<"Popped : " << temp -> data<<'\n';
    top = temp -> next;
    delete temp;
}

void print(){
    Node* temp = top;
    cout<<"Stack : ";
    while(temp != nullptr){
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout<<'\n';
}

int main(){
    top = nullptr;
    push(1);
    push(2);
    push(3);
    push(4);
    print();
    pop();
    print();

    return 0;
}