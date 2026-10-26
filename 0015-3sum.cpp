/*
 * LeetCode #0015 - 3Sum
 * https://leetcode.com/problems/3sum/
 *
 * Difficulty: Medium
 * Topic: Array, Two Pointer, Sorting
 * Time: O(N^2) | Space: O(log n)
 *
 * Approach:
 * Sort the array in ascending order.
 * Iterate through the array, fixing one element at index i.
 * Use left and right pointers to find two additional elements
 * whose sum with nums[i] equals zero.
 *
 * If sum == 0, store the triplet and move both pointers.
 * If sum > 0, decrement right.
 * If sum < 0, increment left.
 *
 * Skip duplicate fixed elements and duplicate pointer values
 * to ensure that only unique triplets are returned.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i+2 < nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() -1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left] == nums[left-1]){
                        left++;
                    }
                    while(right>left && nums[right] == nums[right+1]){
                        right--;
                    }
                }else if(sum > 0){
                    right--;
                }else if(sum< 0){
                    left++;
                }
            }
        }
        return ans;
    }
};