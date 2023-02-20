/* 
Question link : https://leetcode.com/problems/spiral-matrix/

Runtime : 0 ms
Beats : 100 %
Memory : 7 MB
Beats : 34.62 %

Time Complexity : O(n)
-> n since it scans every element in the matrix once.

Space Complexity : O(n)
-> n for matrix
-> n for result
-> 1 each for row_start, row_end, column_start, column_end, row_loop, column_loop

Logic :
We first have to think what spiral scan is. It is easy if we think that we apply the algorithm for nested circles.
Then we need to consider how to create the loop, which I implemented using the start/end indicies. So when applying algorithm to inner nested circle, you simple update the boundary(since you can't physically remove the elements easily).
After that, we need to consider how we should create the loop for 1 directional move(out of 4). Movements can only happen if there are enough elements in the circle(depending on the matrix shape, this circle can be imperfect, so we need if statements to check if there are any new elements to read).
-> When there are no elements, we simply escape the algorithm(since it means that the reading is done for every element), then return the result.

Algorithm :
1. Initialize row_start, row_end, column_start, column_end with the indecies of such values.
2. We first go from left to right. This can only be done when there is an available row, and an available column. 
-> Both conditions are needed because available rows and columns only decrease by 2(think about example of 2,4 matrix or 4,2 matrix).
-> movement is done by traversing from column_start to column_end.
3 Then go from top to bottom. This can only be done when there is an available row.
-> movement is done by traversing from row_start+1(important so you don't add the last element from last step again) to row_end.
4. Then from right to left. This can only be done when there is an available column.
-> movement is done by traversing from column_end-1 to column_start.
5. Then from bottom to top. THis can only be done when there is an available row.
-> movement is done by traversing from row_end-1 to row_start+1.
6. After the 4 steps are done, increment row_start and column_start and decrement row_end and column_end. This indicates that those rows and columns are exhausted.
7. Continue the steps until some condition is not met(which means that every element is matrix is added) so that it breaks the while loop.
8. Return result.
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_start = 0, row_end = matrix.size()-1;
        int column_start = 0, column_end = matrix[0].size()-1;
        vector<int> result;
        while (true){
            // left to right
            if (row_end - row_start >= 0  && column_end - column_start >= 0){
                for (int column_loop = column_start; column_loop <= column_end; column_loop++){
                    result.push_back(matrix[row_start][column_loop]);
                }                
            }
            else break;


            // up to down
            if (row_end - row_start >= 1){
                for (int row_loop = row_start + 1; row_loop <= row_end; row_loop++){
                    result.push_back(matrix[row_loop][column_end]);
                }              
            }
            else break;


            // right to left
            if (column_end - column_start >= 1){
                for (int column_loop = column_end - 1; column_loop >= column_start; column_loop--){
                    result.push_back(matrix[row_end][column_loop]);
                }          
            }
            else break;


            // down to up
            if (row_end - row_start >= 2){
                for (int row_loop = row_end - 1; row_loop >= row_start + 1; row_loop--){
                    result.push_back(matrix[row_loop][column_start]);
                }        
            }
            else break;

            row_start++;
            row_end--;
            column_start++;
            column_end--;
        }
        return result;
    }
};