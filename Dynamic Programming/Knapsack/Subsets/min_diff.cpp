#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

// use the same code as to find a subset given a sum

int min_diff(int arr[], int m, int sum) {
    // since will choose final values only under sum/2
    int n = sum / 2;
    bool dp[m + 1][n + 1];
    vector<int> nums;
    for (int i = 0; i < m + 1; i++) dp[i][0] = true;
    for (int j = 1; j < n + 1; j++) dp[0][j] = false;
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
            // here, we minimize (sum - 2*s1)
            // so for this we choose values for s1 from the last row such that
            if (i == m and dp[i][j]) nums.push_back(j);
        }
    }

    // here we minimize the value of (sum - 2*s2)

    int mn = INT_MAX;
    for (int k = 0; k < nums.size(); k++) {
        mn = min(mn, sum - 2 * nums[k]);
    }

    return mn;
}

int main() {
    // Given an array, the task is to divide it into two sets S1 and S2
    // such that the absolute difference between their sums is minimum.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        int output = min_diff(arr, n, sum);
        cout << output << endl;
    }
    return 0;
}