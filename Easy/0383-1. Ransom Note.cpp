/* 
Question link : https://leetcode.com/problems/ransom-note/

Runtime : 59 ms
Beats : 11.53 %
Memory : 8.8 MB
Beats : 76.39 %

Time Complexity : O(n^2)
-> 2nlogn for ransomNote, magazine sort
-> 2n^2 for ransomNote, magazine scan and erase

Space Complexity : O(n)
-> 2n for input
-> 2 for iterator

Algorithm :
1. Sort both input string.
2. If *ransomNote_iter > *magazine_iter, this means the magazine_iter needs to skip unused early letters, so increment magazine_iter.
3. If *ransomNote_iter < *magazine_iter, this means the needed character for ransomNote doesn't exist in magazine, so return false.
4. If *ransomNote_iter == *magazine_iter, this means the needed character exists in magazine, so use character and erase from both.

Point :
1. vector erase is expensive since it has to shift all elements.
*/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        string::iterator ransomNote_iter = ransomNote.begin();
        string::iterator magazine_iter = magazine.begin();
        while (ransomNote_iter != ransomNote.end() && magazine_iter != magazine.end()){
            if (*ransomNote_iter < *magazine_iter) return false;
            else if (*ransomNote_iter > *magazine_iter) magazine_iter++;
            else{
                ransomNote_iter = ransomNote.erase(ransomNote_iter);
                magazine_iter = magazine.erase(magazine_iter);
            }
        }
        return ransomNote.empty();
    }
};