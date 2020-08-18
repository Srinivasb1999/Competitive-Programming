#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    ll lcm = 0, gcd1 = 0;
    ll first, second;
    cin >> first >> second;
    gcd1 = gcd(first, second);
    lcm = (first * second)/gcd1;
    cout<<lcm;
    return 0;
}