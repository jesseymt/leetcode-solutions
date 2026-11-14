/*
 * LeetCode #0226 - Invert Binary Tree
 * https://leetcode.com/problems/invert-binary-tree/
 *
 * Difficulty: Medium
 * Topic: Tree, Depth-First Search, Binary Tree
 * Time: O(n) | Space: O(Height)
 *
 * Approach:
 * Use recursive depth-first search (DFS) to invert the binary tree in place.
 *
 * If the current node is nullptr, return nullptr as the base case.
 *
 * Swap the left and right child pointers of the current node, then
 * recursively invert both the left and right subtrees.
 *
 * Once both recursive calls finish, return the current root pointer.
 */

#include <utility>
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};