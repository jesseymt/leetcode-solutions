/*
 * LeetCode #0128 - Longest Consecutive Sequence
 * https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * Difficulty: Medium
 * Topic: Array, Hash Table, Hash Set
 * Time: O(n) | Space: O(n)
 *
 * Approach:
 * Insert all numbers into an unordered_set to enable
 * O(1) average membership checks and eliminate duplicates.
 *
 * Iterate through unique numbers, skipping any number
 * whose predecessor (num - 1) exists in the set.
 *
 * For each sequence start, count consecutive integers
 * using a while loop and update the longest length.
 *
 * Iterating over the set prevents repeated traversals
 * caused by duplicate starting values in nums.
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int longest = 0;
        for(int num: nums){
            seen.insert(num);
        }
        for(int num: seen){
            if(seen.count(num-1)){
                continue;
            }
            int consecutive =0;
            int current = num;
            while(seen.count(current)){
                consecutive++;
                current++;
            }
            if(consecutive > longest){
                longest = consecutive;
            }
        }
        return longest;
    }
};