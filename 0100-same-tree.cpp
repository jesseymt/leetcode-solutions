/*
 * LeetCode #0100 - Same Tree
 * https://leetcode.com/problems/same-tree/
 *
 * Difficulty: Easy
 * Topic: Tree, Depth-First Search, Binary Tree
 * Time: O(n) | Space: O(H)
 *
 * Approach:
 * Recursively traverse both binary trees simultaneously.
 * 
 * Check whether either node is null while the other is not.
 * 
 * If both nodes are null, return from the current recursive call.
 * 
 * Compare the values of corresponding nodes and update the shared
 * boolean flag if a mismatch is found.
 * 
 * Recursively check the left and right subtrees.
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
    void check(bool& same, TreeNode* p, TreeNode* q){
        if(p == nullptr && q != nullptr || p != nullptr && q == nullptr || !same){
            same = false;
            return;
        }else if(p == nullptr && q == nullptr){
            return;}
        if(p->val != q->val){
            same = false;
            return;
        }
        check(same, p->left, q->left);
        check(same, p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same = true;
        check(same, p, q);
        return same;
    }
};
