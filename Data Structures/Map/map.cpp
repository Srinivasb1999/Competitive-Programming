#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> A;
    A[1] = 100;
    A[2] = 200;

    map<char, int> cnt;
    string x = "srinivas prabhu";

    for (char c : x) cnt[c]++;

    // replace mp with the name of the map
    for (const auto &p : mp) {
        std::cout << "m[" << p.first << "] = " << p.second << '\n';
    }

    return 0;
}