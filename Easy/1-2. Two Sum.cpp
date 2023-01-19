/* 
Question link : https://leetcode.com/problems/two-sum/

Runtime : 8 ms
Beats : 97.66%
Memory : 10.3 MB
Beats : 73.71%

Time Complexity : O(n)
-> each number is visited at most once, or one number getting visited again if there is no answer.
Space Complexity : O(n)
-> n for vector input
-> n for sorted input

Algorithm :
1. Sort input vector.
2. Using an iterator, find the elements that sum to target. This is done by comparing the target and the sum of current iterator values. If sum is too big, we shift right iterator to decrease the value. If sum is too small, we shit left iterator to increase the value.
3. Once values found, find the index from the original input vector.
4. Push the indexes into return vector, then sort since the order of two indexes can be flipped.
*/

#include <vector>
#include <algorithm> 
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // init sorted input vector
        vector<int> sorted_nums = nums;

        // init result vector
        vector<int> result;

        // sort input vector
        sort(sorted_nums.begin(), sorted_nums.end());

        // define 2 iterators from beginning and end
        vector<int>::iterator start_iterator = sorted_nums.begin();
        vector<int>::iterator end_iterator = sorted_nums.end() - 1;

        // search result
        // if two iterators merge, it means there is no answer(should not happen unless wrong input)
        while(start_iterator < end_iterator){
            // calculate sum of iterator values
            int temp_result = *start_iterator + *end_iterator;
            // result found
            if (temp_result == target){
                break;
            }
            // if sum is big, move end iterator to left to decrease value
            else if (temp_result > target){
                end_iterator--;
            }
            // if sum is small, move start iterator to right to increase value
            else{
                start_iterator++;
            }
        }

    // define iterator of result values in original vector
    vector<int>::iterator result1;
    vector<int>::reverse_iterator result2;
        
    // search for iterator that points to result value in original vector
    // need to find from left and right since it might hold same values and point to same element
    result1 = find(nums.begin(), nums.end(), *start_iterator);
    result2 = find(nums.rbegin(), nums.rend(), *end_iterator);
    
    // push result
    result.push_back(result1 - nums.begin());
    result.push_back(nums.rend() - result2 -1);

    // sort since smaller value has to come first
    sort(result.begin(), result.end());
    
    // return result
    return result;
    }
};