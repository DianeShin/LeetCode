/* 
Question link : https://leetcode.com/problems/generate-parentheses/

Runtime : 0 ms
Beats : 100 %
Memory : 8.1 MB
Beats : 94.7 %

Time Complexity : O((2nCn)/2 * 2n * n) = O(n^2*(2nCn))
-> The number of combinations w/ opening/closing bracket is 2nCn. However half of the combinations are impossible, since closing parentheses come earlier than opening parentheses. This makes 2nCn / 2 number of results.
-> The combinations are made by push_back of each bracket. There are 2n brackets per combination, so we need to multiply.
-> Everytime you push_back, you need to calculate the # of opening/closing bracket. This will take O(n) loop.

Space Complexity : O(1) for input, O(n*(2nCn)) for output
-> 1 for n
-> n*(2nCn) brackets will be needed for output
-> small space usage for i, temp

Algorithm : 
1. There are 2*n brackets, n openings and n closing. We will push this one by one. There are 3 situations for push.
1) There are no brackets. We must open a bracket, so we push_back opening bracket.
2) You have leftover opening bracket, but also there are brackets that needs to be closed. We can push_back both opening/closing bracket.
3) You already used up opening bracket, but there are leftover closing brackets. You can only push_back closing bracket.
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // count # of open parenthesis
    int count_open(string element){
        int count = 0;
        for (int i = 0; i < element.size(); i++){
            if (element[i] == '(') count++;
        }
        return count;
    }
    // count # of closed parenthesis
    int count_close(string element){
        int count = 0;
        for (int i = 0; i < element.size(); i++){
            if (element[i] == ')') count++;
        }
        return count;        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        for (int i = 0; i < 2*n; i++){
            // the start must be an opening one
            if (i == 0){
                result.push_back("(");
            }
            else {
                vector<string> temp;
                for (vector<string>::iterator iter = result.begin(); iter != result.end(); iter++){                    
                    // you can only open since all open ones are closed.
                    if(count_open(*iter) < n && count_open(*iter) == count_close(*iter)){
                        temp.push_back(*iter + "(");
                    }
                    // you can either open or close.
                    else if(count_open(*iter) < n && count_open(*iter) != count_close(*iter)){
                        temp.push_back(*iter + "(");
                        temp.push_back(*iter + ")");
                    }
                    // opening is done, only need to close.
                    else{
                        temp.push_back(*iter + ")");
                    }                    
                }
                result = temp;
            }
        }
        return result;
    }
};