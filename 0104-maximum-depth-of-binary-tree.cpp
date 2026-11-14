/*
 * LeetCode #0104 - Maximum Depth of Binary Tree
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *
 * Difficulty: Easy
 * Topic: Tree, Binary Tree
 * Time: O(n) | Space: O(h)
 *
 * Approach:
 * Use recursive depth-first search (DFS) to calculate the maximum depth
 * of a binary tree.
 *
 * If the current node is nullptr, return 0 as the base case,
 * representing the depth of an empty subtree.
 *
 * Recursively calculate the maximum depth of the left and right subtrees.
 * Return 1 plus the greater of the two depths to account for the current node.
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};