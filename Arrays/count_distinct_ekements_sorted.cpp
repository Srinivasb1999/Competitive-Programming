#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int count_distinct(int arr[], int n) {
    unordered_map<int, bool> mp;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (mp.find(arr[i]) != mp.end()) {
            continue;
        }
        else {
            mp[arr[i]] = true;
            count++;
        }
    }
    return count;
}

int main() {
    int n = 7;
    int arr[] = {10, 20, 20, 30, 30, 30, 30};
    cout << count_distinct(arr, n);
    return 0;
}