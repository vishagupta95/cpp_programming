#include<bits/stdc++.h>
using namespace std;
#define length 3
#define breadth 3
#define height 3


/*
 *
 * Time complexity is n3

We are given a cube which can be formed using a 3-D array as cube[length][breadth][height]. The task is to calculate the minimum sum path which will be achieved by traversing the cube and hence print the result.

Let us see various input output scenarios for this -

In − int cube[length][breadth][height] = { { {2, 4, 1}, {3, 4, 5}, {9, 8, 7}}, { {5, 3, 2}, {7, 6, 5}, {8, 7, 6}}, { {3, 2, 1}, {4, 3, 2}, {5, 4, 3}}}

Out  − Minimum Sum Path In 3-D Array are: 15

Explanation − we are given a cube having length, breadth and height. Now, we will calculate the minimum sum path in 3-D array. So, it will start from 2 + 4 + 1 + 3 + 5 i.e. 15.

In − int cube[length][breadth][height] = { { {1, 2}, {7, 8}}, { {3, 5}, {9, 16}}}

Out − Minimum Sum Path In 3-D Array are: 24

Explanation − we are given a cube having length, breadth and height. Now, we will calculate the minimum sum path in 3-D array. So, it will start from 1 + 2 + 5 + 16 i.e. 24.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int length = 3, breadth = 3, height = 3;
    int cube[3][3][3] = { 
        { {2, 4, 1}, {3, 4, 5}, {9, 8, 7} },
        { {5, 3, 2}, {7, 6, 5}, {8, 7, 6} },
        { {3, 2, 1}, {4, 3, 2}, {5, 4, 3} }
    };
    
    // DP table to store minimum path sum to reach each element
    int dp[length][breadth][height];
    
    // Initialize dp array
    dp[0][0][0] = cube[0][0][0];
    
    // Fill the DP table
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < breadth; ++j) {
            for (int k = 0; k < height; ++k) {
                if (i == 0 && j == 0 && k == 0) continue;  // Skip the first element
                
                int min_sum = INT_MAX;
                
                // Check for valid adjacent cells and take the minimum path sum
                if (i > 0) min_sum = min(min_sum, dp[i-1][j][k]);
                if (j > 0) min_sum = min(min_sum, dp[i][j-1][k]);
                if (k > 0) min_sum = min(min_sum, dp[i][j][k-1]);
                
                dp[i][j][k] = min_sum + cube[i][j][k];
            }
        }
    }
    
    // The answer will be in dp[length-1][breadth-1][height-1]
    cout << "Minimum Sum Path In 3-D Array is: " << dp[length-1][breadth-1][height-1] << endl;
    return 0;
}

