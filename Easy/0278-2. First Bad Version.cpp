/* 
Question link : https://leetcode.com/problems/first-bad-version/

Runtime : 5 ms
Beats : 9.31 %
Memory : 6 MB
Beats : 7.23 %

Time Complexity : O(log n)
-> binary search, just any search only finishes when 'start == end', so it will always need log n searches.

Space Complexity : O(1)
-> 4 for input, start, end, middle

Algorithm :
1. set start, middle, end digit.
2. Perform binary search until start == end. This gives an effect of finding the first bad version.
3. Return either start or end.

Point :
1. To prevent overflow from (start + end)/2, do start + (end - start)/2.
2. When resetting the start/end value, need to be careful that the range always contains a bad version.
-> When isBadVersion(middle) is true, end = middle (not end = middle - 1)
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while (start < end){
            // overflow control
            int middle = start + (end - start)/2;
            // not middle - 1 since this middle can be the first bad version and make the left range only filled with not bad ones.
            if (isBadVersion(middle)) end = middle;
            else start = middle + 1;
        }
        return start;
    }
};