#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string str1, int m, string str2, int n) {
    string dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++) dp[i][0] = "";
    for (int j = 1; j < n + 1; j++) dp[0][j] = "";
    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
            if (str1[i - 1] == str2[j - 1]) {
                string s = dp[i - 1][j - 1];
                dp[i][j] = s + str1[i - 1];
            } else {
                if ((dp[i - 1][j].size()) > (dp[i][j - 1]).size())
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
    return dp[m][n];
}

int main() {
    string s1 = "XYKWYZ";  //"ZXVVYZW";
    string s2 = "DXKUYA";  //"XKYKZPW";
    string output = longestCommonSubsequence(s1, s1.size(), s2, s2.size());
    for (auto i : output) cout << i << " ";
    return 0;
}
