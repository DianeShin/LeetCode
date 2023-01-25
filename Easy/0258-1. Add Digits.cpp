/* 
Question link : https://leetcode.com/problems/add-digits/

Runtime : 4 ms
Beats : 28.82%
Memory : 6 MB
Beats : 8.41%

Time Complexity : hard to tell
-> must need digit_number of calculations
-> additional calculations depend on length and valeus.

Space Complexity : O(1)
-> 2 for input and result

Algorithm :
1. Add digits of num.
2. If result is bigger than 10, put result to num and recalculate until it's smaller than 10.
*/


class Solution {
public:
    int addDigits(int num) {
        int result;
        while (true){
            // add digits of num
            while (num > 0){
                result += num % 10;
                num /= 10;
            }

            // if result is multiple digits, put result to num and recalculate
            if (result >= 10){
                num = result;
                result = 0;
            }    
            else break;        
        }
        return result;
    }
};