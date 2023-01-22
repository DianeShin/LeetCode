/* 
Question link : https://leetcode.com/problems/contains-duplicate-ii/

Time limit exceeded

Time Complexity : O(k*n)
-> for each starting point, you evaluate for max k times.(1 gap, 2 gap ... k gap)

Space Complexity : O(n)
-> n for vector input
-> 3 for k,start,end

Algorithm :
1. set the start index.
2. The end index can set from 1 gap to k gaps
3. if the end index exceeds the input size, break the inner loop.
4. If not, check if the values are same, and return true if it is same.
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int start = 0; start < nums.size()-1; start++){
            for (int end = start + 1; end < start + k + 1; end++){
                if (end > nums.size() -1) break;
                if (nums[start] == nums[end]) return true;
            }
        }
        return false;
    }
};