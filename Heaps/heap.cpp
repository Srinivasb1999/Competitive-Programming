#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x

struct minHeap {
    vector<int>* harr;
    int hsize;
    int capacity;

    minHeap(int cap) {
        this->capacity = cap;
        this->hsize = 0;
        this->harr = new vector<int>(cap);
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
};

int main() {

    return 0;
}