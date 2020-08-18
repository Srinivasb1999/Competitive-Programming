#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 0, -3, 5, 6};
    int element = -3; //this value will be used as the generic element

    // use this to sort a vector
    sort(arr.begin(), arr.end());

    // using binary search on the array given above
    // suppose I want to search whether -3 exists in the above array, then
    bool present = binary_search(arr.begin(), arr.end(), element);

    // sort decreasing order using sort and a lambda function, or sort with greater<>()
    sort(arr.begin(), arr.end(), [](int a, int b){return a > b;});
    sort(arr.begin(), arr.end(), greater<>());
    
    // lower bound- finds element >= the element being searched
    // value returned is an iterator
    auto it1 = lower_bound(arr.begin(), arr.end(), element);

    // upper bound - finds element > the element being searched
    auto it2 = upper_bound(arr.begin(), arr.end(), element);

    // subtracting the iterators from upper bound and lower bound of the same element
    // gives the count of the element
    auto count1 = it2 - it1;

    // counting the element in a c++ vector
    int count2 = count(arr.begin(), arr.end(), element);

    // printing vector in one line
    // for(int i: arr) cout<<i<<" ";   
    return 0;
}