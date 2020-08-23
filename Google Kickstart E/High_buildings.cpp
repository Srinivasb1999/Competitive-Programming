#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int* building(int n, int a, int b, int c) {
    static int arr[n];
}

int main() {
    int t;
    cin >> t;
    int tc = 0;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        tc++;

        cout << "Case #" << tc << ": " << subarray(arr, n) << endl;
    }
    return 0;
}