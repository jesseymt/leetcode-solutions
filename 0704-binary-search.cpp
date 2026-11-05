/*
 * LeetCode #0704 - Binary Search
 * https://leetcode.com/problems/binary-search/
 *
 * Difficulty: Easy
 * Topic: Array, Binary Search
 * Time: O(log n) | Space: O(1)
 *
 * Approach:
 * Use binary search on the sorted array with left and right pointers.
 * Calculate the middle index using left + (right - left) / 2.
 * If the middle element equals the target, return its index.
 * If the middle element is smaller than the target, move left to middle + 1.
 * Otherwise, move right to middle - 1.
 * Repeat until the target is found or the search range becomes empty.
 * Return -1 if the target does not exist.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int middle = left + (right - left) / 2;
            if(nums[middle] == target){
                return middle;
            }
            if(nums[middle] < target){
                left = middle + 1;
            }else{
                right = middle -1;
            }
        }
        return -1;
    }
};