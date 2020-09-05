#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int xor_sum(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < 31; i++) {
        int zero = 0, one = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] & (1 << i))
                one++;
            else
                zero++;
        }
        int pairs = zero * one;
        res += pairs * (1 << i);
    }
    return res;
}

int main() {
    // XOR sum of all pairs of numbers:
    // [5, 9, 7, 6]
    // Pairs = [5, 9], [5, 7], [5, 6], [9, 7], [9, 6], [7, 6]
    // Sum of XOR of all pairs is 47

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Sum of XOR of all pairs in the above array is : " << xor_sum(arr, n) << endl;
    return 0;
}