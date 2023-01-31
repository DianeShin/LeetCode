/* 
Question link : https://leetcode.com/problems/power-of-four/

Runtime : 0 ms
Beats : 100 %
Memory : 5.9 MB
Beats : 58.36 %

Time Complexity : O(log_4_k)
-> n = 4^k * smth -> need log_4_k ish calculations

Space Complexity : O(1)
-> 1 for input

Algorithm :
1. If 'n <= 0', return false(unrepresentable with power of 4)
2. Check if there is a remainder when divided by 4. Divide by 4 and repeat until remainder happens, or n <= 1.

*/


class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        else{
            while (n > 1){
                if (n%4 != 0) return false;
                n /= 4;
            }            
        }
        return true;
    }
};