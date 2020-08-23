#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int subarray(int arr[], int n) {
    int maxCount = 0, count = 1, diff = arr[1] - arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] == diff)
            count++;
        else {
            diff = arr[i] - arr[i - 1];
            count = 2;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int main() {
    int t;
    cin >> t;
    int tc = 0;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        tc++;

        cout << "Case #" << tc << ": " << subarray(arr, n) << endl;
    }
    return 0;
}