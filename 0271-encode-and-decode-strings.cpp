/*
 * LeetCode #0271 - Encode and Decode Strings
 * Platform used to solve: NeetCode
 * Problem link: https://neetcode.io/problems/string-encode-and-decode
 * Original Leetcode link: https://leetcode.com/problems/encode-and-decode-strings/
 *
 * Difficulty: Medium
 * Topic: Array, String
 * Time: O(N) | Space: O(N)
 *
 * Approach:
 * Use length-prefixed encoding to safely handle strings containing delimiters.
 * For each string, append its length, followed by '#', then the string itself.
 *
 * During decoding, iterate through the encoded string using an index.
 * Find the next '#' delimiter to extract the length prefix.
 * Convert the length to an integer using stoi().
 * Use substr() to extract exactly that many characters after the delimiter.
 * Append the extracted string to the result vector.
 * Advance the index past the extracted string and repeat.
 *
 * This approach handles empty strings and strings containing '#' because
 * the decoder uses the stored length rather than splitting on delimiters.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_string = "";
        string separator = "#";

        for(const string& str: strs){
            encoded_string += to_string(str.length()) + separator + str;
        }
        
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        for(int i =0; i < s.length(); i++){
            int j = i;
            string nums = "";
            while(s[j] != '#'){
                nums += s[j];
                j++;
            }
            int num = stoi(nums);
            decoded_strs.push_back(s.substr(j+1, num));
            i = j+num;
        }
        return decoded_strs;
    }
};