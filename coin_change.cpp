#include <iostream>
#include <vector>
using namespace std;

/*
Given an unlimited supply of coins of given denominations, find the total number of distinct ways to get the desired change.
The total number of ways is 6
 
{ 1, 7 }
{ 3, 5 }
{ 1, 1, 3, 3 }
{ 1, 1, 1, 5 }
{ 1, 1, 1, 1, 1, 3 }
{ 1, 1, 1, 1, 1, 1, 1, 1 }
 
 
Input: S = { 1, 2, 3 }, target = 4
 
The total number of ways is 4
*/

// Recursive C++ program for
// coin change problem.
#include <bits/stdc++.h>
using namespace std;

// Returns the count of ways we can
// sum coins[0...n-1] coins to get sum "sum"
int count(int coins[], int n, int sum)
{

	// If sum is 0 then there is 1 solution
	// (do not include any coin)
	if (sum == 0)
		return 1;

	// If sum is less than 0 then no
	// solution exists
	if (sum < 0)
		return 0;

	// If there are no coins and sum
	// is greater than 0, then no
	// solution exist
	if (n <= 0)
		return 0;

	// count is sum of solutions (i)
	// including coins[n-1] (ii) excluding coins[n-1]
	return count(coins, n - 1, sum) +
		count(coins, n, sum - coins[n - 1]);
}

// Driver code
int main()
{
	int i, j;
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;

	cout << " " << count(coins, n, sum);

	return 0;
}

// This code is contributed by shivanisinghss2110


 
// Function to find the total number of ways to get a change of `target`
// from an unlimited supply of coins in set `S`
int count(vector<int> const &S, int target)
{
    // if the total is 0, return 1
    if (target == 0) {
        return 1;
    }
 
    // return 0 if total becomes negative
    if (target < 0) {
        return 0;
    }
 
    // initialize the total number of ways to 0
    int result = 0;
 
    // do for each coin
    for (int c: S)
    {
        // recur to see if total can be reached by including current coin `c`
        result += count(S, target - c);
    }
 
    // return the total number of ways
    return result;
}
 
// Coin Change Problem
int main()
{
    // `n` coins of given denominations
    vector<int> S = { 1, 2, 3 };
 
    // total change required
    int target = 4;
 
    cout << "The total number of ways to get the desired change is "
         << count(S, target);
 
    return 0;
}

