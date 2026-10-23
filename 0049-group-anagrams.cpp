/*
 * LeetCode #0049 - Group Anagrams
 * https://leetcode.com/problems/group-anagrams/
 *
 * Difficulty: Medium
 * Topic: Array, Hash Table, Sorting, String
 * Time: O(N * K) average | Space: O(N * K)
 *
 * Approach:
 * - Count the frequency of each lowercase letter using a 26-element array.
 * - Convert the frequencies into a string key with separators.
 * - Group strings with identical frequency signatures in a hash map.
 * - Push each group into the result vector.
 * 
 * Note: 
 * - Despite O(N * K) average complexity, this implementation ran slower than sorting (75 ms vs. 16 ms) on LeetCode.
 * - Constructing frequency keys adds string conversion overhead.
 * - Runtimes are submission-specific and may vary.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;
        for(const string& str: strs){
            int freq[26] = {0};

            for(char c: str){
                freq[c - 'a']++;
            }
            string key = "";
            for(int count: freq){
                key += "#" + to_string(count);
            }
            groups[key].push_back(str);
        }
        for(const auto& [key, group]: groups){
            ans.push_back(group);
        }
        return ans;
    }
};