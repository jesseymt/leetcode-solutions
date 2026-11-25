/*
 * LeetCode #0287 - Find the Duplicate Number
 * https://leetcode.com/problems/find-the-duplicate-number/
 *
 * Difficulty: Medium
 * Topic: Array, Two Pointer, Floyd's Cycle Finding Algorithm
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Use Floyd's Tortoise and Hare algorithm by treating each array
 * value as a pointer to the next index.
 *
 * Initialize slow and fast at index 0. Move slow one step and
 * fast two steps until they collide inside the cycle.
 *
 * Reset slow to index 0 while keeping fast at the collision point.
 * Move both pointers one step at a time until they meet again.
 *
 * The second meeting point represents the entrance to the cycle,
 * which corresponds to the duplicate number.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};