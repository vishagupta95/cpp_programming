#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
Manasa is out on a hike with friends. She finds a trail of stones with numbers on them. She starts following the trail and notices that 
any two consecutive stones' numbers differ by one of two values. Legend has it that there is a treasure trove at the end of the trail. 
If Manasa can guess the value of the last stone, the treasure will be hers.

*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n , a ,b;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        vector<int> arr;
        if(a==b) arr.push_back((n-1)*a);
        else{
            for(int i=1 ; i<=n ; i++){
                arr.push_back(((n-i)*a)+((i-1)*b));
            }
        }
            sort(arr.begin(), arr.end());
            for(int i=0 ; i<arr.size() ;i++) cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}




