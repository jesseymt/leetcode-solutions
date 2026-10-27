/*
 * LeetCode #0011 - Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/
 *
 * Difficulty: Medium
 * Topic: Array, Two Pointers
 * Time: O(N) | Space: O(1)
 *
 * Approach:
 * Initialize left and right pointers at opposite ends
 * of the array to maximize the initial width.
 *
 * Calculate the area using the shorter height multiplied
 * by the distance between the two pointers.
 *
 * Update maxWater whenever a larger area is found.
 * Move the pointer with the shorter height inward,
 * since moving the taller one cannot increase the area
 * while the shorter height remains the limiting factor.
 *
 * Continue until the pointers meet.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while(left < right){
            int water = min(height[left], height[right])  * (right - left);
            if(water > maxWater){
                maxWater = water;
            }
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxWater;
    }
};