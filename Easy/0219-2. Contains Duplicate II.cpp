/* 
Question link : https://leetcode.com/problems/contains-duplicate-ii/

Runtime : 496 ms
Beats : 9.69%
Memory : 77.1 MB
Beats : 79.18%

Time Complexity : O(n)
-> each value is evaluated once.
-> map/other operations are linear

Space Complexity : O(n)
-> n for vector input
-> n for unordered map
-> 2 for i and iterator

Algorithm :
1. Define a map and traverse the vector.
2. If value doesn't exist in map, add in map as <value,index>
3. If value exists, check if the gap is less than k.
4. If it is less, return true. If not, update the index.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> value_index_map;
        for (int i = 0; i < nums.size(); i++){
            unordered_map<int,int>::iterator pair_finding = value_index_map.find(nums[i]);
            if (pair_finding == value_index_map.end()) value_index_map[nums[i]] = i;
            else{
                if (i - pair_finding -> second <= k) return true;
                else value_index_map[nums[i]] = i;
            }
        }
        return false;
    }
};