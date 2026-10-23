/*
 * LeetCode #0049 - Group Anagrams
 * https://leetcode.com/problems/group-anagrams/
 *
 * Difficulty: Medium
 * Topic: Array, Hash Table, Sorting, String
 * Time: O(N * K * log K) average | Space: O(N * K)
 *
 * Approach:
 * - sort strings
 * - group original strings using sorted string as key
 * - push groups of strings into a final vector
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;
        for(string str: strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(str);
        }
        for(const auto& [str, vector]: groups){
            ans.push_back(vector);
        }
        return ans;
    }
};