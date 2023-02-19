/* 
Question link : https://leetcode.com/problems/powx-n/

Time Limit Exceeded

Time Complexity : O(n)
-> need n times of multiplication

Space Complexity : O(1)
-> 1 each for double, n, result, n_long

Algorithm :
1. To save time, predefine result for n == 0 and x == 1.
2. If n is negative, divide result with x until n == 0, and increase n.
3. If n is postivie, multiply result with x until n == 0, and decrease n.
*/


class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        if (n == 0) return 1;
        else if (x == 1) return 1;
        else if (n < 0){
            while (n < 0){
                result /= x;
                n++;
            }
        }
        else{
            while (n > 0){
                result *= x;
                n--;
            }
        }
        return result;
    }
};