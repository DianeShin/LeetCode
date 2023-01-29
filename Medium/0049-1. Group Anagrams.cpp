/* 
Question link : https://leetcode.com/problems/rotate-image/

Runtime : 43 ms
Beats : 64.21 %
Memory : 20.6 MB
Beats : 59.63 %

Time Complexity : O(k*log k * n)
-> for each word(let's say length is k), need to sort(k*log k)
-> collecting the results take shorter time.

Space Complexity : O(n)
-> worst case, umap needs to save all words separately, consuming 2n space.
-> result contains n words.

Algorithm : anagrams return same result when sorted.
1. for each word, sort.
2. If sorted word in map, add word into vector.
3. If not, create new vector
4. After loop, collect vectors.
*/

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> umap;

        // create map of anagrams
        for (int i = 0; i < strs.size(); i++){
            string curr_string = strs[i];
            sort(curr_string.begin(), curr_string.end());
            if (umap.find(curr_string) == umap.end()) umap[curr_string] = {strs[i]};
            else umap[curr_string].push_back(strs[i]);
        }

        // create result
        for (auto key_value : umap){
            result.push_back(key_value.second);
        }

        return result;
    }
};