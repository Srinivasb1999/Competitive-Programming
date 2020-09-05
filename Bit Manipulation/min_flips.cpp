#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int minFlips(int a, int b, int c) {
    int count = 0;
    for (int i = 0; i < 31; i++) {
        if (c & (1 << i)) {
            if (!(a & (1 << i) or b & (1 << i))) count++;
        }
        else if ((c & (1 << i)) == 0) {
            if ((a & (1 << i) and b & (1 << i)))
                count += 2;
            else if ((a & (1 << i)) or (b & (1 << i)))
                count++;
        }
    }
    return count;
}

int main() {
    // given a, b and c, find the minimum number of flips to make a | b = c
    int a = 2, b = 6, c = 5;
    cout << "Minimum Number of Flips required = " << minFlips(a, b, c) << endl;
    return 0;
}