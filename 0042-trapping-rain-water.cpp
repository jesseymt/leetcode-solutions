/*
 * LeetCode #0042 - Trapping Rain Water
 * https://leetcode.com/problems/trapping-rain-water/
 *
 * Difficulty: Hard
 * Topic: Array, Two Pointers
 * Time: O(N) | Space: O(1)
 *
 * Approach:
 * Use two pointers starting at opposite ends of the array.
 * Maintain leftMax and rightMax to track the tallest walls
 * encountered from each side.
 *
 * Compare the heights at both pointers and process the
 * shorter side, since the opposite wall guarantees a
 * sufficient boundary for trapping water.
 *
 * If the current height exceeds its side's maximum,
 * update that maximum. Otherwise, add the difference
 * between the maximum and current height to the total.
 *
 * Move the processed pointer inward until both meet.
 * Return the total trapped water.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3){
            return 0;
        }
        int left = 0;
        int right = height.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        int trap = 0;

        while (left < right){
            if(height[left] <= height[right]){
                if(height[left] >= leftMax){
                    leftMax = height[left];
                }else{
                    trap += leftMax - height[left];
                }
                left++;
            }else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }else{
                    trap += rightMax - height[right];
                }
                right--;
            }
            
        }
        return trap;
    }
};