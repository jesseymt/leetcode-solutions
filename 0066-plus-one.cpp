/*
 * LeetCode #0066 - Plus One
 * https://leetcode.com/problems/plus-one/
 *
 * Difficulty: Easy
 * Topic: Array, Math
 * Time: O(N) | Space: O(1) auxiliary space
 *
 * Approach:
 * Traverse the digits array backward, starting from the last digit.
 * If the current digit is less than 9, increment it and return.
 * Otherwise, set the digit to 0 and continue to the previous digit
 * to propagate the carry.
 *
 * If all digits were 9, insert a 1 at the beginning of the vector
 * and return the result.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = static_cast<int>(digits.size()) -1; i >=0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};