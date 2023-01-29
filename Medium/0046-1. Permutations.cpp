/* 
Question link : https://leetcode.com/problems/permutations/

Runtime : 8 ms
Beats : 24.39 %
Memory : 8.1 MB
Beats : 32.99 %

Time Complexity : O(n^3)
-> You need 1 + 2 + ... + n insert operations
-> insert operation is O(n) in average

Space Complexity : O(n * n!)
-> n for nums
-> n * n! for result : there are n! number of permutations, and each permutation contains n elements.
-> n for curr_vector
-> 4 for num, result_size, vector_elem, vector_size, 

Algorithm : insert elem one by one 
1. Put first element in vector and insert into result.
2. From second element, insert number in every possible position and push into result vector, then remove altered vector.
3. Repeat until nums is exhausted.

Point :
1. Be very careful when the for condition contains variable. For example, if the condition is vector.size() and the loop modifies the vector, you should save the size before entering loop.
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({nums[0]});
        for (int num = 1; num < nums.size(); num++){
            int result_size = result.size();
            for (int vector_elem = 0; vector_elem < result_size; vector_elem++){
                vector<int> curr_vector = result[0];
                for (int vector_size = 0; vector_size <= curr_vector.size(); vector_size++){
                    vector<int> new_vector = curr_vector;
                    new_vector.insert(new_vector.begin() + vector_size, nums[num]);
                    result.push_back(new_vector);
                }
                result.erase(result.begin());
            }
        }
        return result;
    }
};