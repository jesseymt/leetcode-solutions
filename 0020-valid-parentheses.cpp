/*
 * LeetCode #0020 - Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses/
 *
 * Difficulty: Easy
 * Topic: String, Stack
 * Time: O(N) | Space: O(N)
 *
 * Approach:
 * - Iterate through the string character by character.
 * - Push opening brackets ('(', '{', '[') onto a stack.
 * - For each closing bracket, check whether the stack is
 *  empty or its top doesn't match the corresponding opening bracket.
 * - If invalid, return false; otherwise, pop the matching bracket.
 * - Return true only if the stack is empty after processing the string.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // create stack vector
        vector<char> stack;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push_back(s[i]);
            }
            if(s[i] == ')'){
                if(stack.empty() || stack.back()!='('){
                    return false;
                }
                stack.pop_back();
            }
            if(s[i] == '}'){
                if(stack.empty() || stack.back()!='{'){
                    return false;
                }
                stack.pop_back();
            }
            if(s[i] == ']'){
                if(stack.empty() || stack.back()!='['){
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();      
    }
};