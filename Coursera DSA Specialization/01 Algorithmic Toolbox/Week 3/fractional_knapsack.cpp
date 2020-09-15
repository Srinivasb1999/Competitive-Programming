#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

struct item {
    int weight, value;

    item() {};

    item(int v, int w) {
        this->weight = w;
        this->value = v;
    }
};

bool comp(item a, item b) {
    double a1 = (double)a.value / a.weight;
    double b1 = (double)b.value / b.weight;
    return a1 > b1;
}

void knapsack(int W, item arr[], int n) {
    sort(arr, arr + n, comp);

    int currWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        item x = arr[i];
        if (currWeight + x.weight <= W) {
            currWeight += x.weight;
            finalValue += x.value;
        }
        else {
            int remain = W - currWeight;
            finalValue += (double)remain * x.value / x.weight;
            break;
        }
    }
    cout << setprecision(4) << fixed;
    cout << finalValue;
}

int main() {
    int t, W;
    cin >> t >> W;
    int v, w;
    item* arr = new item[t];
    for (int i = 0; i < t; i++) {
        cin >> v >> w;
        arr[i] = item(v, w);
    }

    knapsack(W, arr, t);
    return 0;
}