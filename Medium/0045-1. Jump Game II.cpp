/* 
Question link : https://leetcode.com/problems/jump-game-ii/

Runtime : 1429 ms
Beats : 5 %
Memory : 17.3 MB
Beats : 25.63 %

Time Complexity : O(n^2)
-> while filling dp aray, scan happens for 1 + 2 + ... + n : O(n^2)

Space Complexity : O(n)
-> n for nums vector
-> n for dp array
-> 1 for index, past_index

Logic:
We have a dp array. dp[i] will indicate min jump until ith node.
To calculate dp[i], we can do min (dp[i], dp[k] + 1) if it's possible to jump from kth node.
-> check this for all node k when k < i.

Algorithm :
1. Initialize dp vector with INT_MAX, which means it needs infinite jumps to reach.
2. Set dp[0] = 0, since it doesn't need any previous jumps to reach 0th node.
3. From index 1, update dp[index]. This is done by scanning nodes left to index(past_index). If it's reachable from the past_index and takes less jumps than the past method, we update dp[index].
4. Return result, which is dp[nums.size()-1], minimal # of jumps to get to node nums.size()-1. 

*/

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // initialize dp array
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        // fill dp array
        for (int index = 1; index < nums.size(); index++){
            for (int past_index = 0; past_index < index; past_index++){
                if (past_index + nums[past_index] >= index){
                    if (dp[index] > 1 + dp[past_index]) dp[index] = 1 + dp[past_index];
                }
            }
        }

        // return result
        return dp[nums.size()-1];
    }
};