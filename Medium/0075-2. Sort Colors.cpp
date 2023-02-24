/* 
Question link : https://leetcode.com/problems/sort-colors/

Runtime : 3 ms
Beats : 55.59 %
Memory : 8.3 MB
Beats : 31.14 %

Time Complexity : O(n)
-> n for nums scan and swap

Space Complexity : O(n) for input, O(1) for algorithm
-> n for nums
-> 1 each for start, end, middle

Logic :
During a linear scan, we push 0s to start and 2s to end.

Algorithm :
1. Scan through nums. There are 3 possible scenarios
1) nums[middle] == 1 : The number is located in the right location, so move middle 1 step right.
2) nums[middle] == 0 : 0 needs to go to the left, so swap with nums[start]. Move start and middle both 1 step right.
3) nums[middle] == 2 : 2 needs to go to the right, so swap with nums[end]. Move end to left. Middle doesn't move since we don't know what the swapped number is, so we have to reevaluate the value in nums[middle].
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int middle = 0;
        while (middle <= end){
            if (nums[middle] == 0){
                swap(nums[start], nums[middle]);
                start++;
                middle++;
            }
            else if (nums[middle] == 1){
                middle++;
            }
            else{
                swap(nums[middle], nums[end]);
                end--;
            }            
        }

    }
};