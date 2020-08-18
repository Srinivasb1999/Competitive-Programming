#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

// storing only last 2 numbers
long long fib_2(int n){
    long long int first = 0;
    long long int second = 1;
    long long int output = 0;
    n = n-1;
    while(n--){
        output = first + second;
        first = second;
        second = output;
    }
    return output;
}

// calculating the last digit on nth fibonacci number
long long fib_3(int n){
    long long int first = 0;
    long long int second = 1;
    long long int output = 0;
    n = n-1;
    while(n--){
        output = (first + second)%10;
        first = second;
        second = output;
    }
    return output;
}


int main(){
    cout<<'\n'<<fib_3(327305);
    // cout<<'\n'<<((1LL<<63) - 1);
    return 0;
}