/* 
Question link : https://leetcode.com/problems/counting-bits/

Runtime : 8 ms 
Beats : 52.84 %
Memory : 8.4 MB
Beats : 36.73 %

Time Complexity : O(nlogn)
-> for binary conversion, needs log n times of calculation(calculation happens while dividing value with 2)
-> conversion happens n times.

Space Complexity : O(n)
-> n for result vector
-> 4 for n, i, sum, num

Algorithm :
1. For each n, run the decimal-binary conversion and count number of 1s during the conversion.
2. Push result in vector

Point :
1. Don't modify for loop variables inside loop, since the variable update will happen on modified variable(unless you intend it)
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;

        for (int i = 0; i <= n; i++){
            int sum = 0;
            int num = i;
            while (num > 0){
                sum += num % 2;
                num /= 2;
            }
            result.push_back(sum);
        } 
        return result;   
    }
};