/* 
Question link : https://leetcode.com/problems/word-pattern/

Runtime : 401 ms
Beats : 2.53 %
Memory : 22,7 MB
Beats : 35.39 %

Time Complexity : O(n^2)
-> need calculation for each combination(upper triangle in matrix) -> n^2/2
-> in 1 combination, only linear calculations are done(thx to dp).

Space Complexity : O(n) for input, O(n^2) for calculation, O(1) for output
-> n for input string
-> n^2 for dp matrix
-> 5 for start, substr_len, start_row_index, row, column

Algorithm :
1. Initialize dp matrix with false. dp[row][column] indicates if a substr starting at row and ending at column is palindrome.
2. Fill in array by moving diagonally, from left-top to right-down, towards right.
-> this is needed since dp[row+1][column-1] information is needed.
3. There are 3 situaitons when determining palindrome.
1) substr has 1 char. This is always palindrome.
2) substr has 2 char. This is palindrome if 2 chars are same.
3) substr has many chars. This is palindrome if first and end char is same, and the middle substr is palindrome(thx to dp, we don't need to calculate again.)
4) After update, if dp[row][column] == true, update substr info if this new substr is longer than others.
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j] tells if substring from i to j is palindrome
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int start = 0, substr_len = 1;

        // fill array
        // need special loop, need to fill upper triangle, diagonally, sticking to the longest diagonal, from top to down
        // this filling method will calculate dp[row+1][column-1] in advance, and also not miss any combination
        for (int start_row_index = 0; start_row_index < s.size(); start_row_index++){
            for (int row = 0, column = start_row_index; column < s.size(); row++, column++){
                // 1 char in substr -> isPalindrome
                if (row == column) dp[row][column] = true;
                
                // 2 char in substr -> isPalindrome if 2 chars are same
                else if (column - row == 1){
                    if (s[row] == s[column]) dp[row][column] = true;
                }

                // multiple char insubstr -> isPalindrome if start and end char is same, and middle substr isPalindrome
                else{
                    if (s[row] == s[column] && dp[row+1][column-1]) dp[row][column] = true;
                }

                // update substr if possible.
                if (dp[row][column] == true){
                    if (column - row + 1 > substr_len){
                        start = row;
                        substr_len = column - row + 1;
                    }
                }          
            }
        }
        return s.substr(start, substr_len);
    }
};