/* 
Question link : https://leetcode.com/problems/isomorphic-strings/

Runtime : 3 ms
Beats : 96.70%
Memory : 6.9 MB
Beats : 92.74%

Time Complexity : O(n)
-> Unordered map is implemented with a hash map, which makes the 'find' operation on average O(1). This find is done for every element. Additional operations such as inserting or returning false is also O(1), so searching for s -> t is O(n).
-> This search is done twice, which makes the conclusion of O(n).

Space Complexity : O(n)
-> there are 2 input strings, which consume 2*n of space.
-> Space complexity of map is technically O(n), and we need one of this.
-> We need O(1) to store iterator
-> in conclusion, the space complexity is O(n).

Algorithm :
1. Find <s[i], t[i]> pair
2. If pair doesn't exist in unordered map, insert pair.
3. If pair exists but the binding is done with different value, return false.
4. do the check with both s-> t and t -> s.
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_t_mapping;
        for(int i = 0; i < s.length(); i++){
            unordered_map<char, char>::iterator pair_finding = s_t_mapping.find(s[i]);
            if (pair_finding== s_t_mapping.end()) s_t_mapping[s[i]] = t[i];
            else if (pair_finding -> second != t[i]) return false;
        }
        s_t_mapping.clear();

        for(int i = 0; i < t.length(); i++){
            unordered_map<char, char>::iterator pair_finding = s_t_mapping.find(t[i]);
            if (pair_finding == s_t_mapping.end()) s_t_mapping[t[i]] = s[i];
            else if (pair_finding -> second != s[i]) return false;
        }
        return true;
    }
};