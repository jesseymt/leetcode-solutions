/*
 * LeetCode #0242 - Valid Anagram
 * https://leetcode.com/problems/valid-anagram/
 *
 * Difficulty: Easy
 * Topic: String
 * Time: O(N) | Space: O(1)
 *
 * Approach:
 * - if both strings are not the same length, return false
 * - create array of size 26 for each char in alphabet, initialized to 0
 * - iterate through both strings simultaneously
 * - subtract 'a' from chars to convert to pertaining alphabet index
 * - increment count for chars in first string
 * - decrement count for chars in second string
 * - if any char's count is nonzero, return false
 * - else, return true
 */

#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();
        if(sLength != tLength ){
            return false;
        }
        
        int arr[26] = {0};
        for(int i = 0; i<sLength; i++){
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for(const auto& value: arr){
            if(value != 0){
                return false;
            }
        }
        return true;
    }
};