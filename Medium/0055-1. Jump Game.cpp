/* 
Question link : https://leetcode.com/problems/jump-game/

Runtime : 66 ms
Beats : 76.69 %
Memory : 54 MB
Beats : 6.56 %

Time Complexity : O(n)
-> n since it scans nums array once.

Space Complexity : O(n)
-> n for nums
-> n for dp_array
-> 1 for index

Algorithm :
1. Initialize start of dp_array with nums[0].
2. From index 1, check if you can get to this index. If yes, set to max(nums[index-1]-1 , nums[index]). If not, set to -1.
-> max() is needed since it might be more benefitial to reach further with previous elements rather than with current element.
3. Check dp_array[nums.size()-1]. If -1, the end is not reachable. If anything else, it is reachable.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp_array;
        dp_array.push_back(nums[0]);
        for (int index = 1; index < nums.size(); index++){
            if (dp_array[index - 1] <= 0) dp_array.push_back(-1);
            else dp_array.push_back(max(nums[index], dp_array[index - 1] - 1));
        }
        if (dp_array[nums.size()-1] == -1) return false;
        else return true;
    }
};