/*
 * LeetCode #0217 - Contains Duplicate
 * https://leetcode.com/problems/contains-duplicate/
 *
 * Difficulty: Easy
 * Topic: Array, Hash Table
 * Time: O(N) average | Space: O(N)
 *
 * Approach:
 * - create unordered map
 * - iterate through nums and check existence
 * - if key exists, return true for duplicates
 * - or else insert num as key and increment it's value
 * - return false if no increment found
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash; 
        for(int i = 0; i < nums.size(); i++){
            if(hash.find(nums[i]) != hash.end()){
                return true;
            }
            hash[nums[i]]++;
        }
        return false;
    }
};