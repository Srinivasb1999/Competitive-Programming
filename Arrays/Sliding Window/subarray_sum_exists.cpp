#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x

bool subarray_sum_exists(vector<int> arr, int target) {
    int start = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        while (sum > target) {
            sum -= arr[start];
            start++;
        }
        if (sum == target) return true;
    }
    return false;
}

pair<int, int> subarray_sum_exists2(vector<int> arr, int target) {
    int start = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        while (sum > target) {
            sum -= arr[start];
            start++;
        }
        if (sum == target) return { start, i };
    }
    return { -1, -1 };
}

int main() {
    // check whether the sum of contigious subarray elements is equal to the target sum;
    vector<int> input = { 1, 4, 20, 3, 10, 5 };
    int target = 37;
    subarray_sum_exists(input, target) ? cout << "True\n" : cout << "False\n";
    pair<int, int> output = subarray_sum_exists2(input, target);
    cout << "The sum is found from Index " << output.first << " to " << output.second;
    return 0;
}