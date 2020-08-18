#include <bits/stdc++.h>
using namespace std;

// Using a matrix for dp - globally
int dp[5][8];
int t[5][8];

// knapsack without memoization
int knapsack(vector<int> &wt, vector<int> &val, int w, int n){
    if(n == 0 or w == 0) return 0;
    if(wt[n-1] <= w){
        return max(val[n-1] + knapsack(wt, val, w - wt[n-1], n-1), knapsack(wt, val, w, n-1));
    }
    else if(wt[n-1] > w) return knapsack(wt, val, w, n-1);
    return 0;
}

// knapsack with memoization
int knapsack2(vector<int> &wt, vector<int> &val, int w, int n){
    if(n == 0 or w == 0) return 0;
    if(dp[n][w]) return dp[n][w];
    if(wt[n-1] <= w){
        return dp[n][w] = max(val[n-1] + knapsack(wt, val, w - wt[n-1], n-1), knapsack(wt, val, w, n-1));
    }
    else return dp[n][w] = knapsack(wt, val, w, n-1);
}

// knapsack with top-down matrix
int knapsack3(vector<int> &wt, vector<int> &val, int w, int n){
    for(int i = 0; i < n+1; i++) t[i][0] = 0;
    for(int j = 0; j < w+1; j++) t[0][j] = 0;
    for(int i = 1; i < n+1; i++)
        for(int j = 1; j < w+1; j++)
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else t[i][j] = t[i-1][j];
    return t[n][w];
}

int main(){
    // Find the largest value possible with the weights and values of each item with a max weight of 7
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 5, 6, 7};
    memset(dp, 0, sizeof(dp));
    int w = 7;
    int maxProfit = knapsack2(wt, val, w, wt.size());
    cout<<maxProfit;
    int maxProfit2 = knapsack3(wt, val, w, wt.size());
    cout<<maxProfit2;
    return 0;
}