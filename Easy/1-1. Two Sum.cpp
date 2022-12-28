/* 
Question link : https://leetcode.com/problems/two-sum/

Runtime : 465 ms 
Beats : 38.9%
Memory : 10.2 MB
Beats : 73.71%

Time Complexity : O(n^2)
-> 1 for vector init
-> n^2 for nested loop
-> 1 for return result

Space Complexity : O(n)
-> n for two vector input
-> 1 for target int
-> 2 for result vector
-> 2 for indexes

Algorithm :
1. From left, choose one element.
2. With a nested loop, choose the next element that's on the right side of left element.
3. Check if the sum of two elements equal to target.
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // init result vector
        vector<int> result;
        
        // loop to choose first element
        for (int first = 0; first < nums.size(); first++){
            // loop to choose second element
            for (int second = first + 1; second < nums.size(); second++){
                // check if sum equals to target
                if (nums[first] + nums[second] == target){
                    // push indexes into result, and push into result
                    result.push_back(first);
                    result.push_back(second);
                    return result;
                }
            }
        }
        // Return statement for syntax. Should not run unless wrong input.
        return result;    
    }
};