#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long s = 0;

    vector<int> arr(n + 5, 0);
    for (int i = 0; i < n; i++) cin >> arr[i], s += arr[i];

    if (s & 1) {
        cout << "NO";
        return 0;
    }

    unordered_map<long long, int> first, second;

    first[arr[0]] = 1;
    for (int i = 1; i < n; i++) second[arr[i]]++;

    long long sdash = 0;
    for (int i = 0; i < n; i++) {
        sdash += arr[i];
        if (sdash == s / 2) {
            cout << "YES";
            return 0;
        }
        else if (sdash < s / 2) {
            long long x = s / 2 - sdash;
            if (second[x] > 0) {
                cout << "YES";
                return 0;
            }
        }
        else {
            long long y = sdash - s / 2;
            if (first[y] > 0) {
                cout << "YES";
                return 0;
            }
        }
        // moving i + 1 element from the second to the first
        first[arr[i + 1]]++;
        second[arr[i + 1]]--;
    }
    cout << "NO";

    return 0;
}