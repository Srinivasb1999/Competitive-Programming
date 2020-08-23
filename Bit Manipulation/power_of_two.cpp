#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

/*
    Since any power of 2 has only one set bit, subtracting one from it results in all previous bits to be set as 1
    8 = 00001000
    7 = 00000111
    Therefore AND operation between such 2 numbers will always end up at 0
*/

bool power_of_two(int n) {
    if (n <= 0)
        return false;
    else
        return (!(n & (n - 1)));
}

int main() {
    ll n = 1099511627776;
    power_of_two(n) ? cout << "True" : cout << "False";
    return 0;
}