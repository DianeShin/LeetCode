/* 
Question link : https://leetcode.com/problems/powx-n/

Time Limit Exceeded

Time Complexity : O(n^2)
-> n^2 to fill dp_array

Space Complexity : O(n)
-> n for sum_array
-> n for nums
-> 1 each for row, column

Algorithm :
1. Fill the dp_array. Initialization(row == column) is done with nums[row]. Calculation after is done by adding previous path + nums[column]
-> filling is done for only the upper trianlge since it's symmetrical.
-> Specifically, the array is reused(considering this algorithm doesn't need to save information about past rows).
2. Compare saved result and new calculation to select bigger value.
*/


#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum_array[nums.size()];
        int result = INT_MIN;
        for (int row = 0; row < nums.size(); row++){
            for (int column = row; column < nums.size(); column++){
                if (row == column) sum_array[row] = nums[row];
                else sum_array[column] = sum_array[column-1] + nums[column];
                if (sum_array[column] > result) result = sum_array[column];
            }
        }
        return result;    
    }
};