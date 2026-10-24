/*
 * LeetCode #0238 - Product of Array Except Self
 * https://leetcode.com/problems/product-of-array-except-self/
 *
 * Difficulty: Medium
 * Topic: Array, Prefix Sum
 * Time: O(N) | Space: O(1) auxiliary, O(N) output
 *
 * Approach:
 * Store prefix products directly in the answer vector.
 * Traverse backward, multiplying each answer element by the running suffix product.
 * Exclude the current element from both products.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int pre = 1;
        int post = 1;
        for(int i =1; i < n; i++){
            pre *= nums[i-1];
            ans[i] = pre;
        }
        for(int i = n-2; i >=0 ; i--){
            post *= nums[i+1];
            ans[i] *= post;
        }
        
        return ans;
    }
};