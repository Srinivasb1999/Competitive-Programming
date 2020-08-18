#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void SlidingWindow(vector<int>& input, int n, int k, vector<int>& output) {
    deque<int> dq;
    int i;
    for (i = 0; i < k; i++) {
        while (!dq.empty() and input[i] >= input[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    for (; i < n; i++) {
        output.push_back(input[dq.front()]);
        while (!dq.empty() and dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() and input[i] >= input[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    output.push_back(input[dq.front()]);
}

int main() {
    // find the maximum value of every subarray of length k in a given array
    int n, k;
    cin >> n >> k;
    vector<int> input(n);
    vector<int> output;

    for (int i = 0; i < n; i++) cin >> input[i];

    SlidingWindow(input, n, k, output);

    for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
    cout << endl;
    return 0;
}

// I/O:
/*
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90
*/