#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, year;
    cin >> year;
    do{
        year++;
        a = year /1000;
        b = year % 1000 / 100;
        c = year % 100 / 10;
        d = year % 10; 
    } while(a == b || a == c || a == d || b == c || b == d || c == d);
    cout << year;
    return 0;
}