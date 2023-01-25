/* 
Question link : https://leetcode.com/problems/first-bad-version/

Time Limit Exceeded

Time Complexity : O(n)
-> need evaluation for every version until found.

Space Complexity : O(1)
-> 1 for input

Algorithm :
1. Check isBadVersion until found.
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        for (int i = 1; i <= n; i++){
            if (isBadVersion(i)) return i;
        }
    }
};