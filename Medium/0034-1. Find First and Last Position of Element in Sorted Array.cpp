/* 
Question link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Runtime : 14 ms
Beats : 33.23 %
Memory : 13.5 MB
Beats : 87.9 %

Time Complexity : O(log n)
-> 2 binary searches performed

Space Complexity : O(n)
-> n for nums
-> 5 for target, start, end, left, right

Algorithm :
1. Set init left, right index as -1(in case not found)
2. Perform binary search for both index. 
-> When found, search if there is the target more on the left/right.
-> When not found, change the range to left/right.

Point :
1. You can define a vector with {elem1, elem2...}
*/


#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        vector<int> result;
        int left = -1, right = -1;
        // find start
        while (start <= end){
            int middle = start + (end - start)/2;
            if (nums[middle] == target){
                left = middle;
                end = middle - 1;
            } 
            else if (nums[middle] < target) start = middle + 1;
            else end = middle -1; 
        }

        // find end
        start = 0;
        end = nums.size()-1;
        while (start <= end){
            int middle = start + (end - start)/2;
            if (nums[middle] == target){
                right = middle;
                start = middle + 1;
            } 
            else if (nums[middle] < target) start = middle + 1;
            else end = middle -1; 
        }

        // return result
        return {left, right};
    }
};