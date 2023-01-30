/* 
Question link : https://leetcode.com/problems/range-sum-query-immutable/

Runtime : 25 ms 
Beats : 78.65 %
Memory : 17.2 MB
Beats : 7.47 %

Time Complexity : O(n) for init, O(1) for method
-> init needs an operation for each element.
-> method needs only max 2 calls from vector.

Space Complexity : O(n)
-> n for range_sum
-> 3 for i, left, right

Algorithm :
<Class>
2. Push_back nums[0] in range_nums.
3. Push_back sum of previous range_nums and nums[i]. This adding method saves time for init.
2. For method, add numbers in range.
<Method>
1. If start of range is 0, just return range_nums[right].
2. If not, return range_nums[right] - range_nums[left-1]. Important to use [left-1] since nums[left] is inclusive.

Point :
1. It's good to think about a method to prevent same work being done multiple times!
*/



#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> range_sum;
public:
    NumArray(vector<int>& nums) {
        range_sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            range_sum.push_back(range_sum[i-1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return range_sum[right];
        else return range_sum[right] - range_sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */