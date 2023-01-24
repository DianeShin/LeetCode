/* 
Question link : https://leetcode.com/problems/summary-ranges/

Runtime : 0 ms
Beats : 100%
Memory :6.7 MB
Beats : 100%

Time Complexity : O(n)
-> Each number is generally evaluated once, twice if the range cuts, and need to check if there are multiple or only one element in range.

Space Complexity : O(n)
-> n for input nums vector
-> max 2n for result(if range paired, needing "->" for every pair)
-> 2 for start, i

Algorithm :
1. Define result vector, and set start as 1st element.
2. If current element is continuous from the previous one, continue.
3. If not, check if range has 1 element.
4. If one, push_back element value.
5. If multiple, push_back range.
6. After the loop, push the last range.

Point :
1. When we check if the next element is continuous, 'nums[i] - nums[i-1] == 1' can make integer overflow if nums[i] == INT_MAX and nums[i-1] = INT_MIN. Use 'nums[i-1] + 1 == nums[i]' instead. Integer overflow never happens since it can only happen when nums[i-1] == INT_MAX, but then nums[i] cannot exist.
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // define result vector
        vector<string> result;

        // only run algorithm if nums is not empty.
        if (nums.size() != 0){
            // define range start
            int start = nums[0];
            
            for (int i = 1; i < nums.size(); i++){
                if (nums[i] - nums[i-1] == 1) continue;
                else if (nums[i-1] == start){
                    // range with only 1 number
                    result.push_back(to_string(start));
                    // set new start value
                    start = nums[i];                
                }
                else{
                    // range of start -> i-1
                    result.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                    // set new start value
                    start = nums[i]; 
                }
            }
            // add last range
            if (nums[nums.size()-1] == start) result.push_back(to_string(start));
            else result.push_back(to_string(start) + "->" + to_string(nums[nums.size()-1]));

        }

        // return result
        return result;
    }
};