/*
 * LeetCode #0125 - Valid Palindrom
 * https://leetcode.com/problems/valid-palindrome/
 *
 * Difficulty: Easy
 * Topic: Two Pointers, String
 * Time: O(n) | Space: O(1)
 *
 * Approach:
 * Initialize left and right pointers at opposite ends
 * of the string.
 *
 * Skip non-alphanumeric characters using isalnum().
 * Compare the remaining characters case-insensitively
 * using tolower().
 *
 * If characters differ, return false immediately.
 * Otherwise, move both pointers inward.
 *
 * Return true if all comparisons succeed.
 */

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) -1;
        while(left < right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(tolower(static_cast<unsigned char>(s[left])) !=
               tolower(static_cast<unsigned char>(s[right]))){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};