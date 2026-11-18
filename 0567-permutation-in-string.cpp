/*
 * LeetCode #0567 - Permutation in String
 * https://leetcode.com/problems/permutation-in-string/
 *
 * Difficulty: Medium
 * Topic: Two Pointers, String, Sliding Window
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Use a fixed-size sliding window of length s1.size() over s2.
 * Initialize two frequency vectors of size 26 to count characters.
 * One vector stores frequencies from s1, while the other tracks
 * frequencies within the current window of s2.
 *
 * Compare both vectors to determine whether the window is a permutation.
 * Slide the window by removing the leftmost character and adding
 * the next character on the right.
 * Return true if any window has matching character frequencies.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
    void update(vector<int>& freq, int& nonzero, int idx, int change){
        if(freq[idx] == 0){
            nonzero++;
        }
        freq[idx] += change;
        if(freq[idx] == 0){
            nonzero--;
        }
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> freq1(26,0);
        int left = 0;
        int right = 0;
        int nonzero = 0;
        for(char c: s1){
            freq1[c - 'a']++;
        }
        for(int num: freq1){
            if(num != 0){
                nonzero++;
            }
        }
        
        while(right < s2.size()){
            update(freq1, nonzero, s2[right] - 'a', -1);
            if(right - left + 1 > s1.size()){
                update(freq1, nonzero, s2[left] - 'a', 1);
                left++;
            }
            if(nonzero == 0){
                return true;
            }
            right++;
        }
        return false;
    }
};
