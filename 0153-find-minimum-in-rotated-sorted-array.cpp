/*
 * LeetCode #0153 - Find Minimum in Rotated Sorted Array
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *
 * Difficulty: Medium
 * Topic: Array, Binary Search
 * Time: O(log n) | Space: O(1)
 *
 * Approach:
 * Use binary search to find the minimum element in a rotated
 * sorted array without duplicates.
 *
 * Compare nums[middle] with nums[right] to determine which
 * half contains the minimum.
 *
 * If nums[middle] < nums[right], the minimum is at middle
 * or to its left, so set right = middle.
 *
 * Otherwise, the minimum must be strictly to the right
 * of middle, so set left = middle + 1.
 *
 * Continue until left == right, then return nums[left].
 */

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() -1;
        while(left < right){
            int middle = left + (right - left)/2;
            if(nums[middle] < nums[right]){
                right = middle;
            }else if(nums[middle] > nums[right]){
                left = middle + 1;
            }
        }
        return nums[left];
    }
};