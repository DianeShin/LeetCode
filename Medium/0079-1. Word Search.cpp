/* 
Question link : https://leetcode.com/problems/word-search/

Runtime : 1015 ms
Beats : 40.70 %
Memory : 8.1 MB
Beats : 24.14 %

Time Complexity : O(n*m * 4^l) : n for row number, m for column number, l for length of word
-> n*m since exist_recursion is called for every element in matrix
-> 4^l since there are 4 possible paths from 1 point in matrix, which is repeated for every char in string.

Space Complexity : O(n*m) for input, O(4^l) for algorithm
-> n * m for board
-> 4^l stacks for recursion algorithm
-> 1 each for temp, solution_1-4 inside each recursion stack

Logic :
It is easy to understand if you think about how you would perform the search. You just need to try searching every possible way(though our brain is fast enough to remove impossible ways very fast).

Algorithm :
1. Call exist_recursion for every element in the matrix with a for loop and return true if word is found in board, false if not.
2. For the search, we need to consider end cases where either word is found(string exhaustion, return true) or where the condition is not met(index out of bound, landed character doens't match the current character)
3. We search the next character by creating a substring excluding the first char of word, then moving the current point in matrix by 1 move(1 up/down/left/right from current point)
4. Combine the search results then return.
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist_recursion(vector<vector<char>>& board, int row_index, int column_index, string word){
        // string is all exhausted, so there is a solution
        if (word.size() == 0) return true;

        // conditions where search failed
        else if (row_index < 0 || row_index >= board.size() || column_index < 0 || column_index >= board[0].size() || board[row_index][column_index] != word[0]) return false;

        // set used char as unappearable char
        char temp = board[row_index][column_index];
        board[row_index][column_index] = '-';

        // create possible moves
        bool solution_1 = exist_recursion(board, row_index - 1, column_index, word.substr(1, word.size()-1));
        bool solution_2 = exist_recursion(board, row_index + 1, column_index, word.substr(1, word.size()-1));
        bool solution_3 = exist_recursion(board, row_index, column_index - 1, word.substr(1, word.size()-1));
        bool solution_4 = exist_recursion(board, row_index, column_index + 1, word.substr(1, word.size()-1));

        // recover board to correct board
        board[row_index][column_index] = temp;

        // return if there is a possible solution
        return solution_1 || solution_2 || solution_3 || solution_4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++){
            for (int column = 0; column < board[0].size(); column++){
                if (exist_recursion(board, row, column, word)) return true;
            }
        }
        return false;
    }
};