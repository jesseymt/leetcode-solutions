/*
 * LeetCode #0001 - Two Sum
 * https://leetcode.com/problems/two-sum/
 * 
 * Difficulty: Easy
 * Topic: Array, Hash Table
 * Time: O(n) | Space: O(n)
 *
 * Approach: 
 * store each number -> first encountered index in a hash map
 * search for complement existence and avoid reusing same index
 * push answer pair into vector and return
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(hash.find(nums[i]) == hash.end()){
                hash[nums[i]] = i;
            }
            if(hash.find(target-nums[i]) != hash.end()){
                if(hash.at(target-nums[i]) != i){
                    ans.push_back(i);
                    ans.push_back(hash.at(target-nums[i]));
                    return ans;
                }
            }

        }
        return {-1,-1};
    }
};