#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

int throttling(int arr[], int n) {
    int drop = 0;
    for (int i = 0; i < n; i++) {
    }
}

int main() {
    /*
    The number of transactions in any given second cannot exceed 3.
    The number of transactions in any given 10 second period cannot exceed 20. 
    A ten-second period includes all requests arriving from any time max(1, T-9) to T (inclusive of both) for any valid time T.
    The number of transactions in any given minute cannot exceed 60. 
    Similar to above, 1 minute is from max(1, T-59) to T.
    Any request that exceeds any of the above limits will be dropped by the gateway. 
    Given the times at which different requests arrive sorted ascending, find how many requests will be dropped.
    Note: Even if a request is dropped it is still considered for future calculations. 
          Although, if a request is to be dropped due to multiple violations, it is still counted only once.   
    
    n = 27
    requestTime = [1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 11, 11, 11, 11 ]
    Dropped Requests = 7
    */
    int n = 25;
    cout << hex << n;
    return 0;
}