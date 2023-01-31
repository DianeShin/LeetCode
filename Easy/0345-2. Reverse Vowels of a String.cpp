/* 
Question link : https://leetcode.com/problems/reverse-vowels-of-a-string/

Runtime : 8 ms
Beats : 64.87 %
Memory : 8.2 MB
Beats : 20.86 %

Time Complexity : O(n)
-> n for left to right scan
-> n for right to left scan

Space Complexity : O(n)
-> n for input string
-> n for result string
-> 2 for start and end iterator

Algorithm :
1. Set 2 iterators from start and end.
2. Whenever the start iterator points a vowel, the end iterator catches up to the next vowel and pushes into result.

*/

#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string result;
        string::reverse_iterator end = s.rbegin();

        for(string::iterator start = s.begin(); start != s.end(); start++){
            if (*start == 'a' || *start == 'e' || *start == 'i' || *start == 'o' || *start == 'u' || *start == 'A' || *start == 'E' || *start == 'I' || *start == 'O' || *start == 'U'){
                while (true){
                    if (*end == 'a' || *end == 'e' || *end == 'i' || *end == 'o' || *end == 'u' || *end == 'A' || *end == 'E' || *end == 'I' || *end == 'O' || *end == 'U'){
                        result.push_back(*end);
                        end++;
                        break;
                    }
                    else{
                        end++;
                    }
                }
            }
            else{
                result.push_back(*start);
            }
        }
        return result;
    }
};