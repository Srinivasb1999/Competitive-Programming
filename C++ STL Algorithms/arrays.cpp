#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int main() {
    vector<int> arr = { 1, 2, 2, 3, 4, 5 };

    find(arr.begin(), arr.end(), 3) != arr.end() ? cout << "3 found\n" : cout << "3 not in the array\n";

    cout << "2 occurs " << count(arr.begin(), arr.end(), 2) << " times\n";

    vector<int> copied_arr(arr.size());
    copy(arr.begin(), arr.end(), copied_arr.begin());
    // for (auto i : copied_arr) cout << i << endl;

    binary_search(arr.begin(), arr.end(), 5) ? cout << "5 exists in the array\n" : cout << "5 doesn't exist\n";

    vector<int> merged_arr(2 * arr.size());
    merge(arr.begin(), arr.end(), copied_arr.begin(), copied_arr.end(), merged_arr.begin());
    // for (auto i : merged_arr) cout << i << endl;

    // auto it = unique(arr.begin(), arr.end());
    // arr.resize(distance(arr.begin(), it));
    // for (auto i : arr) cout << i << " ";

    // vector<int> unique_arr(arr.size());
    // auto it1 = unique_copy(arr.begin(), arr.end(), unique_arr.begin());
    // unique_arr.resize(distance(unique_arr.begin(), it1));
    // for (auto i : unique_arr) cout << i << " ";

    return 0;
}