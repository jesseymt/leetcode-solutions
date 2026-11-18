/*
 * LeetCode #0100 - Same Tree
 * https://leetcode.com/problems/same-tree/
 *
 * Difficulty: Easy
 * Topic: Tree, Depth-First Search, Binary Tree
 * Time: O(n) | Space: O(H)
 *
 * Approach:
 * Recursively compare corresponding nodes in both trees.
 * Return true if both nodes are null.
 * Return false if only one node is null or their values differ.
 * Recursively compare the left and right subtrees using logical AND.
 * Return true only if both subtrees are identical.\
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr){
            return true;
        }
        if(p==nullptr || q==nullptr){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
