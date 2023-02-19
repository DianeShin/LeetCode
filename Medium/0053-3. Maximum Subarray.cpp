#include <vector>
#include <climits>

using namespace std;

/* 
Question link : https://leetcode.com/problems/powx-n/

Runtime : 130 ms
Beats : 35.59 %
Memory : 68.2 MB
Beats : 7.87 %

Time Complexity : O(n)
-> n since nums scan is done once to fill dp_array.

Space Complexity : O(n)
-> n for dp_array
-> n for nums
-> 1 each for index

Algorithm :
1. Initialize dp_array[0] with nums[0], and result with nums[0](which means array with nums[0] is the max sum).
2. Calculate dp_array[index]. This is done by adding nums[index] and possibly dp_array[index-1]. dp_array[index-1] means max sum that ends in index-1. Which is only beneficial to add to dp_array[index] when it's positive.
3. If dp_array[index] is bigger than result, update result.
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp_array[nums.size()];

        // init
        dp_array[0] = nums[0];
        int result = nums[0];

        for (int index = 1; index < nums.size(); index++){
            dp_array[index] = nums[index] + (dp_array[index -1] > 0 ? dp_array[index-1] : 0);
            if (dp_array[index] > result) result = dp_array[index];
        }

        return result;
    }
};