#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    int element = 1; // this element will be used as a generic element
    
    s.insert(1);
    s.insert(-2);
    s.insert(-4);
    s.insert(5);

    // print the set, in the same fashion
    // for(int x: s) cout<<x<<" ";

    // sets store data in a sorted format, and all operations are done in log n

    // use the find function to search whether an element exists in the set
    // if exists, returns an iterator
    if(s.find(element) == s.end()) cout<<"Doesn't exist";

    // using upper_bound and lower_bound
    auto it1 = s.lower_bound(element);
    auto it2 = s.upper_bound(element);
    // subtracting these two iterators will yeild the count of the element

    return 0;
}