/* 
Question link : https://leetcode.com/problems/balanced-binary-tree/

Runtime : 13 ms
Beats : 75.88%
Memory : 20.9 MB
Beats : 59.59%

Time Complexity : O(n)
-> n calls with linear number of operations(check if either left/right tree is unbalanced, check unbalance of current node, return value)

Space Complexity : O(n)
-> 2*n since every node holds left tree and right tree height information

Algorithm :
1. We need an assumption that the tree_height function return -1 if tree is unbalanced, and proper value of height if balanced.
2. Calculate the left/right tree height using recursion.
3. If either of the heights are -1, return -1 as well(no need of calculation since the tree is unbalanced anyways. This step prevents showing true when the root node has balance but a subnode doesn't.)
4. Compare the heights.
5. If the comparison is unbalanced, return -1. If it is balanced, return the tree height(by 1 + bigger heighted tree among left/right tree).
*/

#include <math.h>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int tree_height(TreeNode* root){
        if (root == nullptr) return 0;

        int left_tree_height = tree_height(root -> left);
        int right_tree_height = tree_height(root -> right);
        if (left_tree_height == -1 || right_tree_height == -1) return -1;
        if (abs(left_tree_height - right_tree_height) > 1) return -1;

        return 1 + max(left_tree_height, right_tree_height);
    }
    bool isBalanced(TreeNode* root) {
        return tree_height(root) != -1;
    }
};