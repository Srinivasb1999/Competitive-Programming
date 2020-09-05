#include <iostream>
using namespace std;


int tower(int n, int start = 1, int end_ = 3){
    if (n != 0){
    tower(n - 1, start, 6-start-end_);
    tower(n - 1, 6-start-end_, end_);
    }
}

main(){
    tower(30);
}


