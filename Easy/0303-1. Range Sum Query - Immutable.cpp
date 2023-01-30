/* 
Question link : https://leetcode.com/problems/range-sum-query-immutable/

Runtime : 296 ms 
Beats : 26.9 %
Memory : 17.1 MB
Beats : 35.68 %

Time Complexity : O(n)
-> addition happens for size of range.

Space Complexity : O(n)
-> n for nums

Algorithm :
1. For class, create private num_array and save when constructor called.
2. For method, add numbers in range.
*/


#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> num_array;
public:
    NumArray(vector<int>& nums) {
        num_array = nums;
    }
    
    int sumRange(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; i++){
            result += num_array[i];
        }
        return result;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */