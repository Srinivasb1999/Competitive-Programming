#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x

int lcs(string x, string y) {
    int m = x.length();
    int n = y.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    /* Giving a dictionary and a string ‘str’, your task is to find the longest string 
    in dictionary of size x which can be formed by deleting some characters of the given ‘str’.
    */
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> inputs(n);
        while (n--) {
            string input;
            cin >> input;
            inputs.push_back(input);
        }
        string check;
        cin >> check;

        int max = INT_MIN, index = 0;
        for (int i = 0; i < inputs.size(); i++) {
            int res = lcs(inputs[i], check);
            if (res > max) {
                max = res;
                index = i;
            }
        }
        cout << inputs[index] << endl;
    }
    return 0;
}

/*
2
4
ale apple monkey plea
abpcplea
4
pintu geeksfor geeksgeeks forgeek
geeksforgeeks
*/