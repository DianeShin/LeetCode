/* 
Question link : https://leetcode.com/problems/merge-intervals/

Runtime : 5 ms
Beats : 13.62 %
Memory : 6.6 MB
Beats : 31.80 %

Time Complexity : O(m*n)
-> m*n for result filling

Space Complexity : O(m*n)
-> m*n for result
-> 1 each for m, n, row, column

Logic :
We calculate how to get to the end position by indicating how many ways exist to get to a certain point.
-> This certain point reaches to the end point.

Algorithm :
1. Create result matrix initialized with 1.
-> 1 is only needed for row 0 and column 0 though. Just initialized with 1 for ease.
2. From row 1 and column 1, update result by result[row][column] = result[row-1][column] + result[row][column-1];
*/

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> result(m, vector<int>(n, 1));
        
        for (int row = 1; row < m; row++){
            for (int column = 1; column < n; column++){
                result[row][column] = result[row-1][column] + result[row][column-1];
            }
        }
        return result[m-1][n-1];
    }
};