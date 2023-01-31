/* 
Question link : https://leetcode.com/problems/intersection-of-two-arrays/

Runtime : 7 ms
Beats : 71.34 %
Memory : 11.1 MB
Beats : 6.33 %

Time Complexity : O(nlogn)
-> 2n for set construction
-> 2nlogn for 2 set sorts
-> 2n for vector construction
-> 2n for intersection search

Space Complexity : O(n)
-> 2n for input vector
-> 2n for set
-> 2n for set -> vector
-> 2 for iterators
-> n for result vector

Algorithm :
1. Convert input vector to set and sort, then convert back to vector

Point:
1. set<int> s(vector.begin(), vector.end()) converts vector to set.
2. Items in set is immutable -> sorting is not possible.
*/

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1_set(nums1.begin(), nums1.end());
        set<int> nums2_set(nums2.begin(), nums2.end());
        vector<int> nums1_set_vector(nums1_set.begin(), nums1_set.end());
        vector<int> nums2_set_vector(nums2_set.begin(), nums2_set.end());
        sort(nums1_set_vector.begin(), nums1_set_vector.end());
        sort(nums1_set_vector.begin(), nums1_set_vector.end());

        vector<int> result;
        vector<int>::iterator nums1_iterator = nums1_set_vector.begin();
        vector<int>::iterator nums2_iterator = nums2_set_vector.begin();
        while(nums1_iterator != nums1_set_vector.end() && nums2_iterator != nums2_set_vector.end()){
            if (*nums1_iterator < *nums2_iterator) nums1_iterator++;
            else if (*nums1_iterator > *nums2_iterator) nums2_iterator++;
            else{
                result.push_back(*nums1_iterator);
                nums1_iterator++;
                nums2_iterator++;
            }
        }
        return result;
    }
};