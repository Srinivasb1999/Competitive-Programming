#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int count_set_bits1(int n) {
    int count = 0;
    while (n) {
        if (n & 1) count++;
        n = n >> 1;
    }
    return count;
}

int count_set_bits2(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int count_set_bits3(int n) {
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp[n];
}

int main() {
    int n = 15;
    cout << count_set_bits1(n) << endl;
    cout << count_set_bits2(n) << endl;
    cout << count_set_bits3(n) << endl;
    return 0;
}