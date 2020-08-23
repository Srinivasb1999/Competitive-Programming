#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

struct Heap {
    int* array;
    int count;
    int capacity;
};

Heap* createHeap(int cap) {
    Heap* h = new Heap();
    h->array = new int[cap];
    h->count = 0;
    h->capacity = cap;
    return h;
}

int Parent(Heap* h, int i) {
    if (h->count == 0) return -1;
    return (i - 1) / 2;
}

int LeftChild(Heap* h, int i) {
    if (h->count == 0 or 2 * i + 1 > h->count - 1)
        return -1;
    else
        return 2 * i + 1;
}

int RightChild(Heap* h, int i) {
    if (h->count == 0 or 2 * i + 2 > h->count - 1)
        return -1;
    else
        return 2 * i + 2;
}

int GetMax(Heap* h) {
    if (h->count == 0) return -1;
    return h->array[0];
}

void PercolateDown(Heap* h, int i) {
    int l, r, max;
    l = LeftChild(h, i);
    r = RightChild(h, i);
    if (l != -1 and h->array[l] > h->array[i])
        max = l;
    else
        max = i;
    if (r != -1 and h->array[r] > h->array[i]) max = r;

    if (max != i)
        swap(h->array[i], h->array[max]);

    PercolateDown(h, max);
}

int DeleteMax(Heap* h) {
    int max;
    if (h->count == 0) return -1;
    max = h->array[0];
    swap(h->array[0], h->array[h->count - 1]);
    h->count--;
    PercolateDown(h, 0);
    return max;
}

void ResizeHeap(Heap* h) {
    int* old_array = h->array;
    h->array = new int[h->capacity * 2];

    for (int i = 0; i < h->capacity; i++) {
        h->array[i] = old_array[i];
    }
    h->capacity *= 2;
    delete old_array;
}

void Insert(Heap* h, int data) {
    if (h->count == h->capacity)
        ResizeHeap(h);
    h->count++;
    int i = h->count - 1;
    while (i >= 0 and data > h->array[(i - 1) / 2]) {
        h->array[i] = h->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->array[i] = data;
}

void DestroyHeap(Heap* h) {
    if (h == NULL) return;
    delete (h->array);
    delete (h);
}

void Heapify(Heap* h, int arr[], int n) {
    if (h == NULL) return;
    while (n > h->capacity) ResizeHeap(h);
    for (int i = 0; i < n; i++) {
        h->array[i] = arr[i];
    }
    h->count = n;

    // if h is the height of the heap, then we only need to heapify until the h - 1 th row
    // n gives the last element in the array, (n - 1)/2 is the parent in the h - 1 th row

    for (int i = (n - 1) / 2; i >= 0; i--) {
        PercolateDown(h, i);
    }
}

void HeapSort(int arr[], int n) {
    Heap* h = createHeap(n);
    Heapify(h, arr, n);
    for (int i = 0; i < n; i++) {
        cout << DeleteMax(h) << endl;
    }
}

int main() {
    int arr[] = { 4, 6, 2, 3, 0, 9, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, n);
    return 0;
}