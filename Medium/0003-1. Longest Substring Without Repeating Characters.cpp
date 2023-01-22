/* 
Question link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

Runtime : 15 ms
Beats : 78.91%
Memory : 7 MB
Beats : 92.19%

Time Complexity : O(n^2)
-> worst case, need to compare every character pair(n-1 + n-2 + ... + 1)

Space Complexity : O(n)
-> n for input string
-> 4 for start, max_length, i , p

Algorithm :
1. The rightbound is set with i.
2. From start index, p increases until i-1.
3. if s[i] and s[p] is same, start point is updated.(since the substring starting from that start point is no longer valid)
-> each time p is updated, max_length is updated if it's longer than the max_length previously saved. 
4. If p hit end of string, reevaluate max_length.
*/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max_length = 0;
        
        for (int i = 1; i <= s.length(); i++){
            if (i == s.length()){
                max_length = max(max_length, i - start);
            }
            else{
                for (int p = start; p < i; p++){
                    max_length = max(max_length, i - start);
                    if (s[p] == s[i]){
                        start = p + 1;
                    }
                }                
            }

        }
        return max_length;
    }
};