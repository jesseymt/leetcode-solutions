/*
 * LeetCode #0543 - Diameter of Binary Tree
 * https://leetcode.com/problems/diameter-of-binary-tree/
 *
 * Difficulty: Easy
 * Topic: Tree, Depth-First Search, Binary Tree
 * Time: O(n) | Space: O(h)
 *
 * Approach: 
 * Use recursive depth-first search (DFS) to calculate the height of each subtree
 * while tracking the maximum diameter of the binary tree.
 *
 * For each node, recursively calculate the heights of its left and right subtrees.
 * The diameter passing through the current node is the sum of these heights.
 * Update the maximum diameter if this path is longer than the previous maximum.
 *
 * Return 1 + max(leftHeight, rightHeight) to the parent node, representing the
 * height of the current subtree. The base case returns 0 for a null node.
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
    int height(TreeNode* root, int& diameter){
        if(root == nullptr){
            return 0;
        }

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        int newHeight = 1 + max(leftHeight, rightHeight);

        diameter = max(diameter, leftHeight + rightHeight);
        return newHeight;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};