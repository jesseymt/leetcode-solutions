/*
 * LeetCode #01267 - Two Sum II - Input Array Is Sorted
 * https://leetcode.com/problems/problem-slug/
 *
 * Difficulty: Medium
 * Topic: Array, Two Pointers
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Initialize left and right pointers at opposite ends
 * of the sorted array.
 *
 * Calculate the sum of the two elements.
 * If the sum equals the target, return their 1-based indices.
 * If the sum exceeds the target, decrement right.
 * Otherwise, increment left.
 *
 * Continue until the target pair is found.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int n = numbers.size();
       int low = 0;
       int high = n-1;
       while(low < high){
        int sum = numbers[low] + numbers[high];
        if(sum == target){
            return {low+1, high+1};
        }else if(sum > target){
            high--;
        }else{
            low++;
        }
       }
       return {-1,-1};
    }
};