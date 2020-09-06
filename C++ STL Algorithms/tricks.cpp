#include <bits/stdc++.h>
using namespace std;
#define ll long long

// use this to debug values of variables
#define deb(x) cout<<#x<<" "<<x;


int main(){
    
    // makes cin and cout faster
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Even and Odd functions
    int num = 4;
    string output = num & 1 ? "Odd": "Even";

    // gcd function in stl
    int first = 8, second = 12;
    int gcd = __gcd(first, second);

    // Use this to raise to the power of 2, and use LL explicitly to convert
    // the answer to long long
    long long power_of_2 = 1LL<<35;
    
    // instead of if(condition) x++ write x+=(condition)

    // 

    return 0;
}