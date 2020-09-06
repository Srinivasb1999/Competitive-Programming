#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int output = 0;
    unordered_map<char, int> hash;
    int start = 0;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(hash.find(ch)!=hash.end())
            start = max(start, 1 + hash[ch]);
        if(output < i + 1 - start)
            output = i + 1 - start;
        hash[ch] = i;
    }
    return output;
}

string lengthOfLongestSubstring2(string s) {
    unordered_map<char, int> hash;
    pair<int, int> range= {0, 1};
    int start = 0;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(hash.find(ch)!=hash.end())
            start = max(start, 1 + hash[ch]);
        if(range.second - range.first < i + 1 - start){
            range.first = start;
            range.second = i + 1;
        }
        hash[ch] = i;
    }
    string result = s.substr(range.first, range.second);
    return result;
}



int main(){
    cout<<lengthOfLongestSubstring2("abcdad");
    return 0;
}