#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> sorted(left.size() + right.size(), 0);
    int i = 0, j = 0, k = 0;
    while (i < left.size() and j < right.size()) {
        if (left[i] <= right[j])
            sorted[k++] = left[i++];
        else
            sorted[k++] = right[j++];
    }
    while (i < left.size()) sorted[k++] = left[i++];
    while (j < right.size()) sorted[k++] = right[j++];

    return sorted;
}

vector<int> mergeSort(vector<int> array) {
    if (array.size() <= 1) return array;
    int mid = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + mid);
    vector<int> right(array.begin() + mid, array.end());
    return merge(mergeSort(left), mergeSort(right));
}

int main() {
    vector<int> input = { 2, 8, 4, 2, 6, 7, 9, 1 };
    vector<int> output = mergeSort(input);
    for (auto i : output) cout << i << " ";
    return 0;
}