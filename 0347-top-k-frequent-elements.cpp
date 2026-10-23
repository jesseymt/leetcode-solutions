/*
 * LeetCode #0347 - Top K Frequent Elements
 * https://leetcode.com/problems/top-k-frequent-elements/
 *
 * Difficulty: Medium
 * Topic: Hash Table, Bucket Sort
 * Time: O(N) | Space: O(N)
 *
 * Approach:
 * - Count occurrences of each number using an unordered_map.
 * - Create N + 1 buckets, where each index represents a frequency.
 * - Place each unique number into the bucket matching its frequency.
 * - Traverse buckets backward, starting with the highest frequency.
 * - Collect and return the first K elements.
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> freqs;
        for(int num: nums){
            freqs[num]++;   
        }
        for(auto const& [num, freq]: freqs){
            bucket[freq].push_back(num);
        }
        vector<int> ans;
        for(int i = static_cast<int>(bucket.size())-1; i >=1; i--){
            for(int num: bucket[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};