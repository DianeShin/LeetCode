/* 
Question link : https://leetcode.com/problems/merge-intervals/

Runtime : 0 ms
Beats : 100 %
Memory : 5.9 MB
Beats : 88.99 %

Time Complexity : O(min(m,n))
-> Calculation is done in an efficient way, explained under, in Logic.

Space Complexity : O(1)
-> 1 each for m, n, result

Logic :
We have to choose the order of m-1 right moves and n-1 down moves. This is done by calculating (m-1 + n-1) C (m - 1). Calculation is done efficiently
-> (m-1 + n-1) C (m-1) = (m + n - 2)! /(m-1)!(n-1)! = (m + n - 2) * --- * m / (n-1)! = (m + n -2) * --- * n / (m-1)!
-> We decrement  m + n - 2 until max(m,n) which takes less calculations -> takes min(m,n) calculations

Algorithm :
1. Calculate (m-1 + n-1) C (m - 1) in an efficient way.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long answer = 1;
        for (int dividend = m + n - 2, divisor = 1; dividend >= max(m,n); dividend--, divisor++){
            answer = answer * dividend / divisor;
        }
        return answer;
    }
};