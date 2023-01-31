/* 
Question link : https://leetcode.com/problems/reverse-vowels-of-a-string/

Runtime : 15 ms
Beats : 28.58 %
Memory : 8.7 MB
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

Point :
1. Creating a separate function increases code readability while it drops the performance.
*/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        else return false;
    }

    string reverseVowels(string s) {
        stack<char> vowel_stack;
        string result;

        for (string::iterator string_iter = s.begin(); string_iter != s.end(); string_iter++){
            if (isVowel(*string_iter)) vowel_stack.push(*string_iter);
        }
        for (string::iterator string_iter = s.begin(); string_iter != s.end(); string_iter++){
            if (isVowel(*string_iter)){
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