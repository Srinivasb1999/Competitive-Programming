#include <bits/stdc++.h>
using namespace std;
#define ll long long

int minimum_refills(vector<int> stations, int n, int L){
    int refills = 0, current_refill = 0;
    while(current_refill <= n){
        int last_refill = current_refill;
        while(current_refill <= n and stations[current_refill + 1] - stations[last_refill] <= L) current_refill++;
        if(current_refill == last_refill) return -1;
        if(current_refill <= n) refills++;
    }
    return refills;
}

int minimum_refills(vector<int> stations, int n, int L){
    int current_refill = stations[0], final_pos = stations[n- 1];
    int no_of_refills = 0;
    int max = n - 2;
    while(no_of_refills <= n){
        int last_refill = current_refill;
        if(stations[])
    }

}

int main(){
    vector<int> stations = {0, 3, 6, 9, 12};
    int L = 3; // how long the car can travel on a full tank
    cout<<minimum_refills(stations, stations.size(), L);
    return 0;
}