/* 
Question link : https://leetcode.com/problems/find-the-difference/

Runtime : 5 ms
Beats : 47.67 %
Memory : 6.6 MB
Beats : 91.44 %

Time Complexity : O(n)
-> 2n for s, t scan and addition

Space Complexity : O(n)
-> 2n for input
-> 1 for i

Logic :
char is just ints. When 2 strings have exactly 1 char different, which means the difference of s_sum and t_sum would be the different char.

Algorithm :
1. Use a loop and calculate t[i+1] += t[i] - s[i]
-> This gives an effect of adding all t_chars and subtracting all s_chars without using additional container.
2. Return the difference saved in the last element of t vector.
*/

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i = 0; i < s.size(); i++){
            t[i+1] += t[i] - s[i];
        }
        return t[t.size()-1];
    }
};