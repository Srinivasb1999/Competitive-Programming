#include <bits/stdc++.h>
using namespace std;

bool equal_sum(vector<int> &arr, int n, int sum){
    if(sum % 2 != 0) return false;
    else{
        sum = sum/2;
        bool dp[n+1][sum+1];
        for(int i = 0; i < n + 1; i++) dp[i][0] = true;
        for(int j = 1; j < sum + 1; j++) dp[0][j] = false; 
        for(int i = 1; i < n + 1; i++)
            for(int j = 1; j < sum + 1; j++)
                if(arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
        return dp[n][sum];
    }
}

int main(){
    // Find if there exists 2 subsets in the given array such that they have equal sums
    int n, data;
    cin>>n;    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> data;
        arr.push_back(data);
    }
    int sum = accumulate(arr.begin(), arr.end(), 0);
    bool output = equal_sum(arr, n, sum);
    if(output) cout<<"YES";
    else cout<<"NO";
    return 0;
}