/* 
Question link : https://leetcode.com/problems/valid-perfect-square/

Runtime : 3 ms
Beats : 45.97 %
Memory : 5.9 MB
Beats : 48.37 %

Time Complexity : O(sqrt(n))
-> evaluation done until sqrt(n) or just above.

Space Complexity : O(1)
-> 2 for input, i

Algorithm :
1. From 1 to 46340(sqrt of INT_MAX), check if i*i matches num.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= 46340; i++){
            if (i*i > num) return false;
            else if (i*i == num) return true;
        }
        return false;
    }
};