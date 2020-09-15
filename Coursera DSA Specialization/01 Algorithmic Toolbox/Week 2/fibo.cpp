#include <bits/stdc++.h>
using namespace std;

long long fib(int n){
    if(n <= 1) return n;
    long long int first = 0;
    long long int second = 1;
    long long int output = 0;
    for(int i = 2; i < n; i++){
        output = first + second;
        first = second;
        second = output;
    }
    return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout<<fib(n);
    return 0;
}