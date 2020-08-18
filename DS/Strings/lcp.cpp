#include <bits/stdc++.h>

using namespace std;

int lcp(string s1, string s2) {
    long unsigned i = 0;
    int count = 0;
    while (i < s1.size() and i < s2.size()) {
        if (s1[i] == s2[i]) {
            count++;
            i++;
        } else
            return count;
    }
    return count;
}

int main() {
    int ans = lcp("hello", "hely");
    cout << ans;
}