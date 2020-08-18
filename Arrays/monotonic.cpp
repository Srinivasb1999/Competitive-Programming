#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool monotonic(int arr[], int n) {
    bool is_non_increasing = true;
    bool is_non_decreasing = true;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            is_non_decreasing = false;
        else if (arr[i] > arr[i - 1])
            is_non_increasing = false;
    }
    return is_non_increasing or is_non_decreasing;
}

int main() {
    int arr[] = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
    monotonic(arr, 7) ? cout << "True" : cout << "False";
    return 0;
}