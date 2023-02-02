/* 
Question link : https://leetcode.com/problems/find-the-difference/

Runtime : 8 ms
Beats : 24.41 %
Memory : 6.8 MB
Beats : 31.54 %

Time Complexity : O(nlogn)
-> 2nlogn for s, t sort
-> 2n for s, tscan

Space Complexity : O(n)
-> 2n for input
-> 2 for iterator

Algorithm :
1. Sort both input string.
2. If s is exhausted(different char is the last char of t) or s_iter and t_iter holds different value, return *t_iter.
3. Else, both iterators move to the next character.
*/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        string::iterator s_iter = s.begin();
        string::iterator t_iter = t.begin();
        while(true){
            // s exhausted or different char appeared
            if (s_iter == s.end() || *s_iter != *t_iter) return *t_iter;
            // same char
            else{
                s_iter++;
                t_iter++;
            }
        }
        return 'c';
    }
};