#include <bits/stdc++.h>
using namespace std;
int dp[105][105], br[105][105];

void print(int i, int j) {
    if (i == j) {
        cout << char(i + 'A' - 1);
        return;
    }
    cout << "(";
    print(i, br[i][j]);
    print(br[i][j] + 1, j);
    cout << ")";
}

int solve(int arr[], int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int tempAns, min = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[j] * arr[k];
        if (min > tempAns) min = tempAns, br[i][j] = k;
    }
    return min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        fill(dp[0], dp[0] + 105 * 105, -1);

        solve(arr, 1, n - 1);
        print(1, n - 1);
        cout << endl;
    }
    return 0;
}