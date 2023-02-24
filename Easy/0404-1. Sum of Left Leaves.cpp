/* 
Question link : https://leetcode.com/problems/sum-of-left-leaves/

Runtime : 0 ms
Beats : 100 %
Memory : 13.4 MB
Beats : 52.37 %

Time Complexity : O(n)
-> left nodes are scanned max twice, right nodes are scanned max once.

Space Complexity : O(n) for input, O(1) for algorithm and output
-> n for tree
-> 1 for result

Algorithm :
1. Traverse the tree from start. There are 3 scenarios
1) The left(or right) node is a nullptr. This means the given root and childern doesn't have a left-leaf, so don't need to do anything.
2) The left node is not a nullptr. This case, we need to check if the left-node is a left-leaf, which is possible by checking if the left-node doesn't have any children.
3) The right node is not a nullptr. This case, we should make a recursive call to the right-node, so we can find left-leaves from right subtree.
*/

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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        if (root -> left != nullptr){
            if (root -> left -> left == nullptr && root -> left -> right == nullptr) result += root -> left -> val;
            else result += sumOfLeftLeaves(root -> left);
        }
        if (root -> right != nullptr) result += sumOfLeftLeaves(root -> right);
        return result;
    }
};