#include <bits/stdc++.h>
using namespace std;

pair<int, int> getPalindrome(string s, int left, int right) {
    while (left >= 0 and right < s.size()) {
        if (s[left] != s[right]) break;
        left--;
        right++;
    }
    return {left + 1, right};
}

string longestPalindrome(string s) {
    pair<int, int> max = {0, 1};

    for (int i = 1; i < s.size(); i++) {
        pair<int, int> odd = getPalindrome(s, i - 1, i + 1);
        pair<int, int> even = getPalindrome(s, i - 1, i);
        pair<int, int> curr = odd.second - odd.first > even.second - even.first ? odd : even;
        max = curr.second - curr.first > max.second - max.first ? curr : max;
    }
    return s.substr(max.first, max.second - max.first);
}

int main() {
    string output = longestPalindrome("abcabbacdba");
    cout << output;
    return 0;
}