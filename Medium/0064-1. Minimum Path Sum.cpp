/* 
Question link : https://leetcode.com/problems/minimum-path-sum/

Runtime :  12 ms
Beats :  55.45 %
Memory :  10 MB
Beats :  45.39 %

Time Complexity : O(m*n)
-> m + n for 1st row/column init

Space Complexity : O(m*n)
-> m*n each for input, DP array

Algorithm :
1. Initialize DP array
2. There is only one way to reach every numbers in 1st row and column, so initialize.
3. The other numbers are reached either from left or top, so use min function, then add current number.
4. The right-bottom number of DP array contains the minimum sum.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // define array
        vector<vector<int>> DP(grid.size(), vector<int>(grid[0].size(), 0));

        // initialize first row
        for (int index = 0; index < grid.size(); index++){
            if (index == 0) DP[0][0] = grid[0][0];
            else DP[index][0] = DP[index-1][0] + grid[index][0];
        }

        // initialize first column
        for (int index = 1; index < grid[0].size(); index++){
            DP[0][index] = DP[0][index-1] + grid[0][index];
        }

        // fill DP array
        for (int row = 1; row < grid.size(); row++){
            for (int column = 1; column < grid[0].size(); column++){
                DP[row][column] = min(DP[row-1][column], DP[row][column-1]) + grid[row][column];
            }
        }

        // return
        return DP[grid.size()-1][grid[0].size()-1];
    }
};