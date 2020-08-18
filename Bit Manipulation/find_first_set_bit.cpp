#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int check_bit(int n) {
    int m;
    for (int i = 0; i < 32; i++) {
        m = n >> i;
        if (m & 1) return i + 1;
    }
    return 0;
}

int main() {
    // Find the first set bit from the right
    // Binary representation of the 18 is 010010, the first set bit from the right side is at position 2

    int n = 18;
    cout << check_bit(n) << endl;
    return 0;
}