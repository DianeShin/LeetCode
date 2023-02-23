/* 
Question link : https://leetcode.com/problems/set-matrix-zeroes/

Runtime : 16 ms
Beats : 62.47 %
Memory : 13.5 MB
Beats : 16.51 %

Time Complexity : O(m * n) : m for rows and n for columns
-> m*n each for matrix scan, zero set

Space Complexity : O(m * n) for input, O(m + n) for algorithm
-> m*n for matrix
-> m for row_vector
-> n for column_vector
-> n for zero_rows
-> 1 each for row, column, row_vector_indx

Algorithm :
1. Scan the matrix and indicate the rows/columns that should be set to zero.
-> if matrix[row][column] is 0, that means that the 'row' and 'column' should be set to zero
2. For rows, it's easier, just create a vector with column number of zeros(zero_row), and substitute such rows with this zero_row.
3. For column,s we need to access every row in the column and substitute.
*/

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row_vector;
        vector<int> column_vector;

        // find row/columns to be set as 0
        for (int row = 0; row < matrix.size(); row++){
            for (int column = 0; column < matrix[0].size(); column++){
                if (matrix[row][column] == 0){
                    row_vector.push_back(row);
                    column_vector.push_back(column);
                } 
            }
        }

        // set rows to 0
        vector<int> zero_row(matrix[0].size(), 0);
        for (int row_vector_index = 0; row_vector_index < row_vector.size(); row_vector_index++){
            matrix[row_vector[row_vector_index]] = zero_row;
        }

        // set columns to 0
        for (int column_vector_index = 0; column_vector_index < column_vector.size(); column_vector_index++){
            for (int row = 0; row < matrix.size(); row++){
                matrix[row][column_vector[column_vector_index]] = 0;
            }
        }
    }
};