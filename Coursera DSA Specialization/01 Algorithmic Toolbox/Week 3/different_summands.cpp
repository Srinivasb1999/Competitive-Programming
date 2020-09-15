#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

void Solve(int n) {
    vector<int> Values;
    int K = 0;
    for (int i = 1; n; i++) {
        if (n - i > i) {
            Values.push_back(i);
            K++;
            n -= i;
        }
        else {
            Values.push_back(n);
            K++;
            break;
        }
    }
    cout << K << endl;
    for (int i = 0; i < Values.size(); i++) {
        cout << Values[i] << " ";
    }
}
int main() {
    int n;
    cin >> n;
    Solve(n);
}