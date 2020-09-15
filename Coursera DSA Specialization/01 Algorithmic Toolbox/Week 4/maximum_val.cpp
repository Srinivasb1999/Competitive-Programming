#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int main() {
    ll n;
    cin >> n;
    unordered_map<ll, ll> hash;
    ll data;
    for (ll i = 0; i < n; i++) {
        cin >> data;
        if (hash.find(data) != hash.end())
            hash[data]++;
        else
            hash[data] = 1;
    }
    unordered_map<ll, ll>::iterator it;
    bool flag = false;
    for (it = hash.begin(); it != hash.end(); it++) {
        if (it->second > n / 2) flag = true;
    }
    flag ? cout << 1 : cout << 0;
    return 0;
}