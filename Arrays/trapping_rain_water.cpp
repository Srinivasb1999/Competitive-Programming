#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void area_water(vector<ll> arr) {
    ll n = arr.size();
    vector<ll> leftmax(n);
    vector<ll> rightmax(n);

    leftmax[0] = arr[0];
    for (ll i = 1; i < n; i++) leftmax[i] = max(leftmax[i - 1], arr[i]);

    rightmax[n - 1] = arr[n - 1];
    for (ll i = n - 2; i >= 0; i--) rightmax[i] = max(rightmax[i + 1], arr[i]);

    ll area = 0;
    for (ll i = 1; i < n - 1; i++) area += min(rightmax[i], leftmax[i]) - arr[i];

    cout << area << endl;
}

int main() {
    vector<ll> arr = { 0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3 };

    area_water(arr);
    return 0;
}