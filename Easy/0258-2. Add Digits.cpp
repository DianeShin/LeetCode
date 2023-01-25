/* 
Question link : https://leetcode.com/problems/add-digits/

Runtime : 0 ms
Beats : 100%
Memory : 5.8 MB
Beats : 89.80 %

Time Complexity : O(1)
-> max 2 condition checks

Space Complexity : O(1)
-> 1 for input

Logic :
To check if a number is divisible by 9, we sum all the digits. The remainder doesn't change even though we continue this process multiple times. So it is enough to just return the remainder with the original num.

Algorithm :
1. If num == 0, return 0(needed since numbers divisable by 9 other than 0 needs to return 9)
2. If num % 9 == 0, return 9
3. Else, return num % 9
*/


class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        else if (num % 9 == 0)
            return 9;
        else
            return num % 9;
    }
};