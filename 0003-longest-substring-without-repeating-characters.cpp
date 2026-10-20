/*
 * LeetCode #0003 - Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Difficulty: Medium
 * Topic: Hash Table, Sliding Window, String
 * Time: O(n) | Space: O(min(n, k))
 *
 * Approach:
 * Use left and right pointers to maintain a substring.
 * Store character frequencies in an unordered_map.
 * Expand the window by incrementing the frequency of s[right].
 * If a duplicate occurs, shrink from the left until valid.
 * Track the maximum valid window length.
 */

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> hash; 
        int max_length = 0;
        int left = 0;
        int right = 0;
        
        for(right; right < s.length(); right++){
            hash[s[right]]++; //char occurance count
            while(hash[s[right]] > 1){
                    hash[s[left]]--;
                    if(hash[s[left]] == 0){
                        hash.erase(s[left]);
                    }
                    left++;
            }
            if(hash.size() > max_length){
                max_length = hash.size();
            }
        }
        return max_length;
    }
};