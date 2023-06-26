/* 
Question link : https://leetcode.com/problems/unique-paths-ii/

Runtime : 3 ms
Beats : 69.85 %
Memory : 7.8 MB
Beats : 28.28 %

Time Complexity : O(m*n)
-> m + n for init
-> m*n for array calculation

Space Complexity : O(m*n)
-> m*n each for input, DP vector

Logic :
WWhen there is an obstacle, we can't reach there.

Algorithm :
1. Declare a DP array. Initialize with 0, indicating that there are no paths.
2. Initialize 0 row and column. Indicate that there is only 1 way to reach that block until obstacle is found. We don't need to update values after an obstacle since reaching that block is impossible.
3. Fill the DP array. If there is an obstacle on that block, just continue(no possible way to reach). For any other block, just sum paths coming from left, and coming from top.
4. Return number of paths possible by accessing DP[DP.size()-1][DP[0].size()-1]
*/

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> DP(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        // init
        for (int i = 0; i < DP.size(); i++){
            if (obstacleGrid[i][0] == 1) break;
            else DP[i][0] = 1;         
        }
        for (int i = 0; i < DP[0].size(); i++){
            if (obstacleGrid[0][i] == 1) break;
            else DP[0][i] = 1;
        }

        // calc
        for (int i = 1; i < DP.size(); i++){
            for (int j = 1; j < DP[0].size(); j++){
                if (obstacleGrid[i][j] == 1) DP[i][j] = 0;
                else DP[i][j] = DP[i-1][j] + DP[i][j-1];
            }
        }

        // return output
        return DP[DP.size()-1][DP[0].size()-1];
    }    
};