/*
 * LeetCode #0424 - Longest Repeating Character Replacement
 * https://leetcode.com/problems/longest-repeating-character-replacement/
 *
 * Difficulty: Medium
 * Topic: String, Sliding Window
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Use a sliding window with two pointers (left and right) to find the longest
 * substring that can be made of identical characters with at most k replacements.
 *
 * Maintain a frequency array of 26 uppercase letters and track maxFreq,
 * the highest frequency of a single character encountered in the window.
 *
 * Expand the window by moving right and updating the character frequency.
 * If windowSize - maxFreq > k, shrink the window by decrementing the
 * frequency at left and moving left forward.
 *
 * Keep maxFreq non-decreasing, even when shrinking, since we only need
 * to track the longest achievable window length.
 *
 * Update longest with the maximum window size encountered.
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int longest = 0;
        vector<int> freq(26,0);
        int maxFreq = 0;
        while(right < s.size()){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            if(right - left + 1 - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            longest = max(longest, right - left + 1);
            right++;
        }
        return longest;
    }
};