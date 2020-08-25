#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

struct myhash {
    int bucket;
    list<int>* table;
    myhash(int b) {
        bucket = b;
        table = new list<int>[b];
    }

    void insert(int n) {
        int x = n % bucket;
        table[x].push_back(n);
    }

    void remove(int n) {
        int x = n % bucket;
        list<int>::iterator it = table[x].begin();
        while (it != table[x].end()) {
            if (*it == n) {
                table[x].erase(it);
                return;
            }
            else
                it++;
        }
    }

    void search(int n) {
        int x = n % bucket;
        for (auto i : table[x]) {
            if (i == n) {
                cout << "True" << endl;
                return;
            }
        }
        cout << "False" << endl;
        return;
    }

    void print() {
        for (int i = 0; i < bucket; i++) {
            printf("Key %d : ", i);
            for (auto x : table[i]) cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    myhash a(7);
    a.insert(2);
    a.insert(3);
    a.insert(3);
    a.insert(10);
    a.remove(3);
    a.print();
    a.search(3);
    return 0;
}