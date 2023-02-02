/* 
Question link : https://leetcode.com/problems/find-the-difference/

Runtime : 9 ms
Beats : 13.35 %
Memory : 6.9 MB
Beats : 11.21 %

Time Complexity : O(n)
-> n for map construction
-> n for scan
-> but probably takes more considering unordered_map operations are best case O(1).
Space Complexity : O(n)
-> 2n for input
-> n for unordered map
-> 1 for i

Algorithm :
1. Insert s into unordered map.
2. Scan t and find if the char is in unordered map.
-> If not found or all exhausted, return char.
-> If found, decrement number.
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> s_map;
        // map construction
        for (int i = 0; i < s.size(); i++){
            if (s_map.find(s[i]) == s_map.end()) s_map[s[i]] = 1;
            else s_map[s[i]]++;
        }
        // find different char
        for (int i = 0; i < t.size(); i++){
            if (s_map.find(t[i]) == s_map.end() || s_map[t[i]] == 0) return t[i];
            else s_map[t[i]]--;
        }
        return 'c';
    }
};