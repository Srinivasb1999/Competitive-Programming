#include <bits/stdc++.h>
using namespace std;
#define ll long long

int pisanoPeriod(int m){
    int first = 0, second = 1, temp, output;
    for(int i = 0; i < m*m; i++){
        temp = first;
        first = second;
        second = (temp + second)%m;
        if(first == 0 and second == 1)
            return i + 1;
    }
}

long long fib(int n, int m){
    if(n <= 1) return n;
    ll first = 0;
    ll second = 1;
    ll output = 0;
    n = n-1;
    while(n--){
        output = (first%m + second%m)%m;
        first = second;
        second = output;
    }
    return output % m;
}


int main(){
    ll n, m;   
    cin >> n >> m;
    ll mod = pisanoPeriod(m);
    cout<<fib(n%mod, m);
    return 0;
}