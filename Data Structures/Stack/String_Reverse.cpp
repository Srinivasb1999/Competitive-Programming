#include <bits/stdc++.h>
using namespace std;

string Reverse(string s, int size){
    stack<int> output;
    string newString;
    for(int i = 0; i < size; i++){
        output.push(s[i]);
    }
    for(int i = 0; i < size; i++){
        newString.push_back(output.top());
        output.pop();
    }
    return newString;
}

int main () 
{ 
    string s = "Hello!";
    string output = Reverse(s, s.size());
    cout<<"String : "<<s;
    cout<<"\nReverse : "<<output;

	return 0; 
} 
