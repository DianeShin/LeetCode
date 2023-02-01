/* 
Question link : https://leetcode.com/problems/guess-number-higher-or-lower/

Runtime : 2940 ms
Beats : 5.73 %
Memory : 6 MB
Beats : 52.51 %

Time Complexity : O(n)
-> potentially need to scan n/2 numbers

Space Complexity : O(1)
-> 2 for input, answer

Algorithm :
1. Set init answer to n/2.
2. If value too big, decrement.
3. If value too small, increment.

*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int answer = n/2;
        while (true){
            if (guess(answer) == -1) answer--;
            else if (guess(answer) == 1) answer++;
            else break;
        }
        return answer;
    }
};