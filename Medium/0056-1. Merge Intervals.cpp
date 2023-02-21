/* 
Question link : https://leetcode.com/problems/merge-intervals/

Runtime : 34 ms
Beats : 93.73 %
Memory : 19.2 MB
Beats : 51.31 %

Time Complexity : O(nlogn)
-> nlogn for intervals sort
-> n for intervals scan

Space Complexity : O(n)
-> n each for intervals, result
-> 1 each for interval_index, result_index, result_left_bigger_than_interval_left, result_right_bigger_than_interval_right, result_right_bigger_than_interval_left

Algorithm :
1. Sort intervals and push_back first element into result.
2. Now that it's sorted, we are guaranteed that overlapping only happens with the last element in result vector. There are 3 possible situations
1) If result contains the intervals interval. There is nothing to do in this case.
2) If result's right side overlaps with intervals's left side. Then, we need to update result's right end with intervals's right end.
3) If nothing above, intervals don't have an overlap with result. Then we just push_back to result.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for (int intervals_index = 1; intervals_index < intervals.size(); intervals_index++){
            // positive if bigger, 0 if same, negative if smaller
            int result_left_bigger_than_interval_left = result[result.size()-1][0] - intervals[intervals_index][0];
            int result_right_bigger_than_interval_right = result[result.size()-1][1] - intervals[intervals_index][1];
            int result_right_bigger_than_interval_left = result[result.size()-1][1] - intervals[intervals_index][0];
            // result includes interval
            // result left is smaller or same than interval left
            // result right is bigger or same than interval right
            // do nothing
            if (result_left_bigger_than_interval_left <= 0 && result_right_bigger_than_interval_right >= 0){
                continue;
            }

            // result then interval
            // result left is smaller or same than interval left
            // result right is bigger or same than interval left
            // need to update result right with interval right
            else if (result_left_bigger_than_interval_left <= 0 && result_right_bigger_than_interval_left >= 0){
                result[result.size()-1][1] = intervals[intervals_index][1];
            }

            // there is no relationship with any of the intervals inside result
            else{
                result.push_back(intervals[intervals_index]); 
            }
        }
        return result;
    }
};