#include <bits/stdc++.h>
using namespace std;

long long fib(int n, int m){
    if(n <= 1) return n;
    long long int first = 0;
    long long int second = 1;
    long long int output = 0;
    n = n-1;
    while(n--){
        output = (first % m + second % m)%m;
        first = second;
        second = output;
    }
    return output % m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    cout<<fib(n, m);
    return 0;
}