#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int max_diff(int arr[], int n) {
    int minVal = arr[0], res = arr[1] - arr[0];
    for (int j = 2; j < n; j++) {
        res = max(res, arr[j] - minVal);
        minVal = min(minVal, arr[j]);
    }
    return res;
}

int main() {
    // find the maximum value of arr[j] - arr[i] where j > i
    int n = 7;
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    cout << max_diff(arr, n);
    return 0;
}