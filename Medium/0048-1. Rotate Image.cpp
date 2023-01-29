/* 
Question link : https://leetcode.com/problems/rotate-image/

Runtime : 6 ms
Beats : 16.25 %
Memory : 7.2 MB
Beats : 39.73 %

Time Complexity : O(n^2)
-> n^2/2 loop for horizontal fold
-> n^2/2 loop for diagonal fold
-> 3 operations each in loops

Space Complexity : O(n * n)
-> n^2 for input
-> 2 for row, column

Algorithm :
1. fold horizontally and swap elements.
2. fold diagonally and swap elements.
*/

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrix_size = matrix.size();
        // fold horizontally
        for (int row = 0; row < matrix_size/2; row++){
            for(int column = 0; column < matrix_size; column++){
                int save = matrix[row][column];
                matrix[row][column] = matrix[matrix_size - row - 1][column];
                matrix[matrix_size - row - 1][column] = save;
            }
        }

        // fold diagonally
        for (int row = 0; row < matrix_size; row++){
            for (int column = 0; column < row; column++){
                int save = matrix[row][column];
                matrix[row][column] = matrix[column][row];
                matrix[column][row] = save;
            }
        }

    }
};