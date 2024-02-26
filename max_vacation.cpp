/*
uppose one company wants to give one of its best employees the option to travel among N cities to collect some resources. But employees want some vacations also, we could take vacations in some particular cities and weeks. Our task is to schedule the traveling to maximize the number of vacation days we could take, but there are certain rules and restrictions we have to follow.

We can only travel among N cities; they are represented by indexes from 0 to N-1. Firstly, we are in the city indexed 0 on Monday.

These cities are connected by flights. We have one N x N matrix (not necessarily symmetrical) to represent the flights. The flights representing the airline status from the city i to the city j. If there is no flight from the city i to the city j, then the matrix flights[i][j] will be 0; Otherwise, flights[i][j] = 1. Also, flights[i][i] = 0 for all i.

We have K weeks to travel. We can only take flights at most once per day and can only take flights on each week's Monday morning.

For each city, we can only have restricted vacation days in different weeks, for that we have an N*K matrix called days this is showing this relationship. For the value of days[i][j], it represents the maximum days we could take vacation in the city i in the week j.

So if we have the flights matrix and days matrix, and we need to output the maximum vacation days we could take during K weeks.

So, if the input is like flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]], then the output will be 12

To solve this, we will follow these steps −

n := rows of flights

m := columns of the days matrix

Define one 2D array dp of size (m + 1) x n

for initialize i := m - 1, when i >= 0, update (decrease i by 1), do −

for initialize j := 0, when j < n, update (increase j by 1), do −

for initialize k := 0, when k < n, update (increase k by 1), do −

if j is same as k or flights[j, k] is non-zero, then −

dp[i, j] := maximum of dp[i, j] and days[j, i] + dp[i + 1, k]

ret := dp[0, 0]

for initialize i := 1, when i < n, update (increase i by 1), do −

if flights[0, i] is non-zero, then −

ret := maximum of ret and dp[0, i]

return ret

Let us see the following implementation to get better understanding −
*/




#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
      int n = flights.size();
      int m = days[0].size();
      vector<vector<int> > dp(m + 1, vector<int>(n));
      for (int i = m - 1; i >= 0; i--) {
         for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
               if (j == k || flights[j][k]) {
                  dp[i][j] = max(dp[i][j], days[j][i] + dp[i + 1][k]);
               }
            }
         }
      }
      int ret = 0;
      ret = dp[0][0];
      for (int i = 1; i < n; i++) {
         if (flights[0][i]) {
            ret = max(ret, dp[0][i]);
         }
      }
      return ret;
   }
};
main(){
   Solution ob;
   vector<vector<int>> v1 = {{0,1,1},{1,0,1},{1,1,0}}, v2 = {{1,3,1},{6,0,3},{3,3,3}};
   cout << (ob.maxVacationDays(v1, v2));
}
