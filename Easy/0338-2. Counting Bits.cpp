/* 
Question link : https://leetcode.com/problems/counting-bits/

Runtime : 3 ms 
Beats : 96.62 %
Memory : 8.4 MB
Beats : 36.73 %

Time Complexity : O(n)
-> each number only needs 1 calculation.

Space Complexity : O(n)
-> n for result vector
-> 2 for n, i

Logic : There is a pattern in # of 1s.
Odd number -> 5(101) vs 2(10) or 7(111) vs 3(11)
-> # of 1s change.
Even number -> 2(10) vs 1(1) or 12(1100) vs 6(110)
-> # of 1s don't change.

Algorithm :
1. Push 0 into result vector as init value.
2. Push result[i/2] + i%2. This calculation comes from the base logic.

*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 1; i <= n; i++){
            result.push_back(result[i/2] + i%2);
        }
        return result;
    }
};