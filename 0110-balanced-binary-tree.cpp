/*
 * LeetCode #0110 - Balanced Binary Tree
 * https://leetcode.com/problems/balanced-binary-tree/
 *
 * Difficulty: Easy
 * Topic: Tree, Depth-First Search, Binary Tree
 * Time: O(n) | Space: O(h)
 *
 * Approach:
 * Use recursive depth-first search (DFS) to calculate the height of each subtree
 * while tracking whether the binary tree remains height-balanced.
 *
 * For each node, recursively calculate the heights of its left and right subtrees.
 * If their height difference exceeds 1, update the shared balanced flag to false.
 * This ensures that every node is checked, not just the root.
 *
 * Return 1 + max(leftHeight, rightHeight) to propagate the current subtree's
 * height to its parent. The base case returns 0 for a null node.
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
    int height(bool& balanced, TreeNode* root){
        if(root == nullptr || !balanced){
            return 0;
        }
        int leftHeight = height(balanced, root->left);
        int rightHeight = height(balanced, root->right);

        if(abs(leftHeight - rightHeight) > 1){
            balanced = false;
        }
        return 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(balanced, root);
        return balanced;
    }
};