#include <iostream> 

int n, a, b, c, d = 0, e = 0, f = 0;
int main() 
{ 
    std::cin >> n;
    while(n--){
        std::cin>>a>>b>>c;
        d += a; 
        e += b;
        f += c;
    }
    std::cout<<(d|e|f?"NO":"YES");    
    return 0;
}