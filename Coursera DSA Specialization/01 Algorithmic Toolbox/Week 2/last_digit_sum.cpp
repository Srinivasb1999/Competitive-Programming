#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll fib(int n){
    if(n <= 1) return n;
    ll first = 0, second = 1;
    ll output = 0;
    ll sum = 1;
    n = n-1;
    while(n--){
        output = (first + second)%10;
        sum = (sum + output)%10;
        first = second;
        second = output;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>> n;
    n = n % 60;
    cout<<fib(n);
    return 0;
}