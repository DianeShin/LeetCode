/* 
Question link : https://leetcode.com/problems/reverse-vowels-of-a-string/

Runtime : 7 ms
Beats : 79.8 %
Memory : 8.8 MB
Beats : 6.12 %

Time Complexity : O(n)
-> n for vowel scan
-> n for result construction

Space Complexity : O(n)
-> n for input string
-> n for vowel_stack
-> n for result

Algorithm :
1. Scan the string and save vowels in stack.
2. Rescan the string. When consonant, push_back into result. If not, pop from stack(LIFO) and push_back.
*/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vowel_stack;
        string result;

        for (string::iterator string_iter = s.begin(); string_iter != s.end(); string_iter++){
            if (*string_iter == 'a' || *string_iter == 'e' || *string_iter == 'i' || *string_iter == 'o' || *string_iter == 'u' || *string_iter == 'A' || *string_iter == 'E' || *string_iter == 'I' || *string_iter == 'O' || *string_iter == 'U') vowel_stack.push(*string_iter);
        }
        for (string::iterator string_iter = s.begin(); string_iter != s.end(); string_iter++){
            if (*string_iter == 'a' || *string_iter == 'e' || *string_iter == 'i' || *string_iter == 'o' || *string_iter == 'u' || *string_iter == 'A' || *string_iter == 'E' || *string_iter == 'I' || *string_iter == 'O' || *string_iter == 'U'){
                result.push_back(vowel_stack.top());
                vowel_stack.pop();
            } 
            else{
                result.push_back(*string_iter);
            }
        }    
        return result;    
    }
};