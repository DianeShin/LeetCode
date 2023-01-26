/* 
Question link : https://leetcode.com/problems/diameter-of-binary-tree/

Runtime : 16 ms
Beats : 46.9 %
Memory : 20.2 MB
Beats : 94.15 %

Time Complexity : O(n)
-> n for DFS
-> n for result update(done for every node in tree)

Space Complexity : O(n)
-> n for input
-> 3 for left_depth, right_depth, result

Logic :
A diameter is calculated by coming from the left node, passing the node, then going to the right node.
This means that we can calculate the max value by adding left node depth and right node depth of every node.

Algorithm :
1. Run the depth calculation algorithm.
2. While running, update result if left node depth + right node depth is bigger than result.
*/

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
    int result;
    int depth(TreeNode* node){
        if (node == nullptr) return 0;
        else{
            int left_depth = depth(node -> left);
            int right_depth = depth(node -> right);
            if (result < left_depth + right_depth) result = left_depth + right_depth;
            return 1 + max(left_depth, right_depth);
        } 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return result;
    }
};