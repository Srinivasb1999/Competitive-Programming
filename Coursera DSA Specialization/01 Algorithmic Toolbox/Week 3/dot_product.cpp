#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

long long max_dot_product(vector<int> a, vector<int> b) {
    // write your code here
    long long result = 0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    for (size_t i = 0; i < a.size(); i++) {
        result += ((long long)a[i]) * b[i];
    }

    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b) << endl;
}