#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x

int max_sum_subarray(int arr[], int n, int k) {
    int current_sum = 0, max_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }
    max_sum = current_sum;
    for (int i = k; i < n; i++) {
        current_sum += (arr[i] - arr[i - k]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    int arr[] = { 1, 8, 30, -5, 20, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum sum of subarray of size 3 is: " << max_sum_subarray(arr, n, 3);
    return 0;
}