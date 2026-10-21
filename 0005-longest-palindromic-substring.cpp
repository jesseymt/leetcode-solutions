/*
 * LeetCode #0005 - Longest Palondromic Substring
 * https://leetcode.com/problems/longest-palindromic-substring/
 *
 * Difficulty: Medium
 * Topic: Two Pointers, String
 * Time: O(N^2) | Space: O(N)
 *
 * Approach:
 * Iterate through every character in the string as a potential palindrome center.
 * Check both palindrome types:
 * Odd-length: initialize left = i, right = i.
 * Even-length: initialize left = i, right = i + 1.
 * While both pointers are within bounds and their characters match, expand outward using left-- and right++.
 * If the current palindrome is longer than the longest found, update the result using substr().
 * Return the longest palindromic substring.
 */

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string sub = "";
        for(int i =0; i < s.length(); i++){
            //odd palindromes
            int left = i;
            int right = i;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if(right-left+1 > sub.length()){
                    sub = s.substr(left, right-left+1);
                }
                left--;
                right++;
            }
            //even palindromes
            left =i;
            right =i+1;
            while(left>=0 && right < s.length() && s[left] == s[right]){
                if(right-left+1 > sub.length()){
                    sub = s.substr(left, right-left+1);
                }
                left--;
                right++;
            }
        }
        return sub;
    }
};