#include <vector>
#include <climits>

using namespace std;

/* 
Question link : https://leetcode.com/problems/powx-n/

Runtime : 111 ms
Beats : 86.92 %
Memory : 67.7 MB
Beats : 62.62 %

Time Complexity : O(n)
-> n since nums scan is done once to fill dp_array.

Space Complexity : O(n)
-> 1 for curr_sum
-> n for nums
-> 1 each for index

Logic :
Technically, we don't even need to save the values except for max sum until the index right before. So we only have 1 container for that value, curr_sum.

Algorithm :
1. Initialize curr_sum and result with nums[0].
2. Update curr_sum with nums[index] and potentially adding curr_sum. Addition only happens if curr_sum is positive(which means max sum until last index is benefitial).
3. If curr_sum is bigger than result, update result.
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0], result = nums[0];

        for (int index = 1; index < nums.size(); index++){
            curr_sum = nums[index] + (curr_sum > 0 ? curr_sum : 0);
            if (curr_sum > result) result = curr_sum;
        }

        return result;
    }
};