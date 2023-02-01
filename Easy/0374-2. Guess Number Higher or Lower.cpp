/* 
Question link : https://leetcode.com/problems/guess-number-higher-or-lower/

Runtime : 0 ms
Beats : 100 %
Memory : 5.9 MB
Beats : 52.51 %

Time Complexity : O(logn)
-> binary search

Space Complexity : O(1)
-> 5 for input, start, end, middle, answer

Algorithm :
1. Perform binary search until value found.

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
        int start = 1, end = n;
        int answer;
        while (true){
            int middle = start + (end - start)/2;
            if (guess(middle) == -1){
                end = middle -1;
            } 
            else if (guess(middle) == 1){
                start = middle + 1;
            }
            else{
                answer = middle;
                break;
            }
        }
        return answer;
    }
};