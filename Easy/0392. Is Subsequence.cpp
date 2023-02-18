/* 
Question link : https://leetcode.com/problems/is-subsequence/

Runtime : 0 ms
Beats : 100 %
Memory : 6.3 MB
Beats : 91.21 %

Time Complexity : O(n)
-> n each for s string and t string scan

Space Complexity : O(n)
-> n each for s string and t string
-> 1 each for s_index and t_index

Logic :
The order needs to be kept, so one scan of t with comparing chars in s and t is enough(if t is exhausted, return false).

Algorithm :
1. Define a variable to indicate index of t string.
2. Create a for loop with string s. 
3. Compare the char that s_index and t_index is pointing. If the char matches, move t_index to the next one(since current one is used) then break loop. If it doesn't, move t_index by 1 and recompare. If t is exhausted, return false.
4. If the for loop was successfully finished, return true.
*/

#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_index = 0;
        for (int s_index = 0; s_index < s.size(); s_index++){
            while (true){
                if (t_index == t.size()) return false;
                else if (s[s_index] == t[t_index]){
                    t_index++;
                    break;
                }
                else t_index++;
            }
        }
        return true;
    }
};