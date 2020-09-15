#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

unordered_map<ll, ll> hash_table;

ll binarySearch(ll arr[], ll n, ll data) {
    if (hash_table.find(data) != hash_table.end()) return hash_table[data];
    ll left = 0;
    ll right = n - 1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (arr[mid] == data) {
            hash_table[data] = mid;
            return mid;
        }
        else if (arr[mid] < data)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    ll n, k;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cin >> k;
    ll queries[k];
    ll data;
    for (ll i = 0; i < k; i++) cin >> data, cout << binarySearch(arr, n, data) << " ";
    return 0;
}