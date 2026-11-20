/*
 * LeetCode #0076 - Minimum Window Substring
 * https://leetcode.com/problems/minimum-window-substring/
 *
 * Difficulty: Hard
 * Topic: Hash Table, String, Sliding Window
 * Time: O(n + m) | Space: O(1)
 *
 * Approach:
 * Use a sliding window with a fixed-size ASCII frequency array of 128
 * integers to track the remaining occurrences of characters from t.
 *
 * Initialize the array with frequencies from t and set remaining to
 * the total number of required characters, including duplicates.
 *
 * Expand the right pointer. If the current character's frequency is
 * positive, decrement remaining. Always decrement its frequency,
 * allowing negative values to represent extra occurrences.
 *
 * When remaining reaches zero, the window contains all required
 * characters. Update the minimum length and starting index if needed.
 *
 * Shrink the window by incrementing the left character's frequency.
 * If it becomes positive, increment remaining because a required
 * occurrence is now missing. Continue until the window becomes invalid.
 *
 * Store only the best starting index and length to avoid repeatedly
 * constructing substrings. Return the minimum substring once at the end.
 * 
 * Unlike the original unordered_map implementation, which tracks the
 * number of distinct characters with unsatisfied frequencies, this
 * version tracks the total number of missing character occurrences.
 *
 * Positive frequencies indicate missing occurrences, zero indicates
 * exactly enough, and negative frequencies indicate extra occurrences.
 *
 * This eliminates the need to check whether a character exists in
 * the map, since all characters can be indexed directly in the array.
 * Only positive frequencies affect the remaining counter.
 */

#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }

        int freq[128] = {};

        for(char c : t){
            freq[c]++;
        }

        int remaining = t.size();
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for(int right = 0; right < s.size(); right++){
            char c = s[right];

            if(freq[c] > 0){
                remaining--;
            }
            freq[c]--;

            while(remaining == 0){
                int currLen = right - left + 1;

                if(currLen < minLen){
                    minLen = currLen;
                    minStart = left;
                }

                char leftChar = s[left];

                freq[leftChar]++;

                if(freq[leftChar] > 0){
                    remaining++;
                }

                left++;
            }
        }

        if(minLen == INT_MAX){
            return "";
        }

        return s.substr(minStart, minLen);
    }
};