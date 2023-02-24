/* 
Question link : https://leetcode.com/problems/sort-colors/

Runtime : 3 ms
Beats : 55.50 %
Memory : 8.4 MB
Beats : 31.13 %

Time Complexity : O(n)
-> n each for nums scan and value filling

Space Complexity : O(n) for input, O(1) for algorithm
-> n for nums
-> 1 each for red, blue, white, index

Algorithm :
1. Scan through nums and count number of 0/1/2.
2. From 0, fill nums until exhausted. Then 1 then 2.
*/

#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (int index = 0; index < nums.size(); index++){
            if (nums[index] == 0) red++;
            else if (nums[index] == 1) white++;
            else blue++;
        }
        for (int index = 0; index < nums.size(); index++){
            if (red != 0){
                nums[index] = 0;
                red--;
            }
            else if (white != 0){
                nums[index] = 1;
                white--;
            }
            else nums[index] = 2;
        }
    }
};