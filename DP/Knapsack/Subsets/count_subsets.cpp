#include <bits/stdc++.h>
using namespace std;

int count_subsets(vector<int> &arr, int n, int sum){
    int dp[n+1][sum+1];
    for(int i = 0; i < n + 1; i++) dp[i][0] = 1;
    for(int j = 1; j < sum + 1; j++) dp[0][j] = 0;
    for(int i = 1; i < n + 1; i++)
        for(int j = 1; j < sum + 1; j++)
            if(j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
    return dp[n][sum];
}


int main(){
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int n = arr.size();
    int sum = 10;
    int output = count_subsets(arr, n, sum);
    cout<<output;
    return 0;
}