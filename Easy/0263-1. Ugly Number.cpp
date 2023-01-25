/* 
Question link : https://leetcode.com/problems/ugly-number/

Runtime : 8 ms
Beats : 7.97 %
Memory : 5.8 MB
Beats : 94.14 %

Time Complexity : O(log n)
-> worst case, num = 2^k that requires log n time calculation
-> better case, other factors are included that the calculation is done faster

Space Complexity : O(1)
-> 1 for input

Algorithm :
1. Divide number with 2, 3, 5 until they can't divide num wo/ remainder.
2. Check if resulting number is 1.
*/

class Solution {
public:
    bool isUgly(int n) {
        while (n % 2 == 0){
            n /= 2;
        }
        while (n % 3 == 0){
            n /= 3;
        }
        while (n % 5 == 0){
            n /= 5;
        }
        return n == 1;
    }
};