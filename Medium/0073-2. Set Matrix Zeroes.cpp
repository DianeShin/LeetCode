/* 
Question link : https://leetcode.com/problems/set-matrix-zeroes/

Runtime : 8 ms
Beats : 96.86 %
Memory : 13.1 MB
Beats : 99.31 %

Time Complexity : O(m * n) : m for rows and n for columns
-> m*n each for matrix scan, zero set

Space Complexity : O(m * n) for input, O(n) for algorithm
-> m*n for matrix
-> n for zero_row : for shorter algorithm, can change to manually filling zeros, which makes space complexity of O(1).
-> 1 each for row_zero_flag, column_zero_flag

Algorithm :
1. Scan row 0 and column 0 and check if they contain a zero
-> This step is needed since the zero row/column information will be saved in row 0 and column 0.
2. Scan through row 1-end, column 1-end, and if there is a zero, save it to row 0 and column 0.
3. Scan through row 0 and column 0, and set the corresponding rows and columns to zero.
4. Check the flag, and set row 0 and column 0 as zero if needed.
*/

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row_zero_flag = false;
        bool column_zero_flag = false;
        vector<int> zero_row(matrix[0].size(), 0);

        // check if row 0 should be zero_row
        for (int column = 0; column < matrix[0].size(); column++){
            if (matrix[0][column] == 0) row_zero_flag = true;
        }
        
        // check if column 0 should be 0
        for (int row = 0; row < matrix.size(); row++){
            if (matrix[row][0] == 0) column_zero_flag = true;
        }

        // save zero row/column information in matrix row 0 and column 0
        for (int row = 1; row < matrix.size(); row++){
            for (int column = 1; column < matrix[0].size(); column++){
                if (matrix[row][column] == 0){
                    matrix[0][column] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        // set zero row
        for (int row = 1; row < matrix.size(); row++){
            if (matrix[row][0] == 0) matrix[row] = zero_row;
        }

        // set zero column
        for (int column = 0; column < matrix[0].size(); column++){
            if (matrix[0][column] == 0){
                for (int row = 1; row < matrix.size(); row++){
                    matrix[row][column] = 0;
                }
            }
        }

        // set row 0
        if (row_zero_flag) matrix[0] = zero_row;

        // set column 0
        if (column_zero_flag){
            for (int row = 0; row < matrix.size(); row++){
                matrix[row][0] = 0;
            }
        }
    }
};