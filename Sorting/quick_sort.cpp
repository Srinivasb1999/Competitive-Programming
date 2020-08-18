#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

int main() {
    vector<int> array = { 4, 2, 6, 5, 1, 2, 3 };
    quickSort(array, 0, array.size() - 1);
    for (auto i : array) cout << i << " ";
    return 0;
}