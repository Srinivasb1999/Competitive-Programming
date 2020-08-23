#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int dp[30][1000];
int findSx(int a[], int i, int x) {
    if (i < 0)
        return x;
    if (dp[i][x])
        return dp[i][x];
    return dp[i][x] = max(findSx(a, i - 1, x ^ a[i]), findSx(a, i - 1, x));
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        memset(dp, 0, sizeof(dp));
        cout << findSx(a, n - 1, 0) << endl;
    }
    return 0;
}