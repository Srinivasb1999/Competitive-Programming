#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<int> arr(t);
    for(int i = 0; i < t; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());
    cout<<(long long) arr[t-1]*arr[t-2];
    return 0;
}