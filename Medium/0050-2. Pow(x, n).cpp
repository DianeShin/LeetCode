/* 
Question link : https://leetcode.com/problems/powx-n/

Runtime : 0 ms
Beats : 100 %
Memory : 5.9 MB
Beats : 94.53 %

Time Complexity : O(log n)
-> 2^k = n, so k multiplications needed

Space Complexity : O(log k)
-> log k for recursion information
-> 1 each for x, n, result

Algorithm :
1. To save time, predefine result for n == 0 and x == 1.
2. When n is even, call myPow(x*x, n/2).
3. When n is odd and positive, call x * myPow(x*x, n/2). This is needed so that x is not lost during n/2.
4. When n is negative, call 1 / myPow(x, -n). This doesn't occur overflow since when n = INT_MIN, n is even so it is caught in the first if, sizing down the n.
*/

class Solution {
public:
    double myPow(double x, int n) {
        double result;
        if (x == 1 || n == 0) return 1;

        // even n, positive or negative
        if (n % 2 == 0) return myPow(x*x, n/2);

        // odd n, only positive
        else if (n % 2 == 1) return x * myPow(x*x, n/2);

        // odd n, only negative
        else return 1 / myPow(x, -n);
        // this works since INT_MIN -1 is even number, and will be managed by the first line.
    }
};