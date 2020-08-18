#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll static dp[1001][1001], br[1001][1001];

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

ll solve(int arr[], int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    ll min = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        ll tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (tempAns < min) min = tempAns, br[i][j] = k;
    }
    return dp[i][j] = min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    fill(dp[0], dp[0] + 1001 * 1001, -1);
    ll min_cost = solve(arr, 1, n - 1);
    cout << min_cost << endl;
    print(1, n - 1);
    return 0;
}