#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    // find the maximum sum of a contigious subarray
    // Kadane's Algorithm
    int maxEndingHere = 0, maxSoFar = 0;
    vector<int> array = { 2, 3, -8, 7, -1, 2, 3 };
    for (int i = 0; i < array.size(); i++) {
        maxEndingHere = max(maxEndingHere + array[i], array[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    cout << maxSoFar << endl;
    return 0;
}