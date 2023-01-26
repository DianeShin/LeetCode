/* 
Question link : https://leetcode.com/problems/binary-tree-paths/

Runtime : 0 ms
Beats : 100%
Memory : 12.4 MB
Beats : 90.13%

Time Complexity : O(V)
-> Each node is traversed once.

Space Complexity : O(h) for DFS, O(n) for algorithm
-> h is max depth of tree. 'path' saves tree depth worth string.
-> Though we need n vector input, and leaf_node_number_sized result vector.

Algorithm :
1. Do a recursive call until we reach to the leaf node.
2. If not leaf, pass the past route + curr_node path to DFS again, with non null left/right path.
3. When leaf, push_back the whole path to result vector.

Point :
1. DFS time complexity for tree is O(n), while it is O(V + E) for graph.
*/

#include <vector>
#include <string>

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
    vector<string> result;
    void DFS(TreeNode* node, string path){
        if (node -> left == nullptr && node -> right == nullptr) result.push_back(path + to_string(node -> val));
        else{
            if (node -> left != nullptr) DFS(node -> left, path + to_string(node -> val) + "->");
            if (node -> right != nullptr) DFS(node -> right, path + to_string(node -> val) + "->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        DFS(root, "");
        return result;
    }
};