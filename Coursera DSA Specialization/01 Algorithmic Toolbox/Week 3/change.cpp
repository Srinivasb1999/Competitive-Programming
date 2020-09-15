#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int change(int x) {
    int output = 0;
    int arr[] = { 10, 5, 1 };
    for (int i = 0; i < 3; i++) {
        if (x >= arr[i]) {
            output += x / arr[i];
            x = x % arr[i];
        }
    }
    return output;
}

int main() {
    int n;
    cin >> n;
    cout << change(n);
    return 0;
}