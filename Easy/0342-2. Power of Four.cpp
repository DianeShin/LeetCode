/* 
Question link : https://leetcode.com/problems/power-of-four/

Runtime : 0 ms
Beats : 100 %
Memory : 5.8 MB
Beats : 82.14 %

Time Complexity : O(1)
-> 1 calculation each for check

Space Complexity : O(1)
-> 1 for input

Algorithm :
1. n & n-1 is all 1s if n is even number and positive.
2. n-1 is divisible by 3 if n is 4k.

Why is 4^k-1 divisible by 3?
When k = 0 -> 3 is divisible by 3.
If 4^k-1 is divisible by 3,
4^(k+1)-1 = 4*4^k-1 = (3+1)4^k-1 = 3*4^k + 4^k-1 -> divisible by 3.

Point :
1. n & n-1 checks positivity too. However, integer overflow can happen from n-1, so n > 0 is needed first(short circuit evaluation)
2. (n-1) % 3 checks non-zero too. But same issue can happen from above.
*/


class Solution {
public:
    bool isPowerOfFour(int n) {
        // check positivity, check 2k, check n-1
        return (n > 0) && !(n & n-1) && ((n-1) % 3 == 0);
    }
};