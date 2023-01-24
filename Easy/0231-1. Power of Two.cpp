/* 
Question link : https://leetcode.com/problems/power-of-two/

Runtime : 4 ms
Beats : 27.8%
Memory :5.9 MB
Beats : 56.59%

Time Complexity : O(1)
-> linear operation for comparison, bitwise and, bit flip.

Space Complexity : O(1)
-> 1 for input

Algorithm :
1. If 'n <= 0', return false(unrepresentable with power of 2)
2. Else, do bitwise AND with n-1. If power of 2, it will return all 1s. Flip the result and return.

Point :
1. If the integer is power of 2, there is only one 1 in binary representation
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        else return !(n & n-1);
    }
};