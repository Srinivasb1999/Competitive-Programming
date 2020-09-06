#include <bits/stdc++.h>
using namespace std;


bool subset_sum(vector<int> &arr, int n, int sum){
    bool t[n+1][sum+1];
    for(int i = 0; i < n + 1; i++) t[i][0] = true;
    for(int j = 1; j < sum + 1; j++) t[0][j] = false;
    for(int i = 1; i < n + 1; i++)
        for(int j = 1; j < sum + 1; j++)
            if(arr[i-1] <= sum){
                t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j];
            }
            else t[i][j] = t[i-1][j];
    return t[n][sum];

}

int main(){
    // Find if there exists a subset which adds up to the sum 11
    vector<int> arr = {2, 3, 8};
    int n = arr.size();
    int sum = 11;
    bool output = subset_sum(arr, n, sum);
    if(output) cout<< "True";
    else cout<<"False";
    return 0;
}