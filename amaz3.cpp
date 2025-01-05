/*
You have discovered n mysterious particles on a line with integer charges of c1, c2, ..., cn. You have a device that allows you to perform the following operation:

Choose a particle and remove it from the line. The remaining particles will shift to fill the gap created. If there are particles with charges x and y directly to the left and right of the removed particle, they will combine into a single particle with charge x + y.

For example, if the line of particles has charges [-3, 1, 4, -1, 5, -9], performing the operation on the 4th particle will transform the line into [-3, 1, 9, -9].

If you then use the device on the 1st particle in this new line, the line will become [1, 9, -9].

You will continue performing operations until only one particle remains. What is the maximum charge of the remaining particle that you can obtain?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute maximum charge of the last remaining particle
int maxCharge(vector<int>& charges) {
    int n = charges.size();
    
    // Create a DP table to store results for subarrays
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Create a prefix sum array to calculate sum of subarrays efficiently
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + charges[i];
    }
    
    // Function to calculate sum of elements from index i to j
    auto getSum = [&](int i, int j) {
        return prefixSum[j + 1] - prefixSum[i];
    };
    
    // Fill the DP table
    for (int length = 2; length <= n; ++length) {  // length of subarray
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = getSum(i, j);  // Initialize with the sum of the subarray
            for (int k = i; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + getSum(i, j));
            }
        }
    }
    
    // The result is the maximum charge for the entire array
    return dp[0][n - 1];
}

int main() {
    // Example usage
    vector<int> charges = {-3, 1, 4, -1, 5, -9};
    cout << "Maximum possible charge: " << maxCharge(charges) << endl;
    return 0;
}

