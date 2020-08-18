#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, j, data, posx, posy;
    for(j = 0; j< 5; j++)
        for (i = 0; i < 5; i++)
        {
            cin>>data;
            if(data==1){
                posx = i; 
                posy = j;
            }
                
        }
    cout<<abs(2 - posx)+ abs(2 - posy);
    return 0;
}