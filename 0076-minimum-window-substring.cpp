/*
 * LeetCode #0076 - Minimum Window Substring
 * https://leetcode.com/problems/minimum-window-substring/
 *
 * Difficulty: Hard
 * Topic: Hash Table, String, Sliding Window
 * Time: O(n + m) | Space: O(1)
 *
 * Approach:
 * Use a sliding window with an unordered_map to track the remaining
 * frequencies of characters required from t.
 *
 * Initialize the map with character counts from t and track the number
 * of distinct characters whose required frequencies are not yet satisfied.
 *
 * Expand the right pointer, decrementing frequencies for relevant
 * characters. When a frequency reaches zero, decrement remaining_t.
 *
 * Once remaining_t reaches zero, the window is valid. Record its length
 * and starting index if it is smaller than the previous minimum.
 *
 * Shrink the window by moving the left pointer, restoring frequencies.
 * If a frequency becomes positive, increment remaining_t because the
 * window no longer contains enough occurrences of that character.
 *
 * Continue expanding and shrinking until the entire string is processed.
 * Return the shortest valid substring, or an empty string if none exists.
 */

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    void updateLeft(const string& s, unordered_map<char, int>& freq_t, int& rem_t, int& left){
        char c = s[left];
        
        if(freq_t.find(c) != freq_t.end()){
            freq_t[c]++;
            
            if(freq_t.at(c) == 1){
                rem_t++;
            }
        }
        
        left++;
    }
    void updateRight(const string& s, unordered_map<char, int>& freq_t, int& rem_t, int right){
        char c = s[right];
        
        if(freq_t.find(c) != freq_t.end()){
            freq_t[c]--;
            if(freq_t.at(c) == 0){
                rem_t--;
            }
        }
        
    }
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        
        unordered_map<char, int> freq_t;
        for(char c: t){
            freq_t[c]++;
        }
        int remaining_t = freq_t.size();
        
        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        
        while(right < s.size()){
            updateRight(s, freq_t, remaining_t, right);
            
            while(remaining_t == 0){
                int currLen = right-left+1;
                
                if(currLen<minLen){
                    minLen = currLen;
                    minStart = left;
                }
                
                updateLeft(s, freq_t, remaining_t, left);
            }
    
            right++;
        }
        
        if(minLen == INT_MAX){
            return "";
        }
         
        return s.substr(minStart, minLen);
    }
};