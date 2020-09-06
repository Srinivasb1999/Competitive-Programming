#include <bits/stdc++.h>
using namespace std;

#define max 100

class Stack{
    private:
        int top;
    public:
        int arr[max];
        Stack()
        {
            top = -1;
        }

        void push(int data){
            if(top < max - 1) arr[++top] = data;
            else cout<<"Stack Overflow\n";
        }

        int pop(){
            if(top >= 0){
                int data = arr[top--];
                return data;
            }
            else {
                cout<<"Stack Underflow\n";
                return 0;
            }
        }

        int topElement(){
            return arr[top];
        }

        bool isEmpty(){
            return (top < 0);
        }

        void print(){
            cout<<"The Stack is : ";
            for(int i = 0; i <= top; i++){
                cout<<arr[i]<<' ';
            }
            cout<<'\n';
        }
};


int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.print();
    s.push(30);
    s.print();
    int a = s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print();
    cout<<"The popped element is : "<<a;
    return 0;
}