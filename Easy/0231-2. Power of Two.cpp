/* 
Question link : https://leetcode.com/problems/power-of-two/

Runtime : 0 ms
Beats : 100%
Memory :5.9 MB
Beats : 56.59%

Time Complexity : O(log n)
-> when input is close to 2^k, need to divide k times.

Space Complexity : O(1)
-> 1 for input

Algorithm :
1. If 'n <= 0', return false(unrepresentable with power of 2)
2. Else, divide by 2 until remainder is not 0(n being odd).
3. If n is 1, return true. Else, return false.

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0){
            n /= 2;
        }
        return n == 1;
    }
};