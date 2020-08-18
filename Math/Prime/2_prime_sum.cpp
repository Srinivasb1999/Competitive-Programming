#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

pair<int, int> find_prime(int n, bool sieve[]) {
    for (int k = 2; k < n; k++) {
        if (sieve[k] and sieve[n - k]) return { k, n - k };
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool sieve[10000];

    fill(sieve, sieve + 10000, true);

    for (int i = 2; i <= 100; i++) {
        if (sieve[i] == true) {
            for (int j = 2 * i; j <= 10000; j += i) {
                sieve[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, int> output = find_prime(n, sieve);
        cout << output.first << " " << output.second << endl;
    }
    return 0;
}