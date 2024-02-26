#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
// g++ avg_new.cpp -std=c++11  
int main()
{
    // a vector containing several duplicate elements
    vector<int> v{1,2,1,1,3,3,3,4,5,4};
    auto print = [&] (int id) {
        cout << "@" << id << ": ";
        for (int i : v)
            cout << i << ' ';
        cout << '\n';
    };
    print(1);
 
    // remove consecutive (adjacent) duplicates
    auto last = unique(v.begin(), v.end());
    // v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    print(2);
 
    // sort followed by unique, to remove all duplicates
    sort(v.begin(), v.end()); // {1 1 2 3 4 4 5}
    print(3);
 
    last = unique(v.begin(), v.end());
    // v now holds {1 2 3 4 5 x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    print(4);
}
