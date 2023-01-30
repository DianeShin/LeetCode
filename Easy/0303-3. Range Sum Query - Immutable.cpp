/* 
Question link : https://leetcode.com/problems/range-sum-query-immutable/

Runtime : 23 ms 
Beats : 87.3 %
Memory : 17.3 MB
Beats : 7.47 %

Time Complexity : O(n) for init, O(1) for method
-> init needs an operation for each element.
-> method needs only max 2 calls from vector.

Space Complexity : O(n)
-> n for num_array
-> n for range_sum
-> 3 for i, left, right

Algorithm :
<Class>
1. Save nums from reference.
2. Push_back num_array[0] in range_nums.
3. Push_back sum of previous range_nums and num_array[i]. This adding method saves time for init.
2. For method, add numbers in range.
<Method>
1. If start of range is 0, just return range_nums[right].
2. If not, return range_nums[right] - range_nums[left-1]. Important to use [left-1] since nums[left] is inclusive.

Point :
1. Pass by reference is expensive since the compiler reloads everytime rather than saving the reference. It is cheaper to copy the value from reference if possible.
-> But this also takes more memory, so need to choose the right method depending on situation.
*/


#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> num_array;
    vector<int> range_sum;
public:
    NumArray(vector<int>& nums) {
        num_array = nums;
        range_sum.push_back(num_array[0]);
        for (int i = 1; i < num_array.size(); i++){
            range_sum.push_back(range_sum[i-1] + num_array[i]);
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