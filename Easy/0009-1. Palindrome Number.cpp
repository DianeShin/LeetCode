/* 
Question link : https://leetcode.com/problems/palindrome-number/

Runtime : 4 ms
Beats : 98.27%
Memory : 5.9 MB
Beats : 82.86%

Time Complexity : O(n)
-> n/2 sized loop
-> linear operations inside

Space Complexity : O(n)
-> 1 for input int
-> n for string-converted int
-> 2 for iterators

Algorithm :
1. Convert int to string.
2. Using two iterators starting from front and back, we check if they are equal.
3. Stop if the two iterators point the same char, this means the input is palindrome.
*/

#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string input_string = to_string(x);
        string::iterator start_iterator = input_string.begin();
        string::iterator end_iterator = input_string.end() -1;

        while(start_iterator < end_iterator){
            if (*start_iterator == *end_iterator){
                start_iterator++;
                end_iterator--;
            }
            else{
                return false;
            }
        }   
        return true;     
    }

};