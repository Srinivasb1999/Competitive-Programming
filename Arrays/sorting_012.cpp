#include <iostream>
#include <vector>
using namespace std;

#define deb(x) cout << #x << x;

void sort012(int arr[], int n) {
    int m = 0;
    int h = n - 1;
    int l = 0;
    while (m <= h) {
        if (arr[m] == 0) {
            swap(arr[l], arr[m]);
            l++;
            m++;
        }
        else if (arr[m] == 1) {
            m++;
        }
        else if (arr[m] == 2) {
            swap(arr[m], arr[h]);
            h--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int z = n;
    int zero = 0, one = 0, two = 0;

    int data;
    while (n--) {
        cin >> data;
        if (data == 0) zero++;
        if (data == 1) one++;
        if (data == 2) two++;
    }

    vector<int> output;
    for (int i = 0; i < zero; i++) output.push_back(0);
    for (int i = 0; i < one; i++) output.push_back(1);
    for (int i = 0; i < two; i++) output.push_back(2);

    for (int i = 0; i < z; i++) cout << output.at(i) << " ";
    cout << endl;
}