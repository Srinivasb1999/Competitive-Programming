#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fib(int n){
    ll first = 0;
    ll second = 1;
    ll output = 0;
    n = n-1;
    while(n--){
        output = (first + second)%10;
        first = second;
        second = output;
    }
    return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>> n;
    cout<<fib(n);
    return 0;
}