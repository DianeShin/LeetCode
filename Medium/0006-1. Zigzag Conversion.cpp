/* 
Question link : https://leetcode.com/problems/invert-binary-tree/

Runtime : 21 ms
Beats : 49.68%
Memory :8.3 MB
Beats : 82.68%

Time Complexity : O(n)
-> 1 Calculation for each character.
-> linear condition checks for middle row elements.

Space Complexity : O(n)
-> n for input string
-> n for result string
-> 3 for numRows, index, row.

Algorithm : Add to result from first row to last row.
1. The first row is constituted with index += 2 * (numRows-1). Add to result until index exceeds string size.
2. The middle rows are constituted with above_index plus/minus curr_row. Need to check if index is less than 0 or bigger than size of string.
-> Used while(true) because above_index can exceed the limit when above_index - curr_row might be still in index.
3. The last row is constituted with index of row number += 2 * (numRows-1).

Point :
1. Comparison of signed/unsigned int(size_t) returns weird results. Convert to signed int before comparison.
*/

#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if (numRows == 1) return s;
        else{
            for (int row = 0; row < numRows ; row++){
                if (row == 0){
                    int index = 0;
                    while (index < s.size()){
                        result.push_back(s[index]);
                        index += 2 * (numRows - 1);
                    }                
                }
                else if (row == numRows -1){
                    int index = row;
                    while (index < s.size()){
                        result.push_back(s[index]);
                        index += 2 * (numRows - 1);
                    }                
                }
                else{
                    int index = 0;
                    while (true){
                        if (index - row >= (long long) s.size()) break;
                        else{
                            if (index - row > 0) result.push_back(s[index - row]);
                        }
                        if (index + row >= (long long) s.size()) break;
                        else{
                            if (index + row < (long long) s.size()) result.push_back(s[index + row]);
                        }                        
                        index += 2 * (numRows - 1);
                    }                    
                }
            }  
            return result;         
        }
    }
};