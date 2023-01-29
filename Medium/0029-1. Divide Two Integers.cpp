/* 
Question link : https://leetcode.com/problems/divide-two-integers/

Runtime : 0 ms
Beats : 100 %
Memory : 5.9 MB
Beats : 58.32 %

Time Complexity : hard to tell
-> heavily depends on the dividend and divisor.

Space Complexity : O(1)
-> 7 for divisor, dividend, u_divisor, u_dividend, is_positive, quotient_portion, ans

Algorithm : bitwise shift
1. Save the sign and put dividend and divisor in unsigned int.
2. Find quotient_portion where 'u_divisor * 2 << quotient_portion' is about to exceed u_dividend.
3. Subtract 'u_divisor * 2 << quotient_portion' from u_dividend and add it to ans.
4. Continue until u_dividend is smaller than u_divisor. The leftover u_divisor is remainder.
5. Consider sign and return answer.

Point :
1. uint32_t : exactly 32 bits
2. unsigned int : depends on what compiler calls. Just needs to meet the requirement of representing [0, 65535]. Might represent with 16bit if 16bit processor(mem address is 16bit).
3. You cannot just put normal int into unsigned int, will return weird value. Use abs() for correct value.
4. abs() does not need a header!
5. multiplication > addition > bit shift > size comparison > logical comparison > assignment operation precedence.
6. Initialize int! There is no default value(while Java has default value of 0).
*/

#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        bool is_positive = dividend < 0 == divisor < 0;
        unsigned int u_dividend = abs(dividend);
        unsigned int u_divisor = abs(divisor);
        unsigned int ans = 0;

        while (u_dividend >= u_divisor){
            short quotient_portion = 0;
            while (u_dividend > (u_divisor << quotient_portion + 1)) quotient_portion++;
            ans += 1 << quotient_portion;
            u_dividend -= u_divisor << quotient_portion;
        }
        if (ans == 1 << 31 && is_positive) return INT_MAX;
        if (!is_positive) ans = -ans;
        return ans;
    }
};