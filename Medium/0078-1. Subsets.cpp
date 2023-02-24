/* 
Question link : https://leetcode.com/problems/subsets/

Runtime : 5 ms
Beats : 38.62 %
Memory : 7 MB
Beats : 88.46 %

Time Complexity : O(2^n)
-> Insertion happens 1, 2, 4, ..., 2^(n-1) times during the algorithm
-> total time consumption is the sum of geometric sequence.

Space Complexity : O(n) for input, O(n) for algorithm, O(n^2) for output
-> n for nums
-> n^2 for result
-> 1 each for index, size, result_index
-> n for new_vector

Logic :
The elements already inside result vector can be considered as the subsets that doesn't contain nums[index]
-> we need to copy vector, push_back nums[index] into copied vector, then push_back this vector into result 

Algorithm :
1. Initialize result vector as a vector with 1 element which is an empty vector.
2. For every element in nums, iterate through result vector, insert the element, and push_back into result.
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1, vector<int>());
        for (int index = 0; index < nums.size(); index++){
            int size = result.size();
            for (int result_index = 0; result_index < size; result_index++){
                vector<int> new_vector(result[result_index]);
                new_vector.push_back(nums[index]);
                result.push_back(new_vector);
            }
        }
        return result;
    }
};