/*
 * LeetCode #0572 - Subtree of Another Tree
 * https://leetcode.com/problems/subtree-of-another-tree/
 *
 * Difficulty: Easy
 * Topic: Tree, Depth-First Search, Binary Tree
 * Time: O(n * m) | Space: O(h1 + h2)
 *
 * Approach:
 * Recursively traverse the main tree to find a potential starting
 * node whose value matches the root of subRoot.
 *
 * When a matching value is found, use a helper function to compare
 * both trees recursively, checking node values and structure.
 * Return true if both trees are identical.
 *
 * If the comparison fails, continue searching the left and right
 * subtrees for another potential match.
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
    bool sameTree(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        return sameTree(p->left, q->left) && sameTree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr){
            return true;
        }
        if(root == nullptr){
            return false;
        }
        if(root->val == subRoot->val && sameTree(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};