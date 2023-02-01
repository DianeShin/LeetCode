/* 
Question link : https://leetcode.com/problems/valid-perfect-square/

Runtime : 0 ms
Beats : 100 %
Memory : 6 MB
Beats : 48.37 %

Time Complexity : O(log n)
-> binary search from 1 to num

Space Complexity : O(1)
-> 2 for input, i

Logic :
1. You can set the range to num/2 since sqrt(num) is way smaller than num/2
-> but have to be careful for 1.

Algorithm :
1. if n is 1, return true
2. if not, perform binary search from 1 to num/2.

Point :
1. log grows slower than sqrt.
3. Be careful of overflow.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int start = 1, end = num/2;
        while (start <= end){
            long long middle = (start + end)/2;
            if (middle * middle > num) end = middle -1;
            else if (middle * middle < num) start = middle + 1;
            else return true;
        }
        return false;
    }
};