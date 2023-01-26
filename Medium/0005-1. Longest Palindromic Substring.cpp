/* 
Question link : https://leetcode.com/problems/word-pattern/

Runtime : 256 ms
Beats : 29.9 %
Memory : 7 MB
Beats : 75.36 %

Time Complexity : O(n^3)
-> there are 1 + 2 + ... + n number of substrings.
-> for each substring, every character in substring is accessed.
-> This gives a compexity of O(n^3).

Space Complexity : O(n)
-> n for input string
-> 3 for result, i, p.

Algorithm :
1. Create possible substrings from the longest ones.
2. Check palindrome for every string.
*/


#include <string>

using namespace std;

class Solution {
public:
    bool checkPalindrome(string::iterator start_iter, string::iterator end_iter){
        while (start_iter < end_iter){
            if (*start_iter++ != *end_iter--) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string result = s.substr(0 , 1);
        for (int i = s.length() - 1; i > 0; i--){
            for (int p = 0; p < s.length() - i; p++)
            if(checkPalindrome(s.begin() + p , s.begin() + p + i)){
                return s.substr(p, i+1);
            }
        }
        return result;
    }
};