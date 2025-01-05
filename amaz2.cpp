#include <iostream>
#include <vector>
#include <algorithm>

/*

A team of engineers at Amazon, using advanced simulation tools, is analyzing a series of interconnected systems, where each system has charge values represented by charge[i], which can be positive, negative, or zero.

The engineers have a specialized tool that allows them to perform the following operations: select a system and remove it, causing the neighboring systems to automatically merge and combine their charge values. If the removed system has neighboring systems with charges x and y directly to its left and right, they will combine to form a new system with charge x + y. No combination will take place if the system is the leftmost or rightmost in the array.

Since the process is computationally expensive, the engineers will simulate the operation using Amazon's advanced tools.

For example, if the system charges are [-3, 1, 4, -1, 5, -9], using the tool on the 4th system (index 3) will result in the new sequence [-3, 1, 9, -9], as the charges from the 3rd and 5th systems combine to 4 + 5 = 9. If they then use the tool on the 1st system in this new sequence, it will become [1, 9, -9].

The engineers will continue performing these operations until only one system remains.

Given an array charge of size n, find the maximum possible charge of the remaining system after performing these operations.

Example 1:
n = 5
charge = [-2, 4, 3, -2, 1]
Answer: 4
Example 2:
n = 5
charge = [-2, 4, 9, 1, -1]
Answer: 9
*/

/*



using namespace std;

long getMaximumCharge(vector<int>& charge) {
    int n = charge.size();
    
    // If only one element exists, return it directly
    if (n == 1) {
        return charge[0];
    }
    
    // Initialize dp array to store the maximum charge achievable
    vector<long> dp(n, 0);
    
    // Base case: The last system can't merge with anything, so its value stays as is
    dp[n-1] = charge[n-1];
    
    // Traverse from second last system to the first
    for (int i = n-2; i >= 0; --i) {
        // Start by assuming the current system value is the best achievable
        dp[i] = charge[i];
        
        // If there's a system to the right, consider merging with it
        if (i + 1 < n) {
            dp[i] = max(dp[i], (long)(charge[i] + charge[i+1]));
        }
        
        // Additionally, consider merging with the next system after removal (if not at the end)
        if (i + 2 < n) {
            dp[i] = max(dp[i], (long)(charge[i] + charge[i+1] + charge[i+2]));
        }
    }
    
    // Return the maximum value achieved after processing
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> charge1 = {-2, 4, 3, -2, 1};
    cout << getMaximumCharge(charge1) << endl;  // Output: 4
    
    vector<int> charge2 = {-2, 4, 9, 1, -1};
    cout << getMaximumCharge(charge2) << endl;  // Output: 9
    
    vector<int> charge3 = {-1, 3, 2};
    cout << getMaximumCharge(charge3) << endl;  // Output: 3
    
    return 0;
}

