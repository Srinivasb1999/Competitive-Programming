#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int nthStair(int n, int m, unordered_map<int, int> &mp) {
    if (n == 0) return 1;
    if (mp.find(n) != mp.end()) return mp[n];
    int ways = 0;
    for (int i = 1; i <= m; i++) {
        if (i <= n)
            ways = ways + nthStair(n - 1, m, mp);
    }
    mp[n] = ways;
    return ways;
}

int staircase(int n, int m) {
    unordered_map<int, int> mp;
    int output = nthStair(n, m, mp);

    for (const auto &p : mp) {
        std::cout << "m[" << p.first << "] = " << p.second << '\n';
    }

    return output;
}

int main() {
    cout << endl;
    cout << staircase(4, 2);
    return 0;
}