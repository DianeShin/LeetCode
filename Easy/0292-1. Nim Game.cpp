/* 
Question link : https://leetcode.com/problems/nim-game/submissions/885875878/

Runtime : 0 ms 
Beats : 100 %
Memory : 6 MB
Beats : 45.69%

Time Complexity : O(1)
-> 1 modulus calculation is enough.

Space Complexity : O(1)
-> 1 for input

Logic :
Knowing you can win when there are 1/2/3 stones and lose when there are 4 stones(since you make a situation where the opponent has 1/2/3 stones).
For 5/6/7 stones, you can make the situation where opponent gets 4 stones next.
For 8 stones, opponent will get 5/6/7 stones and win.
This continues, which concludes that I will win unless there are 4k stones.

Algorithm :
1. return n % 4
*/


class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};