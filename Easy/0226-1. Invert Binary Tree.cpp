/* 
Question link : https://leetcode.com/problems/invert-binary-tree/

Runtime : 8 ms
Beats : 11.26%
Memory : 9.8 MB
Beats : 44.83%

Time Complexity : O(n)
-> inversion needs to be done for every node.

Space Complexity : O(n)
-> n needed for input tree
-> max n-1 needed to save left tree.

Algorithm :
1. change left and right node
2. Using recursion, invert the left and right tree.
*/

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        else{
            TreeNode* save = root -> left;
            root -> left = invertTree(root -> right);
            root -> right = invertTree(save);
            return root;                
        }
    
    }
};