/* 
Question link : https://leetcode.com/problems/word-pattern/

Runtime : 0 ms
Beats : 100 %
Memory : 6.3 MB
Beats : 86.20 %

Time Complexity : O(n)
-> evaluation done for n times when n is min(# of pattern, # of word)(excess is ignored)

Space Complexity : O(n)
-> n for umap, n for reversed_umap, n for pattern, n for s
-> 5 for delimiter, word, i, pos, search

Algorithm :
1. Extract word. If this fails, it means there are more patterns than words, so return false.
2. Check map if word already exists.
3. If it does, check if value matches. If it does, continue. If it doesn't, return false.
4. If it doesn't, push key-value into map.
5. Do this for both pattern-s umap and s-pattern umap
6. After loop, if there are words left in s, it means there are more words than pattern, so return false.
7. If not, return true.
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap;
        unordered_map<string, char> reverse_umap;

        string delimiter = " ";
        string word;
        for (int i = 0; i < pattern.size(); i++){
            // find delimiter position
            size_t pos = s.find(delimiter);

            // extract word
            // remove word + delimiter
            if (pos == string::npos){
                word = s;
                s = "";
            } 
            else{
                word = s.substr(0, pos);
                s.erase(0, pos + 1);
            }
            
            // if larger pattern than number of words
            if (word == "") return false;

            // find value for key
            unordered_map<char, string>::iterator search = umap.find(pattern[i]);
            unordered_map<string, char>::iterator reverse_search = reverse_umap.find(word);

            // 1. pattern -> s
            // key doesn't exist
            if (search == umap.end()){
                umap[pattern[i]] = word;
            } 
            // key exists , and pattern matches
            else if (search -> second == word) continue;
            // key exists, and pattern doesn't match
            else return false;

            // 2. s -> pattern
            // key doesn't exist
            if (reverse_search == reverse_umap.end()){
                reverse_umap[word] = pattern[i];
            } 
            // key exists, and pattern matches
            else if (reverse_search -> second == pattern[i]) continue;
            // key exists, and pattern doesn't match
            else return false;            
        }

        // if larger words than pattern
        if (s.size() != 0) return false;
        else return true;
    }
};