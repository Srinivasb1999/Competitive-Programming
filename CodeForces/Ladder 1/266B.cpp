#include <bits/stdc++.h>
using namespace std;

int main(){
    string h;
    int n, t, i;
    cin >> n >> t >> h;

    while(t--){
        for(i = 0; i < n - 1; i++){
            if(h[i] == 'B' && h[i+1] == 'G'){
                h[i + 1] = 'B';
                h[i] = 'G'; 
                i++;
            }
        }
    }

    cout<<h;

    return 0;
}